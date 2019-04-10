

 int motorL = 6;
 int motorR = 5;
  
 int xJPin = A0;
 int yJPin = A1;
 
  
 float x_coordinate;
 float y_coordinate;
  
  

// variables of the mathematical model used
  float speed;
 
  float theta_rad;
  float theta_deg;
  float radius;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(motorR, OUTPUT);
  pinMode(motorL, OUTPUT);
  
  
}

void loop() {
  x_coordinate = analogRead(xJPin);
  y_coordinate = analogRead(yJPin);
  
  delay(10);

  x_coordinate = map(x_coordinate, 0, 1023, -500, 500);
  y_coordinate = map(y_coordinate, 0, 1023, -500, 500);


  radius = sqrt(sq(x_coordinate) + sq(y_coordinate));    
    if(radius < 28) {
      theta_rad = 0;
    }
    else {
      theta_rad = atan2(y_coordinate,x_coordinate);
    }
    if(radius < 27) {
      radius = 0;
    }
    else if(radius >= 400) {
      radius = 400;
    }
    
  theta_deg = theta_rad * 4068/71;
  
    if((theta_deg > 75) && (theta_deg < 105)) { //forward
      speed = map(radius, 0, 500, 75, 190);
      analogWrite(motorL, speed);
      analogWrite(motorR, speed);
      
    }
    else if((theta_deg > -105) && (theta_deg < -75)) { //backward
      

    }
    else if(((theta_deg < 75) && (theta_deg > 0)) || ((theta_deg > -75) && (theta_deg < 0))) { //left
 
     analogWrite(motorR, 110);
      analogWrite(motorL, 0);
    
    }
    else if(((theta_deg > 105) && (theta_deg < 180)) || ((theta_deg > -105) && (theta_deg < -180))) { //right      theta_deg = theta_deg - 180;    
    

     analogWrite(motorR, 0);
      analogWrite(motorL, 110);
    }
  else
    {
      analogWrite(motorL, 0);
      analogWrite(motorR, 0);
    }         
  
  

}
