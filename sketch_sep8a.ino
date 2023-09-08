#define BLYNK_TEMPLATE_ID "TMPL3cIOAksO4"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "YrFhTcEn9XFYJrc3tkpyCsvygj3Uo6N9"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // Dta pin is connetced to D2 on ESP
#define DHTTYPE DHT11 //Name the sensor as an on object

char auth[] = "YrFhTcEn9XFYJrc3tkpyCsvygj3Uo6N9";
char ssid[] = "G-spot";
char pass[] = "forget password";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if(isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intened");
    return;
  }
  Serial.println("Humidity:");
  Serial.println(h);
  Serial.println("%");
  Serial.println("Temperature:");
  Serial.println(t);
  Serial.println("degree celsius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(2000);
}
