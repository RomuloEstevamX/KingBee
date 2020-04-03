String inputString = "";        
bool stringComplete = false;  

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  // inicia o serial:
  Serial.begin(115200);
  // reserva 200 bytes pra inputString:
  inputString.reserve(200);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // imprime a string nova quando chega:
  if (stringComplete) {
    Serial.print("Jarvis Falando: ");
    Serial.print(inputString);
    // limpa a string:
    if(inputString.startsWith("ligar")){
      digitalWrite(IN1, !digitalRead(IN1));// toggle
      pinMode (12, OUTPUT);
    }
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    
    char inChar = (char)Serial.read();
    
    inputString += inChar;
    
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
