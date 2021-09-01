#include<LiquidCrystal.h>                       //including LCD library
LiquidCrystal lcd(8,9,4,5,6,7);                  //Initialising LCD
void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);                                   //Serial beginning
lcd.begin(16,2);                                           //LCD beginning
digitalWrite(13,LOW);
Serial.println("Mobile Number Registration");
lcd.setCursor(0,0);                                   //Setting cursor position in LCD
lcd.println("Mobile Number ");
lcd.setCursor(2,1);
lcd.println("Registration ");
delay(3000);
lcd.clear();                                                //Clearing LCD Screen

///////////////Sending AT commands to the GSM////////////////
Serial.println("AT");lcd.println("AT");delay(1000);lcd.clear();
Serial.println("ATE0");lcd.println("ATE0");delay(1000);lcd.clear();
Serial.println("AT+CMGF=1");lcd.println("AT+CMGF=1");delay(1000);lcd.clear();
Serial.println("AT+CNMI=1,2,0,0");lcd.println("AT+CNMI=1,2,0,0");delay(1000);lcd.clear();

/*Place your number instead of  XXXXXXXXXX*/

Serial.println("AT+CMGS=\"XXXXXXXXXX\"\r");

delay(1000);
Serial.println("Project on Mobile Number Registration");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Project on Mobile");
lcd.setCursor(0,1);
lcd.print("Number Registration");
delay(1000);
Serial.println("send me your number with *");                          //acknowledgement message
lcd.clear();
lcd.setCursor(0,0);lcd.println("send me your");
lcd.setCursor(0,1);lcd.println(" number with *");delay(1000);
Serial.println(char(26));
delay(1000);
}

void loop() {
lcd.clear();
Serial.println("AT");lcd.println("AT"); delay(1000);lcd.clear();
Serial.println("ATE0");lcd.println("ATE0"); delay(1000);lcd.clear();
Serial.println("AT+CNMI=1,2,0,0");lcd.println("AT+CNMI=1,2,0,0"); delay(1000);lcd.clear();
Serial.println("AT+CMGF=1"); lcd.println("AT+CMGF=1");delay(1000);lcd.clear();
int i = 0, j = 0, a = 0;
boolean mssg = false;
char msg[150],num[10];
if (Serial.available() > 0)
{
while (1)
{
while (Serial.available() == 0);
if(Serial.available()>0)
{
msg[i] = Serial.read();
if (msg[i-1] == '*')
{
mssg = true;
}
if (mssg)
{
num[j] = msg[i];
j++;
a++;
}
if (a == 10)
{
mssg = false;
break;
}
i++;
}
}
for (int k = 0; k < 10; k++)
{
Serial.print(num[k]); //Mobile number storning into the array
delay(100);
}
Serial.println("\n");lcd.clear();
Serial.println("AT");lcd.println("AT");delay(1000);lcd.clear();
Serial.println("ATE0");lcd.println("ATE0"); delay(1000);lcd.clear();
Serial.println("AT+CMGF=1");lcd.println("AT+CMGF=1");delay(1000);lcd.clear();
Serial.println("AT+CNMI=1,2,0,0");lcd.println("AT+CNMI=1,2,0,0");delay(1000);lcd.clear();
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(num); //acknowledgement as mobile number stored
Serial.print('"');
Serial.print("\r\n");
delay(1000);
Serial.print(" Mobile Number Registered");
lcd.clear();
lcd.setCursor(0,0);
lcd.println("Mobile Number");
lcd.setCursor(2,1);
lcd.println("Registered");
delay(1000);
Serial.println(char(26));
delay(1000);
lcd.clear();
lcd.print("Message Sent");
}

}
