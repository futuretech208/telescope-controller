const unsigned int PIN_RA_STEP = 2;
const unsigned int PIN_RA_DIRECTION = 3;
const unsigned int PIN_8X = 4;
const unsigned int PIN_2X = 5;
const unsigned int PIN_RA_MINUS = 6;
const unsigned long STEP_INTERVAL_SIDEREAL = 9.0838509316769500;     // milisecond
const unsigned long STEP_INTERVAL_2X_SIDEREAL = 4.5419254658384700;  // miliseconds
const unsigned long STEP_INTERVAL_8X_SIDEREAL = 1.1354813664596200;   // miliseconds

void setup()
{
  pinMode(PIN_RA_STEP, OUTPUT);
  pinMode(PIN_RA_DIRECTION, OUTPUT);
  pinMode(PIN_8X, INPUT);
  pinMode(PIN_2X, INPUT);
  pinMode(PIN_RA_MINUS, INPUT);

  digitalWrite(PIN_RA_STEP, LOW);
  digitalWrite(PIN_RA_DIRECTION, LOW);                  // for changing the direction in Northen or southern hemisphere
  digitalWrite(PIN_8X, LOW);
  digitalWrite(PIN_2X, LOW);
  digitalWrite(PIN_RA_MINUS, LOW);
  Serial.begin(9600);
}

void loop()
{
  setRightAscensionDirection();
  checkSpeed();
}

void setRightAscensionDirection()
{
  if (digitalRead(PIN_RA_MINUS) == HIGH)
  {
    digitalWrite(PIN_RA_DIRECTION, HIGH);                 // counterclockwise
  }
  else
  {
    digitalWrite(PIN_RA_DIRECTION, LOW);                // clockwise
  }
}

void checkSpeed()
{
  if ((digitalRead(PIN_8X) == HIGH))
  {
    digitalWrite(PIN_RA_STEP, HIGH);
    delay(STEP_INTERVAL_8X_SIDEREAL);
    digitalWrite(PIN_RA_STEP, LOW);
    delay(STEP_INTERVAL_8X_SIDEREAL);
  }

  if ((digitalRead(PIN_2X) == HIGH))
  {
    digitalWrite(PIN_RA_STEP, HIGH);
    delay(STEP_INTERVAL_2X_SIDEREAL);
    digitalWrite(PIN_RA_STEP, LOW);
    delay(STEP_INTERVAL_2X_SIDEREAL);
  }
  else
  {
    digitalWrite(PIN_RA_STEP, HIGH);
    delay(STEP_INTERVAL_SIDEREAL);
    digitalWrite(PIN_RA_STEP, LOW);
    delay(STEP_INTERVAL_SIDEREAL);
  }
}

