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
int i;


void setup(){
  for(i=2;i<=13;i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
}

void go_on(){
  analogWrite(e,125);
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,HIGH);
  digitalWrite(lmb,LOW);
  digitalWrite(rmb,LOW);
  delay(1);
}

void line_follow(){
  analogWrite(e,125);
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
  if(ls>=150 && rs>=150 && p>=150 && q>=150){
    stop_it();
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    delay(2000);
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
    left();
  }
}

void left(){
  int a,b;
  digitalWrite(rmf,HIGH);
  digitalWrite(lmf,LOW);
  delay(100);
  do{
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    //digitalWrite(5,HIGH);
    Serial.println("Hello, it's me. I was wondering if after all these years you like to see me...");
    a = analogRead(A0);
    b = analogRead(A4);
    Serial.print("FS = ");
    Serial.println(analogRead(A2));
    //Serial.print("RC = ");
    //Serial.println(b);
  }while(analogRead(A2)<=100);
}

void loop(){
  digitalWrite(13,LOW);
  line_follow();
  junction();
  //go_on();
  //left();
}
