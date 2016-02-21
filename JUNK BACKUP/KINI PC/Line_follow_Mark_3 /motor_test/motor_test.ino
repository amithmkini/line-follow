/*This is a motor testing code*/
int i;
int lmf = 8;
int lmb = 9;
int rmf = 10;
int rmb = 11;

void setup(){
  for(i=8;i<12;i++)
    pinMode(i,OUTPUT);
}

void loop(){
  analogWrite(3,255);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}
