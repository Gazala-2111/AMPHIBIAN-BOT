int enA = 5; //enable pin A to be connected in digital pin 5
int in1 = 8; // IN1
int in2 = 9; // IN2
int enB = 6; //enable pin B to be connected in digital pin 6
int in3 = 10; // IN3
int in4 = 11; // IN4

char command;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'F': // Move forward
    Serial.print("Your code is executing successfully moving forward");
      moveForward();
      break;
    case 'B': // Move backward
    Serial.print("Your code is executing successfully moving backward");
      moveBackward();
      break;
    case 'L': // Turn left
    Serial.print("Your code is executing successfully turning left");
      turnLeft();
      break;
    case 'R': // Turn right
    Serial.print("Your code is executing successfully turning right");
      turnRight();
      break;
    case 'S': // Stop
      stopMotors();
      break;
    default:
      Serial.print("Invalid command");
      // Invalid command
      break;
  }
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Full speed(Duty cycle (2^n)-1)
  analogWrite(enB, 255); // Full speed
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255); // Full speed
  analogWrite(enB, 255); // Full speed
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Full speed
  analogWrite(enB, 255); // Full speed
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255); // Full speed
  analogWrite(enB, 255); // Full speed
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0); // Stop
  analogWrite(enB, 0); // Stop
}