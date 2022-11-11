#include "QWeatherApi.h"

QWeatherApi::QWeatherApi() {
}

void QWeatherApi::config(String userKey, String location, String unit, String lang) {
//   _requserKey = userKey;
//   _reqLocation = location;
//   _reqUnit = unit;
//   _reqLang = lang;
    _query_str = "location=" + location +
              "&key=" + userKey + "&unit=" + unit + "&lang=" + lang + "&gzip=n";
}

bool QWeatherApi::getFrom(String baseurl) {
  // https请求
  std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
  client->setInsecure(); // 不进行服务器身份认证
  HTTPClient https;
  #ifdef DEBUG
  Serial.print("[HTTPS] begin...\n");
  #endif DEBUG
  String url = baseurl+"?"+_query_str;

  if (https.begin(*client, url)) {  // HTTPS连接成功
    #ifdef DEBUG
    Serial.print("[HTTPS] GET...\n");
    #endif DEBUG
    int httpCode = https.GET(); // 请求

    if (httpCode > 0) { // 错误返回负值
      #ifdef DEBUG
      Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      #endif DEBUG
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) { // 服务器响应
        String payload = https.getString();
        #ifdef DEBUG
        Serial.println(payload);
        #endif DEBUG
        _parseNowJson(payload);
        return true;
      }
    } else { // 错误返回负值
      #ifdef DEBUG
      Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      #endif DEBUG
      return false;
    }
    https.end();
  } else { // HTTPS连接失败
    #ifdef DEBUG
    Serial.printf("[HTTPS] Unable to connect\n");
    #endif DEBUG
    return false;
  }
  return false;
}


// 返回API状态码
String QWeatherApi::getServerCode() {
  return _response_code;
}

// 返回当前API最近更新时间
String QWeatherApi::getLastUpdate() {
  return _last_update_str;
}

