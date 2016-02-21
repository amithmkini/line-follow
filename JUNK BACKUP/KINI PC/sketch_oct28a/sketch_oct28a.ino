int lfs = A2; //Left front sensor
int rfs = A3; //Right "      "
int i;
int lmb = 7; //Left motor back
int lmf = 8; //Left motor front
int rmb = 9; //Right motor back
int rmf = 10; //Right motor front
int ls = A4;  //Left sensor
int rs = A5;  //Right sensor
int lcount = 0; //Left count
int rcount = 0; //Right count


void setup(){
}

void junction(){
  if(analogWrite(lfs)<1 && analogWrite(rfs)<1 && analogWrite(ls)<1 && analogWrite(rs)<1){ //Assuming all the 4 sensors are in the straight line
    //Do something here
    //Try calling the turning functions
  }
}

void counter(){
  //This is the trickiest part. Last time, it never worked for the straight condition but it was working for the left and the right condition. Weird!
  //Think different this time!
  //Think about the delay after adding it to the variable. 
