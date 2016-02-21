void setup(){
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

int count = 0;
int a;

void loop(){
  a = digitalRead(2);
  if(a>0){
    count++;
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  Serial.print(count);
  Serial.println("\t");
  delay(1000);
}

