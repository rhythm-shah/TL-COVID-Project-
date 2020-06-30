int const irPin = 2;
int const relayPin = 13;

int reading;

void setup() 
{
    pinMode(irPin, INPUT);                   // ir pin should be input to get sense of an object infront
    pinMode(relayPin, OUTPUT);               // relay pin is output to control relay
    digitalWrite(relayPin, HIGH);                            
    Serial.begin(9600);
}

void loop() 
{              
    reading = digitalRead(irPin);            
    Serial.println(reading);                 // For serial monitor
    
    if (reading == HIGH) {                   // if any object is infront
          digitalWrite(relayPin, HIGH);      // Ring bell
        }
    else {
          digitalWrite(relayPin, LOW);       // Don't ring bell
        }

    delay(500);
}
