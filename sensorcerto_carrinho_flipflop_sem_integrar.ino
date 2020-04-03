String inputString = "";        
bool stringComplete = false;  

int IN1 = 4; //motor 1
int IN2 = 5; //motor 1
int IN3 = 6; //motor 2
int IN4 = 7; //motor 2
int distancia = 0;
int disdir= 0;
int disesq = 0;

#define echoPin 11
#define trigPin 12

#include "Ultrasonic.h"

Ultrasonic ultrasonic(12,13);

void setup()   {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
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
  digitalWrite(IN1, LOW);     //Motor 1
  digitalWrite(IN2, HIGH);    //Motor 2
  digitalWrite(IN1, HIGH);    //Motor 1
  digitalWrite(IN2, LOW);     //Motor 2
}

void drive_direita(){             //função drive_direita
  digitalWrite(IN1, HIGH);     //Motor 1
  digitalWrite(IN1, LOW);      //Motor 1
  digitalWrite(IN2, LOW);      //Motor 2
  digitalWrite(IN2, HIGH);     //Motor 2
}

void drive_stop(){                //função drive_stop
  digitalWrite(IN1, LOW);      //Motor 1
  digitalWrite(IN2, LOW);      //Motor 2
  digitalWrite(IN1, LOW);      //Motor 1
  digitalWrite(IN2, LOW);      //Motor 2
}

void drive_re(){                  //função drive_re
  digitalWrite(IN1, HIGH);     //Motor 1
  digitalWrite(IN1, LOW);      //Motor 1
  digitalWrite(IN2, HIGH);     //Motor 2
  digitalWrite(IN2, LOW);      //Motor 2
}

void drive_frente(){              //função drive_frente
  digitalWrite(IN1, LOW);      //Motor 1
  digitalWrite(IN1, HIGH);     //Motor 1
  digitalWrite(IN2, LOW);      //Motor 2
  digitalWrite(IN2, HIGH);     //Motor 2
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
