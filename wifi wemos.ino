#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// Network SSID
const char* ssid = "MAURO";
const char* password = "R0ci02021";
//OBLIGADO EL LINK DEBE IR IP DEL SERVIDOR
String Link = "http://192.168.0.101/pr1/datos.php";
const int ledv = 7;
const int ledr = 6;
int pinRele = D3;

void setup() {
  
  Serial.begin(57600);
  delay(10);
  pinMode(pinRele, OUTPUT);
 
  // Connect WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("Name");
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
}
 
void loop() {
  HTTPClient http;
  WiFiClient client;
  char c;
   if (http.begin(client, Link)) //Iniciar conexión
   {
      Serial.print("[HTTP] GET...\n");
      int httpCode = http.GET();  // Realizar petición
      if (httpCode > 0) {
         Serial.printf("[HTTP] GET... code: %d\n", httpCode);
         if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();   // Obtener respuesta
            Serial.println(payload);   // Mostrar respuesta por serial
            c= payload[0];
            if (c=='1'){
              Serial.write('1');  
                digitalWrite(pinRele, HIGH);
            }
            if (c=='0'){  
                digitalWrite(pinRele, LOW);
                Serial.write('0');
            }
         }
      }
      else {
         Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
          digitalWrite(LED_BUILTIN, HIGH); 
          delay(600);
          digitalWrite(LED_BUILTIN, LOW);
      }
      http.end();
   }
   else {
      Serial.printf("[HTTP} Unable to connect\n");
   }

  delay(1000);  //GET Data at every 5 seconds
}
