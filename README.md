# Carrinho de controle remoto com ESP32


Este é meu projeto de carrinho de controle remoto, desenvolvido durante o curso técnico de Eletrônica. O firmware publicado reúne duas formas de controle: uma página web acessada pela rede Wi-Fi criada pelo ESP32 e comandos enviados por Bluetooth Classic usando um aplicativo de celular.

## O que o firmware oferece

- Controle de avanço, ré, giro à esquerda, giro à direita e parada.
- Página web local servida pelo próprio ESP32.
- Controle Bluetooth Serial (SPP) com comandos de um caractere.
- Os dois serviços são iniciados pelo mesmo sketch.

## Como usar

### Wi-Fi

1. Grave o firmware em uma placa ESP32 compatível.
2. Conecte o celular à rede **Carrinho_ESP32**.
3. Abra no navegador o endereço exibido no Monitor Serial. O ponto de acesso do ESP32 normalmente usa **192.168.4.1**.
4. Use os botões da página para controlar o carrinho.

A rede é criada pelo ESP32; não precisa estar conectada ao roteador doméstico. A senha inicial do sketch é **carrinho123**. Troque esse valor no código antes de usar.

### Bluetooth

1. Pareie o celular com **Carrinho_ESP32_RC**.
2. No aplicativo [Arduino Bluetooth Controller](https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control), configure os botões para enviar os caracteres abaixo.
3. Conecte ao dispositivo e use os controles configurados.

| Caractere | Ação |
|---|---|
| F | Avançar |
| B | Recuar |
| L | Girar à esquerda |
| R | Girar à direita |
| S | Parar |

O firmware lê comandos de Bluetooth Serial. O aplicativo precisa enviar exatamente os caracteres indicados.

## Ligações de controle documentadas

| Entrada da ponte H | GPIO do ESP32 |
|---|---:|
| IN1 | 19 |
| IN2 | 18 |
| IN3 | 5 |
| IN4 | 4 |

Esses GPIOs aparecem no sketch Bluetooth enviado para o projeto e no esquema escolar. A lista de componentes está em [docs/lista-de-materiais.md](docs/lista-de-materiais.md), e as instruções de montagem com o esquema estão em [docs/montagem.md](docs/montagem.md#esquema-original).

## Preparar e gravar

- Instale o Arduino IDE e o suporte de placas ESP32.
- Use uma placa que ofereça Bluetooth Classic com SPP; nem todos os modelos ESP32 têm esse recurso.
- Abra [firmware/wifi-bluetooth/carrinho_wifi_bluetooth.ino](firmware/wifi-bluetooth/carrinho_wifi_bluetooth.ino), selecione o modelo correto da placa e grave o sketch.
- Altere a senha do ponto de acesso antes de usar.

O sketch usa Wi-Fi, servidor web e Bluetooth Serial fornecidos pelo core Arduino para ESP32.

## Estado e limitações

O firmware contém os dois meios de controle, mas a compilação e a operação no carrinho físico ainda não foram verificadas nesta publicação. A documentação da Espressif classifica Wi-Fi SoftAP conectado junto com Bluetooth Classic conectado como suportado, com desempenho instável; por isso, o uso simultâneo ainda precisa de ensaio no carrinho. Se os dois controles enviarem comandos, o último comando processado define o estado dos motores. O firmware não para automaticamente quando uma conexão cai.

Os documentos do projeto identificam a ponte H como L298M no esquema e mini L298N na lista de materiais. A pinagem de sinal está documentada acima; o caminho de alimentação não está detalhado o bastante para reproduzir com segurança apenas por este README.

## Arquivos

- [Firmware Wi-Fi e Bluetooth](firmware/wifi-bluetooth/carrinho_wifi_bluetooth.ino)
- [Lista de materiais](docs/lista-de-materiais.md)
- [Montagem e uso](docs/montagem.md)
- [Autoria e créditos](docs/creditos.md)
- [Referências consultadas](docs/referencias.md)

## Autoria

O carrinho e o projeto escolar são meus. As referências externas serviram para consulta técnica e inspiração de organização; elas não são a origem do projeto. Veja [docs/creditos.md](docs/creditos.md) e [docs/referencias.md](docs/referencias.md).
