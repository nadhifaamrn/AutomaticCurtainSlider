#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
int pinSensorLDR = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastServoPos = -1; // Track last position to avoid repeated movement

void setup() {
  myservo.attach(8);
  pinMode(pinSensorLDR, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.print("LDR Servo Demo");
}

void loop() {
  int lightValue = analogRead(pinSensorLDR);
  Serial.println(lightValue);

  if (lightValue < 15) {  // Dark
    if (lastServoPos != 0) {
      myservo.write( 0);
      lastServoPos = 0;
      delay(5000);
    }
  } else {  // Bright
    if (lastServoPos != 180) {
      myservo.write(180);
      lastServoPos = 180;
      delay(5000);
    }
  } 

  delay(500); // brief pause
}