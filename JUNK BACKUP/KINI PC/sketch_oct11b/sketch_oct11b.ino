int ls = A4;
int rs = A5;
int a = 0;
int lc = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  a = analogRead(ls);
  if(a==0){
    lc++;
    Serial.print("L= ");
    Serial.println(lc);
  }
  delay(1000);
}
