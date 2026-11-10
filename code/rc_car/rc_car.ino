/*
  Bluetooth Controlled 4WD RC Car
  Pins 4, 5 -> Left Motors (IN1, IN2)
  Pins 6, 7 -> Right Motors (IN3, IN4)
*/

#define IN1 4  // Left Motors Forward
#define IN2 5  // Left Motors Backward
#define IN3 6  // Right Motors Forward
#define IN4 7  // Right Motors Backward

char command;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize motors to stopped state
  stopCar();

  // Bluetooth default baud rate
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      // --- Basic Movements ---
      case 'F': forward();      break;
      case 'B': backward();     break;
      case 'L': turnLeft();     break;
      case 'R': turnRight();    break;

      // --- Diagonal Movements ---
      case 'G': forwardLeft();  break;
      case 'I': forwardRight(); break;
      case 'H': backLeft();     break;
      case 'J': backRight();    break;

      // --- Stop Commands ---
      case 'S':
      case 'D': stopCar();      break;

      // Ignore speed adjustments, lights, or horn toggles safely
      default: break;
    }
  }
}

// ================= MOTOR FUNCTIONS =================

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  // Left wheels reverse, Right wheels forward (Pivot Left)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  // Left wheels forward, Right wheels reverse (Pivot Right)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void forwardLeft() {
  // Stop left side, drive right side
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void forwardRight() {
  // Drive left side, stop right side
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void backLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
