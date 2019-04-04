void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 int motorR = 6;
 int motorL = 5;
  
 int xJPin = A0;
 int yJPin = A1;
 
  
 float x_coordinate;
 float y_coordinate;
  
  

// variables of the mathematical model used
  float speed;
 
  float theta_rad;
  float theta_deg;
  float radius;

  pinMode(motorR, OUTPUT);
  pinMode(motorL, OUTPUT);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
   readJoystick();

}

void readJoystick(){
  x_coordinate = analogRead(xJPin);
  y_coordinate = analogRead(yJPin);
  
  delay(10);

  x_coordinate = map(x_coordinate, 0, 1023, -500, 500);
  y_coordinate = map(y_coordinate, 0, 1023, -500, 500;
}


void createMathModel() {
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
      speed = map(pot_value, 0, 1023, 0, 400);
      
    }
    else if((theta_deg > -105) && (theta_deg < -75)) { //backward
      

    }
    else if(((theta_deg < 75) && (theta_deg > 0)) || ((theta_deg > -75) && (theta_deg < 0))) { //right
 
     analogWrite(motorL, 110);
      analogWrite(motorR, 0);
    
    }
    else if(((theta_deg < 105) && (theta_deg > 0)) || ((theta_deg > -105) && (theta_deg < 0))) { //leftb      theta_deg = theta_deg - 180;    
    }

     analogWrite(motorL, 0);
      analogWrite(motorR, 110);
    }
  else
    {
      analogWrite(motorL, 0);
      analogWrite(motorR, 0);
               
  
  
 
}
