int p,q;
int lmb = 8;
int lmf = 7;
int rmb = 10;
int rmf = 9;
int enable = 3;
int rcount=0;
int i;  

void setup(){
  pinMode(lmb,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(rmf,OUTPUT);
  pinMode(enable,OUTPUT);
  Serial.begin(9600);
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
  p = analogRead(A4);
  q = analogRead(A5);
  if(q==0 && p!=0){
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    digitalWrite(lmb,LOW);
    digitalWrite(rmb,LOW);
    delay(1);
  }
  else if(p==0 && q!=0){
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
  int lfs = analogRead(A4);
  int rfs = analogRead(A5);
  int ls = analogRead(A2);
  int rs = analogRead(A3);
  if(lfs==0 && rfs==0 && ls==0 && rs==0){
    stop_it();
    delay(1000);
    left();
  }
}

void left(){
  analogWrite(enable,50);
  int lfs = analogRead(A4);
  int rfs = analogRead(A5);
  int rcount=0;
  
  
    do{ 
      digitalWrite(rmf,LOW);
    digitalWrite(lmf,HIGH);
    
  /*int rrc=analogRead(A3);
  
    if(rrc==0)
      rcount++;
      
      Serial.print("Countt = ");
      Serial.println(rcount);
  
  */  
  }while(lfs!=0 );
  line_follow();
  
   }

void loop(){
  
  line_follow();
  junction();
  
}
