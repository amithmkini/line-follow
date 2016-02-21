int rmf=10;
int rmb=12;
int lmf=8;
int lmb=9;
int e=11;
int lcled=7;
int ltled=6;
int trnled=5;
int rtled=4;
int rcled=3;
int stpled=2;
int i,lc=0,rc=0;


//Does modular programming work when you have to do a lot of tasks at a time?
//It works only when the individual task is clearly segregated and not dependent on the other parts of the program...
//Think outside the box...

void setup(){
  for(i=2;i<=13;i++)
    pinMode(i,OUTPUT);
  //Serial.begin(9600);
}

void loop(){
  analogWrite(e,255);
  int p = analogRead(A1);
  int q = analogRead(A3);
  if(p>=40 && q<=40){
    digitalWrite(6,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else if(p<=40 && q>=40){
    digitalWrite(6,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else{
    analogWrite(e,255);
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(4,HIGH);
    delay(1);
  }
}
