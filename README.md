# Projeto-Monitoramento-ESP32
Implementação e Aplicabilidade da Internet das Coisas (IoT) na Gestão da Água e Saneamento

# 🌊 Projeto de Monitoramento de Nível de Água com ESP32 e IoT

Este projeto foi desenvolvido como parte da atividade final da disciplina **OBJETOS INTELIGENTES CONECTADOS** no curso de Análise e Desenvolvimento de Sistemas.

A proposta é criar um sistema embarcado usando **ESP32**, sensores e atuadores, capaz de enviar dados de forma remota via **MQTT** e visualizar as informações no **ThingSpeak**.

---

## 📌 Objetivos

- Monitorar o nível da água em um reservatório usando sensor ultrassônico.
- Coletar temperatura e umidade com o sensor DHT22.
- Acionar um LED e relé em condições críticas.
- Enviar os dados para a nuvem via MQTT (ThingSpeak).
- Simular o sistema com Wokwi e testar em ambiente físico.

---

## ⚙️ Componentes e Tecnologias

| Componente         | Função                                   |
|--------------------|-------------------------------------------|
| ESP32              | Microcontrolador principal               |
| Sensor HC-SR04     | Medição de nível de água                 |
| Sensor DHT22       | Temperatura e umidade                    |
| Módulo Relé        | Acionamento de válvula                   |
| LED                | Alerta visual                            |
| ThingSpeak         | Visualização dos dados na nuvem          |
| MQTT               | Protocolo de comunicação leve e eficiente|
| Wokwi              | Simulação de circuito                    |

---

## 🧪 Funcionamento

O sistema realiza a leitura dos sensores a cada 15 segundos e publica os dados no ThingSpeak via protocolo MQTT. O LED acende e o relé é acionado quando o nível de água está abaixo do limite crítico.

---

## 📊 Visualização dos Dados

![Gráfico ThingSpeak](Imagens/print_thingspeak.png)

Você pode ver o canal ThingSpeak com os dados em tempo real aqui:  
🔗 **[Canal ThingSpeak](https://thingspeak.mathworks.com/channels/2681880/private_show)**

---

## 💻 Simulação no Wokwi

Este projeto foi simulado com sucesso no ambiente virtual Wokwi:  
🔗 **[Acesse a simulação](https://wokwi.com/projects/410766655456274433)**

![Wokwi](Imagens/print_wokwi.png)

---

## 🎥 Demonstração em vídeo

Assista à demonstração do projeto em funcionamento no YouTube (vídeo não listado):  
🔗 **[Assista ao vídeo](https://youtube.com/SEU_VIDEO_AQUI)**

---

## 🧩 Fluxograma

![Fluxograma](Fluxograma/fluxograma.png)

---

## ⏱️ Medições de Tempo

Tempo médio entre ações dos sensores e atuadores via MQTT:

| Nº da Medição | Sensor/Atuador         | Tempo de Resposta (ms) |
|---------------|-------------------------|--------------------------|
| 1             | Sensor HC-SR04          | 500                      |
| 2             | DHT22                   | 550                      |
| 3             | Acionamento do relé     | 600                      |
| 4             | LED                     | 400                      |

📄 Ver mais em: `Medicoes/tabela_tempos.xlsx`

---

## 📂 Documentação

- 📄 [Relatório Final PDF](Documentacao/A3_Relatorio_Final)
- 📝 [Relatório Word (editável)](Documentacao/Relatorio.docx)

---

## 👥 Autores

- Fernando Alvarenga Moreira  
- David Santos da Silva  
- Marcos Vinicius Acario Bastos

---

## 🔗 Licença

Este projeto é de uso acadêmico. Você pode utilizar e adaptar com os devidos créditos.


