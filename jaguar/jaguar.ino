///////////////////////////
// CONSTANTS
//////////////////////////
//-----  NAME -------------- PIN LABEL -----
#define GREEN_LED 12        // D12
#define BLUE_LED 11         // D11
#define RED_LED 10          // D10
#define LHS_MOTOR 3         // D3; TIP 120 (responds to high)
#define RHS_MOTOR 5         // D5; TIP 125 (responds to low)
#define RHS_TRANSISTOR 14   // A0 | 951 = full black, 965 = corner black, 976 = edge black, 980 = white
#define LHS_TRANSISTOR 19   // A5 | 0 = full black, 3 = corner black, 8 = edge black, 14 = white
#define MID_TRANSISTOR 17   // A3 | 160 = full black, 231 = corner black, 615 = edge black, 922 = white

///////////////////////////
// GLOBALS
//////////////////////////
enum directions { RIGHT = 0, LEFT = 1, STRAIGHT = 2 };

///////////////////////////
// FUNCTION DELCARATIONS
//////////////////////////

// Sets pinMode for all visible light LEDs.
void initVisibleLEDS();

// Sets pinMode for the two motors.
void initMotors();

// Sets pinMode for the transistors.
void initTransistors();

// Tells robot to turn in direction in int direction which is a value from enum directions
void turn(int dir);

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
  initMotors();
  initTransistors();
  Serial.begin(9600);

}

void loop()
{
    printTransistorReadings(LHS_TRANSISTOR);
    analogWrite(LHS_MOTOR, 255);
    //analogWrite(RHS_MOTOR, 0); 
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



void turn(int dir)
{
  switch (dir)
  {
    case RIGHT:
      break;
    case LEFT:
      break;
    case STRAIGHT:
      break;
  }
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

