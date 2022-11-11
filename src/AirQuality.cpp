#include "AirQuality.h"

AirQuality::AirQuality() {
}


// 尝试获取信息，成功返回true，失败返回false
bool AirQuality::get() {
  String url = "https://devapi.qweather.com/v7/air/now";
  return getFrom(url);
}

// 解析Json信息
void AirQuality::_parseNowJson(String payload) {
  const size_t capacity = 2*JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(10) + 250;
  DynamicJsonDocument doc(capacity);

  deserializeJson(doc, payload);

  const char* code = doc["code"];
  const char* updateTime = doc["updateTime"];
  JsonObject now = doc["now"];

  _response_code = doc["code"].as<String>();         // API状态码
  _last_update_str = doc["updateTime"].as<String>(); // 当前API最近更新时间
  _now_aqi_int = now["aqi"].as<int>();               // 实时空气质量指数
  _now_category_str = now["category"].as<String>();  // 实时空气质量指数级别
  _now_primary_str = now["primary"].as<String>();    // 实时空气质量的主要污染物，优时返回 NA

}

// 实时空气质量指数
int AirQuality::getAqi() {
  return _now_aqi_int;
}

// 实时空气质量指数级别
String AirQuality::getCategory() {
  return _now_category_str;
}

// 实时空气质量的主要污染物，空气质量为优时，返回值为NA
String AirQuality::getPrimary() {
  return _now_primary_str;
}