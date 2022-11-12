#include "AirQualityForecast.h"

AirQualityForecast::AirQualityForecast()
{
}

// 尝试获取信息，成功返回true，失败返回false
bool AirQualityForecast::get()
{
    String url = "https://devapi.qweather.com/v7/air/5d";
    return getFrom(url);
}

// 解析Json信息
void AirQualityForecast::_parseNowJson(String payload)
{
    // String input;

    StaticJsonDocument<1024> doc;

    DeserializationError error = deserializeJson(doc, payload);

    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }
    _response_code = doc["code"].as<String>();         // API状态码
    _last_update_str = doc["updateTime"].as<String>(); // 当前API最近更新时间

    // const char *code = doc["code"];             // "200"
    // const char *updateTime = doc["updateTime"]; // "2022-11-12T17:42+08:00"
    // const char *fxLink = doc["fxLink"];         // "http://hfx.link/2ax4"
    int i = 0;
    for (JsonObject daily_item : doc["daily"].as<JsonArray>())
    {

        // const char *daily_item_fxDate = daily_item["fxDate"];     // "2022-11-12", "2022-11-13", "2022-11-14", ...
        _aqi_int[i] = daily_item["aqi"].as<int>(); // "38", "37", "70", "56", "78"
        //_category_str[i] = daily_item["level"];       // "1", "1", "2", "2", "2"
        _category_str[i] = daily_item["category"].as<String>(); // "优", "优", "良", "良", "良"
        _primary_str[i] = daily_item["primary"].as<String>();   // "NA", "NA", "PM2.5", "PM2.5", "PM2.5"
        i++;
        if (i >= 5)
            break;
    }

    // const char *refer_sources_0 = doc["refer"]["sources"][0]; // "QWeather"
    // const char *refer_sources_1 = doc["refer"]["sources"][1]; // "CNEMC"

    // const char *refer_license_0 = doc["refer"]["license"][0]; // "CC BY-SA 4.0"
}

// 空气质量指数
int AirQualityForecast::getAqi(int index)
{
    return _aqi_int[index % 5];
}

// 空气质量指数级别
String AirQualityForecast::getCategory(int index)
{
    return _category_str[index % 5];
}

// 空气质量的主要污染物，空气质量为优时，返回值为NA
String AirQualityForecast::getPrimary(int index)
{
    return _primary_str[index % 5];
}