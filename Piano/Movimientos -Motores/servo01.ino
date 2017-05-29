const int pinMotor1A = 2;
const int pinMotor1B = 3;



void setup() {
  // put your setup code here, to run once:
  pinMode(pinMotor1A, OUTPUT);
  pinMode(pinMotor1B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //izquierda
 
  
  //derecha
  moveMotor(1);
  delay(1000);

  moveMotor(2);
  delay(500);
   
  moveMotor(0);
  delay(1000);
  
  moveMotor(2);
  delay(500);

}


void moveMotor(int sentido){
  if (sentido == 0){
    
     digitalWrite(pinMotor1A, HIGH);
    digitalWrite(pinMotor1B, LOW);
  }
  else if (sentido == 1){
     digitalWrite(pinMotor1A, LOW);
    digitalWrite(pinMotor1B, HIGH);
  }
  else if(sentido == 2){
     digitalWrite(pinMotor1A, LOW);
    digitalWrite(pinMotor1B, LOW);
  }
}

