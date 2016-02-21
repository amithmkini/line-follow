int lfs = 2; //Left front sensor
int rfs = 3; //Right "      "
int i;
int lmb = 7; //Left motor back
int lmf = 8; //Left motor front
int rmb = 9; //Right motor back
int rmf = 10; //Right motor front
int ls = 4;
int rs = 5;
int str = 0;
int lcount = 0;
int rcount = 0;

void setup(){
  pinMode(lfs,INPUT);
  pinMode(rfs,INPUT);
  pinMode(lmb,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(rmf,OUTPUT);
}

void go_on(){
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,HIGH);
  delay(1);
}

void stop_it(){
  for(i=7;i<11;i++){
    digitalWrite(i,LOW);
  }
  delay(1000);
}
  
void straight(){
  if(digitalRead(lfs)==0 && digitalRead(rfs)!=0){
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    delay(1);
  }
  else if(digitalRead(lfs)!=0 && digitalRead(rfs)==0){
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,HIGH);
    delay(1);
  }
  else{
    go_on();
    delay(1);
  }
}

void left(){
  if(digitalRead(rs)==0){
    go_on();
    delay(50);
    stop_it();
    digitalWrite(rmf,HIGH);
    delay(2000);
  }
}

void right(){
  if(digitalRead(ls)==0){
    go_on();
    delay(50);
    stop_it();
    digitalWrite(lmf,HIGH);
    delay(2000);
  }
}
/*
int lt_count(){
  int lcount;
  if(digitalRead(rs)!=0 && digitalRead(ls)==0){
    lcount++;
  }
  delay(1);
  return lcount;
}

int rt_count(){
  int rcount;
  if(digitalRead(ls)!=0 && digitalRead(rs)==0){
    rcount++;
  }
  delay(1);
  return rcount;
}
*/

void loop(){
  digitalWrite(rmb,LOW);
  digitalWrite(lmb,LOW);
  straight();
  delay(1);
  if(digitalRead(lfs)==0 && digitalRead(rfs)==0){
    stop_it();
    if(lcount>rcount){
      left();
    }
    else if(rcount>lcount){
      right();
    }
    else{
      straight();
    }
    lcount=rcount=0;
  }
}
  
