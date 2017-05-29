const int pinMotor1A = 2;
const int pinMotor1B = 3;

const int pinMotor2A = 4;
const int pinMotor2B = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinMotor1A, OUTPUT);
  pinMode(pinMotor1B, OUTPUT);
  pinMode(pinMotor2A, OUTPUT);
  pinMode(pinMotor2B, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char dato= Serial.read();
    if(dato=='a'){
      moveMotor(1);  
      delay(1000);    
      stopMotor();
      }
      else if(dato == 'd'){
      moveMotor(2);
      delay(1000);    
      stopMotor();
     }
  }
}

void moveMotor(int pinMotor){
  if(pinMotor == 1){
    digitalWrite(pinMotor1A, HIGH); //mueve motor 1B
  }
  else if(pinMotor == 2){
    digitalWrite(pinMotor1B, HIGH); //mueve motor 1A
  }
  else if(pinMotor == 3){
    digitalWrite(pinMotor2A, HIGH);
  }
  else if(pinMotor == 4){
    digitalWrite(pinMotor2B, HIGH);
  }
}

void stopMotor(){
    digitalWrite(pinMotor1A, LOW);
    digitalWrite(pinMotor1B, LOW);
    digitalWrite(pinMotor2A, LOW);
    digitalWrite(pinMotor2B, LOW);
}

