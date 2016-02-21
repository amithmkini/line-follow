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

void setup(){
	for(int i=0; i<=13; i++)
		pinMode(i,OUTPUT);
        Serial.begin(9600);
}

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

void get_input(){
	for(int i=0; i<5; i++){
		in[i] = analogRead(i);
                Serial.print(in[i]);
                Serial.print("   ");
        }
        Serial.println();
        sensor_lights();
}

void line_follow(){
	digitalWrite(12,LOW);
	digitalWrite(8,LOW);

	analogWrite(11,150);

	if(in[2] >= 600 && in[3] < 600 && in[1] < 600){
		analogWrite(10,65);
		analogWrite(9,65);
	}
	else if(in[1] >= 600 && in[2] < 600 && in[3] < 600){
		analogWrite(10,20);
		analogWrite(9,130);
	}
        else if(in[3] >= 600 && in[1] < 600 && in[2] < 600){
		analogWrite(10,130);
		analogWrite(9,20);
	}
	else if((in[3] >= 600 && in[4] >= 600)&&(in[2] >= 600)){
		digitalWrite(10,HIGH);
		digitalWrite(9,LOW);
	}
	else if(in[3] >= 600 && in[4] >= 600){
		digitalWrite(10,HIGH);
		digitalWrite(9,LOW);
	}
	else if((in[0] >= 600 && in[1] >= 600)&&(in[2] >= 600)){
		digitalWrite(10,LOW);
		digitalWrite(9,HIGH);
	}
	else if(in[0] >= 600 && in[1] >= 600){
		digitalWrite(10,LOW);
		digitalWrite(9,HIGH);
	}
	//else if(in[0] >= 600 && in[1] >= 600 && in[2] >= 600 && in[3] >= 600 && in[4] >= 600)
	//	digitalWrite(11,LOW);
	else{
		analogWrite(10,65);
		analogWrite(9,65);
	}
}

void loop(){
	get_input();
	line_follow();
}
