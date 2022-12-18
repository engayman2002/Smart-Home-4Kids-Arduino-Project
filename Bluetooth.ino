char blue;
void Bluetooth(){
if( mySerial.available() ){
  
    blue=mySerial.read();
    switch(blue)
    {
      case 'A':
      // Function for Open the Door
      Door(1);
      break;
      case 'a':
      // Function for Close the Door
      Door(0);
      break;
      case 'B':
      // Function for Open the Light of The Outside of Apartment
      digitalWrite(ledmpin,1);
      break;
      case 'b':
      // Function for Close the Light of The Outside of Apartment
      digitalWrite(ledmpin,0);
      break;
      case 'C':
      // Function for Open the Light of The Hall
      digitalWrite(led0pin,1);
      break;
      case 'c':
      // Function for Close the Light of The Hall
      digitalWrite(led0pin,0);
      break;
      case 'D':
      // Function for Open the Fan of The Hall
      digitalWrite(fanpin,1);
      break;
      case 'd':
      // Function for Close the Fan of The Hall
      digitalWrite(fanpin,0);
      break;
      case 'E':
      // Function for Open the Light of The First Room
      digitalWrite(led1pin,1);
      break;
      case 'e':
      // Function for Close the Light of The First Room
      digitalWrite(led1pin,0);
      break;
      case 'F':
      // Function for Open the Light of The Second Room
      digitalWrite(led2pin,1);
      break;
      case 'f':
      // Function for Close the Light of The Second Room
      digitalWrite(led2pin,0);
      break;
    }


    
}}
