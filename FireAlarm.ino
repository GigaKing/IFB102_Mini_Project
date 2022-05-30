// Flame Detector for Arduino Uno -- To be ported to the Raspberry Pi

//Variables for setup and loop function
int fireDetector = D5;
int val = LOW;
int externalLED = D7;
int buzzer = D6;

bool on_fire = false;


void activated() {
  //Variables for the message function
    if (on_fire == false){
        Particle.publish("fire");
    }
    on_fire = true;
  
    digitalWrite(externalLED, HIGH);
    digitalWrite(buzzer, HIGH);  
    
}


void deactivated() {
  //Variables for the message function
    on_fire = false;
    
    digitalWrite(externalLED, LOW);
    digitalWrite(buzzer, LOW);
    
}


void setup() {
  // put your setup code here, to run once:
  pinMode(fireDetector, INPUT);
  pinMode(externalLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}


void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(fireDetector);
  if (val == HIGH)
  {
    Serial.print("Oh god, My house is on fire");
    activated();
    }
  else
  {
    Serial.print("There is no fire");
    deactivated();
    
  }
  delay(500);
}
