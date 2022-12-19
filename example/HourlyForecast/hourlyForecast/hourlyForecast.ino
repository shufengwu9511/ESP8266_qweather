#include <ESP8266_Heweather.h>

const char* ssid = "yourssid";          // WiFi名称
const char* password = "yourpass";  // WiFi密码

String UserKey = "youruserkey";  // 私钥 https://dev.qweather.com/docs/start/get-api-key
String Location = "101280601";                        // 城市代码 https://github.com/qweather/LocationList,表中的 Location_ID
String Unit = "m";                                    // 公制-m/英制-i
String Lang = "en";                                   // 语言 英文-en/中文-zh
float ROUND = 1.5;                                      

HourlyForecast hourForecast;

void setup() {
  Serial.begin(115200);
  Serial.println("");

  ConnectWiFi();  // 连接WiFi

  hourForecast.config(UserKey, Location, Unit, Lang);  // 配置请求信息
}

void loop() {
  if (hourForecast.get()) {  // 获取更新
    Serial.println(F("======24 Hour Forecast Info======"));
    Serial.print("Server Response: ");
    Serial.println(hourForecast.getServerCode());  // 获取API状态码
    Serial.print(F("Last Update: "));
    Serial.println(hourForecast.getLastUpdate());  // 获取服务器更新天气信息时间
    for (int i = 0; i < 24; i++) {
      Serial.println(F("========================"));
      Serial.print("fxTime:");
      Serial.println(hourForecast.getFxtime(i));
      Serial.print("Temp:");
      Serial.println(hourForecast.getTemp(i));   
      Serial.print("Text:");
      Serial.println(hourForecast.getText(i));
      Serial.print("Precipitation:");
      Serial.println(hourForecast.getPrecip(i));                              
      // Serial.print(F("Day "));
      // Serial.println(hourForecast.getFxDate(i));
      // Serial.print(F("Aqi: "));
      // Serial.println(hourForecast.getAqi(i));  // 实时空气质量指数
      // Serial.print(F("Category: "));
      // Serial.println(hourForecast.getCategory(i));  // 实时空气质量指数级别
      // Serial.print(F("Primary: "));
      // Serial.println(hourForecast.getPrimary(i));  // 实时空气质量的主要污染物，优时返回值为 NA
    }
    Serial.println(F("========================"));
  } else {  // 更新失败
    Serial.println("Update Failed...");
    Serial.print("Server Response: ");
    Serial.println(hourForecast.getServerCode());  // 参考 https://dev.qweather.com/docs/start/status-code
  }
  delay(ROUND * 3600000);
}

// 连接WiFi
void ConnectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  int i = 0;
  while (WiFi.status() != WL_CONNECTED && (i < 10)) {
    delay(1000);
    Serial.print('.');
    i++;
  }
  if (i == 10) {  // 10s失败
    Serial.println("WiFi Connection Failed");
  } else {  // 成功
    Serial.println("");
    Serial.println("WiFi Connection Successful!");
    Serial.print("IP address:    ");
    Serial.println(WiFi.localIP());
  }
}