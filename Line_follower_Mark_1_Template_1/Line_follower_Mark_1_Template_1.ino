/*
enable = 
lmf = 
lmb =
rmf = 
rmb = 

sensor analogous pins.

digital pin - analog sensor no.
           -       0
           -       1
           -       2
           -       3
           -       4


black >= 200
white < 200
*/

int in[5];

void setup(){
	for(int i=0; i<=13; i++)
		pinMode(i,OUTPUT);
}

void sensor_lights(){
        int x=0;
        while(x < 5){
                if(in[x] >= 200)
                        digitalWrite(//corresponding digital pin,HIGH);
                else
                        digitalWrite(//corresponding digital pin,LOW);
        }
}

void get_input(){
	for(int i=0; i<5; i++)
		in[i] = analogRead(i);
        sensor_lights();
}

void line_follow(){
	digitalWrite(//lmb,LOW);
	digitalWrite(//rmb,LOW);
	digitalWrite(//enable,HIGH);
	
	if(in[2] >= 200 && in[3] < 200 && in[1] < 200){
		analogWrite(//lmf,125);
		analogWrite(//rmf,125);
	}
	else if(in[1] >= 200 && in[2] < 200 && in[3] < 200){
		analogWrite(//lmf,25);
		analogWrite(//rmf,175);
	}
	else if(in[3] >= 200 && in[1] < 200 && in[2] < 200){
		analogWrite(//lmf,175);
		analogWrite(//rmf,25);
	}
	else if(in[3] >= 200 && in[4] >= 200){
		digitalWrite(//lmf,HIGH);
		digitalWrite(//rmf,LOW);
	}
	else if(in[0] >= 200 && in[1] >= 200){
		digitalWrite(//lmf,LOW);
		digitalWrite(//rmf,HIGH);
	}
	else if(in[0] >= 200 && in[1] >= 200 && in[2] >= 200 && in[3] >= 200 && in[4] >= 200)
		digitalWrite(//enable,LOW);
	else{
		/*
		analogWrite(//lmf,125);
		analogWrite(//rmf,125);
		*/
	}
}

void loop(){
	get_input();
	line_follow();
}
