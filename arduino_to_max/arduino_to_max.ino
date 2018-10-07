void setup() {
  // put your setup code here, to run once:
int button1 = 2;
int button2 = 3;

int state1 = 0;
int state2 = 0;

pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);

}

void loop() {
  
  if (digitalRead == HIGH) {
  Serial.print("0");
  }
  else {
    Serial.print("1");
  }

}
