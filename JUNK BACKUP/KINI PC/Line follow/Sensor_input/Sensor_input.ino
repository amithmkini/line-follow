void setup(){
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  int x = digitalRead(2);
  if(x>0){
    digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,HIGH);
  }
}
