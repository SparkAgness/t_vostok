#include <WiFi.h>
#include <ESP8266WebServer.h>
#include <GyverBME280.h>
#include <Wire.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

/* Установите здесь свои SSID и пароль */
const char* ssid = "Andrey_Fe";  
const char* password = "20031984";  

ESP8266WebServer server(80);
GyverBME280 bme;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//for pasting bme's measutments into web-interface
String str_temp;
String str_press;

String str_time;
String str_date;
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
String week_days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//func of interprerating int to string
String Interpretate(int val, bool time_format=false);


void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println();
    Serial.println("IP: ");   
    Serial.println(WiFi.localIP());
    server.on("/", handle_OnConnect);
    server.onNotFound(handle_NotFound);
    server.begin();
    Serial.println("HTTP server started");
    Serial.println(str_temp);

    bme.begin(0x76);

    timeClient.begin();
    timeClient.setTimeOffset(10800);
}
void loop() {
    timeClient.update();
    str_time = Interpretate(timeClient.getHours(), 1) + ":" + Interpretate(timeClient.getMinutes(), 1);
    time_t epochTime = timeClient.getEpochTime();
    tm* ptm = gmtime((time_t*)&epochTime);
    str_date = week_days[timeClient.getDay()] + ",\n " + String(ptm->tm_mday) + " " + months[ptm->tm_mon] + " " + String(ptm->tm_year + 1900);

    str_temp = Interpretate(int(bme.readTemperature()) - 3);
    str_press = Interpretate(int(bme.readPressure())/133);
    server.handleClient();
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(str_temp)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
String SendHTML(String str_temp) {
  String ptr = "<!DOCTYPE html> <html>\n";
    ptr +="<meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
    ptr +="<title>My clever home</title>\n";
    ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
    ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
    ptr += "</style>\n";
    ptr += "<body>\n";
    ptr +="<h1>";
    ptr += str_date;
    ptr += "\n ";
    ptr += str_time;
    ptr += "</h1>\n";
    ptr +="<h2>The weather today is:</h2>\n";
    ptr += "<h3>Temperature is: ";
    ptr += str_temp;
    ptr += " Celcius</h3>\n";
    ptr += "<h3>Pressure is: ";
    ptr += str_press;
    ptr += " mm Hg</h3>\n";
    ptr +="</body>\n";
    ptr +="</html>\n";
  return ptr;
}

String Interpretate(int val, bool time_format)
{
    String value = "";
    char hundreds = 32;
    char dec = 32;
    char ones = 32;
    if (val/100 > 0) {
        hundreds = 48 + val/100;
        dec = 48 + (val - int(hundreds - 48)*100)/10;
        ones = 48 + (val - int(hundreds - 48)*100 - int(dec - 48)*10);
    }
    if (val/10 > 0 && val/10 < 10) {
        dec = 48 + val/10;
        ones = 48 + (val - int(dec - 48)*10);
    }
    if (val < 10) {
        ones = 48 + val;
    }
    if ((time_format) && val < 10) {
        return value = "0" + String(ones);
    }
    if ((time_format) && val > 10) {
        return value = String(dec) + String(ones);
    }
    return value = String(hundreds) + String(dec) + String(ones);
}
