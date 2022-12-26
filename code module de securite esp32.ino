
#define timeSeconds 10

#include <WiFi.h>
#include <FirebaseESP32.h>
#include "DHTesp.h"
#include<stdlib.h>
 
#define DHTpin 15
DHTesp dht;

#include <PubSubClient.h>



char buff[10];
#define FIREBASE_HOST "homecare-c54e8-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "19bZdGb4HNAiJCgMOsl3161PqDsaR3aUHoMU0i2S"
#define WIFI_SSID "Fixbox-7EDABC"
#define WIFI_PASSWORD "MzBjYzU3"
const char* ssid = "access_point";
const char* password = "mywifikey";
const char* mqtt_server = "192.168.0.4";


// Set GPIOs for LED and PIR Motion Sensor
const int motionSensor = 19;
int ledRed = 17;
int ledgreen = 18;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

String detectionD = "";


//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;


String mytemp; 
String myhum;



WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;


// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  Serial.println("intrus detecte");
        detectionD = "1";

  startTimer = true;
  lastTrigger = millis();
}

void setup_wifi() {

Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}



void setup()
{

  Serial.begin(115200);
   dht.setup(DHTpin, DHTesp::DHT11);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.
  
  Firebase.enableClassicRequest(firebaseData, true);
  */

  //String path = "/data";
    Serial.println("------------------------------------");
  Serial.println("Connected...");



  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);



        detectionD = "0";



        pinMode(ledRed, OUTPUT);  
  pinMode(ledgreen, OUTPUT);// Initialize the BUILTIN_LED pin as an output
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);


  

  
}



 
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character

  if(strcmp(topic,"doorState/Closed") == 0){
  if ((char)payload[0] == '1') {
    digitalWrite(ledRed, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(ledRed, LOW);  // Turn the LED off by making the voltage HIGH
  }}
  else if(strcmp(topic,"doorState/Opened") == 0){

      if ((char)payload[0] == '1') {
    digitalWrite(ledgreen, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(ledgreen, LOW);  // Turn the LED off by making the voltage HIGH
  }
    }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("compter/Erreur", "Error de transfer de donnes");
      // ... and resubscribe
      client.subscribe("doorState/Closed");
      client.subscribe("doorState/Opened");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}





void loop()
{
  

   
delay(100); 

  json.set("/detection", detectionD);


  Firebase.updateNode(firebaseData,"/DetectionDesSpammeurs",json);


 





 // Current time
  now = millis();
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))) {
    Serial.println("pas d'intrus");
      detectionD = "0";
    startTimer = false;
  }

if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "data #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("compteur/coutMesuree", msg);
  }


}