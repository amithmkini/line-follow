int i=0;

void setup(){
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop(){
  int a = analogRead(A1);
  if(a>=60){
    i++;
    Serial.println(i);
    delay(1500);
  }
  Serial.print("Analog reading: ");
  Serial.println(a);
}
