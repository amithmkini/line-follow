int i;
int w212 = 0;
int r213 = 1;
int w223 = 2;
int r233 = 3;

int g311 = 4;
int g312 = 5;
int g313 = 6;
int g321 = 7;
int w322 = 8;
int g323 = 9;
int g331 = 10;
int g332 = 11;
int g333 = 12;

void setup(){
  /*
  pinMode(w212,OUTPUT);
  pinMode(r213,OUTPUT);
  pinMode(w223,OUTPUT);
  pinMode(r233,OUTPUT);
  pinMode(g311,OUTPUT);
  pinMode(g312,OUTPUT);
  pinMode(g313,OUTPUT);
  pinMode(g321,OUTPUT);
  pinMode(w322,OUTPUT);
  pinMode(g323,OUTPUT);
  pinMode(g331,OUTPUT);
  pinMode(g332,OUTPUT);
  pinMode(g333,OUTPUT);
  */
  for(i=0;i<13;i++){
    pinMode(i,OUTPUT);
  }
}

void diamondon(){
  delay(1020);
  digitalWrite(w212,HIGH);
  digitalWrite(w223,HIGH);
  digitalWrite(w322,HIGH);
  delay(2000);
  low();
  delay(5);
}

void low(){
  for(i=0;i<13;i++){
    digitalWrite(i,LOW);
  }
  delay(1);
}

void cor3_on(){
  digitalWrite(g311,HIGH);
  digitalWrite(g331,HIGH);
  digitalWrite(g313,HIGH);
  digitalWrite(g333,HIGH);
  delay(1500);
  low();
  delay(750);
}

void col31_on(){
  digitalWrite(g311,HIGH);
  digitalWrite(g321,HIGH);
  digitalWrite(g331,HIGH);
  delay(250);
  low();
}

void col32_on(){
  digitalWrite(g312,HIGH);
  digitalWrite(w322,HIGH);
  digitalWrite(g332,HIGH);
  delay(250);
  low();
}

void col33_on(){
  digitalWrite(g313,HIGH);
  digitalWrite(g323,HIGH);
  digitalWrite(g333,HIGH);
  delay(250);
  low();
}

void col23_on(){
  digitalWrite(r213,HIGH);
  digitalWrite(w223,HIGH);
  digitalWrite(r233,HIGH);
  delay(250);
  low();
}

void loop(){
  diamondon();cor3_on();col31_on();col32_on();col33_on();col23_on();delay(750);
}
