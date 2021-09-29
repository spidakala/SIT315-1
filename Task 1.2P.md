//C++ code
//
const int buttonPin = 2; 
//it is the number of the push button
const int ledPin = 13; 
//it is the number of the led Pin

uint8_t led_state = LOW; //sets the led state to LOW 7
void setup()
{
pinMode(13, OUTPUT); 
  // intialises the led pin as output pinMode(2, INPUT); 
  //intializes the push button as input
attachInterrupt(digitalPinToInterrupt(2), new_isr, CHANGE); //attach interrupt to the ISR vector
}
void loop()
{
delay(500); // wait for 0.5 second
}
//interrupt service routine //call isr when interrupt occurs //ISR function
void new_isr()
{
led_state = !led_state;//toggle state when interrupt occurs
digitalWrite(ledPin, led_state); //led pin = 13 equal the state value 
}
