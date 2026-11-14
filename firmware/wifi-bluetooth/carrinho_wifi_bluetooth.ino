#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error "Bluetooth Classic não está habilitado neste alvo."
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error "Bluetooth Serial (SPP) não está disponível neste alvo."
#endif

// Credenciais demonstrativas do ponto de acesso criado pelo ESP32.
// Troque a senha antes de usar o carrinho.
const char* WIFI_SSID = "Carrinho_ESP32";
const char* WIFI_PASSWORD = "carrinho123";
const char* BLUETOOTH_NAME = "Carrinho_ESP32_RC";

// GPIOs documentados no esquema enviado e no código original.
const uint8_t IN1 = 19;
const uint8_t IN2 = 18;
const uint8_t IN3 = 5;
const uint8_t IN4 = 4;

WebServer server(80);
BluetoothSerial SerialBT;

void moverFrente() {
  // Mantém a combinação do firmware recebido.
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moverTras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void girarEsquerda() {
  // Motor A avança e motor B recua, conforme a orientação descrita no código original.
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarDireita() {
  // Motor A recua e motor B avança, conforme a orientação descrita no código original.
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void processarComando(char comando) {
  switch (comando) {
    case 'F':
      moverFrente();
      break;
    case 'B':
      moverTras();
      break;
    case 'L':
      girarEsquerda();
      break;
    case 'R':
      girarDireita();
      break;
    case 'S':
      parar();
      break;
    default:
      // Ignora CR/LF comuns em terminais seriais; outros caracteres param os motores.
      if (comando != '\r' && comando != '\n') {
        Serial.print("Comando inválido: ");
        Serial.println(comando);
        parar();
      }
      return;
  }

  Serial.print("Comando executado: ");
  Serial.println(comando);
}

void enviarComandoDaWeb(char comando) {
  processarComando(comando);
  server.send(200, "text/plain", "OK");
}

void handleRoot() {
  const char pagina[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="pt-BR">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Carrinho ESP32</title>
  <style>
    body { font-family: sans-serif; text-align: center; margin: 2rem auto; max-width: 32rem; }
    .grid { display: grid; grid-template-columns: repeat(3, 1fr); gap: .7rem; }
    button { min-height: 4rem; font-size: 1.1rem; }
    .stop { background: #b42318; color: white; }
  </style>
</head>
<body>
  <h1>Carrinho ESP32</h1>
  <p>Controle pela rede Wi-Fi do ESP32.</p>
  <div class="grid">
    <span></span><button onclick="sendCommand('F')">Frente</button><span></span>
    <button onclick="sendCommand('L')">Girar à esquerda</button>
    <button class="stop" onclick="sendCommand('S')">Parar</button>
    <button onclick="sendCommand('R')">Girar à direita</button>
    <span></span><button onclick="sendCommand('B')">Ré</button><span></span>
  </div>
  <p id="status" aria-live="polite"></p>
  <script>
    async function sendCommand(command) {
      const status = document.getElementById('status');
      try {
        await fetch('/cmd?value=' + command);
        status.textContent = 'Comando enviado: ' + command;
      } catch (error) {
        status.textContent = 'Não foi possível enviar o comando.';
      }
    }
  </script>
</body>
</html>)rawliteral";
  server.send(200, "text/html; charset=utf-8", pagina);
}

void handleWebCommand() {
  if (!server.hasArg("value") || server.arg("value").length() != 1) {
    server.send(400, "text/plain", "Use um comando: F, B, L, R ou S.");
    return;
  }

  enviarComandoDaWeb(server.arg("value")[0]);
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  parar();

  WiFi.mode(WIFI_AP);
  if (!WiFi.softAP(WIFI_SSID, WIFI_PASSWORD)) {
    Serial.println("Falha ao iniciar o ponto de acesso Wi-Fi.");
  } else {
    Serial.print("Rede Wi-Fi: ");
    Serial.println(WIFI_SSID);
    Serial.print("Abra no navegador: http://");
    Serial.println(WiFi.softAPIP());
  }

  server.on("/", HTTP_GET, handleRoot);
  server.on("/cmd", HTTP_GET, handleWebCommand);
  server.begin();

  if (!SerialBT.begin(BLUETOOTH_NAME)) {
    Serial.println("Falha ao iniciar o Bluetooth Serial.");
  } else {
    Serial.print("Bluetooth pronto: ");
    Serial.println(BLUETOOTH_NAME);
  }
}

void loop() {
  server.handleClient();

  while (SerialBT.available() > 0) {
    const char comando = static_cast<char>(SerialBT.read());
    processarComando(comando);
  }

  delay(10);
}
