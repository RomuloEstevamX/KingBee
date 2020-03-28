String inputString = "";        
bool stringComplete = false;  

void setup() {
  // inicia o serial:
  Serial.begin(115200);
  // reserva 200 bytes pra inputString:
  inputString.reserve(200);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // imprime a string nova quando chega:
  if (stringComplete) {
    Serial.print("Jarvis Falando: ");
    Serial.print(inputString);
    // limpa a string:
    if(inputString.startsWith("ligar")){
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));// toggle
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
