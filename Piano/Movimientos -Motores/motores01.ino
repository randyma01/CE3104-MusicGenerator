//----- Motor A - Controlador 1 -----\\

const int m1Aa = 2; 
const int m1Ab = 3;  //pin PWM ~

//----- Motor B - Controlador 1 -----\\

const int m1Ba = 4; 
const int m1Bb = 5;  //pin PWM ~

//----- Motor A - Controlador 2 -----\\

const int m2Aa = 7; 
const int m2Ab = 6;  //pin PWM ~

//----- Motor B - Controlador 2 -----\\

const int m2Ba = 8; 
const int m2Bb = 9;  //pin PWM ~



void setup() {
  //Motor 1A
  pinMode(m1Aa, OUTPUT);
  pinMode(m1Ab, OUTPUT);  

  //Motor 1B
  pinMode(m1Ba, OUTPUT);
  pinMode(m1Bb, OUTPUT);  
  
  //Motor 2A
  pinMode(m2Aa, OUTPUT);
  pinMode(m2Ab, OUTPUT);  

  //Motor 2A
  pinMode(m2Ba, OUTPUT);
  pinMode(m2Bb, OUTPUT);  
}

void loop() {
  
}



void moveMotor1A(){
  //digitalWrite(m1Aa, LOW);
  analogWrite(m1Ab, 250); 
  
}


/******************************************/

void stopMotor(int pinA, int pinB){
  digitalWrite(pinA, LOW);
  analogWrite(pinB, 0);
}

void motor1A(byte speedM){
  digitalWrite(m1Aa, LOW);
  analogWrite(m1Ab, speedM); 
}

void motor1B(byte speedM){
  digitalWrite(m1Ba, LOW);
  analogWrite(m1Bb, speedM); 
}


void motor2A(int giro){
  if(giro == 0){
    digitalWrite(m2Aa, LOW);
    digitalWrite(m2Ab, HIGH);
  }
  else if(giro == 1){
    digitalWrite(m2Aa, HIGH);
    digitalWrite(m2Ab, LOW);
  }
  else if(giro == 3){
    digitalWrite(m2Aa, LOW);
    digitalWrite(m2Ab, LOW);
  }
}

void motor2B(int giro){
  if(giro == 0){
    digitalWrite(m2Ba, LOW);
    digitalWrite(m2Bb, HIGH);
  }
  else if(giro == 1){
    digitalWrite(m2Ba, HIGH);
    digitalWrite(m2Bb, LOW);
  }
  else if( giro == 3){
     digitalWrite(m2Ba, LOW);
    digitalWrite(m2Bb, LOW);
  }
  
}




/*if (Serial.available()) {
    char dato= Serial.read();
    if(dato=='a'){
      nota1y2();  
      delay(500);    
      stopMotor();
      }
     else if(dato == 'd'){
      nota1MB();
      delay(1000);    
      stopMotor();
     }
     else if(dato == 'r'){
      nota2MA();
      delay(1000);
      stopMotor();
     }
  }
  
  
    motor1A(255);
  delay(1000);
  stopMotor(m1Aa, m1Ab);
  delay(6000);
  
  motor1B(200);
  delay(1000);
  stopMotor(m1Ba, m1Bb);
  delay(6000);

  motor2A(0);
  delay(1000);
  motor2A(3); //stopMotor
  delay(6000);

  motor2B(0);
  delay(1000);
  motor2B(3); //stopMotor
  delay(6000);



  delay(10000);
*/
