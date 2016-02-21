int a;

void setup(){ 
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(13,LOW);
  a=analogRead(A4);
  Serial.println(a);
  if(a<50){ 
    digitalWrite(5,HIGH);
  }
  else{ 
    digitalWrite(5,LOW);
  }
}
