///////////////////////////
// CONSTANTS
//////////////////////////
// Arduino Constants
//-----  NAME -------------- PIN LABEL -----
#define GREEN_LED 12        // D12
#define BLUE_LED 11         // D11
#define RED_LED 10          // D10
#define LHS_MOTOR 3         // D3; TIP 120 (responds to high)
#define RHS_MOTOR 5         // D5; TIP 125 (responds to low)
#define RHS_TRANSISTOR 14   // A0 | 951 = full black, 965 = corner black, 976 = edge black, 980 = white
#define LHS_TRANSISTOR 19   // A5 | 2 = full black, 3 = corner black, 8 = edge black, 14 = white
#define MID_TRANSISTOR 17   // A3 | 299 = full black, 231 = corner black, 582 = edge black, 953 = white

// Logic Constants
#define RT_WHITE 980
#define RT_BLACK 951
#define RT_MID 975
#define LT_WHITE 14
#define LT_BLACK 2
#define LT_MID 8
#define MT_WHITE 953
#define MT_BLACK 299
#define MT_MID 582
///////////////////////////
// GLOBALS
//////////////////////////
enum directions { RIGHT = 0, LEFT = 1, STRAIGHT = 2, STOP = 3 };

///////////////////////////
// FUNCTION DELCARATIONS
//////////////////////////

// Sets pinMode for all visible light LEDs.
void initVisibleLEDS();

// Sets pinMode for the two motors.
void initMotors();

// Sets pinMode for the transistors.
void initTransistors();

// Tells robot to drive in direction given by dir which is a value from the enum directions.
void drive(int dir);

// Zeros-out the visible LEDS (i.e., digitalWrites low to all).
void zeroVisibleLEDS();

// testing Motors
void testMotors();

// Lights up LEDs based on transistor readings.
void testTransistor();

// Print transitors readings.
void printTransistorReadings();

///////////////////////////
// MAIN
//////////////////////////
void setup() 
{
  initVisibleLEDS();
  zeroVisibleLEDS();
  initMotors();
  initTransistors();
  drive(STOP);
  Serial.begin(9600);
}

void loop()
{
  // We're hitting black with our left, drive left to get back on track
  if( analogRead(LHS_TRANSISTOR) <= LT_MID )
  {
      zeroVisibleLEDS();
      digitalWrite(BLUE_LED, HIGH);
      drive(LEFT);
  }
  // We're hitting black with our right, drive right to get back on track
  else if( analogRead(RHS_TRANSISTOR) <= RT_MID )
  {
      zeroVisibleLEDS();
      digitalWrite(RED_LED, HIGH);
      drive(RIGHT);
  }
  // Basically, both our LHS and RHS are reading whiteish, and our mid's on black, meaning we're on track
  else if( MID_TRANSISTOR <= MT_MID )
  {
      zeroVisibleLEDS();
      digitalWrite(GREEN_LED, HIGH);
      drive(STRAIGHT);
  }
}

///////////////////////////
// FUNCTION DEFINITIONS
//////////////////////////
void initVisibleLEDS()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void initMotors()
{
  pinMode(LHS_MOTOR, OUTPUT);
  pinMode(RHS_MOTOR, OUTPUT);
}

void initTransistors()
{
  pinMode(RHS_TRANSISTOR, INPUT);
  pinMode(LHS_TRANSISTOR, INPUT);
  pinMode(MID_TRANSISTOR, INPUT);
}



void drive(int dir)
{
  switch (dir)
  {
    case RIGHT:
      analogWrite(RHS_MOTOR, 192); // RHS speed increases with lower number, so decrease speed here with higher number
      analogWrite(LHS_MOTOR, 128);
      break;
    case LEFT:
      analogWrite(RHS_MOTOR, 128);
      analogWrite(LHS_MOTOR, 64);
      break;
    case STRAIGHT:
      analogWrite(RHS_MOTOR, 128);
      analogWrite(LHS_MOTOR, 128);
      break;
     case STOP:
      analogWrite(RHS_MOTOR, 255);
      analogWrite(LHS_MOTOR, 0);
      break;
  }
}

void zeroVisibleLEDS()
{
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void testMotors()
{
  analogWrite(RHS_MOTOR, HIGH);
  analogWrite(LHS_MOTOR, LOW);
}

void testTransistor(int toTest)
{
  switch(toTest)
  {
    case RHS_TRANSISTOR:
      if( analogRead(RHS_TRANSISTOR) == HIGH )
      {
        digitalWrite(GREEN_LED, HIGH);
      }
      else
      {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, HIGH);
      }
      break;
    case LHS_TRANSISTOR:
      if( analogRead(LHS_TRANSISTOR) == HIGH )
      {
        digitalWrite(BLUE_LED, HIGH);
      }
      else
      {
        digitalWrite(BLUE_LED, HIGH);
        digitalWrite(RED_LED, HIGH);
      }
      break;
    case MID_TRANSISTOR:
      if( analogRead(MID_TRANSISTOR) == HIGH )
      {
        digitalWrite(RED_LED, HIGH);
      }
      else
      {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
        digitalWrite(RED_LED, HIGH);
      }
      break;
  }
}


void printTransistorReadings(int input)
{
  switch( input )
  {
    case LHS_TRANSISTOR:
      Serial.println("LHS Transistor: " + String(analogRead(LHS_TRANSISTOR)));
      break;
    case RHS_TRANSISTOR:
      Serial.println("RHS Transistor: " + String(analogRead(RHS_TRANSISTOR)));
      break;
    case MID_TRANSISTOR:
      Serial.println("MID Transistor: " + String(analogRead(MID_TRANSISTOR)));
      break;
  }
}

