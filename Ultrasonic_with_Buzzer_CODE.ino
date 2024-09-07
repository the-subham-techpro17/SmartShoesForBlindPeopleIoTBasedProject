// defines pins numbers
const int trigPin = 4;
const int echoPin = 5;
const int Relay = 6;
const int ledPin = 7;
 
// defines variables
long duration;
int distance;
int safetyDistance;
 
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(Relay, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
 
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <=25){
  digitalWrite(Relay, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(Relay, LOW);
  digitalWrite(ledPin, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}



This is a complete Arduino sketch written in the C++ programming language that measures distance using an ultrasonic 
sensor and turns on an LED and relay if the distance is less than or equal to 25 cm.

 Here is a brief summary of what the code does:

The code defines four constant integer variables trigPin, echoPin, Relay, and ledPin, and initializes them with the values 4, 5, 6, and 7, respectively. These variables represent the pin numbers of the ultrasonic sensor's trigger pin, echo pin, and the relay and LED pins on the Arduino board.


The setup() function sets the pin modes for the trigPin, echoPin, Relay, and ledPin as output and input, respectively, and starts the serial communication at a baud rate of 9600.

The loop() function continuously measures the distance using the ultrasonic sensor and calculates the distance in centimeters using the speed of sound. It then stores this value in the distance variable and the safetyDistance variable.

If the safetyDistance is less than or equal to 25 cm, the code turns on the relay and LED by setting their respective pins to high using digitalWrite(). Otherwise, the relay and LED are turned off by setting their respective pins to low using digitalWrite().


The code prints the distance value on the serial monitor using Serial.print() and Serial.println() functions.

Overall, this code is an example of how an ultrasonic sensor can be used to detect the distance of an object and trigger an action based on that distance.


