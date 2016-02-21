
/* a
 _____
|f   |
|  g | b
|____|
|    |
|e   | c
|____|
   d
   
*/

//This 7-Segment display is connected in a common cathode configuration, therefore we are using negative logic (HIGH=No glow, LOW=glow)
int i;
int a = 0;
int b = 1;
int c = 2;
int d = 3;
int e = 4;
int f = 5;
int g = 6;

void setup(){
  for(i=0;i<7;i++){
    pinMode(i,OUTPUT); //For loop for-the-win! :)
  }
}

void clr(){
  for(i=0;i<7;i++){
    digitalWrite(i,HIGH);
  }
  delay(1);
}


void zero(){
  for(i=0;i<7;i++){
    if (i!=6){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void one(){
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  delay(999);
  clr();
}

void two(){
  for(i=0;i<7;i++){
    if (i!=2 && i!=5){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void three(){
  for(i=0;i<7;i++){
    if (i!=4 && i!=5){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void four(){
  for(i=0;i<7;i++){
    if (i!=0 && i!=3 && i!=4){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void five(){
  for(i=0;i<7;i++){
    if (i!=1 && i!=4){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void six(){
  for(i=0;i<7;i++){
    if (i!=1){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void seven(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  delay(999);
  clr();
}

void eight(){
  for(i=0;i<7;i++){
    digitalWrite(i,LOW);
  }
  delay(999);
  clr();
}

void nine(){
  for(i=0;i<7;i++){
    if (i!=4){
      digitalWrite(i,LOW);
    }
  }
  delay(999);
  clr();
}

void loop(){
  zero();one();two();three();four();five();six();seven();eight();nine();
}
