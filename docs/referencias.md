# Referências consultadas

As fontes abaixo foram usadas para conferir conceitos e orientar a documentação. Não foram copiados textos, códigos, imagens ou diagramas para o projeto.

## Documentação oficial

- [Arduino-ESP32: Wi‑Fi API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html) — documenta os modos STA e SoftAP; no SoftAP, dispositivos conectam-se à rede criada pelo ESP32 e podem acessar um servidor HTTP local.
- [Arduino-ESP32: Bluetooth](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/bluetooth.html) — descreve `BluetoothSerial` para Bluetooth Classic/SPP nos chips compatíveis.
- [ESP-IDF: RF Coexistence](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/coexist.html) — mostra a matriz de coexistência Wi‑Fi/Bluetooth. SoftAP conectado junto com Bluetooth Classic conectado é marcado como suportado com desempenho instável.
- [ESP-IDF: Bluetooth Architecture Overview](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/bt-architecture/overview.html) — informa quais famílias ESP32 oferecem Bluetooth Classic; ESP32-S3 e ESP32-C3, por exemplo, não oferecem Classic.
- [GitHub Docs: Best practices for repositories](https://docs.github.com/en/repositories/creating-and-managing-repositories/best-practices-for-repositories) — recomenda README e informações que ajudem visitantes a entender e navegar pelo projeto.
- [GitHub Docs: About READMEs](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/about-readmes) — explica o papel do README e o uso de links relativos para documentos e imagens.

## Fontes relacionadas à montagem

- [Random Nerd Tutorials: ESP32 Remote-Controlled Wi-Fi Car Robot](https://randomnerdtutorials.com/esp32-wi-fi-car-robot-arduino/) — exemplo de carrinho com servidor web por Wi‑Fi; usa uma configuração própria e não é o código deste repositório.
- [Vídeo da ponte H mini L298M](https://www.youtube.com/watch?v=asyDvC_SyIc) — vídeo indicado no documento escolar. A página não pôde ser aberta durante a revisão; o título/descrição foi transcrito do documento.
- [L298N Mini H-Bridge dual motor driver — Robotics.org.za](https://www.robotics.org.za/motors-controllers/motors-dc-controllers/L298M-MINI) — a descrição indica uma placa compacta com duas saídas de motor, quatro sinais de controle, alimentação do módulo de 2–10 V e sinais de entrada de 1,8–7 V. A imagem e as especificações se parecem com as do módulo mostrado no documento escolar; isso não confirma que seja a mesma peça instalada.

## Aplicativo

- [Arduino Bluetooth Controller — Google Play](https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control) — a página informa que os controles são configuráveis e que o protocolo do app deve corresponder ao código.
- [diegoguevara/esp32-robot-car](https://github.com/diegoguevara/esp32-robot-car) — exemplo público que usa o mesmo aplicativo e documenta os comandos `F`, `B`, `L`, `R` e `S`. Foi consultado como pista de configuração; o mapa precisa ser confirmado no app instalado pelo estudante.
- [Shib-Sankar-Das/ESP32-Bluetooth-RC-Car-Project](https://github.com/Shib-Sankar-Das/ESP32-Bluetooth-RC-Car-Project) — referência de organização em pastas separadas para diagramas, firmware e README. Seus componentes e ligações não foram reutilizados.
