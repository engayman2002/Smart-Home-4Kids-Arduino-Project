void MQ2(){
  if(digitalRead(mq2pin)==0)
  {
    digitalWrite(buz,1);
  }
  else if( (digitalRead(mq2pin)==1) && (stbuz==false) )
  {
    digitalWrite(buz,0);
    }
}
