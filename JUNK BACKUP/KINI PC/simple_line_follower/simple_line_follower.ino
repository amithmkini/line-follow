int lmf=8, lmb=7, rmf=10, rmb=9, lfs=2, rfs=3;
int b=0,c=0;

void setup() {

  pinMode(lfs,INPUT);
  pinMode(rfs,INPUT);
  pinMode(lmf,OUTPUT);
  pinMode(rmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(lmb,OUTPUT);
}

void loop(){
  
  b = (digitalRead(lfs));
  c = (digitalRead(rfs));
  
  if(b==HIGH && c==HIGH){
    	digitalWrite(lmf,HIGH);
    	digitalWrite(rmf,HIGH);
    	digitalWrite(lmb,LOW);
    	digitalWrite(rmb,LOW);
    	}
    //left turn
    
    	else if(c==HIGH && b==LOW){
    	digitalWrite(lmf,LOW);
    	digitalWrite(rmf,HIGH);
    	digitalWrite(lmb,LOW);
    	digitalWrite(rmb,LOW);
    	}
    //right turn
    
    	else if(b==HIGH && c==LOW){
    	digitalWrite(lmf,HIGH);
    	digitalWrite(rmf,LOW);
    	digitalWrite(lmb,LOW);
    	digitalWrite(rmb,LOW);
    	}
        else if(c==LOW && b==LOW){
        digitalWrite(lmf,LOW);
    	digitalWrite(rmf,LOW);
    	digitalWrite(lmb,LOW);
    	digitalWrite(rmb,LOW);
        delay(10000);
        
    }
}
