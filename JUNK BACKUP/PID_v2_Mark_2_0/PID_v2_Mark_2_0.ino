//Code includes weighted mean calculation &  mark1 + kd_calc.
//Use either one only
//There seems to be a problem with weighted mean calculation. Until then use the latter

double error = 0,last_error = 0, kp = 20, kd = 0;

void setup(){
  Serial.begin(9600);
  for(int i=0; i<=13; i++)
    pinMode(i,OUTPUT);
}


double pid(int pos){
  return (pos - 2);
}

int maxi(int *x){
  int large = *x;
static  int large_pos=0;
 
  for(int i=0; i<5; i++){
    if(large < *(x+i)){
      large = *(x+i);
      large_pos = i;
    }
  }
  return large_pos;
}

void loop(){
  double sum = 0, wsum = 0;
  digitalWrite(8,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  int i,in;
  int *val[5];
  for(i=0; i<5; i++){
    *(val[i]) = analogRead(i);
    /*
    Serial.print(analogRead(i));
    Serial.print("   ");
    Serial.print(analogRead(i));
    Serial.print("   ");
    in = analogRead(i);
    wsum += (i * in);
    sum += in;
    */
  
  /*
  Serial.print("                         ");
  Serial.print(wsum);
  Serial.print("   ");
  Serial.print(sum);
  Serial.print("   ");
  Serial.print(wsum/sum);    */
  }
  
 
  if(((*val)[0] >= 650 && (*val)[1] >= 650) || ((*val)[3] >= 650 && (*val)[4] >= 650)){
    Serial.println("TEST");
    delay(500);
  }
  
  
  error = pid(maxi(val[0]));
  //error = wsum/sum - 2;
  
  double x = kp*error + kd*(error - last_error);
  last_error = error;
  
  /*
  Serial.print("                 ");
  Serial.print(x);
  Serial.print("   ");
  Serial.print(error);
  Serial.println("");
  */
  
  analogWrite(9,75 - x);
  analogWrite(10,75 + x);
  
  //Serial.println(maxi(val[0]));
}
