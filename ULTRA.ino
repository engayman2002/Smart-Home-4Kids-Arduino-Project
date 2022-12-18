int dis;
long dur;
int ULTRA()
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
dur=pulseIn(echoPin,HIGH);
dis=dur*0.034*0.5;
return dis;
}
