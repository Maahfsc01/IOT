#include <UIPEthernet.h>

byte mac[] = {0xDE , 0xAD, 0xBE, 0xEF, 0xAA, 0xB3};
char server[] = "www.google.com";
char a = 'A';
char b = "abc";

EthernetClient client;


void setup() {
  Serial.begin(9600);
  
  if (Ethernet.begin(mac) == 0 ) {
   
    Serial.println("FAIL");
  }
  
  delay(1000);

  if (client.connect(server,80)){

    Serial.println("connected");

    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  }
    
else {
  Serial.println("FAIL D NOW");
  
}
}

void loop() {
  if (client.available()){
    
  }char c = client.read();
  Serial.print(c);

  if (!client.connected()){
    Serial.println();
    Serial.println("NO CONNECTED");
    client.stop();

while(true);

    
  }
}
