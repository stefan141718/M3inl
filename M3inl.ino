// Sensor 7. fotomotståndssensormodul för ljusbarriärer

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT_PULLUP);
    Serial.begin(9600);  
}

int currentvalue = HIGH;

void loop() {
    if (digitalRead(2) == LOW) {
      currentvalue = currentvalue == HIGH ? LOW : HIGH;
      Serial.println(currentvalue == LOW ? "PÅ" : "AV");
    }

    digitalWrite(LED_BUILTIN, currentvalue);

    if (currentvalue == LOW) {
      int val = analogRead(A5);  
      Serial.println(val < 512 ? "Tänt " : "Släckt ");
    }

    delay(500);   
}