// Battery Level Logic ESP(32)

#define POT_PIN 34
#define RED_LED 2
#define GREEN_LED 4
#define YELLOW_LED 5

float voltage;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  Serial.begin(115200);
  Serial.println("=== Battery Level Logic ===");
}

void loop() {

  int raw = analogRead(POT_PIN);

  //convert ADC-> voltage
  voltage = (raw / 4095.0)* 3.3;

  // Reset LEDS
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);

  // LOW
  if(voltage < 1.5) {
    digitalWrite(RED_LED, HIGH);
    Serial.println("LOW BATTERY");
  }
  // NORMAL
  else if (voltage <= 2.5) {
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("NORMAL");
  }
  // HIGH
  else{
    digitalWrite(YELLOW_LED, HIGH);
    Serial.println("HIGH/ OVERVOLTAGE");
  }
  Serial.print("voltage: ");
  Serial.println(voltage);

  delay(500);
}