//PATTERN of 3x3 LEDs USING 2 ARDUINOs
//HOPING THOSE 2 WORK WITH CO-OPERATION... (no not people, arduino boards)

/*
top
8blue 1white

mid
5red 4white

bottom
8green 1white


mera part yeh hain
top, mid-5 with fullstop


b111  b112  b113
b121  w122  b123
b131  b132  b133

r211.  w212   r213
w221.  r222.  w223
r231.  w232.  r233

g311  g312  g313
g321  w322  g323
g331  g332  g333

*/
void setup(){
   int i;
  for(i=0;i<=13;i++){
    pinMode(i,OUTPUT);
  } 
}

int b111=0;
int b112=1;
int b113=2;
int b121=3;
int w122=4;
int b123=5;
int b131=6;
int b132=7;
int b133=8;

int r211=9;
int w221=10;
int r231=11;
int w232=12;
int r222=13;

void diamondon(){
  digitalWrite(r222,HIGH);
  delay(1000);
  digitalWrite(w122,HIGH);
  digitalWrite(w221,HIGH);
  digitalWrite(w232,HIGH);
  delay(2000);
}

void diamondoff(){
  digitalWrite(w122,LOW);
  digitalWrite(w221,LOW);
  digitalWrite(w232,LOW);
  delay(5);
}

void cor1_on(){
 int j;
  for(j=0;j<=8;j++){
   if(j==4)
     continue;
     
   if(j%2==0)
     digitalWrite(j,HIGH);
   else
     digitalWrite(j,LOW);
  }
  delay(1500);
}

void cor1_off(){
 int j;
  for(j=0;j<=8;j++){
   if(j==4)
     continue;
    if(j%2!=0){ 
     digitalWrite(j,HIGH);
    }
    else
    digitalWrite(j,LOW);
  }
  delay(250);
}

void col11_on(){
  low();
  digitalWrite(0,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  delay(250);
}


void low(){
  int i;
  for(i=0;i<13;i++){
    digitalWrite(i,LOW);
  }
 delay(1);
}

void col21_on(){
  low();
  digitalWrite(r211,HIGH);
  digitalWrite(w221,HIGH);
  digitalWrite(r231,HIGH);
  delay(250);
  low();
  delay(1000);
}

void col13_on(){
  digitalWrite(b113,HIGH);
  digitalWrite(b123,HIGH);
  digitalWrite(b133,HIGH);
  delay(250);
  low();
}

void col12_on(){
  digitalWrite(b112,HIGH);
  digitalWrite(w122,HIGH);
  digitalWrite(b132,HIGH);
  delay(500);
  low();
}
  
void loop(){
  diamondon();diamondoff();cor1_on();cor1_off();col11_on();col21_on();col13_on();col12_on();
}
