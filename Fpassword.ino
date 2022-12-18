void Fpassword() {
  
  if(EEPROM.read(0)!=1)
  {
    lcd.setCursor(0,0);
    lcd.print("New Password : ");
    lcd.setCursor(0,1);
    lcd.print("=> ");
    String password = "";
    while(true)
    {
      char key=mykey.getKey();
      if(key == '=')
      {
        EEPROM.write(0,1);
        EEPROM.write(1,0);
        WriteStringToEEPROM(2,password);
        break;
        }
        else if(key == '/')
        {
          password="";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("New Password : ");
          lcd.setCursor(0,1);
          lcd.print("=> ");
          }
        else if(key)
        {
          password+=String(key);
          lcd.print("*");
          }
      }
      lcd.clear();
      lcd.print("The Password is");
      lcd.setCursor(0,1);
      lcd.print("set Successfully");
    }else
    {
      int noOfTrials=EEPROM.read(1);
      String password= ReadStringFromEEPROM(2);
      bool isCorrectPassword=false;

      for(int i=noOfTrials;i<3;i++)
      {
        vTaskDelay( 1000 / portTICK_PERIOD_MS );
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter Password :");
        lcd.setCursor(0,1);
        lcd.print("=> ");
        String userPassword="";

        while(true)
        {
          char key = mykey.getKey();
          if(key=='=')
          {
            if(userPassword.equals(password))
            {
              isCorrectPassword=true;
              lcd.clear();
              lcd.print("Correct");
              Door(1);
              digitalWrite(ledmpin,1);
              EEPROM.update(1,0);
              }
             else
             {
              isCorrectPassword=false;
              lcd.clear();
              lcd.print("Incorrect!");
              Door(0);
              digitalWrite(ledmpin,0);
              EEPROM.write(1,noOfTrials+1);
              }
              break;
            }
            else if(key == '/')
            {
              userPassword="";
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Enter Password :");
              lcd.setCursor(0,1);
              lcd.print("=> ");
              }
            else if(key)
            {
              userPassword+=String(key);
              lcd.print("*");
              }
          }
          if(isCorrectPassword)
          {
            break;
            }
        }
      if(isCorrectPassword)
      {
          lcd.clear();
          lcd.print("Hello , Have a");
          lcd.setCursor(0,1);
          lcd.print("    Nice Day    ");
          vTaskDelay( 1000 / portTICK_PERIOD_MS ); 
        }
      else
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("  Emsk Haramy!  ");
        lcd.setCursor(0,1);
        lcd.print("  Shoftak ^_^  ");
        stbuz=true;
        while(1)
        {
       
          digitalWrite(buz,1);
          if( mySerial.available() )
          {
            if(mySerial.read()=='A')
            {
            stbuz=false;
            digitalWrite(buz,0);
            lcd.clear();
            lcd.setCursor(0,0);
            EEPROM.write(0,0);
            EEPROM.write(1,0);
            Door(1);
            break;
            }
          }
          
          
         }
        }
      }
      
}

void WriteStringToEEPROM(int addrOffset,const String &strToWrite)
{
  byte len=strToWrite.length();
  EEPROM.write(addrOffset,len);
  for(int i=0;i<len;i++)
  {EEPROM.write(addrOffset+1+i,strToWrite[i]);}
}
String ReadStringFromEEPROM(int addrOffset)
{
  int newStrLen=EEPROM.read(addrOffset);
  char data[newStrLen+1];
  for(int i=0;i<newStrLen;i++)
  {data[i]=EEPROM.read(addrOffset+1+i);}
  data[newStrLen]='\0';
  return String(data);
}
