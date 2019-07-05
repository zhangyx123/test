#include "Arduino.h"


void morse(int pin);
void dot();
void dash();
void w_space();
void s_space();



int l[28][4]={

// A to I

{1,2,0,0},{2,1,1,1},{2,1,2,1},{2,1,1,0},{1,0,0,0},{1,1,2,1},{2,2,1,0},{1,1,1,1},{1,1,0,0},

// J to R 

{1,2,2,2},{2,1,2,0},{1,2,1,1},{2,2,0,0},{2,1,0,0},{2,2,2,0},{1,2,2,1},{2,2,1,2},{1,2,1,0},

// S to Z

{1,1,1,0},{2,0,0,0},{ 1,1,2,0},{1,1,1,2},{1,2,2,0},{2,1,1,2},{2,1,2,2},{2,2,1,1 },{3,0,0,0},{4,0,0,0}

};



void setup()

{

  morse (13);  

  Serial.begin(9600);
  Serial.print('\n');

  

}


int _pin;
int lag;


//*-** *---****

void loop()

{

  while(Serial.available() > 0 )

  {

  int ascii=Serial.read();

 

  ascii=ascii-97;



  for(int i=0;i<4;i++)

  {

    if(l[ascii][i]==1)

    {

      dot();

      Serial.print('*');

      }

    else if(l[ascii][i]==2)

    {

      dash();

      Serial.print('_');

      }

    else if(l[ascii][i]==3)

    {

      c_space();

      Serial.print(' ');

      }

    else if(l[ascii][i]==4)

    {

      w_space();

      Serial.print('\n');

      }

  }

  delay(3000);

  Serial.print('@');
  }



}




void morse(int pin)

{

  pinMode(pin,OUTPUT);

  _pin=pin;

  lag=250;

}



void dot()

{

  digitalWrite(_pin,HIGH);

    delay(lag);

  digitalWrite(_pin,LOW);

  delay(lag);

}



void dash()

{

  digitalWrite(_pin,HIGH);

  delay(lag*4);

  digitalWrite(_pin,LOW);

  delay(lag);

}



void c_space()

{

  digitalWrite(_pin,LOW);

  delay(lag*3);

}



void w_space()

{

  digitalWrite(_pin,LOW);

  delay(lag*7);

}
