# Referências consultadas

As fontes abaixo ajudaram a conferir as tecnologias usadas e a organizar a apresentação do projeto. O carrinho, seu protótipo físico e sua autoria são de Vinícius Cavassani. Nenhum código, texto, imagem ou diagrama dos projetos externos foi copiado para este repositório.

## Documentação oficial

- [Arduino-ESP32: Wi-Fi API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html) — explica os modos de conexão, incluindo o ponto de acesso (SoftAP) criado pelo ESP32.
- [Arduino-ESP32: Bluetooth](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/bluetooth.html) — documenta Bluetooth Classic Serial (SPP) nos chips compatíveis.
- [ESP-IDF: RF Coexistence](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/coexist.html) — matriz de coexistência de Wi-Fi e Bluetooth; SoftAP conectado junto com Bluetooth Classic conectado é listado como suportado, com desempenho instável.
- [ESP-IDF: Bluetooth Architecture Overview](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/bt-architecture/overview.html) — descreve os recursos Bluetooth por família de chip ESP32.


## Projetos públicos usados como inspiração de organização

As estrelas são a contagem exibida no GitHub em 14 de novembro de 2026 e podem mudar.

- [CoretechR/ESP32-WiFi-Robot](https://github.com/CoretechR/ESP32-WiFi-Robot) — 165 estrelas na consulta. O repositório separa a interface de controle e os arquivos Eagle, além de incluir README e licença. Usei essa organização como referência para separar firmware, documentação, imagens e esquemas. É outro projeto, com vídeo, e não é a implementação deste carrinho.
- [0015/ESP32-RC-CAR](https://github.com/0015/ESP32-RC-CAR) — 37 estrelas na consulta. Mantém firmware, imagens, esquemas, README e licença em itens separados. A versão descrita é baseada em BLE; serve como referência de apresentação e organização, não como base de código.

## Referências do projeto

- [Random Nerd Tutorials: ESP32 Remote-Controlled Wi-Fi Car Robot](https://randomnerdtutorials.com/esp32-wi-fi-car-robot-arduino/) — tutorial externo de carrinho controlado por Wi-Fi, enviado como material de estudo. Não é o firmware deste repositório.
- [Arduino Bluetooth Controller — Google Play](https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control) — página do aplicativo indicado para enviar comandos Bluetooth.
- [Vídeo da mini ponte H L298M](https://www.youtube.com/watch?v=asyDvC_SyIc) — link indicado nos documentos escolares como referência sobre a ponte H.
