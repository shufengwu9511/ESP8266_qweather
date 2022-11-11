#ifndef _QWEATHER_API_H_
#define _QWEATHER_API_H_

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

// #define DEBUG // 调试用
//提取API基类,将调用的基础代码放在基类,减少重复代码,具体API实现只用考虑如何解析返回的json数据
class QWeatherApi { 
  public:
    QWeatherApi();
    void config(String userKey, String location, String unit, String lang);
    bool getFrom(String baseurl);
    String getServerCode();
    String getLastUpdate();
    virtual bool get()=0;
  protected:
    
    
    String _response_code = "no_init";           // API状态码
    String _last_update_str = "no_init";         // API最近更新时间
    virtual void _parseNowJson(String payload)=0; // 解析json信息
  private:
    String _query_str;

    

};
#endif
