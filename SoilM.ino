void SoilM()
{
  if(digitalRead(soilpin)==0)
  {
    digitalWrite(motor,1);
  }
  else
  {
    digitalWrite(motor,0);
  }
}
