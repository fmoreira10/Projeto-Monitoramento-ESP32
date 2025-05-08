#include <WiFi.h>
#include <WiFiClient.h>
#include <Ultrasonic.h>
#include "DHTesp.h"    // Biblioteca do DHT
#include "ThingSpeak.h" // Biblioteca ThingSpeak

// Configurações de WiFi
#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// Canal e API Key do ThingSpeak
const int myChannelNumber = 2681880; // Substitua pelo seu canal
const char* myApiKey = "G70ERUBMHVY5GT1M"; // Substitua pela sua API Key
const char* server = "api.thingspeak.com";

// Pinos do Sensor Ultrassônico (HC-SR04)
#define TRIG_PIN 12
#define ECHO_PIN 14

// Pino do Sensor de Temperatura/Umidade (DHT22)
#define DHT_PIN 15

// Pino do Relé (que acende o LED)
#define RELAY_PIN 19

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);
DHTesp dhtSensor;
WiFiClient client;

unsigned long lastUpdate = 0;
const unsigned long updateInterval = 15000; // Envia dados a cada 15 segundos

void setup() {
  Serial.begin(115200);

  // Inicializa WiFi
  connectToWiFi();

  // Inicializa o sensor DHT22
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // Configura o pino do relé como saída
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Medição do nível de água com o sensor ultrassônico
  int distance = ultrasonic.read();

  // Medição da temperatura e umidade com o sensor DHT22
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  float temperatura = data.temperature;
  float umidade = data.humidity;

  // Controle do relé baseado na distância
  if (distance < 100) { // Se o nível for menor que 100 cm
    digitalWrite(RELAY_PIN, HIGH);  // Liga o relé (acende o LED externo)
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Desliga o relé (apaga o LED externo)
  }

  // Verifica se o intervalo de atualização foi atingido
  if (millis() - lastUpdate >= updateInterval) {
    Serial.print("Nível de água: ");
    Serial.print(distance);
    Serial.println(" cm");

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" ºC");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");

    // Envia os dados para o ThingSpeak
    ThingSpeak.setField(1, distance);
    ThingSpeak.setField(2, temperatura);
    ThingSpeak.setField(3, umidade);

    int response = ThingSpeak.writeFields(myChannelNumber, myApiKey);

    if (response == 200) {
      Serial.println("Dados enviados com sucesso ao ThingSpeak.");
    } else {
      Serial.print("Erro ao enviar: ");
      Serial.println(response);
    }

    lastUpdate = millis();
  }

  delay(1000); // Atraso de 1 segundo entre as leituras
}

// Função para conectar ao WiFi
void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println(" Conectado!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}
