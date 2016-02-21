void setup(){
  Serial.begin(9600);
  for(int i=0; i<=13; i++)
    pinMode(i,OUTPUT);
}

double pid(int pos){
  double kp = 40;
  int setpoint = 2;
  return kp*(setpoint - pos);
}

int maxi(int *x){
  int large = *x;
  static int large_pos = 0;
 
  for(int i=0; i<5; i++){
    if(large < *(x+i)){
      large = *(x+i);
      large_pos = i;
    }
  }
  return large_pos;
}

void loop(){
  digitalWrite(8,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  int i;
  int (*val)[5];
  for(i=0; i<5; i++){
    (*val)[i] = analogRead(i);
    Serial.print(analogRead(i));
    Serial.print("   ");
  }
  Serial.println("");
  double x = pid(maxi(val[0]));
  analogWrite(10 ,100 - x);
  analogWrite(9,100 + x);
  //Serial.println(x);
  //delay(10);
  //pid(maxi(val[0]));
  delay(1);
}

