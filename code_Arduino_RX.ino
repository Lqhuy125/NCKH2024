// Motor A connections Right
const int enA = 11; 
const int in1 = 10; 
const int in2 = 9; 

// Motor B connections Left
const int enB = 6; //Trái
const int in3 = 7; 
const int in4 = 8; 

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(in1, OUTPUT); //in1 = 1 tiến
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); //in3 = 1 tiến
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(enA, 200);
  // digitalWrite(in1, 1);
  // digitalWrite(in2, 0);

  // analogWrite(enB, 200);
  // digitalWrite(in3, 1);
  // digitalWrite(in4, 0);

  while (Serial.available() >= 0) {
    char receivedData = Serial.read();   // read one byte from serial buffer and save to receivedData
    Serial.print(receivedData);
    //a: trai nhieu b:trai it d: phai nhieu e:phai it
    Serial.print("\n");
    if (receivedData == 'A') {
      re_trai_2();
      delay(1000);
    }
    else if (receivedData == 'B') {
      re_phai_1();
      delay(1000);
    }
    else if (receivedData == 'D') {
      re_trai_2();
      delay(1000);
    }
    else if (receivedData == 'E') {
      re_phai_1();
      delay(1000);
    }
    else
    {
      di_thang();
    }
  }
}


void di_thang(){
  analogWrite(enA, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  analogWrite(enB, 200);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

//Re trai it
void re_trai_1(){
  //Phải tiến nhiều
  analogWrite(enA, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  //Trái tiến ít
  analogWrite(enB, 100);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

//Re trai nhieu
void re_trai_2(){
  //Phải tiến
  analogWrite(enA, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  //Trai dừng hẳn
  analogWrite(enB, 0); 
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void re_phai_1(){
  //Trái tiến ít
  analogWrite(enA, 100);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  //Trái tiến nhiều
  analogWrite(enB, 200);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void re_phai_2(){
  //Phải tiến
  analogWrite(enA, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  //Trái tiến
  analogWrite(enB, 200); 
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

