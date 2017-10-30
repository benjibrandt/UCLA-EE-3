///////////////////////////
// CONSTANTS
//////////////////////////
#define GREEN_LED 12
#define BLUE_LED 11
#define RED_LED 10
///////////////////////////
// FUNCTION DELCARATIONS
//////////////////////////
void initLEDS();

///////////////////////////
// MAIN
//////////////////////////
void setup() 
{
  // put your setup code here, to run once:
  initLEDS();
  Serial.begin(9600);

}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
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

