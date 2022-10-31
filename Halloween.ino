const int trigPin = 11;
float distance = 0; 
const int echoPin = 12;  
const int Ledpin = 7;
  
void setup() {
  Serial.begin (9600); 
  pinMode(Ledpin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT);
  // put your setup code here, to run once:

}
void loop() {

  distance = getDistance();   //variable to store the distance measured by the sensor

  Serial.print(distance);
  if(distance <= 10){
    digitalWrite(Ledpin, LOW);
    Serial.println("the distance is less than 10");
    
    }
    else{
      
      digitalWrite(Ledpin, HIGH);
    }
  // put your main code here, to run repeatedly:

}


float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calcualtedDistance;         //variable to store the distance calculated from the echo time
  
  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor

  calcualtedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  
  return calcualtedDistance;              //send back the distance that was calculated
}

  
