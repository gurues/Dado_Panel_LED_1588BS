/*
************************ DADO ELECTRÓNICO *********************************************
________________________________________________________________________________________

En este proyecto se realiza un dado electrónico mediante una matriz led de 8x8 modelo
1588BS controlada por un arduino nano para que muestre los números de un dado de forma
aleatoria.
________________________________________________________________________________________
*/


#include <Arduino.h>

// Para realizar debug puerto serie
//#define ___DEBUG___
// Array 2 dimensiones filas pin nº:
int R[] = {12,7,14,9,4,15,13,17};  
// Array 2 dimensiones columnas pin nº:
int C[] = {8,19,18,11,16,10,6,5};    


unsigned long interval = 1500;  // Tiempo de cálculo del dado
unsigned long previousMillis;   // Control tiempo de calculo del dado
bool tirada;                    // Control tiempo de calculo del dado
int dado = 0;                   // Valor del dado

// Control interrupciones
const int intPin = 2;
const int intPin_ = 3;
volatile int state = LOW;
  
// Números del dado
//______________________________________________________________________________________________________

unsigned char uno[8][8] =      //uno 
{  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
}; 

unsigned char dos[8][8] =      //dos
{  
  0,0,0,0,0,0,0,0,  
  0,1,1,0,0,0,0,0,  
  0,1,1,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,1,1,0, 
  0,0,0,0,0,1,1,0,  
  0,0,0,0,0,0,0,0,  
}; 

unsigned char tres[8][8] =      //tres
{  
  1,1,0,0,0,0,0,0,  
  1,1,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,
  0,0,0,0,0,0,0,0, 
  0,0,0,0,0,0,1,1,  
  0,0,0,0,0,0,1,1,  
}; 

unsigned char cuatro[8][8] =     //cuatro
{  
  0,0,0,0,0,0,0,0, 
  0,1,1,0,0,1,1,0,  
  0,1,1,0,0,1,1,0,   
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,
  0,1,1,0,0,1,1,0,  
  0,1,1,0,0,1,1,0,   
  0,0,0,0,0,0,0,0,   
};

unsigned char cinco[8][8] =      //cinco
{  
  1,1,0,0,0,0,1,1,  
  1,1,0,0,0,0,1,1,   
  0,0,0,0,0,0,0,0, 
  0,0,0,1,1,0,0,0,  
  0,0,0,1,1,0,0,0,
  0,0,0,0,0,0,0,0, 
  1,1,0,0,0,0,1,1,   
  1,1,0,0,0,0,1,1,   
};

unsigned char seis[8][8] =      //seis
{  
  1,1,0,1,1,0,1,1,  
  1,1,0,1,1,0,1,1,   
  0,0,0,0,0,0,0,0, 
  1,1,0,1,1,0,1,1,  
  1,1,0,1,1,0,1,1,
  0,0,0,0,0,0,0,0, 
  1,1,0,1,1,0,1,1,   
  1,1,0,1,1,0,1,1,   
};

unsigned char full[8][8] =      //todo
{  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,   
  1,1,1,1,1,1,1,1, 
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,
  1,1,1,1,1,1,1,1, 
  1,1,1,1,1,1,1,1,   
  1,1,1,1,1,1,1,1,   
};

//_______________________________________________________________________________________________________

// Función de limpieza del display panel led 1588BS
void Clear()                          
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(R[i],LOW);  
    digitalWrite(C[i],HIGH);  
  }  
} 

// Función que muestra los números del dado
void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//columna a LOW 
    //Recorro todas las filas de la columna
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c]);  // muestro valor del dado en display
    }  
    delay(1);  
    Clear();  //apago todos los led del display
  }  
}  
  
// Función de llamada tras interrupción
void eval_int(){
  state =HIGH;
}

//_______________________________________________________________________________________________________

void setup()  
{  
  #ifdef ___DEBUG___
    Serial.begin(9600);
  #endif
  // Definición de los pines de control panel led 8x8 1588BS
  for(int i = 0;i<8;i++){  
    pinMode(R[i],OUTPUT);  
    pinMode(C[i],OUTPUT);  
  }  

  // Configuración de las interrupciones
  pinMode(intPin, INPUT_PULLUP);
  pinMode(intPin_, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(intPin), eval_int, LOW);
  attachInterrupt(digitalPinToInterrupt(intPin_), eval_int, LOW);

  // Limpieza display
  Clear();

}  
  
void loop(){ 

  // Control del tiempo de cálculo del dado (configurado a 1,5 seg)
  unsigned long currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= interval){
    // dado disponible para otra tirada
    attachInterrupt(digitalPinToInterrupt(intPin), eval_int, LOW);
    attachInterrupt(digitalPinToInterrupt(intPin_), eval_int, LOW);
    Clear();
    tirada = false; 
  }

  // Validación de interrupciones
  if (state == HIGH)  {
    detachInterrupt(digitalPinToInterrupt(intPin));
    detachInterrupt(digitalPinToInterrupt(intPin_));
    state = LOW;
    tirada = true;
  }

  // Generación aleatoria del valor del dado
  if (tirada){
    dado = random(1, 7);
    #ifdef ___DEBUG___
      Serial.print("Dado = ");
      Serial.println(dado);
    #endif
  }
  else
    previousMillis = millis();

  // Muestra del valor del dado
  switch (dado) {
    case 0:
      Display(full); 
      break;
    case 1:
      Display(uno); 
      break;
    case 2:
      Display(dos); 
      break;
    case 3:
      Display(tres); 
      break;
    case 4:
      Display(cuatro); 
      break;
    case 5:
      Display(cinco); 
      break;
    case 6:
      Display(seis); 
      break;  
  }
  
}  
  
