#include <Servo.h>

//Servo doorServo;
Servo fingerServo;

int swPin = 8;

int pos = 0;
int selectedMove = 0;             //move selector

void setup()
{
  pinMode (13, OUTPUT); //para ver cuándo se activa el switch
  pinMode(swPin, INPUT);
  //  doorServo.attach(9);           //set door servo on Pin 9 pwm
  fingerServo.attach(10);          //set finger servo on Pin 10 pwm
  //  doorServo.write(80);           //set door to hiding position
  fingerServo.write(130);            //set finger to hiding position
}


void loop() {

  //if the switch is on, move door and finger to switch it off
  if (digitalRead(swPin) == 1) {
    digitalWrite (13, HIGH);
    if (selectedMove > 9) {
      selectedMove = 0;
    } //when all moves are played, repeat the moves from beginning

    if (selectedMove == 0) {
      simpleClose();
    }
    else if (selectedMove == 1) {
      simpleClose();
    }
    else if (selectedMove == 2) {
      simpleClose2();
    }
    else if (selectedMove == 3) {
      crazydoor();
    }
    else if (selectedMove == 4) {
      slow();
    }
    else if (selectedMove == 5) {
      serious();
    }
    else if (selectedMove == 6) {
      trollClose();
    }
    else if (selectedMove == 7) {
      simpleClose();
    }
    else if (selectedMove == 8) {
      matrix();
    }
    else if (selectedMove == 9) {
      sneak();
    }

    selectedMove += 1;         //swith to next move

  }
  else {
    digitalWrite (13, LOW);
  }
}

void casa(){  //vuelve a home
  for (pos = 0; pos < 129; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
}

// Moves

// basic move
void simpleClose()
{
  //mueve el servo hasta el switch
  for (pos = 129; pos >= 0; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  casa();
}

// open and wait, then move finger and wait, then switch of and hide
void simpleClose2()
{
  for (pos = 129; pos >= 0; pos -= 5) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(1000);
  for (pos = 100; pos < 129; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
  for (pos = 0; pos < 100; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
}

//open door then close it many times, wait, then quickly reopen, switch off and hide.

void crazydoor()
{
  for (pos = 129; pos >= 0; pos -= 3) {
    fingerServo.write(pos);
    delay(15);
  }
  for (pos = 0; pos < 129; pos += 3) {
    fingerServo.write(pos);
    delay(15);
  }
}

//open door,move finger very slowly forward and back to hiding very slowly, then quickly close door
void slow()
{
  for (pos = 129; pos >= 0; pos -= 1) {
    fingerServo.write(pos);
    delay(30);
  }
  for (pos = 0; pos < 129; pos += 1) {
    fingerServo.write(pos);
    delay(30);
  }
}

//serious

void serious() {
  for (pos = 129; pos >= 0; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  for (pos = 40; pos < 129; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }

  fingerServo.write(40);
  delay(1000);

  for (pos = 0; pos < 70; pos += 1) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(800);
}


void trollClose() {
  for (pos = 127; pos >= 0; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  for (pos = 0; pos < 127; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
}

void matrix()
{
  for (pos = 129; pos >= 0; pos -= 4) {
    fingerServo.write(pos);
    delay(10);
  }
  delay(300);
  for (pos = 80; pos < 129; pos += 1) {
    fingerServo.write(pos);
    delay(30);
  }
  for (pos = 0; pos < 80; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
}

void sneak()
{

  for (pos = 129; pos >= 0; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  for (pos = 70; pos < 129; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(100);
  for (pos = 90; pos >= 70; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(100);
  for (pos = 70; pos < 90; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(100);
  for (pos = 90; pos >= 70; pos -= 4) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(500);
  for (pos = 40; pos < 90; pos += 4) {
    fingerServo.write(pos);
    delay(15);
  }
  delay(500);
  for (pos = 0; pos < 40; pos += 1) {
    fingerServo.write(pos);
    delay(30);
  }
  casa();
}
