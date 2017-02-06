void play(int pos)
{
  int diff = pos - curr_pos;
  
  if(diff >= 0)
  {
    sr.write(90 + 90/npos*diff);
    delay(period);
  }
  else
  {
    sr.write(85 + 85/npos*diff);
    delay(period);
  } 
   sr.writeMicroseconds(1400);
   //s.write(45);
   //delay(100);
   s.write(0);
   delay(100);
   s.write(45);
   delay(100);
   curr_pos = pos;
}

void doublestroke(int pos)
{
  int diff = pos - curr_pos;
  sr.write(90 + 90/npos*diff);
  if(diff >= 0)
  {
    delay(period);
  }
  else
  {
    delay(period*ratio);
  }
   sr.writeMicroseconds(1400);
   s.write(45);
   delay(100);
   s.write(0);
   delay(150);
   delay(period/2);
   s.write(45);
   delay(100);
   s.write(0);
   delay(100);
   curr_pos = pos;
}

void endsong()
{
  int diff = 0 - curr_pos;
  
  if(diff >= 0)
  {
    sr.write(90 + 90/npos*diff);
    delay(period);
  }
  else
  {
    sr.write(85 + 85/npos*diff);
    delay(period);
  }
  sr.writeMicroseconds(1400);
  curr_pos = 0;
}

void Twinkle()
{
  play(1);
  play(1);
  play(5);
  play(5);
  play(6);
  play(6);
  play(5);
  delay(period);
  play(4);
  play(4);
  play(3);
  play(3);
  play(2);
  play(2);
  play(1);
  
  endsong;
}

