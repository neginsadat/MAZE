#include <NewPing.h>

//  ⁄—Ì› ÅÌ‰ùÂ« »—«Ì ”‰”Ê—Â«
#define TRIGGER_PIN_FRONT 12
#define ECHO_PIN_FRONT 11
#define TRIGGER_PIN_LEFT 10
#define ECHO_PIN_LEFT 9
#define TRIGGER_PIN_RIGHT 8
#define ECHO_PIN_RIGHT 7
#define MAX_DISTANCE 200

//  ⁄—Ì› ÅÌ‰ùÂ« »—«Ì „Ê Ê—Â«
#define MOTOR_LEFT_FORWARD 3
#define MOTOR_LEFT_BACKWARD 4
#define MOTOR_RIGHT_FORWARD 5
#define MOTOR_RIGHT_BACKWARD 6

NewPing sonarFront(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT, MAX_DISTANCE);
NewPing sonarLeft(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT, MAX_DISTANCE);
NewPing sonarRight(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT, MAX_DISTANCE);

void setup() {
  pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned int distanceFront = sonarFront.ping_cm();
  unsigned int distanceLeft = sonarLeft.ping_cm();
  unsigned int distanceRight = sonarRight.ping_cm();

  Serial.print("Front: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right: ");
  Serial.print(distanceRight);
  Serial.println(" cm");

  stopRobot(); //  Êﬁ› —»«  ﬁ»· «“  ’„Ì„ùêÌ—Ì

  if (distanceFront > 20) {
    // Õ—ò  »Â Ã·Ê
    moveForward();
    delay(500);
  } else if (distanceRight > 20) {
    // Õ—ò  »Â —«” 
    turnRight();
    delay(500);
  } else if (distanceLeft > 20) {
    // Õ—ò  »Â çÅ
    turnLeft();
    delay(500);
  } else {
    //  Êﬁ› Ê ç—Œ‘ »Â ⁄ﬁ»
    moveBackward();
    delay(500);
    stopRobot(); //  Êﬁ› »⁄œ «“ Õ—ò  »Â ⁄ﬁ»
    turnRight();
    delay(500);
    stopRobot(); //  Êﬁ› »⁄œ «“ ç—Œ‘
    turnRight();
    delay(500);
  }

  delay(100); //  √ŒÌ— òÊ «Â »—«Ì ”‰”Ê—
}

void moveForward() {
  digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}

void moveBackward() {
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_LEFT_BACKWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
}

void turnRight() {
  digitalWrite(MOTOR_LEFT_FORWARD, HIGH);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, HIGH);
  delay(300); //  √ŒÌ— »—«Ì ç—Œ‘ ò«„·° »«Ìœ  ‰ŸÌ„ ‘Êœ
}

void turnLeft() {
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_LEFT_BACKWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_FORWARD, HIGH);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
  delay(300); //  √ŒÌ— »—«Ì ç—Œ‘ ò«„·° »«Ìœ  ‰ŸÌ„ ‘Êœ
}

void stopRobot() {
  digitalWrite(MOTOR_LEFT_FORWARD, LOW);
  digitalWrite(MOTOR_LEFT_BACKWARD, LOW);
  digitalWrite(MOTOR_RIGHT_FORWARD, LOW);
  digitalWrite(MOTOR_RIGHT_BACKWARD, LOW);
}
