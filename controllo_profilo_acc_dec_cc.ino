unsigned long int tempo_iniziale = 0;
unsigned long int timer = 0;

const int pinControllo_motore_cc = 3;
float delta = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  tempo_iniziale = millis();
  timer = millis() - tempo_iniziale;
  Serial.println("Accelerazione");
  
  while(timer<=15000 && delta <= 1){
    delta = timer/15000.0;
    analogWrite(pinControllo_motore_cc, delta*255);
    timer = millis() - tempo_iniziale;
    
    Serial.print("delta= ");
    Serial.println(delta);
  }

 delay(30*60*1000); //aspett0 30 secondi

  tempo_iniziale = millis();
  timer = millis() - tempo_iniziale;
  Serial.println("Decelerazione");
  while(timer<=15000 && delta >=0){
    delta = 1- timer /15000.0;
    analogWrite(pinControllo_motore_cc, delta*255);
    timer = millis() - tempo_iniziale;
    Serial.print("delta= ");
    Serial.println(delta);
  }

  delay(1000);
  Serial.println("Ok");

}
