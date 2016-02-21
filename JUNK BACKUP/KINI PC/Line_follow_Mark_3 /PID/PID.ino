int rmf=9;
int rmb=8;
int lmf=10;
int lmb=12;
int e=11;/*
int lcled=7;
int ltled=6;
int trnled=5;
int rtled=4;
int rcled=3;
int stpled=2;*/
int i,lc=0,rc=0;
long sensors_average;
int sensors_sum;
int pos;
long sensors[]={0,0,0,0,0};
int set_point=2,max_speed=125;
double K1=40,K2=0,K3=0,prop,last_prop=0,integral=0,derivative,error=0;

void setup(){
  for(i=2;i<=13;i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
}

void calculations(){
  sensors_sum=0;
  sensors_average=0;
  sensors[0] = analogRead(A0);
  sensors[1] = analogRead(A1);
  sensors[2] = analogRead(A2);
  sensors[3] = analogRead(A3);
  sensors[4] = analogRead(A4);
  for(int i=0;i<5;i++){
    if(sensors[i]<100)
      sensors[i]=0;
    else
      sensors[i]=500;

    sensors_average+=sensors[i]*i;
    sensors_sum+=int(sensors[i]);
  }
  pos=sensors_average/sensors_sum;
  /*Serial.print(sensors_average);
  Serial.print("\t");
  Serial.print(sensors_sum);     
  Serial.print("\t");
  Serial.print(pos);
  Serial.println("");*/
  delay(50);
  prop=pos-set_point;
  integral+=prop;
  derivative=prop-last_prop;
  last_prop=prop;
  error=prop*K1+integral*K2+derivative*K3;
}
void turn(){
  if(error<-250)
    error=-250;
  
  if(error>250)
    error=250;
    
  if(error>=0){
    analogWrite(lmf,max_speed+error);
    analogWrite(rmf,max_speed-error);
  }
  else{
    analogWrite(rmf,max_speed-error);
    analogWrite(lmf,max_speed+error); 
  }
}
/*
void led_glow(){
  if(analogRead(A0)<50)
  {digitalWrite(7,HIGH);}
  else
  {digitalWrite(7,LOW);}
  
  if(analogRead(A1)<50)
  {digitalWrite(6,HIGH);}
  else
  {digitalWrite(6,LOW);}
  
  if(analogRead(A2)<35)
  {digitalWrite(5,HIGH);}
  else
  {digitalWrite(5,LOW);}
  
  if(analogRead(A3)<50)
  {digitalWrite(4,HIGH);}
  else
  {digitalWrite(4,LOW);}
  
  if(analogRead(A4)<50)
  {digitalWrite(3,HIGH);}
  else
  {digitalWrite(3,LOW);}
}
*/
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
    delay(5000);
    //digitalWrite(trnled,HIGH);
    /*digitalWrite(4,LOW);
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
    //right();
    if(lc>rc)
    {
        left();lc=0;rc=0;
    }
    else if(rc>lc)
    {
        right();lc=0;rc=0;
    }
    else
    {
        lc=0;rc=0;calculations();
    }
  }
}

void left(){
  int a,b;
  digitalWrite(rmf,HIGH);
  digitalWrite(lmf,LOW);
  delay(500);
  do{
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,LOW);
    digitalWrite(5,HIGH);
    a = analogRead(A0);
    b = analogRead(A4);
    Serial.print("FS = ");
    Serial.println(analogRead(A2));
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
  }while(analogRead(A2)<=100);
  digitalWrite(5,LOW);
}
void lccounter(){
  int a = analogRead(A0);
  int b = analogRead(A4);
  int c = analogRead(A2);
  if(a>=60){
    lc++;
    Serial.print("lc = ");
    Serial.println(lc);
    delay(100);
  }
}
void rccounter(){
  int b = analogRead(A4);
  int a = analogRead(A0);
  int c = analogRead(A2);
  if(b>=60)
  {
    rc++;
    Serial.print("rc = ");
    Serial.println(rc);
    delay(100);
  }
}

  
void loop(){
  analogWrite(e,200);
  digitalWrite(rmb,LOW);
  digitalWrite(lmb,LOW);
  calculations();
}
