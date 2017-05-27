//------------- Pin Pulsadores -------------\\

// Blancas (Notas Basicas)
const int pC   = 1;    //Do
const int pD   = 2;    //Re
const int pE   = 3;    //Mi
const int pF   = 4;    //Fa
const int pG  = 5;     //Sol
const int pA   = 6;    //La
const int pB   = 7;    //Si


// Negras (Notas Sostenidas)
const int pCs  = 8;     //Do#
const int pDs  = 9;     //Re#
const int pFs  = 10;    //Fa#
const int pGs = 11;     //Sol#
const int pAs  = 12;    //La#

// Altavoz
const int altavoz = 13;
const int altavoz2 = 0;

//------------- Notas (Frecuencias 3_Octava) -------------\\


const int C  = 131;     //Do
const int Cs = 138;     //Do_Sostenido
const int D  = 146;     //Re
const int Ds = 155;     //Re_Sostenido
const int E  = 164;     //Mi
const int F  = 174;     //Fa
const int Fs = 185;     //Fa_Sostenido
const int G  = 196;     //Sol
const int Gs = 207;     //Sol_Sostenido
const int A  = 220;     //La
const int As = 233;     //La_Sostenido
const int B  = 246;     //Si


//------------- Notas (Altavoz) ---------;b ----\\

int NOTAS[ ]        = {C, D, E, F, G, A, B, Cs, Ds, Fs, Gs, As};
int pulsadores[ ]    = {pC, pD, pE, pF, pG, pA, pB, pCs, pDs, pFs, pGs, pAs};

int pulsador_activado = 0;


void setup() {
  // put your setup code here, to run once:
  for(int pin=11; pin>0; pin--) {
      pinMode(pulsadores[pin] , INPUT);
  } 
}

void loop() {
  // put your main code here, to run repeatedly
  int pulsador_actual; // se declara como variable local
  // el bucle analiza el estado de los 7 pulsadores
  for (int pulsador=0; pulsador<12; pulsador++) {
    pulsador_actual = digitalRead(pulsadores[pulsador]); // se lee el estado del pulsador
      // si se presiono, se procede a reproducir la nota asociada
       if (pulsador_actual == HIGH) {
         tone(altavoz,NOTAS[pulsador]); // reproduce la nota
         // grabamos el pulsador que ha sido apretado
         pulsador_activado = pulsadores[pulsador];
         break;
       }
  }
  // su soltamos el pulsador activo apagamos cortamos el sonido
  if (digitalRead(pulsador_activado) == LOW) {
    noTone(altavoz);
  }
  

}
