# Carrinho de controle remoto com ESP32

Este repositório reúne a documentação e o firmware do meu carrinho robótico, desenvolvido como projeto multidisciplinar de Eletrônica. O mesmo sketch inicia duas formas de controle: uma página aberta pela rede Wi‑Fi criada pelo ESP32 e comandos seriais recebidos pelo aplicativo via Bluetooth.

> **Estado do material:** o firmware e a documentação foram organizados a partir dos arquivos enviados. Ainda não foi possível compilar o sketch nem testar a coexistência de Wi‑Fi e Bluetooth no carrinho físico. As ligações de alimentação também precisam ser conferidas na montagem.

## Conteúdo

- [`firmware/wifi-bluetooth/carrinho_wifi_bluetooth.ino`](firmware/wifi-bluetooth/carrinho_wifi_bluetooth.ino): firmware com ponto de acesso Wi‑Fi, página de controle e Bluetooth Serial.
- [`docs/lista-de-materiais.md`](docs/lista-de-materiais.md): relação dos componentes descritos nos documentos escolares.
- [`docs/montagem.md`](docs/montagem.md): GPIOs documentados e instruções para os dois meios de controle; detalhes elétricos pendentes estão sinalizados.
- [`docs/creditos.md`](docs/creditos.md): autoria e fontes.
- [`docs/referencias.md`](docs/referencias.md): documentação oficial e exemplos públicos consultados.
- [`images/montagem/README.md`](images/montagem/README.md): orientações para adicionar fotos próprias.

## Como controlar pelo Wi‑Fi

O ESP32 cria a rede `Carrinho_ESP32`. A senha demonstrativa no código é `carrinho123`; altere-a antes de usar. Conecte o celular a essa rede e abra no navegador o endereço IP que aparece no Monitor Serial (normalmente `192.168.4.1`). A página tem botões para frente, ré, girar à esquerda, girar à direita e parar.

Essa rede é criada pelo próprio ESP32 e serve para comunicação local com o carrinho; não é a rede do roteador da casa.

## Como controlar pelo Bluetooth

O dispositivo Bluetooth aparece como `Carrinho_ESP32_RC`. Configure o modo Car Controller do aplicativo para enviar estes caracteres:

| Comando | Ação |
|---|---|
| `F` | Avançar |
| `B` | Recuar |
| `L` | Girar à esquerda |
| `R` | Girar à direita |
| `S` | Parar |

A página do aplicativo informa que os controles podem ser configurados; o mapa acima corresponde ao firmware. A configuração exata do app deve ser conferida no celular antes do primeiro uso.

## GPIOs documentados

| Entrada da ponte H | GPIO do ESP32 |
|---|---:|
| `IN1` | 19 |
| `IN2` | 18 |
| `IN3` | 5 |
| `IN4` | 4 |

Essas ligações aparecem tanto no sketch recebido como no esquema escolar. O código original identifica o motor A como direito e o B como esquerdo; essa orientação física ainda precisa ser verificada.

## Componentes

A lista completa conforme os documentos está em [`docs/lista-de-materiais.md`](docs/lista-de-materiais.md). O esquema e a lista ilustrada apontam para uma ponte H mini L298M/L298N; ainda falta conferir a inscrição do módulo instalado.

## Instalação do firmware

1. Use uma placa ESP32 compatível com Bluetooth Classic/SPP. `BluetoothSerial` não funciona em todo chip da família ESP32; por exemplo, ESP32-S3 e ESP32-C3 não oferecem Bluetooth Classic.
2. Abra o sketch no Arduino IDE e selecione o modelo exato da placa.
3. Altere a senha de demonstração do ponto de acesso, se necessário.
4. Compile e grave o sketch.
5. Faça o primeiro teste com as rodas suspensas e o carrinho bem preso. Mantenha as mãos afastadas dos motores.
6. Conecte pelo Wi‑Fi ou pelo Bluetooth e envie um comando de parada após cada teste.

A compilação não foi verificada neste ambiente. Não ligue a alimentação dos motores sem confirmar a pinagem, o módulo e a distribuição de energia descritos em [`docs/montagem.md`](docs/montagem.md).

## Uso simultâneo e limitações

O sketch mantém o ponto de acesso Wi‑Fi e o Bluetooth ativos ao mesmo tempo. Os dois controladores atuam sobre os mesmos motores; se comandos diferentes chegarem próximos, o último processado prevalece. Evite controlar pelos dois meios ao mesmo tempo.

A Espressif lista a coexistência de Wi‑Fi em modo SoftAP conectado e Bluetooth Classic conectado como suportada, mas com desempenho instável. Esse comportamento precisa ser testado no modelo exato do ESP32. O firmware também não para automaticamente ao perder uma conexão; use o botão `S` ou o botão “Parar”.

## Versão e referências Wi‑Fi

O firmware Wi‑Fi deste repositório foi escrito para o ponto de acesso do próprio ESP32. O tutorial da Random Nerd Tutorials e o vídeo da ponte H são referências de estudo; nenhum código, texto ou diagrama deles foi copiado para este projeto. Veja [`docs/referencias.md`](docs/referencias.md).

## Créditos

O material escolar foi preparado em colaboração, com contribuição de Vinícius Cavassani; os metadados dos documentos originais registram Celso Carnevale como autor. As referências consultadas, incluindo projetos públicos usados como inspiração de organização, e os limites de redistribuição estão descritos em [`docs/referencias.md`](docs/referencias.md) e [`docs/creditos.md`](docs/creditos.md).
