
int trigPin = 4;    
int echoPin = 3;  
int R1 = 10;    //Right motor
int R2 = 11;

int L1 = 12;    //Left motor
int L2 = 13;
 
long duration, distance ;
  
void setup() {
  
  Serial.begin (9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  pinMode(30, OUTPUT);
  pinMode(50, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    
}
 
void loop()
{  
//sensor 1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  distance = (duration/2) / 29.1;
  
 // inches = (duration/2) / 74; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm         ");

if(distance>20)
{ digitalWrite (50, HIGH);
  digitalWrite (30, LOW);
  
  digitalWrite (R1, HIGH); //FORWARD
  digitalWrite (R2, LOW); 
  digitalWrite (L1, HIGH); //FORWARD
  digitalWrite (L2, LOW); }

 else
{ digitalWrite (30, HIGH);
  digitalWrite (50, LOW);
  
  digitalWrite (R1, LOW); //BACKWARD
  digitalWrite (R2, HIGH);
  digitalWrite (L1, LOW); //BACKWARD
  digitalWrite (L2, HIGH);
  delay(1000);
   
 digitalWrite (L1, HIGH); //FORWARD
  digitalWrite (L2, LOW); 
   digitalWrite (R1, LOW); //BACKWARD
  digitalWrite (R2, LOW);
    delay(1000);
  }
 
}
 
 

