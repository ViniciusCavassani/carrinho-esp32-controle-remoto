# Montagem e uso

Este documento separa as ligações de sinal que aparecem no código e no esquema das informações de alimentação que ainda precisam ser conferidas no carrinho físico.

## Ponte H e GPIOs

O esquema identifica a ponte H como `L298M` e os quatro sinais de controle como:

| Sinal da ponte H | GPIO do ESP32 |
|---|---:|
| `IN1` | 19 |
| `IN2` | 18 |
| `IN3` | 5 |
| `IN4` | 4 |

A lista de materiais chama o componente de mini L298N. A imagem do esquema e o módulo ilustrado correspondem ao formato compacto vendido como L298N Mini/L298M-MINI: duas saídas de motor, quatro entradas de controle e alimentação indicada de 2 a 10 V. Essa identificação é a melhor correspondência encontrada nos documentos e na referência de produto; falta conferir a marcação da peça instalada.

O desenho nomeia os motores como `MA` e `MB`. O código original descreve A como direito e B como esquerdo, mas essa orientação física não foi confirmada por foto da montagem.

## Alimentação: pendente de conferência

Os arquivos registram uma bateria Ni-MH de 6 V e mostram uma conexão de bateria no esquema, mas não explicam suficientemente o percurso de alimentação entre a bateria, a ponte H e o ESP32. O esquema do módulo mini não mostra pinos `ENA`/`ENB`; por isso, não use a observação do código original sobre ligar esses pinos em 5 V — ela parece referir-se a outro formato de driver.

Antes de energizar, confira a placa real, seus terminais e as especificações do fabricante. O código nesta proposta não acrescenta ligações de alimentação que não estejam documentadas.

## Controle por Wi‑Fi

O firmware inicia um ponto de acesso chamado `Carrinho_ESP32` e uma página HTTP. A senha de exemplo está definida no sketch como `carrinho123`; troque-a antes de utilizar.

1. Grave o firmware em uma placa ESP32 compatível.
2. Conecte o celular à rede `Carrinho_ESP32`.
3. Abra o endereço mostrado no Monitor Serial. No modo SoftAP do ESP32, o endereço padrão normalmente é `192.168.4.1`.
4. Use a página para enviar frente (`F`), ré (`B`), esquerda (`L`), direita (`R`) ou parar (`S`).

O SoftAP do ESP32 cria uma rede local; não é necessário configurar o roteador doméstico.

## Controle por Bluetooth

O firmware anuncia `Carrinho_ESP32_RC` por Bluetooth Classic Serial/SPP. No aplicativo Arduino Bluetooth Controller, configure os botões para enviar `F`, `B`, `L`, `R` e `S`. O aplicativo permite personalizar controles, mas a configuração no celular do estudante ainda não foi verificada.

## Comandos e motores

| Comando | Ação no código |
|---|---|
| `F` | Motor A e B acionados para avançar, conforme a orientação declarada no código recebido. |
| `B` | Motor A e B acionados para recuar. |
| `L` | Canais em sentidos opostos para girar à esquerda. |
| `R` | Canais em sentidos opostos para girar à direita. |
| `S` | Todas as entradas `IN1`–`IN4` em nível baixo. |

As funções `L` e `R` foram alteradas em relação ao código recebido: agora os dois motores giram em sentidos opostos. O sentido real precisa ser conferido no carrinho; se o lado de giro estiver invertido, a orientação dos motores ou a ordem dos fios pode diferir da descrita.

## Wi‑Fi e Bluetooth ao mesmo tempo

O sketch inicia os dois serviços. Ambos controlam os mesmos motores, e o último comando processado substitui o anterior. Não há prioridade entre o aplicativo e a página web.

Wi‑Fi SoftAP conectado junto com Bluetooth Classic conectado é uma combinação que a documentação da Espressif classifica como suportada, mas de desempenho instável. Teste a resposta do carrinho com os dois conectados antes de apresentar o recurso como validado.

## Limitações atuais

- A compilação do sketch e a operação física ainda não foram verificadas.
- O firmware não possui parada automática quando a conexão Wi‑Fi ou Bluetooth cai.
- A entrada Bluetooth lê caracteres; os comandos configurados no app devem corresponder ao mapa acima.
- Alimentação, terras comuns e identificação final do driver dependem de conferir a montagem real.
