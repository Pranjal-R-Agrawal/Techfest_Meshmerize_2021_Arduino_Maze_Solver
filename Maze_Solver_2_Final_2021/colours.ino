void magenta ()

{
  analogWrite (3, 200); //BLUE
  analogWrite(5, 0); //Green      // MAGENTA
  analogWrite(6, 150); //red
  lightsoff();
}

void yellow ()
{
  analogWrite (3, 0); //BLUE
  analogWrite(5, 200); //Green      // Yellow
  analogWrite(6, 150); //red
  lightsoff();
}
void cyan()
{
  analogWrite (3, 200); //BLUE
  analogWrite(5, 200); //Green      // Cyan
  analogWrite(6, 0); //red
  lightsoff();
}
void green ()

{
  digitalWrite (3, LOW);
  digitalWrite(5, HIGH);          // GREEN
  digitalWrite(6, LOW);
  lightsoff();
}

void red ()
{
  digitalWrite (3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);           //RED
}
void blue ()
{
  digitalWrite (3, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);           //BLUE
  lightsoff();
}
void lightsoff()
{
  digitalWrite (3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}
