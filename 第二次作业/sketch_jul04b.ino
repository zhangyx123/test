void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  Serial.begin(9600);
}

int input;
int num=0;
int fu(int t);

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    input=Serial.read();
    input=input-48;

    for(num=0;num<4;num++)
    {
      if(input>=fu(3-num))
      {
        digitalWrite(5-num,HIGH);
        input=input-fu(3-num);
        }
      else
      {
        digitalWrite(5-num,LOW);
      }
      }
       
    delay(1000);
      
    }
}

int fu(int t)
{
  int sum=1;
  if(t==0)
  return 1;
  else
  {
    for(int i=0;i<t;i++)
    {
