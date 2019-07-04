char* letters[] = {
  "*-","-***", "-*-*", "-**", "*", "**-", "--*","****", "**",
  "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*-",
  "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"
};
int dotDelay = 200;
int ledPin = 13;
String morse = "";
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);            
//  Serial.println(morse);
}

void loop()
{
  char ch;
  if (Serial.available()>0)       
  {
    ch = Serial.read();           
    if (ch >='97' && ch <='123')
    {
      morse += letters[ch - 'a'];
      flashSequence(letters[ch - 'a']);
    }
    else if(ch == ' ')
    {
      delay(dotDelay * 7);
    }
  }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0')
  {
    
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '*')
  {
    delay(dotDelay);
  }
  else
  {
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);
  Serial.println(morse);
}
