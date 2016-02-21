int p,q;
int lmb = 10;
int lmf = 9;
int rmb = 8;
int rmf = 7;
int enable = 3;
int i;

void setup(){
  pinMode(lmb,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(rmf,OUTPUT);
  pinMode(enable,OUTPUT);
}

void go_on(){
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,HIGH);
  digitalWrite(lmb,LOW);
  digitalWrite(rmb,LOW);
  delay(1);
}

void line_follow(){
  analogWrite(enable,125);
  p = analogRead(A4); //Left sensor
  q = analogRead(A5); //Right sensor
  if(q==0 && p!=0){
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else if(p==0 && q!=0){
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else{
    go_on();
    delay(1);
  }
}

void stop_it(){
  for(i=7;i<11;i++){
    digitalWrite(i,LOW);
  }
  delay(1);
}

void junction(){
  int lfs = analogRead(A4);
  int rfs = analogRead(A5);
  int ls = analogRead(A2);
  int rs = analogRead(A3);
  if(lfs==0 && rfs==0 && ls==0 && rs==0){
    stop_it();
    delay(1000);
    left();
    //right();
  }
}

//A1 - Front sensor

void left(){
  int fs;
  digitalWrite(lmf,LOW);
  digitalWrite(rmf,HIGH);
  delay(750);
  do{
    fs = analogRead(A1);
    digitalWrite(lmf,LOW);
    digitalWrite(rmf,HIGH);
  }while(fs!=0);
  stop_it();
}

void right(){
  int fs;
  digitalWrite(rmf,LOW);
  digitalWrite(lmf,HIGH);
  delay(750);
  do{
    fs = analogRead(A1);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,HIGH);
  }while(fs!=0);
  stop_it();
}

void loop(){
  line_follow();
  junction();
}
