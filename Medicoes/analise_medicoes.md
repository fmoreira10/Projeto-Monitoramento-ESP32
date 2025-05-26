# 📊 Análise das Medições

## Objetivo
Avaliar o desempenho do sistema de monitoramento de água com sensores integrados ao ESP32, verificando o tempo de resposta e a estabilidade da comunicação MQTT.

## Metodologia
As leituras foram coletadas utilizando os sensores HC-SR04 e DHT22, com envio dos dados a cada 15 segundos via protocolo MQTT para o ThingSpeak. Os testes foram realizados em simulação na plataforma Wokwi e em ambiente físico com um reservatório doméstico.

## Dados Coletados
Veja os arquivos `tabela_tempos.xlsx` e `dados_medicoes.csv` para os registros de medição.

## Resultados e Gráficos

- Tempo médio de resposta do **HC-SR04**: **500 ms**
- Tempo médio de resposta do **DHT22**: **550 ms**
- Tempo médio de acionamento do **Relé**: **600 ms**
- Tempo médio do **LED**: **400 ms**
- Média geral: **512,5 ms**

![Gráfico de tempos médios](grafico_tempo_resposta.png)

## Conclusões

O sistema apresentou tempos de resposta satisfatórios para aplicações residenciais e domésticas. A comunicação via MQTT demonstrou estabilidade e eficácia tanto na simulação Wokwi quanto nos testes físicos.
