int LEFTMOST_SENSOR = A0;
int LEFT_SENSOR = A1;
int CENTER_SENSOR = A2;
int RIGHT_SENSOR = A3;
int RIGHTMOST_SENSOR = A4;

int LEFT_MOTOR = 2;
int RIGHT_MOTOR = 3;

int LINE_THRESHOLD = 500; 
float KP = 0.5;  
float KD = 5;   
float KI = 0.004;  

float error;
float previousError = 0;
float time;
float oldtime=0;


void setup() {
  Serial.begin(9600);
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(LEFTMOST_SENSOR, INPUT);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(RIGHTMOST_SENSOR, INPUT);
}

void loop() {
  time = millis();
  float dt = time - oldtime;
  int leftmostSensorValue = analogRead(LEFTMOST_SENSOR);
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int centerSensorValue = analogRead(CENTER_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);
  int rightmostSensorValue = analogRead(RIGHTMOST_SENSOR);
  oldtime = time;

  Serial.print("Leftmost: ");
  Serial.println(leftmostSensorValue);
  Serial.print(" - Left: ");
  Serial.println(leftSensorValue);
  Serial.print(" - Center: ");
  Serial.println(centerSensorValue);
  Serial.print(" - Right: ");
  Serial.println(rightSensorValue);
  Serial.print(" - Rightmost: ");
  Serial.println(rightmostSensorValue);
  Serial.println();

  error = (leftmostSensorValue * -0.1) + (leftSensorValue * -0.05) + (rightSensorValue * 0.05) + (rightmostSensorValue * 0.1);

  float proportional = error;
  float derivative = (error - previousError)/dt;
  float integral += error*dt;
  float output = (KP * proportional) + (KD * derivative) + (KI * integral);
  previousError = error;

  if(output > 55){
    output = 55;
  }
  
  if (leftmostsensorvalue<LINE_THRESHOLD && leftsensorvalue<LINE_THRESHOLD && centersensorvalue>LINE_THRESHOLD && rightsensorvalue<LINE_THRESHOLD && rightmostsensorvalue<LINE_THRESHOLD){
    analogWrite(LEFT_MOTOR, 200);
    analogWrite(RIGHT_MOTOR, 200);
  }
  else if (leftsensorvalue > LINE_THRESHOLD) {
    analogWrite(LEFT_MOTOR, 200 + output);
    analogWrite(RIGHT_MOTOR, 200 - output);
  }else if (leftmostSensorValue > LINE_THRESHOLD) {
    analogWrite(LEFT_MOTOR, 200 + output);
    analogWrite(RIGHT_MOTOR, 200 - output);
  }else if (rightSensorValue > LINE_THRESHOLD) {
    analogWrite(LEFT_MOTOR, 200 + output);
    analogWrite(RIGHT_MOTOR, 200 - output);
  }else if (rightmostsensorvalue > LINE_THRESHOLD) {
    analogWrite(LEFT_MOTOR, 200 + output);
    analogWrite(RIGHT_MOTOR, 200 - output);
  }else if (leftmostsensorvalue>LINE_THRESHOLD && leftsensorvalue>LINE_THRESHOLD && centersensorvalue>LINE_THRESHOLD && rightsensorvalue>LINE_THRESHOLD && rightmostsensorvalue>LINE_THRESHOLD){
    analogWrite(LEFT_MOTOR, 0);
    analogWrite(RIGHT_MOTOR, 0);
  }
}
