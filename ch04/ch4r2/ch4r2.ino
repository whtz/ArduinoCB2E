/*
 * SerialFormatting
 * Print values in various formats to the serial port
 */
char chrValue = 65;  // these are the starting values to print
byte byteValue = 65;
int intValue  = 65;
float floatValue = 65.0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("chrValue: ");
  Serial.println(chrValue);
  Serial.write(chrValue);
  Serial.println();
  Serial.println(chrValue,DEC);

  Serial.println("byteValue: ");
  Serial.println(byteValue);
  Serial.write(byteValue);
  Serial.println();
  Serial.println(byteValue,DEC);
  
  Serial.println("intValue: ");
  Serial.println(intValue);
  Serial.println(intValue,DEC);
  Serial.println(intValue,HEX);
  Serial.println(intValue,OCT);
  Serial.println(intValue,BIN);

  Serial.println("floatValue: ");
  Serial.println(floatValue);

  delay(1000); // delay a second between numbers
  chrValue++;  // to the next value
  byteValue++;
  intValue++;
  floatValue +=1;
}