/*
enable = 11
lmf = 10
lmb = GND
rmf = 9
rmb = GND

black > 400
white < 100
*/
int in[5];
char expr[100];
int ptop=0,optop=0;
char opst[100],post[100];

int stack[100];
int top=0;

int thresh = 400;

void setup(){
  for(int i=4; i<=13; i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
}

void get_input(){
  for(int i=0; i<5; i++){
    in[i] = analogRead(i);
  }
}

void line_follow(){
  analogWrite(11,255);
  if(in[2] > thresh && in[1] < thresh && in[3] < thresh){
    analogWrite(10,100);
    analogWrite(9,100);
  }
  else if(in[2] > thresh && in[1] > thresh && in[3] < thresh && in[0] > thresh){
    stop_it();
    do{
      analogWrite(10,0);
      analogWrite(9,150);
    }while(!(analogRead(1) < thresh && analogRead(2) > thresh && analogRead(3) < thresh));
  }
  else if(in[2] > thresh && in[1] > thresh && in[0] < thresh){
    analogWrite(10,0);
    analogWrite(9,200);
  }
   else if(in[2] > thresh && in[3] > thresh && in[4] > thresh){
    stop_it();
    do{
      analogWrite(10,150);
      analogWrite(9,0);
    }while(!(analogRead(1) < thresh && analogRead(2) > thresh && analogRead(3) < thresh));
  }
   else if(in[2] > thresh && in[1] < thresh && in[3] > thresh && in[4] < thresh){
    analogWrite(10,200);
    analogWrite(9,0);
  }
  else if(in[2] < thresh && in[1] > thresh && in[3] < thresh){
    analogWrite(10,0);
    analogWrite(9,200);
  }
   else if(in[2] < thresh && in[1] < thresh && in[3] > thresh){
    analogWrite(10,200);
    analogWrite(9,0);
  }
  else{
    analogWrite(10,100);
    analogWrite(9,100);
    
  }
}
void stop_it(){
  analogWrite(10,0);
  analogWrite(9,0);
  delay(100);
}

void count(){
  if(digitalRead(2)==HIGH && analogRead(2) > thresh && analogRead(0) < thresh && analogRead(4) < thresh){
   left_detect();
   delay(350);
  }
  if(digitalRead(3)==HIGH && analogRead(2) > thresh && analogRead(4) < thresh && analogRead(0) < thresh){
    right_detect();
    delay(350);
  }
}

int prev_turn = 0, sys = 0, flag=0, i=0;
char ans[100];
int flag_char_int = 1;  //0 implies op to be read, 1 implies number to be read
char sign[] = {'+', '-', '*', '/'};
char bi[] = {'1', '2'};
char oct[] = {'1', '8'};

void left_detect(){
  Serial.println("Left");
  if (flag_char_int == 0) {
      if (prev_turn == 0)     expr[i++] = '-';
      else    expr[i++] = '/';
      flag_char_int = 1;
  }else{
      if (sys == 0)   {  expr[i++] = bi[1]; Serial.println("Binary");}
      else   { expr[i++] = oct[1]; Serial.println("Octal"); }
      flag_char_int = 0;
  }
  Serial.println(expr[i-1]);
}
void right_detect(){
  Serial.println("Right");
  if (flag_char_int == 0) {
      if (prev_turn == 0)     expr[i++] = '+';
      else    expr[i++] = '*';
      flag_char_int = 1;
  }else{
      if (sys == 0){     expr[i++] = bi[0]; Serial.println("Binary");}
      else   { expr[i++] = oct[0]; Serial.println("Octal");}
      flag_char_int = 0;
  }
  Serial.println(expr[i-1]);
}

void trailblaaze(){

    if (flag == 0 )  sys = 0; 
    else  sys = 1;

    //01 -> right detect
    //10 -> left detect
    //
    // if (prev_turn == 0){
    //     //01 -> +
    //     //10 -> -
    //
    // }
    // else{
    //     //01 -> *
    //     //10 -? /
    // }
    //
    // if (sys == 0){
    //     //01 = 1
    //     //10 = 2
    // }
    // else{
    //     //01 = 1
    //     //10 = 8
    // }

    if (in[0] > thresh && in[1] > thresh && in[2] > thresh || in[4] > thresh && in[3] > thresh && in[2] > thresh){
        if (flag == 0)  flag = 1;
        else flag =  0;
        if (in[4] > thresh)  prev_turn = 1;
        else  prev_turn = 0;
    }

}

void loop(){
  get_input();
  line_follow();
  trailblaaze();
  count();
  stop_it_final();
}

//The infix to postfix converter - Akshay

void push(char e){
 post[ptop]=e;
 ptop++;
}


void pushop(char e){
 opst[optop]=e;
 optop++;
}

void pop(){
 optop--;
}

int prec(char c){
 switch(c){
  case '^':return 5;
           break;
  case '*':return 4;
           break;
  case '/':return 4;
           break;
  case '+':return 3;
           break;
  case '-':return 3;
           break;
 }
}

void infix2postfix(char expr[100]){
  int i,x,y;
  char n;

  for(i=0;expr[i]!='\0';++i){ 
    if(!(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'||expr[i]=='^'))
      push(expr[i]);
    else{
      x=prec(expr[i]);
      y=prec(opst[optop-1]);

      if(optop==0||x>y){
        pushop(expr[i]);
      }
      else{
        while(x<=y){
          push(opst[optop-1]);
          pop();
          y=prec(opst[optop-1]);
        }
        pushop(expr[i]);
      }
    }
  }

  for(i=optop-1;i>=0;--i){
    push(opst[i]);
    pop();
  }
  post[ptop]='\0';
}

// postfix eval

void postpush(int c){
 stack[top]=c;
 top++;
}

void postpop(){
 top--;
}

int asccon(char c){
  return c-48;
}

void postfixeval(char post[100]){
  int i;

  for(i=0;post[i]!='\0';++i){
    if(!(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^'))
      postpush(asccon(post[i]));
    else{
      switch(post[i]){
        int x,temp;
        case '^': temp=stack[top-1];
                  x=stack[top-2];
                  while(temp-1){
                    x*=stack[top-2];
                    --temp;
                  }
                  postpop();
                  postpop();
                  postpush(x);
                  break;
        case '*': x=(stack[top-2]*stack[top-1]);
                  postpop();
                  postpop();
                  postpush(x);
                  break;
        case '/': x=(stack[top-2]/stack[top-1]);
                  postpop();
                  postpop();
                  postpush(x);
                  break;
        case '+': x=(stack[top-2]+stack[top-1]);
                  postpop();
                  postpop();
                  postpush(x);
                  break;
        case '-': x=(stack[top-2]-stack[top-1]);
                  postpop();
                  postpop();
                  postpush(x);
                  break;
      }
    }
  }
}

void runonce(){
  infix2postfix(expr);
  postfixeval(post);
  Serial.println();
  Serial.println(expr);
  Serial.print("ans = ");
  Serial.println(stack[0]);
}

void stop_it_final(){
  if (analogRead(5) < thresh){
    analogWrite(9,0);
    analogWrite(10,0);
    expr[i++] = '\0';
    runonce();
    delay(10000000);
  }
}

