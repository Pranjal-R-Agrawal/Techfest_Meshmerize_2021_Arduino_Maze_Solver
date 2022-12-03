int turnspeed1 = 140;
int turnspeed2 = 90;

void botleft ()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9, turnspeed1);
  analogWrite(10, turnspeed1);
  delay(100);
  while (analogRead(1) > threshold)
  {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(9, turnspeed2);
    analogWrite(10, turnspeed2);
  }
  analogWrite(9, 0);
  analogWrite(10, 0);
  delay(50);
}

void botright ()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9, turnspeed1);
  analogWrite(10, turnspeed1);
  delay(100);
  while (analogRead(3) > threshold)
  {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    analogWrite(9, turnspeed2);
    analogWrite(10, turnspeed2);
  }
  analogWrite(9, 0);
  analogWrite(10, 0);
  delay(50);
}

void botstraight ()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(9, lfspeed);
  analogWrite(10, lfspeed);
}

void botinchforward ()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(9, turnspeed1);
  analogWrite(10, turnspeed1);
  delay(10);
}
void botstop ()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(9, 0);
  analogWrite(10, 0);
}
void botuturn ()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9, (lfspeed * 0.7 * 0.8));
  analogWrite(10, lfspeed * 0.7);
  delay(250);
  while (analogRead(1) > threshold)
  {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(9, turnspeed2 * 0.8);
    analogWrite(10, turnspeed2);
  }
  analogWrite(9, 0);
  analogWrite(10, 0);
  delay(50);
}
