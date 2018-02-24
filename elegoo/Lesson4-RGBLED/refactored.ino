#define BLUE 3
#define GREEN 5
#define RED 6

#define R 0
#define G 1
#define B 2

#define delayTime 10

int colors[3] = {0,0,0};
int other = 0;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

int translate(int color) {
  int translation = 0;
  switch (color) {
    case 0:
      translation = 6;
      break;
    case 1:
      translation = 5;
      break;
    case 2:
      translation = 3;
      break;
  }
  return translation;
}

void loop()
{
  #define delayTime 10 // fading time between colors

  for (int i = 0; i < 3; i++) {
    colors[0] = colors[1] = colors[2] = 0;
    colors[i] = 255;
    other = (i + 1) % 3;
    for (int j = 0; j < 255; j++) {
      colors[i] -= 1;
      colors[other] +=1;
      analogWrite(translate(i), colors[i]);
      analogWrite(translate(other), colors[other]);
      delay(delayTime);
    }   
  }
}
