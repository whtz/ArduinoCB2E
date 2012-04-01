/*
 * SerialReceive sketch
 * Blink the LED at a rate proportional to the received digit value
 */
const int ledPin = 13; // pin the LED is connected to
int   blinkRate=0;     // blink rate stored in this variable

void setup()
{
  Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
  pinMode(ledPin, OUTPUT); // set this pin as output
}

void loop()
{
  blink(); 
}

void serialEvent()
{
  while(Serial.available())
  {
    char ch = Serial.read();
    Serial.write(ch);    
    if( isDigit(ch) ) // is this an ascii digit between 0 and 9?
    {
      blinkRate = (ch - '0');      // ASCII value converted to numeric value
      blinkRate = blinkRate * 100; // actual rate is 100mS times received digit 
    }
  }
}

// blink the LED with the on and off times determined by blinkRate
void blink()
{
  digitalWrite(ledPin,HIGH);
  delay(blinkRate); // delay depends on blinkrate value
  digitalWrite(ledPin,LOW);
  delay(blinkRate);
}