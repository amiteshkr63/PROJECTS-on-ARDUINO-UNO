#include<EEPROM.h>
int Addr;
String r;
void empty_buffer()
{
  while(Serial.available()>0)
    Serial.read();
}
void error()
{
   Serial.println("WRONG FORMAT TRY AGAIN");
  Serial.println("CORRECT FORMAT:\nread addr_location\nwrite addr_location data");
    empty_buffer();
}
void setup() {
  Serial.begin(9600);
  //initializing EEPROM address with some Data
  for(int k=0;k<1024;k++)
  {
    if(k%2==1)//EEPROM ODD ADDR=1
    EEPROM.write(k,1);
   else//EEPROM EVEN ADDR=2
    EEPROM.write(k,2);
  }
  Serial.println("FORMAT:\nread addr_location\nwrite addr_location data");
  }

void loop() {
  Serial.available();
  delay(40);//bcz ARDUINO has time to calculate total bytes waiting in Buffer 

  //reading EEPROM addr in FORMAT "read Addr_EEPROM"
if((Serial.available()>=6)&&(Serial.available()<9))
{
  r=Serial.readStringUntil(' ');
  if(r=="read")
    {
 for(int i=1;i<=Serial.available();i++)
 {
  if(i==1){
    Addr=(int)Serial.parseInt();
    Serial.print("Reading Data at EEPROM Addr");
    Serial.print(Addr);
    Serial.print("==");
  Serial.println(EEPROM.read(Addr));
}
   empty_buffer();
 }
    
} 
  else
      error();
  
}
      //writing EEPROM addr in FORMAT "write Addr_EEPROM DATA"
  if(Serial.available()>=9)
  {
          r=Serial.readStringUntil(' ');
          if(r=="write")
    {
    for(int j=1;j<=Serial.available();j++)
    {

      if(j==1)
      {
        
        Addr=(int)Serial.parseInt();
        Serial.read();//releasing space b/w "addr_loc data"
        int data=(int)Serial.parseInt();
        EEPROM.write(Addr,data);
        //Printing Modified Data
        Serial.print("Writing Data at EEPROM Addr");
    Serial.print(Addr);
    Serial.print("==");
  Serial.println(EEPROM.read(Addr));
}
      empty_buffer();
      }
      
  }
    else
    error();
  }
  else
    if(Serial.available()>0)
    error();
  }

//TinkerCad Simulation:https://www.tinkercad.com/things/7gsQvOfRcwZ-v2eeprom-read-and-write-via-serial-monitor-/editel?sharecode=TC9azo3S-7j7kTj2MSsTrZJnqGteUM8hY3NgYkcuphc
//GitHub Screencast:https://github.com/amiteshkr63/PROJECTS-on-ARDUINO-UNO/blob/main/ARDUINO%20EEPROM%20write.mp4
