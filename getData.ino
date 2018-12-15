boolean output = true;
uint64_t timeStart = millis(), timeEnd = millis();

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  if(digitalRead(2) == HIGH){
    output = !output;
    delay(1000);
  }

  timeEnd = millis();

  if(timeEnd - timeStart > 2000){
    timeStart = millis();
    timeEnd = millis();
    if(output){
      println(voltage);
      float vScaled = 24*voltage;
      float power = (120-vScaled)/(220/vScaled);
      Serial.println(power);
    }
  }
}
