/*
enable = 11
 lmf = 10
 lmb = 12
 rmf = 9
 rmb = 8
 
 sensor analogous pins.
 digital pin - analog sensor no.
 2           -       0
 3           -       1
 4           -       2
 5           -       3
 6           -       4
 
 black >= 600
 white < 600
 */

int in[5];
const int enable = 11, lmf = 10,lmb = 12, rmf = 9, rmb = 8;

void setup(){
        for(int i=0; i<=13; i++)
          pinMode(i,OUTPUT);
        //Serial.begin(9600);
}
/*
void sensor_lights(){
        int x=0;
        digitalWrite(13,LOW);
        while(x < 5){
          if(in[x] >= 600)
            digitalWrite(x+2,HIGH);
          else
            digitalWrite(x+2,LOW);
          x++;
        }
}
*/
void get_input(){
        for(int i=0; i<5; i++){
          in[i] = analogRead(i);
          //Serial.print(in[i]);
          //Serial.print("   ");
        }
        //Serial.println();
        //sensor_lights();
}

void line_follow(){
        analogWrite(enable,255);
        
        if(in[2] >= 600 && in[3] < 600 && in[1] < 600){
          analogWrite(lmf,150);
          analogWrite(rmf,150);
          digitalWrite(lmb,LOW);
          digitalWrite(rmb,LOW);
        }
        else if(in[1] >= 600 && in[2] < 600 && in[3] < 600){
          //Left Turn
          digitalWrite(rmf,HIGH);
          digitalWrite(rmb,LOW);  
          digitalWrite(lmf,LOW);
          digitalWrite(lmb,HIGH);
        }
        else if(in[3] >= 600 && in[1] < 600 && in[2] < 600){
          //Right Turn
          digitalWrite(rmf,LOW);
          digitalWrite(rmb,HIGH);  
          digitalWrite(lmf,HIGH);
          digitalWrite(lmb,LOW);
        }
        else if((in[3] >= 600 && in[4] >= 600)&&(in[2] >= 600)){
          //Right Turn
          digitalWrite(rmf,LOW);
          digitalWrite(rmb,HIGH);  
          digitalWrite(lmf,HIGH);
          digitalWrite(lmb,LOW);
        }
        else if(in[3] >= 600 && in[4] >= 600){
          //Right Turn
          digitalWrite(rmf,LOW);
          digitalWrite(rmb,HIGH);  
          digitalWrite(lmf,HIGH);
          digitalWrite(lmb,LOW);
        }
        else if((in[0] >= 600 && in[1] >= 600)&&(in[2] >= 600)){
          //Left Turn
          digitalWrite(rmf,HIGH);
          digitalWrite(rmb,LOW);  
          digitalWrite(lmf,LOW);
          digitalWrite(lmb,HIGH);
        }
        else if(in[0] >= 600 && in[1] >= 600){
          //Left Turn
          digitalWrite(rmf,HIGH);
          digitalWrite(rmb,LOW);  
          digitalWrite(lmf,LOW);
          digitalWrite(lmb,HIGH);
        }
        else if(in[0] >= 600 && in[1] >= 600 && in[2] >= 600 && in[3] >= 600 && in[4] >= 600)
        	digitalWrite(enable,LOW);
        else{
          analogWrite(lmf,150);
          analogWrite(rmf,150);
          digitalWrite(lmb,LOW);
          digitalWrite(rmb,LOW);
        }
}

void loop(){
        get_input();
        line_follow();
}

