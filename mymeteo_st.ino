#include <WiFi.h>
#include <ESP8266WebServer.h>
#include <GyverBME280.h>
#include <Wire.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

/* Установите здесь свои SSID и пароль */
const char* ssid = "Andrey_Fe-netis";  
const char* password = "20031984";  

ESP8266WebServer server(80);
GyverBME280 bme;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//for pasting bme's measutments into web-interface
String str_temp;
String str_press;
String str_humid;
String str_average_temp;

String str_time;
String str_date;
String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
String week_days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
bool paste_enable = true;

//func of interprerating int to string
String Interpretate(int val, bool time_format=false);

//average values adding
void PasteAvValue(int begin[4][12], int pastes_row, int paste_place, int vals_time)
{
    begin[pastes_row][paste_place] = vals_time;
};


int AverageCalc(int* arr_source);
int AvrPasteCounter(int* arr);
enum average AvrTypeSwitcher();

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
    enum average {mo_day = 0, mo_night, ye_day, ye_night} average_type, average_typeH;
    int average_temp[4][12] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    timeClient.update();
    str_time = Interpretate(timeClient.getHours(), 1) + ":" + Interpretate(timeClient.getMinutes(), 1);
    time_t epochTime = timeClient.getEpochTime();
    tm* ptm = gmtime((time_t*)&epochTime);
    str_date = week_days[timeClient.getDay()] + ",\n " + String(ptm->tm_mday) + " " + months[ptm->tm_mon] + " " + String(ptm->tm_year + 1900);
    str_temp = Interpretate(int(bme.readTemperature()) - 3);
    str_press = Interpretate(int(bme.readPressure())/133);
    str_humid = Interpretate(int(bme.readHumidity()));
    str_average_temp = Interpretate(*(*(average_temp + 2)));
    server.handleClient();

    if (paste_enable && !ptm->tm_min && !ptm->tm_sec) {
        int hours = ptm->tm_hour;
        if ((hours < 8) || (hours > 19)) {
            average_type = ye_night;
            if (hours > 19) {hours = hours - 11;}
        } else if (hours > 7 && hours < 20) {
            average_type = ye_day;
            hours = hours - 8;
        } 
        PasteAvValue(average_temp, average_type, hours, int(bme.readTemperature()));
        average_type = mo_day;
        average_typeH = ye_day;
        *(*(average_temp + average_type) + AvrPasteCounter(*(average_temp + average_type))) = AverageCalc(*(average_temp + average_typeH));
        average_type = mo_night;
        average_typeH = ye_night;
        *(*(average_temp + average_type) + AvrPasteCounter(*(average_temp + average_type))) = AverageCalc(*(average_temp + average_typeH));
        paste_enable = false;
    }
    if (!paste_enable && ptm->tm_min) {paste_enable = true;}
    
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
    ptr += "<h3>The humidity is:";
    ptr += str_humid;
    ptr += "%</h3>";
    ptr += "Average temperature yesterday is: ";
    ptr += str_average_temp;
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

//calculating number of fillings arrays days/nights on mo_day/mo_night
int AvrPasteCounter(int* arr)
{
    int size = 12, count;
    for (count = 0; count < size; ++count) {
        if (!(*(arr + count))) {return count;}
        }
        return -1;
    
}

//calculating of average value on average_temp array
int AverageCalc(int* arr_source)
{
    int count = AvrPasteCounter(arr_source);
    int sum = 0;
    if (count) {
        for (int i = 0; i < count; ++i) {
            sum += *(arr_source + i);
        }
        sum /= int(count);
    }
    return sum;
}
enum average AvrTypeSwitcher()
{

};
