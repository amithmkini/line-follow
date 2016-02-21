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


void setup(){
  for(i=2;i<=13;i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
}

void go_on(){
  analogWrite(e,255);
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,HIGH);
  digitalWrite(lmb,LOW);
  digitalWrite(rmb,LOW);
  delay(1);
}

void line_follow(){
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
    go_on();
    digitalWrite(6,HIGH);
    digitalWrite(4,HIGH);
    delay(1);
  }
}

void stop_it(){
  for(i=8;i<11;i++){
    digitalWrite(i,LOW);
  }
  digitalWrite(12,LOW);
  delay(1);
}

void junction(){
  int ls = analogRead(A0);
  int rs = analogRead(A4);
  int p = analogRead(A1);
  int q = analogRead(A3);
  if(ls>=100 && rs>=100 && p>=100 && q>=100){
    stop_it();
    //digitalWrite(trnled,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    delay(20);
    /*
    Serial.print("LC = ");
    Serial.println(ls);
    Serial.print("RC = ");
    Serial.println(ls);
    Serial.print("L = ");
    Serial.println(p);
    Serial.print("R = ");
    Serial.println(q);
    Serial.println("---------------");
    */
    right();
  }
}

void left(){
  int a,b;
  digitalWrite(rmf,HIGH);
  digitalWrite(lmf,LOW);
  delay(250);
  do{
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    digitalWrite(5,HIGH);
    //Serial.println("Hello, it's me. I was wondering if after all these years you like to see me...");
    a = analogRead(A0);
    b = analogRead(A4);
    Serial.print("FS = ");
    Serial.println(analogRead(A2));
    //Serial.print("RC = ");
    //Serial.println(b);
  }while(analogRead(A2)<=50);
  digitalWrite(5,LOW);
}
void right(){
  int a,b;
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,LOW);
  delay(500);
  do{
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(5,HIGH);
    //Serial.println("Hello, it's me. I was wondering if after all these years you like to see me...");
    //a = analogRead(A0);
    //b = analogRead(A4);
    //Serial.print("FS = ");
    //Serial.println(analogRead(A2));
    //Serial.print("RC = ");
    //Serial.println(b);
  }while(analogRead(A2)<=50);
  digitalWrite(5,LOW);
}

void counterglow()
{
  if(analogRead(A0)<=50)
    digitalWrite(7,HIGH);
  else
    digitalWrite(7,LOW);
  
  if(analogRead(A4)<=50)
    digitalWrite(3,HIGH);
  else
    digitalWrite(3,LOW);
}
void lccounter(){
  int a = analogRead(A0);
  int b = analogRead(A4);
  int c = analogRead(A2);
  if(a>=60&&b<=60){
    lc++;
    Serial.print("lc = ");
    Serial.println(lc);
    delay(500);
  }
}
void rccounter(){
  int b = analogRead(A4);
  int a = analogRead(A0);
  int c = analogRead(A2);
  if(b>=60&&a<=60)
  {
    rc++;
    Serial.print("rc = ");
    Serial.println(rc);
    delay(500);
  }
}

void loop(){
  digitalWrite(13,LOW);
  line_follow();
  junction();
  counterglow();
  lccounter();
  rccounter();
}
