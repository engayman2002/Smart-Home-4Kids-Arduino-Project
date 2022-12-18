// ----------------------------- Servo ( Door ) Function -----------------------------
void Door(byte val){
  if(val==1) // Open Door
  {
    myservo.write(110);
    }
  else // Close Door
  {
    myservo.write(10);
    }   
}
