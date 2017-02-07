void play(int pos)
{
  sr.writeMicroseconds(1400);
  int diff = pos - curr_pos;
  
  if(diff >= 0)
  {
    sr.write(90 + 90/(npos+2)*diff);
    delay(period + delays*diff*sqrt(diff));
    sr.writeMicroseconds(1400);
  }
  else
  {
    sr.write(85 + 85/(npos)*diff);
    delay(period + delays*(-diff)*sqrt(-diff));
    sr.writeMicroseconds(1400);
  } 
   
   //s.write(45);
   //delay(100);
   s.write(0);
   sr.writeMicroseconds(1400);
   delay(100);
   s.write(45);
   sr.writeMicroseconds(1400);
   delay(100);
   curr_pos = pos;
   sr.writeMicroseconds(1400);
}

void endsong()
{
  sr.writeMicroseconds(1400);
  int diff = 0 - curr_pos;
  
  if(diff >= 0)
  {
    sr.write(90 + 90/(npos+2)*diff);
    delay(period + delays*diff*sqrt(diff));
  }
  else
  {
    sr.write(85 + 85/(npos)*(diff));
    delay(period + delays*(-diff)*sqrt(-diff));
  }
  curr_pos = 0;
  sr.writeMicroseconds(1400);
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
  delay(period);
  
  /*play(5);
  play(5);
  play(4);
  play(4);
  play(3);
  play(3);
  play(2);
  delay(period);
  
  play(5);
  play(5);
  play(4);
  play(4);
  play(3);
  play(3);
  play(2);
  delay(period);
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
  play(1);*/
  endsong();
}

