#include <ESP8266_Heweather.h>

const char* ssid = "yourssid";          // WiFi名称
const char* password = "yourpass";  // WiFi密码

String UserKey = "youruserkey";  // 私钥 https://dev.qweather.com/docs/start/get-api-key
String Location = "101280601";                        // 城市代码 https://github.com/qweather/LocationList,表中的 Location_ID
String Unit = "m";                                    // 公制-m/英制-i
String Lang = "en";                                   // 语言 英文-en/中文-zh
float ROUND = 1.5;                                   

AirQualityForecast airQF;

void setup() {
  Serial.begin(9600);
  Serial.println("");

  ConnectWiFi();  // 连接WiFi

  airQF.config(UserKey, Location, Unit, Lang);  // 配置请求信息
}

void loop() {
  if (airQF.get()) {  // 获取更新
    Serial.println(F("======Air Quality Forecast Info======"));
    Serial.print("Server Response: ");
    Serial.println(airQF.getServerCode());  // 获取API状态码
    Serial.print(F("Last Update: "));
    Serial.println(airQF.getLastUpdate());  // 获取服务器更新天气信息时间
    for (int i = 0; i < 5; i++) {
      Serial.println(F("========================"));
      Serial.print(F("Day "));
      Serial.println(airQF.getFxDate(i));
      Serial.print(F("Aqi: "));
      Serial.println(airQF.getAqi(i));  // 实时空气质量指数
      Serial.print(F("Category: "));
      Serial.println(airQF.getCategory(i));  // 实时空气质量指数级别
      Serial.print(F("Primary: "));
      Serial.println(airQF.getPrimary(i));  // 实时空气质量的主要污染物，优时返回值为 NA
    }
    Serial.println(F("========================"));
  } else {  // 更新失败
    Serial.println("Update Failed...");
    Serial.print("Server Response: ");
    Serial.println(airQF.getServerCode());  // 参考 https://dev.qweather.com/docs/start/status-code
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