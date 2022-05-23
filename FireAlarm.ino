// Flame Detector for Arduino Uno -- To be ported to the Raspberry Pi

//Variables for setup and loop function
int L_LED = 13;
int fireDetector = 8;
int val = LOW;
int externalLED = 4;
int buzzer = 7;


void activated() {
  //Variables for the message function
    digitalWrite(externalLED, HIGH);
    digitalWrite(buzzer, HIGH);  
    
}


void deactivated() {
  //Variables for the message function
    digitalWrite(externalLED, LOW);
    digitalWrite(buzzer, LOW);
    
}


void setup() {
  // put your setup code here, to run once:
  pinMode(fireDetector, INPUT);
  pinMode(L_LED, OUTPUT);
  pinMode(externalLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}


void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(fireDetector);
  if (val == HIGH)
  {
    Serial.print("Oh god, My house is on fire");
    digitalWrite(L_LED, HIGH);
    activated();
    }
  else
  {
    Serial.print("There is no fire");
    digitalWrite(L_LED, LOW);
    deactivated();
    
  }
}
