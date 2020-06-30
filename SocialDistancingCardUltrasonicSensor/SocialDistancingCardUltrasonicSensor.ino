int const trigPin = 6;
int const echoPin = 5;
int const buzzPin = 13;

long duration;
int distance;

void setup()
{
    pinMode(trigPin, OUTPUT);                     // trig pin will have pulses output
    pinMode(echoPin, INPUT);                      // echo pin should be input to get pulse width
    pinMode(buzzPin, OUTPUT);                     // buzz pin is output to control buzzer
    Serial.begin(9600); 
}

void loop()
{
    digitalWrite(trigPin, HIGH);
    delay(1);                                     // Output pulse with 1ms width on trigPin
    digitalWrite(trigPin, LOW);                                        
                                                                   
    duration = pulseIn(echoPin, HIGH);            // Measure the pulse input in echo pin

    distance = (duration/2) / 29.1;               // Distance is half the duration devided by 29.1(from datasheet)
    Serial.print("Distance: ");
    Serial.println(distance);                     // For serial monitor

    if (distance <= 100 && distance >= 0) {       // if distance less than 1 meter and more than 0 (0 or less means over range)
          digitalWrite(buzzPin, LOW);             // Buzz
        } 
    else {
          digitalWrite(buzzPin, HIGH);            // Don't buzz
        }

    delay(60);
}
