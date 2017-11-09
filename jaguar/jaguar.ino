///////////////////////////
// CONSTANTS
//////////////////////////
//-----  NAME -------------- PIN LABEL -----
#define GREEN_LED 12        // D12
#define BLUE_LED 11         // D11
#define RED_LED 10          // D10
#define LHS_MOTOR 3         // D3; TIP 120 (responds to high)
#define RHS_MOTOR 5         // D5; TIP 125 (responds to low)
#define RHS_TRANSISTOR 14   // A0
#define LHS_TRANSISTOR 19   // A5
#define MID_TRANSISTOR 17   // A3

///////////////////////////
// FUNCTION DELCARATIONS
//////////////////////////

// Sets pinMode for all visible light LEDs.
void initVisibleLEDS();

// Sets pinMode for the two motors.
void initMotors();

// Lights up LEDs based on transistor readings.
void testTransistor();

///////////////////////////
// MAIN
//////////////////////////
void setup() 
{
  initVisibleLEDS();
  initMotors();
  Serial.begin(9600);

}

void loop()
{

  testTransistor(RHS_TRANSISTOR);

  // analogWrite(LHS_MOTOR, HIGH);
  // analogWrite(RHS_MOTOR, LOW);
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

void testTransistor(int toTest)
{
  switch(toTest)
  {
    case RHS_TRANSISTOR:
      if( digitalRead(RHS_TRANSISTOR) == HIGH )
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
      if( digitalRead(LHS_TRANSISTOR) == HIGH )
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
      if( digitalRead(MID_TRANSISTOR) == HIGH )
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

