String inputString = "";        
bool stringComplete = false;  

int cm = 0;
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(115200);
  inputString.reserve(200);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
{
 // imprime a string nova quando chega:
  if (stringComplete) {
    Serial.print("Jarvis Falando: ");
    Serial.print(inputString);
    // limpa a string:
    if(inputString.startsWith("ligar")){
      digitalWrite(IN1, !digitalRead(IN1));// toggle
    }
    inputString = "";
    stringComplete = false;
  }
}
  cm = 0.01723 * readUltrasonicDistance(12, 11);
  while (cm <= 200) {
    Serial.print("Distancia:");
    Serial.println(0.01723 * readUltrasonicDistance(12, 11));
    delay(5000); // Wait for 2000 millisecond(s)
  }
  if (cm > 200) {
    Serial.println("Distancia Maxima atingida");
    Serial.println("Sensor desativado");
    delay(5000); // Wait for 2000 millisecond(s)
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
