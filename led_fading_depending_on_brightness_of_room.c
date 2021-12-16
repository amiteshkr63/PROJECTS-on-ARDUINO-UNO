// C++ code
//
int bright=0;
void setup()
{
  pinMode(14,INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(14));
  bright=255-analogRead(14);
  analogWrite(11,bright);
  }
