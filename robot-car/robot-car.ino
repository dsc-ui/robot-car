// pins for the lm298
#define ENB 6
#define IN4 7
#define IN3 8
#define IN2 9
#define IN1 10
#define ENA 11

// to keep track of the speed of the car
int speed {255};

// high level functions
void driveForward(int speed);
void driveReverse(int speed);
void turnLeftForward(int speed);
void turnRightForward(int speed);
void turnLeftReverse(int speed);
void turnRightReverse(int speed);
void brake();

// high level functions
void leftWheelsForward(int speed);
void rightWheelsForward(int speed);
void leftWheelsReverse(int speed);
void rightWheelsReverse(int speed);
void leftWheelsStop(void);
void rightWheelsStop(void);


void setup(){
  pinMode(ENB, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(ENA, OUTPUT);
}


void loop() {
  /*
   * a simple demo just to test some functions and see everything is working fine
   * to be extended as see fit for several applications
   * some of which are:
   * self-driving car
   * remote controlled driving carAI-powered car and many more
  */
  driveForward(speed);
  delay(3000);

  turnLeftForward(speed);
  delay(3000);

  driveForward(speed);
  delay(3000);
  
  turnRightForward(speed);
  delay(3000);
  
  brake();
  delay(1000);
}


void brake(){
  /* 
   *stops the car's wheels
  */
  leftWheelsStop();
  rightWheelsStop();
}

void driveForward(int speed){
  /* 
   *  drives the car forward with a given speed
   *  rotates the wheels of the car in the forward direction
  */
  leftWheelsForward(speed);
  rightWheelsForward(speed);
}

void driveReverse(int speed){
  /* 
   *  drives the car backward with a given speed
   *  rotates the wheels of the car in a backward direction
  */
  leftWheelsReverse(speed);
  rightWheelsReverse(speed);
}

void turnLeftForward(int speed){
   /* 
   *  turns the car left while direction forward with a given speed
   *  rotates the left wheels in the forward direction
   *  stops the right wheel motion
  */
  leftWheelsStop();
  rightWheelsForward(speed);
}

void turnRightForward(int speed){
   /* 
   *  turns the car right while direction forward with a given speed
   *  rotates the right wheels in the forward direction
   *  stops the left wheel motion
  */
  leftWheelsForward(speed);
  rightWheelsStop();
}

void turnLeftReverse(int speed){
   /* 
   *  turns the car left while direction backward with a given speed
   *  rotates the left wheels in the backward direction
   *  stops the right wheel motion
  */
  leftWheelsStop();
  rightWheelsReverse(speed);
}

void turnRightReverse(int speed){
  /* 
   *  turns the car right while direction backward with a given speed
   *  rotates the right wheels in the backward direction
   *  stops the left wheel motion
  */
  leftWheelsReverse(speed);
  rightWheelsStop();
}


void leftWheelsForward(int speed){
  /* 
   *  move the left wheels in a forward direction with a given speed, in the counter-clockwise direction
  */
  analogWrite(ENB, speed);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rightWheelsForward(int speed){
  /* 
   *  move the right wheels in a forward direction with a given speed, in the clockwise direction
  */
  analogWrite(ENA, speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void leftWheelsReverse(int speed){
  /* 
   *  move the left wheels in a backward direction with a given speed, in the clockwise direction
  */
  analogWrite(ENB, speed);
  
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);  
}

void rightWheelsReverse(int speed){
  /* 
   *  move the right wheels in a backward direction with a given speed, in the counter-clockwise direction
  */
  analogWrite(ENA, speed);

  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
}

void leftWheelsStop(void){
  /* 
   * stops the left wheels motion
  */
  digitalWrite(ENB, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rightWheelsStop(void){
  /* 
   * stops the left wheels motion
  */
  digitalWrite(ENA, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
