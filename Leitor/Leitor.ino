// Variables
# include "DHT.h"
#include <WiFi.h>
#include "ThingSpeak.h"

DHT dht(26, DHT11);

const char* ssid = "SENAC VISITANTES";
const char* password = "trijuntos";

const char* myWriteAPIKey = "";
unsigned long myChannelNumber ="";

WiFiClient cliente;

// --------------------------------------------------

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n WiFi conectado!");
  Serial.print("Endereço de IP: ");
  Serial.println(WiFi.localIP());

    // Inicia a comunicação com o ThingSpeak
  ThingSpeak.begin(cliente);
}

// --------------------------------------------------

void loop() {
  float temp = dht.readTemperature();
  // float temp = random(0,40);
  float umid = dht.readHumidity();
  // float umid = random(0,100);

  Serial.println(temp);
  Serial.println(umid);


  int x = ThingSpeak.setField(1, temp);
  int y = ThingSpeak.setField(2, umid);
  int z = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if(x == 200 && y == 200){
      Serial.println("dados enviados com sucesso.");
    }else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
      Serial.println("Problem updating channel. HTTP error code " + String(y));
    }


  delay(60000);

}

// --------------------------------------------------
