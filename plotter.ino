long previousTime = 0;
long currentTime = 0;
bool state = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  analogWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
}

int generateSquareSignal(long currentTime) {
  int state = round(currentTime / 100) % 2;
  digitalWrite(LED_BUILTIN, (HIGH - LOW) * state + LOW);
}

int generateTriangleSignal(long currentTime) {
  // Cannot get proper readings with this function - in progress
  float step = ((float) (round(currentTime / 30) % 20)) / 20;
  float value = ((float) (HIGH - LOW)) * step + LOW;

  analogWrite(9, (value * 255) / 10);
}

void loop() {
  delay(10); 
  float test = analogRead(3);
  Serial.println(test);

  currentTime = millis();
  generateSquareSignal(currentTime);
}
