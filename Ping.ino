#include <SPI.h>         
#include <Ethernet.h>
#include <ICMPPing.h>

int verde = 7;
int vermelho = 8;
char numero;


byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // max address for ethernet shield
byte ip[] = {192,168,3,250}; // ip address for ethernet shield
byte pingAddr[] = {192,168,3,1}; // ip address to ping

SOCKET pingSocket = 0;

char buffer [256];

void setup() 
{
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  Ethernet.begin(mac, ip);
  //Serial.begin(9600);
  pinMode(9, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  //delay(1000);
}

void loop()
{
  ICMPPing ping(pingSocket);
  ping(4, pingAddr, buffer);
  Serial.println(buffer);
  
numero = atoi((buffer));

if (numero == 1)
{
  digitalWrite(vermelho, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  beep(200);   // wait for a second
  digitalWrite(vermelho, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  
}
else
{
  digitalWrite(verde, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);    
  digitalWrite(verde, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
}
}


void beep(unsigned char delayms){
  analogWrite(9, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
} 











