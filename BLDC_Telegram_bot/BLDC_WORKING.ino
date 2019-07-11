#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Servo.h>
char ssid[] = "prakhar";         
char password[] = "7505108475";   
#define BOTtoken "822632120:AAGMn_Od-l7dZiBCq4GIC9f-1WEfBJalyTs"  //Bot Token Telegram

//Servo esc_signal;
int  i =0;
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
int Bot_mtbs = 1000; 
long Bot_lasttime;   
bool Start = false;

void handleNewMessages(int numNewMessages) 
{
  Serial.print("NewMessages ");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) 
  {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    String from_name = bot.messages[i].from_name;
    if (from_name == "") from_name = "Guest";

    if (text == "Hey") 
      {
        bot.sendMessage(chat_id, "Hello");
      }
    if (text == "Light 1 on" || text == "light 1 on") 
      {
        bot.sendMessage(chat_id, "Light 1 turned ON");
        Serial.println("Light 1 turned ON");
        //esc_signal.write(55);   
        i=1;
        if(i==1)
        {
          digitalWrite(16,LOW);
        }
    }
     
  if (text == "light 1 off" || text == "Light 1 off") 
      {
        bot.sendMessage(chat_id, "Light 1 turned OFF");
        Serial.println("Light 1 turned Off");
        //esc_signal.write(0);   
        i=0;
        if(i==0)
        {
          digitalWrite(16,HIGH);
        }
      }

  if (text == "Light 2 on" || text == "light 2 on") 
      {
        bot.sendMessage(chat_id, "Light 2 turned ON");
        Serial.println("Light 2 turned ON");
        //esc_signal.write(55);   
        i=1;
        if(i==1)
        {
          digitalWrite(5,LOW);
        }
    }

 if (text == "light 2 off" || text == "Light 2 off") 
      {
        bot.sendMessage(chat_id, "Light 2 turned OFF");
        Serial.println("Light 2 turned Off");
        //esc_signal.write(0);   
        i=0;
        if(i==0)
        {
          digitalWrite(5,HIGH);
        }
      }

  if (text == "Light 3 on" || text == "light 3 on") 
      {
        bot.sendMessage(chat_id, "Light 3 turned ON");
        Serial.println("Light 3 turned ON");
        //esc_signal.write(55);   
        i=1;
        if(i==1)
        {
          digitalWrite(5,LOW);
        }
    }


   if (text == "light 3 off" || text == "Light 3 off") 
      {
        bot.sendMessage(chat_id, "Light 3 turned OFF");
        Serial.println("Light 3 turned Off");
        //esc_signal.write(0);   
        i=0;
        if(i==0)
        {
          digitalWrite(5,HIGH);
        }
      }   
  
  if (text == "Light 4 on" || text == "light 4 on") 
      {
        bot.sendMessage(chat_id, "Light 4 turned ON");
        Serial.println("Light 4 turned ON");
        //esc_signal.write(55);   
        i=1;
        if(i==1)
        {
          digitalWrite(5,LOW);
        }
    }

   if (text == "light 4 off" || text == "Light 4 off") 
      {
        bot.sendMessage(chat_id, "Light 2 turned OFF");
        Serial.println("Light 2 turned Off");
        //esc_signal.write(0);   
        i=0;
        if(i==0)
        {
          digitalWrite(5,HIGH);
        }
      }   
  
  }
}

void setup() 
{
  Serial.begin(57600);
  pinMode(5, OUTPUT);
 // pinMode(D1, OUTPUT);
  pinMode(16, OUTPUT);
 pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  //digitalWrite(4, LOW);
 // esc_signal.attach(2);  //Specify here the pin number on which the signal pin of ESC is connected.
 //esc_signal.write(20);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  //delay(3000);            //ESC initialization delay.
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(50);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  if (millis() > Bot_lasttime + Bot_mtbs)  
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while(numNewMessages) 
    {
      Serial.println("");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    Bot_lasttime = millis();
  }
}
