# SIT315

int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
volatile byte state = LOW;


void setup()
{
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), blink, HIGH);
}

void loop()
{
  baselineTemp = 40;
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print("C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
  delay(1000);
  
}

void blink()
{
  state = !state;
}