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
double kp = 300, ki = 0, kd = 300, prev_e_p=0, e_p=0, e_i=0, e_d=0, error=0, setpoint = 0, pos = 0;

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
		//Serial.print(in[i]);
		//Serial.print("   ");
        }
//        Serial.println("");
}

double w_mean(){
	static double sum = 0, wsum = 0;
	sum = in[0] + in[1] + in[2] + in[3] + in[4];
	wsum = in[1] + 2*in[2] + 3*in[3] + 4*in[4];
	//wsum = 0*in[0] + 1*in[1] + 2*in[2] + 3*in[3] + 4*in[4];
        //wsum = -2*in[0] + (-1*in[1]) + 0*in[2] + 1*in[3] + 2*in[4];
	return wsum/sum;
}

void line_follow(){
	//PID
	digitalWrite(12,LOW);
	digitalWrite(8,LOW);

	analogWrite(11,150);
	
	static int flag = 0;
	
	if(!flag){
		setpoint = w_mean();
		flag = 1;
	}
	
	pos = w_mean();
	
	e_p = pos - setpoint;
	
	e_d = e_p - prev_e_p;

        //e_i = e_i + e_p;

  	error =   kp*e_p + ki*e_i + kd*e_d;
        
	prev_e_p = e_p;
        
        if(error>127.5)
                error = 127.5;
        if(error<-127.5)
                error = -127.5;
                
	analogWrite(10, 127.5 + error);
	analogWrite(9, 127.5 - error);

        Serial.print(pos);
        Serial.print("   ");
        Serial.println(error);
        //Serial.print("   ");
        //Serial.println(e_d);
}

void loop(){
	get_input();
        //sensor_lights();
	line_follow();
        sensor_lights();
}
