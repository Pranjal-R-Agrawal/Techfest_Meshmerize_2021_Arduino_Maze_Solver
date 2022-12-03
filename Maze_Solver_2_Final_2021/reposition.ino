void reposition()
{
  if (e == 2)
  {
    str += 'E';
    endFound = 1;
    red();
    botstop();
    delay(2000);
  }
  else if (r == 1)
  {
    if (paths > 1) str += 'R';
    botright(); //take left
  }
  
  else if (s == 1)
  {
    if (paths > 1) str += 'S';
  }
  else if (l == 1)
  {
    if (paths > 1) str += 'L';
    botleft(); //take right
  }

  else if (u == 1)
  {
    str += 'U';
    botuturn(); //take left
  }
  lightsoff();

}
