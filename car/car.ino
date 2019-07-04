void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
int invalue=0;
void loop()
{
	if(Serial.available()>0)
    {
    	invalue=Serial.read();
      	switch(invalue)
        {
        	case 'w':
          		qianjin();
          		break;
          	case 's':
          		houtui();
          		break;
          	case 'a':
          		left();
          		break;
          	case 'd':
          		right();
          		break;
          	case ' ':
          		zanting();
          		break;
        }
    }
}

void qianjin()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void houtui()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void left()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}


void right()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void zanting()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
}
