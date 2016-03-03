/*
enable = 11
lmf = 10
lmb = 3
rmf = 9
rmb = 5

sensor analogous pins.
digital pin - analog sensor no.
2           -       0
4           -       1
6           -       2
7           -       3
8           -       4

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

/*
void sensor_lights(){
        int x=0;

        if(in[0] >= 600)
                digitalWrite(2,HIGH);
        else
                digitalWrite(2,LOW);
                
        if(in[1] >= 600)
                digitalWrite(4,HIGH);
        else
                digitalWrite(4,LOW);
                
        if(in[2] >= 600)
                digitalWrite(6,HIGH);
        else
                digitalWrite(6,LOW);
                
        if(in[3] >= 600)
                digitalWrite(7,HIGH);
        else
                digitalWrite(7,LOW);
                
        if(in[4] >= 600)
                digitalWrite(8,HIGH);
        else
                digitalWrite(8,LOW);
                
}
*/

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
        
        
	analogWrite(11,150);
	
	static int flag = 0;
	
	if(!flag){
		setpoint = w_mean();
		flag = 1;
	}
	
	pos = w_mean();
	
	e_p = pos - setpoint;
	
	e_d = e_p - prev_e_p;

       // e_i = e_i + e_p;

  	error =   kp*e_p + ki*e_i + kd*e_d;
        
	prev_e_p = e_p;
        
        if(error>127.5)
                error = 127.5;
        if(error<-127.5)
                error = -127.5;
        /*
        if(error>=0)
        {
          analogWrite(10,127.5 + error);
          digitalWrite(9,LOW);
          digitalWrite(3,LOW);
          analogWrite(5,12.75 + (error*0.1));
        }
        else if(error<0)
        {
          analogWrite(9,127.5 - error);
          digitalWrite(10,LOW);
          digitalWrite(5,LOW);
          analogWrite(3,12.75 - (error*0.1));
        }
        */
                
	analogWrite(10, 127.5 + error);
	analogWrite(9, 127.5- error);
        analogWrite(5, 12.75-(error*0.1));
        analogWrite(3, 12.75-(error*0.1));

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
        //sensor_lights();
}
