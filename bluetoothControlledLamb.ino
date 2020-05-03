#include <SoftwareSerial.h>       //Sanal haberleşme portu oluşturmak için gerekli kütüphane
SoftwareSerial myBT(10, 11);   // RX | TX
char data;      //BLuetooth modüleden gelen verileri tutan değişken
void setup()
{
  Serial.begin(9600);     //Seri monitör haberleşmesi başlatılıyor.
  myBT.begin(9600);  //Buraya modülün baud hızı gelecek. Eğer değiştirdiyseniz onu girmeniz gerekli 
}
 
void loop()
{
   
  if (myBT.available()) {
    data = myBT.read();
    Serial.println(data);
    if(data == 'a') {
      digitalWrite(13, HIGH);
      myBT.write("Led is turned on\n");
      
    }
    else if(data == 'b') {
      digitalWrite(13, LOW);
      myBT.write("Led is turned off right now\n");
    }
  }
  if (Serial.available())
    myBT.write(Serial.read());
}
