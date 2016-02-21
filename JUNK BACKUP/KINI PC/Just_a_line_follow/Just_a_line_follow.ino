int p,q,r,s;
int rmb = 8;
int rmf = 7;
int lmb = 10;
int lmf = 9;
int enable = 3;
int i;
int lfs = A4;
int rfs = A5;
int ls = A2;
int rs = A3;

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
  p = analogRead(lfs); //Left sensor
  q = analogRead(rfs); //Right sensor
  if(q!=0 && p==0){
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else if(p!=0 && q==0){
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,HIGH);
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

//A3-Left A2-Right

void junction(){
  int e = analogRead(lfs);
  int f = analogRead(rfs);
  int g = analogRead(ls);
  int h = analogRead(rs);
  if(e==0 && f==0 && g==0 && h==0){
    stop_it();
    delay(5000);
    //left();
  }
}

/*
void left(){
  int count=0;
  int rc=analogRead(A2);
  do{
    if(rc==0){
      count++;
    }
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,HIGH);
    delay(50);
  }while(count < 2);
  do{
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
  }while(rc>0);
}
*/



void loop(){
  analogWrite(enable,100);
  line_follow();
  junction();
}
