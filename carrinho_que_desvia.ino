int PortPin2 = 2;    // Motor 1
int PortPin3 = 3;    // Motor 1
int PortPin4 = 4;    // Motor 2
int PortPin5 = 5;    // Motor 2
int distancia = 0;
int disdir= 0;
int disesq = 0;

#define echoPin 13
#define trigPin 12

#include "Ultrasonic.h"

Ultrasonic ultrasonic(12,13);

void setup()   {
  Serial.begin(9600);
  pinMode(PortPin2, OUTPUT);
  pinMode(PortPin3, OUTPUT);
  pinMode(PortPin4, OUTPUT);
  pinMode(PortPin5, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

}

void loop()  {
  drive_frente();
  delay(100);   
  distancia = ultrasonico();
  Serial.println(distancia);
  delay(10);

  if(distancia <= 5){
    drive_esquerda();
    delay(1500);
    drive_stop();
    delay(200);
    disesq = ultrasonico();
    Serial.print("Esquerda: ");
    Serial.println (disesq);
    drive_direita();
    delay(2900);
    drive_stop();
    delay(200);
    disdir = ultrasonico();
    Serial.print("Direita: ");
    Serial.println(disdir);
    if(disdir >= disesq){
      Serial.println("-->Direita");
      drive_frente();
    }
    else{
      Serial.println("<--Esquerda");
      drive_esquerda();
      delay(2800);
      drive_stop();
      delay(200);
      drive_frente();
    }
  }  
}

void drive_esquerda(){           //função drive_esquerda
  digitalWrite(PortPin2, LOW);     //Motor 1
  digitalWrite(PortPin3, HIGH);    //Motor 2
  digitalWrite(PortPin4, HIGH);    //Motor 1
  digitalWrite(PortPin5, LOW);     //Motor 2
}

void drive_direita(){             //função drive_direita
  digitalWrite(PortPin2, HIGH);     //Motor 1
  digitalWrite(PortPin3, LOW);      //Motor 1
  digitalWrite(PortPin4, LOW);      //Motor 2
  digitalWrite(PortPin5, HIGH);     //Motor 2
}

void drive_stop(){                //função drive_stop
  digitalWrite(PortPin2, LOW);      //Motor 1
  digitalWrite(PortPin4, LOW);      //Motor 2
  digitalWrite(PortPin3, LOW);      //Motor 1
  digitalWrite(PortPin5, LOW);      //Motor 2
}

void drive_re(){                  //função drive_re
  digitalWrite(PortPin2, HIGH);     //Motor 1
  digitalWrite(PortPin3, LOW);      //Motor 1
  digitalWrite(PortPin4, HIGH);     //Motor 2
  digitalWrite(PortPin5, LOW);      //Motor 2
}

void drive_frente(){              //função drive_frente
  digitalWrite(PortPin2, LOW);      //Motor 1
  digitalWrite(PortPin3, HIGH);     //Motor 1
  digitalWrite(PortPin4, LOW);      //Motor 2
  digitalWrite(PortPin5, HIGH);     //Motor 2
}

int ultrasonico(){

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  int distancia = (ultrasonic.Ranging(CM));

  return(distancia);

}
