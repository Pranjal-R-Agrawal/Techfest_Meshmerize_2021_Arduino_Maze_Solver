/*MR Dir- 7
   MR PWM- 9
   ML Dir- 8
   ML PWM- 10
   RGB- 6,5,3

   Line sensor on A0,A1,A2,A3,A4
   A0-left & A4 - right
   Battery voltage check on A7
*/

const int startButton = 11;

bool l = 0;
bool r = 0;
bool s = 0;
bool u = 0;
int e = 0;
int paths = 0;

bool endFound = 0;

int blackValue = 900;
int whiteValue = 100;
int threshold = 650;
//int threshold = (blackValue + whiteValue) * 0.5;
int FT = 50;
int P, D, I, previousError, PIDvalue, error;
int lsp = 100;
int rsp = 100;
int lfspeed = 190;
int turnspeed;
float Kp = 0.04;
float Kd = 0.05;
float Ki = 0 ;

String str;

void setup() {
  Serial.begin(9600);
  pinMode(startButton, INPUT_PULLUP);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (3, OUTPUT); //blue
  pinMode (5, OUTPUT); //green
  pinMode (6, OUTPUT); //red
}

void loop() {
  while (digitalRead(startButton) == 1)
  { //Do nothing while waiting for button press
  }
  delay(300);

  while (endFound == 0)
  {
    linefollow();
    checknode();

    botstop();
    delay(90);

    reposition ();
  }

  for (int x = 0; x < 10; x++)
  {
    str.replace("RURUS", "U");
    str.replace("RUSUR", "U");
    str.replace("RUR", "S");
    str.replace("SUR", "L");
    str.replace("RUS", "L");
    str.replace("RUL", "U");
    str.replace("LUR", "U");
  }
  int endpos = str.indexOf('E');

  while (digitalRead(startButton) == 1)
  { //Do nothing while waiting for button press
  }
  
  lightsoff();
  delay(300);

  for (int i = 0; i <= endpos; i++)
  {
    char node = str.charAt(i);
    paths = 0;
    while (paths < 2)
    {
      linefollow();
      checknode();
      if (paths == 1)
      {
        botstop();
        delay(75);
        reposition();
      }
    }
    switch (node)
    {
      case 'L':
        botstop();
        delay(75);
        botleft();
        break;

      case 'S':
        break;

      case 'R':
        botstop();
        delay(75);
        botright();
        break;

      case 'E':
        for (int i = 0; i < 10; i++)
        {
          botinchforward ();
        }
        red();
        botstop();
        delay(1000);
        break;
    }//_________end of switch
  }//_________end of for loop

}
