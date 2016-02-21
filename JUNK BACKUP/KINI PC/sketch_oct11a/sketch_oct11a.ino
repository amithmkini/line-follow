int lfs = 2; //Left front sensor
int rfs = 3; //Right "      "
int i;
int lmb = 7; //Left motor back
int lmf = 8; //Left motor front
int rmb = 9; //Right motor back
int rmf = 10; //Right motor front
int ls = A4;  //Left sensor
int rs = A5;  //Right sensor
int str = 0; //??
int lcount = 0; //Left count
int rcount = 0; //Right count

void setup(){
  pinMode(lfs,INPUT);
  pinMode(rfs,INPUT);
  pinMode(lmb,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(rmf,OUTPUT);
  Serial.begin(9600);
}

void counter(){ 
  int d = analogRead(ls);
  int e = analogRead(rs);
  if(d==0){
    lcount++;
    Serial.println(d);
    Serial.print("L = ");
    Serial.println(lcount);
  }
  else if(e==0){
    rcount++;
    Serial.println(e);
    Serial.print("R = ");
    Serial.println(rcount);
  }
  delay(1000);
}

void loop(){
  counter();
}
