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
        Serial.println("");
}

void line_follow(){
	//PID
	static double kp, ki, kd, error=0, prev_error=0;
	digitalWrite(12,LOW);
	digitalWrite(8,LOW);

	analogWrite(11,150);
	
	
	
	prev_error = error;
	analogWrite(10,127.5-error);
	analogWrite(9,127.5-error);
}

void loop(){
	get_input();
        //sensor_lights();
	line_follow();
        sensor_lights();
}
