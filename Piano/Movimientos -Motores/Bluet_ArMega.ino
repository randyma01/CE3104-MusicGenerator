#include <Servo.h>

//#define HC05 Serial3

Servo motorDo;
Servo motorDoS;
Servo motorRe;
Servo motorReS;
Servo motorMi;
Servo motorFa;
Servo motorFaS;
Servo motorSol;
Servo motorSolS;
Servo motorLa;
Servo motorLaS;
Servo motorSi;

void setup() {
  /*
   * Bluetooth
   */
  // Serial.begin(9600);
  //  HC05.begin(9600);
 // String stringTwo =  String("This is a string");
  
  /*
   * Motores
   */
 motorDo.attach(1);
  motorDoS.attach(2);
  motorRe.attach(3);
  motorReS.attach(4);
  motorMi.attach(5);
  motorFa.attach(6);
  motorFaS.attach(7);
  motorSol.attach(8);
  motorSolS.attach(9);
  motorLa.attach(10);
  motorLaS.attach(11);
  motorSi.attach(12);
  

  moverMotores();

}


void loop() {



  

  /*
  mvDo(500);
  mvDoS(500);
  mvRe(500);
  mvReS(500);
  mvMi(500);
  mvFa(500);
  mvFaS(500);
  mvSol(500);
  mvSolS(500);
  mvLa(500);
  mvLaS(500);
  mvSi(500);
  */
}


/*
 * Declarar el valor inicial
 * En 90 grados para la posicion 
 * de los motores con respecto a la tecla
 */
void moverMotores(){
  motorDo.write(90);
  motorDoS.write(175);
  motorRe.write(178);
  motorReS.write(139);
  motorMi.write(177);
  motorFa.write(155);
  motorFaS.write(168);
  motorSol.write(175);
  motorSolS.write(1);
  motorLa.write(1);
  motorLaS.write(35);
  motorSi.write(20);
}




//----------------------- Funcion del motor para su respectiva nota -----------------------\\


void mvDo(int tiempo){
  motorDo.write(30);

  delay(tiempo);

  motorDo.write(90);

  delay(200);
}

void mvDoS(int tiempo){
  motorDoS.write(50);

  delay(tiempo);

  motorDoS.write(175);

  delay(200);
}

void mvRe(int tiempo){
  motorRe.write(100);

  delay(tiempo);

  motorRe.write(178);

  delay(200);
}

void mvReS(int tiempo){
  motorReS.write(1);

  delay(tiempo);

  motorReS.write(139);

  delay(200);
}
void mvMi(int tiempo){
  motorMi.write(90);

  delay(tiempo);

  motorMi.write(177);

  delay(200);
}

void mvFa(int tiempo){
  motorFa.write(30);

  delay(tiempo);

  motorFa.write(155);

  delay(200);
}
void mvFaS(int tiempo){
  motorFaS.write(30);

  delay(tiempo);

  motorFaS.write(168);

  delay(200);
}

void mvSol(int tiempo){
  motorSol.write(70);

  delay(tiempo);

  motorSol.write(175);

  delay(200);
}
void mvSolS(int tiempo){
  motorSolS.write(90);

  delay(tiempo);

  motorSolS.write(1);

  delay(200);
}

void mvLa(int tiempo){
  motorLa.write(100);

  delay(tiempo);

  motorLa.write(1);

  delay(200);
}
void mvLaS(int tiempo){
  motorLaS.write(178);

  delay(tiempo);

  motorLaS.write(35);

  delay(200);
}

void mvSi(int tiempo){
  motorSi.write(177);

  delay(tiempo);

  motorSi.write(20);

  delay(200);
}
