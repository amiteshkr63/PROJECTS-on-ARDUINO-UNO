#include<EEPROM.h>
int Addr;
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
 for(int i=1;i<=Serial.available();i++)
 {
  if(i==1){
    Addr=(int)Serial.parseInt();
    Serial.print("Data at EEPROM Addr");
    Serial.print(Addr);
    Serial.print("==");
  Serial.println(EEPROM.read(Addr));
}
   Serial.read();//Cleaning leftout data in Buffer
 }
} 
      //writing EEPROM addr in FORMAT "write Addr_EEPROM DATA"
  if(Serial.available()>=9)
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
        Serial.print("Modified Data at EEPROM Addr");
    Serial.print(Addr);
    Serial.print("==");
  Serial.println(EEPROM.read(Addr));
}
      Serial.read();//Cleaning leftout data in Buffer
      }
  }
  

  }
