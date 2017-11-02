///////////////////////////
// CONSTANTS
//////////////////////////
#define GREEN_LED 12
#define BLUE_LED 11
#define RED_LED 10
#define LHS_MOTOR 3
#define RHS_MOTOR 5
///////////////////////////
// FUNCTION DELCARATIONS
//////////////////////////
void initLEDS();

///////////////////////////
// MAIN
//////////////////////////
void setup() 
{
  initLEDS();
  initMotors();
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, HIGH);

  analogWrite(LHS_MOTOR, HIGH);
  analogWrite(RHS_MOTOR, HIGH);
}

///////////////////////////
// FUNCTION DEFINITIONS
//////////////////////////
void initLEDS()
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

