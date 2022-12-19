#include "HourlyForecast.h"

HourlyForecast::HourlyForecast()
{
    for (int i = 0; i < 24; i++)
    {
        _hourly_cloud_float[i] = 999;
        _hourly_dew_float[i] = 999;
        _hourly_fxtime_str[i] = "no_init";
        _hourly_humidity_float[i] = 999;
        _hourly_icon_int[i] = 999;
        _hourly_pop_float[i] = 999;
        _hourly_precip_float[i] = 999;
        _hourly_pressure_float[i] = 9999;
        _hourly_temp_int[i] = 999;
        _hourly_text_str[i] = "no_init";
        _hourly_wind360_int[i] = 999;
        _hourly_winddir_str[i] = "no_init";
        _hourly_windscale_str[i] = "no_init";
        _hourly_windspeed_int[i] = 999;
    }
}

bool HourlyForecast::get()
{
    String url = "https://devapi.qweather.com/v7/weather/24h";
    return getFrom(url);
}

void HourlyForecast::_parseNowJson(String payload) // 解析json信息
{  //memory limited, break payload to small part to user jsondocument
    //sample payload: {"code":"200","updateTime":"2022-12-14T20:35+08:00","fxLink":"http://hfx.link/3i71","hourly":[{"fxTime":"2022-12-14T22:00+08:00","temp":"11","icon":"305","text":"Light Rain","wind360":"51","windDir":"NE","windScale":"3-4","windSpeed":"16","humidity":"93","pop":"55","precip":"0.3","pressure":"1010","cloud":"76","dew":"10"},{"fxTime":"2022-12-14T23:00+08:00","temp":"11","icon":"305","text":"Light Rain","wind360":"49","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"92","pop":"55","precip":"0.3","pressure":"1011","cloud":"76","dew":"9"},{"fxTime":"2022-12-15T00:00+08:00","temp":"11","icon":"305","text":"Light Rain","wind360":"47","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"91","pop":"55","precip":"0.3","pressure":"1011","cloud":"76","dew":"9"},{"fxTime":"2022-12-15T01:00+08:00","temp":"11","icon":"151","text":"Cloudy","wind360":"45","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"90","pop":"25","precip":"0.0","pressure":"1012","cloud":"45","dew":"9"},{"fxTime":"2022-12-15T02:00+08:00","temp":"11","icon":"151","text":"Cloudy","wind360":"43","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"89","pop":"20","precip":"0.0","pressure":"1012","cloud":"45","dew":"9"},{"fxTime":"2022-12-15T03:00+08:00","temp":"11","icon":"151","text":"Cloudy","wind360":"39","windDir":"NE","windScale":"3-4","windSpeed":"16","humidity":"88","pop":"20","precip":"0.0","pressure":"1011","cloud":"45","dew":"9"},{"fxTime":"2022-12-15T04:00+08:00","temp":"11","icon":"151","text":"Cloudy","wind360":"35","windDir":"NE","windScale":"3-4","windSpeed":"16","humidity":"87","pop":"20","precip":"0.0","pressure":"1010","cloud":"37","dew":"9"},{"fxTime":"2022-12-15T05:00+08:00","temp":"11","icon":"150","text":"Clear","wind360":"34","windDir":"NE","windScale":"3-4","windSpeed":"18","humidity":"89","pop":"20","precip":"0.0","pressure":"1009","cloud":"28","dew":"9"},{"fxTime":"2022-12-15T06:00+08:00","temp":"11","icon":"150","text":"Clear","wind360":"35","windDir":"NE","windScale":"3-4","windSpeed":"18","humidity":"90","pop":"16","precip":"0.0","pressure":"1008","cloud":"26","dew":"9"},{"fxTime":"2022-12-15T07:00+08:00","temp":"11","icon":"100","text":"Sunny","wind360":"38","windDir":"NE","windScale":"3-4","windSpeed":"16","humidity":"92","pop":"7","precip":"0.0","pressure":"1007","cloud":"26","dew":"9"},{"fxTime":"2022-12-15T08:00+08:00","temp":"11","icon":"100","text":"Sunny","wind360":"40","windDir":"NE","windScale":"3-4","windSpeed":"18","humidity":"94","pop":"7","precip":"0.0","pressure":"1007","cloud":"26","dew":"10"},{"fxTime":"2022-12-15T09:00+08:00","temp":"11","icon":"100","text":"Sunny","wind360":"41","windDir":"NE","windScale":"3-4","windSpeed":"18","humidity":"95","pop":"7","precip":"0.0","pressure":"1007","cloud":"26","dew":"10"},{"fxTime":"2022-12-15T10:00+08:00","temp":"12","icon":"100","text":"Sunny","wind360":"42","windDir":"NE","windScale":"3-4","windSpeed":"20","humidity":"94","pop":"7","precip":"0.0","pressure":"1007","cloud":"26","dew":"11"},{"fxTime":"2022-12-15T11:00+08:00","temp":"12","icon":"100","text":"Sunny","wind360":"44","windDir":"NE","windScale":"3-4","windSpeed":"20","humidity":"93","pop":"7","precip":"0.0","pressure":"1008","cloud":"26","dew":"11"},{"fxTime":"2022-12-15T12:00+08:00","temp":"12","icon":"100","text":"Sunny","wind360":"37","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"92","pop":"10","precip":"0.0","pressure":"1008","cloud":"30","dew":"11"},{"fxTime":"2022-12-15T13:00+08:00","temp":"13","icon":"305","text":"Light Rain","wind360":"35","windDir":"NE","windScale":"3-4","windSpeed":"14","humidity":"92","pop":"53","precip":"0.3","pressure":"1009","cloud":"76","dew":"11"},{"fxTime":"2022-12-15T14:00+08:00","temp":"13","icon":"101","text":"Cloudy","wind360":"34","windDir":"NE","windScale":"3-4","windSpeed":"13","humidity":"93","pop":"45","precip":"0.0","pressure":"1009","cloud":"76","dew":"12"},{"fxTime":"2022-12-15T15:00+08:00","temp":"13","icon":"305","text":"Light Rain","wind360":"42","windDir":"NE","windScale":"1-2","windSpeed":"11","humidity":"94","pop":"53","precip":"0.3","pressure":"1009","cloud":"76","dew":"12"},{"fxTime":"2022-12-15T16:00+08:00","temp":"14","icon":"305","text":"Light Rain","wind360":"52","windDir":"NE","windScale":"1-2","windSpeed":"9","humidity":"97","pop":"51","precip":"0.3","pressure":"1008","cloud":"76","dew":"13"},{"fxTime":"2022-12-15T17:00+08:00","temp":"13","icon":"101","text":"Cloudy","wind360":"66","windDir":"NE","windScale":"1-2","windSpeed":"9","humidity":"100","pop":"47","precip":"0.0","pressure":"1008","cloud":"76","dew":"13"},{"fxTime":"2022-12-15T18:00+08:00","temp":"12","icon":"151","text":"Cloudy","wind360":"83","windDir":"E","windScale":"1-2","windSpeed":"9","humidity":"100","pop":"36","precip":"0.0","pressure":"1008","cloud":"76","dew":"12"},{"fxTime":"2022-12-15T19:00+08:00","temp":"12","icon":"150","text":"Clear","wind360":"53","windDir":"NE","windScale":"1-2","windSpeed":"9","humidity":"100","pop":"20","precip":"0.0","pressure":"1007","cloud":"26","dew":"12"},{"fxTime":"2022-12-15T20:00+08:00","temp":"12","icon":"150","text":"Clear","wind360":"68","windDir":"NE","windScale":"1-2","windSpeed":"9","humidity":"100","pop":"20","precip":"0.0","pressure":"1007","cloud":"23","dew":"12"},{"fxTime":"2022-12-15T21:00+08:00","temp":"12","icon":"151","text":"Cloudy","wind360":"57","windDir":"NE","windScale":"1-2","windSpeed":"9","humidity":"100","pop":"20","precip":"0.0","pressure":"1007","cloud":"34","dew":"12"}],"refer":{"sources":["QWeather","NMC","ECMWF"],"license":["CC BY-SA 4.0"]}}
    // String input;
    StaticJsonDocument<1024> doc;
    String headerJson;
    
    int i= payload.indexOf("\"hourly\"");
    if (i==-1){
        Serial.println(F("Json response: hourly element not found. "));
        return;
    }
    int j = payload.lastIndexOf(",",i);  //backward find the first ,
    headerJson = payload.substring(0,j)+"}";
    DeserializationError error = deserializeJson(doc,headerJson);
    if (error)
    {
        Serial.print(F("deserializeJson() failed for first part : "));
        Serial.println(error.f_str());
        return;
    }
    
    // DynamicJsonDocument doc(12288); // generated by https://arduinojson.org/v6/assistant/

    // DeserializationError error = deserializeJson(doc, payload);

    // if (error)
    // {
    //     Serial.print(F("deserializeJson() failed: "));
    //     Serial.println(error.f_str());
    //     return;
    // }
    _response_code = doc["code"].as<String>();
    _last_update_str = doc["updateTime"].as<String>();

    
    j=payload.lastIndexOf("]");
    int itemIndex =0;
    String itemJson;
    int end =i+1;
    while(itemIndex<24 && end<j){
        doc.clear();
        int start = payload.indexOf("{",end);
        if (-1==start) break;
        end = payload.indexOf("}",start);
        DeserializationError error = deserializeJson(doc,payload.substring(start,end+1));
         if (error)
        {
            Serial.print(F("deserializeJson() failed for item  "));
            Serial.print(itemIndex);
            Serial.println(error.f_str());
            return;
        }
        _hourly_fxtime_str[itemIndex] = doc["fxTime"].as<String>();

        _hourly_temp_int[itemIndex] = doc["temp"].as<int>();              // "2", "1", "0", "0", "-2", "-3", "-3", "-4", "-4", ...
        _hourly_icon_int[itemIndex] = doc["icon"].as<int>();              // "100", "100", "100", "150", "150", "150", "150", ...
        _hourly_text_str[itemIndex] = doc["text"].as<String>();           // "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", ...
        _hourly_wind360_int[itemIndex] = doc["wind360"].as<int>();        // "335", "339", "341", "344", "349", "353", ...
        _hourly_winddir_str[itemIndex] = doc["windDir"].as<String>();     // "西北风", "西北风", "西北风", "西北风", "西北风", "北风", ...
        _hourly_windscale_str[itemIndex] = doc["windScale"].as<String>(); // "3-4", "3-4", "4-5", "4-5", "3-4", ...
        _hourly_windspeed_int[itemIndex] = doc["windSpeed"].as<int>();    // "20", "24", "25", "25", "24", "22", ...
        _hourly_humidity_float[itemIndex] = doc["humidity"].as<float>();  // "11", "11", "11", "12", "13", "14", "14", ...
        _hourly_pop_float[itemIndex] = doc["pop"].as<float>();            // "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ...
        _hourly_precip_float[itemIndex] = doc["precip"].as<float>();      // "0.0", "0.0", "0.0", "0.0", "0.0", "0.0", ...
        _hourly_pressure_float[itemIndex] = doc["pressure"].as<float>();  // "1025", "1025", "1026", "1025", "1025", ...
        _hourly_cloud_float[itemIndex] = doc["cloud"].as<float>();        // "0", "0", "0", "0", "0", "0", "0", "0", "0", ...
        _hourly_dew_float[itemIndex] = doc["dew"].as<float>();            // "-25", "-26", "-26", "-27", "-27", "-27", "-27", ...
        itemIndex++;

    }
    // // const char *code = doc["code"];             // "200"
    // // const char *updateTime = doc["updateTime"]; // "2021-02-16T13:35+08:00"
    // // const char *fxLink = doc["fxLink"];         // "http://hfx.link/2ax1"
    // int i = 0;
    // for (JsonObject hourly_item : doc["hourly"].as<JsonArray>())
    // {

    //     // const char *hourly_item_fxTime = hourly_item["fxTime"];       // "2021-02-16T15:00+08:00", ...
    //     _hourly_fxtime_str[i] = hourly_item["fxTime"].as<String>();

    //     _hourly_temp_int[i] = hourly_item["temp"].as<int>();              // "2", "1", "0", "0", "-2", "-3", "-3", "-4", "-4", ...
    //     _hourly_icon_int[i] = hourly_item["icon"].as<int>();              // "100", "100", "100", "150", "150", "150", "150", ...
    //     _hourly_text_str[i] = hourly_item["text"].as<String>();           // "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", "晴", ...
    //     _hourly_wind360_int[i] = hourly_item["wind360"].as<int>();        // "335", "339", "341", "344", "349", "353", ...
    //     _hourly_winddir_str[i] = hourly_item["windDir"].as<String>();     // "西北风", "西北风", "西北风", "西北风", "西北风", "北风", ...
    //     _hourly_windscale_str[i] = hourly_item["windScale"].as<String>(); // "3-4", "3-4", "4-5", "4-5", "3-4", ...
    //     _hourly_windspeed_int[i] = hourly_item["windSpeed"].as<int>();    // "20", "24", "25", "25", "24", "22", ...
    //     _hourly_humidity_float[i] = hourly_item["humidity"].as<float>();  // "11", "11", "11", "12", "13", "14", "14", ...
    //     _hourly_pop_float[i] = hourly_item["pop"].as<float>();            // "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", ...
    //     _hourly_precip_float[i] = hourly_item["precip"].as<float>();      // "0.0", "0.0", "0.0", "0.0", "0.0", "0.0", ...
    //     _hourly_pressure_float[i] = hourly_item["pressure"].as<float>();  // "1025", "1025", "1026", "1025", "1025", ...
    //     _hourly_cloud_float[i] = hourly_item["cloud"].as<float>();        // "0", "0", "0", "0", "0", "0", "0", "0", "0", ...
    //     _hourly_dew_float[i] = hourly_item["dew"].as<float>();            // "-25", "-26", "-26", "-27", "-27", "-27", "-27", ...
    //     i++;
    //     if (i >= 24)
    //         break;
    // }

    // JsonArray refer_sources = doc["refer"]["sources"];
    // const char *refer_sources_0 = refer_sources[0]; // "QWeather"
    // const char *refer_sources_1 = refer_sources[1]; // "NMC"
    // const char *refer_sources_2 = refer_sources[2]; // "ECMWF"

    // const char *refer_license_0 = doc["refer"]["license"][0]; // "commercial license"
}
String HourlyForecast::getFxtime(int index)
{
    return _hourly_fxtime_str[index % 24];
}
int HourlyForecast::getTemp(int index)
{
    return _hourly_temp_int[index % 24];
}

int HourlyForecast::getIcon(int index)
{
    return _hourly_icon_int[index % 24];
}
String HourlyForecast::getText(int index)
{
    return _hourly_text_str[index % 24];
}
int HourlyForecast::getWind360(int index)
{
    return _hourly_wind360_int[index % 24];
}
String HourlyForecast::getWindDir(int index)
{
    return _hourly_winddir_str[index % 24];
}

int HourlyForecast::getWindSpeed(int index)
{
    return _hourly_windspeed_int[index % 24];
}
float HourlyForecast::getHumidity(int index)
{
    return _hourly_humidity_float[index % 24];
}
float HourlyForecast::getPrecip(int index)
{
    return _hourly_precip_float[index % 24];
}
float HourlyForecast::getPop(int index)
{
    return _hourly_pop_float[index % 24];
}

float HourlyForecast::getPressure(int index)
{
    return _hourly_pressure_float[index % 24];
}
float HourlyForecast::getCloud(int index)
{
    return _hourly_cloud_float[index % 24];
}
float HourlyForecast::getDew(int index)
{
    return _hourly_dew_float[index % 24];
}
String HourlyForecast::getWindScale(int index)
{
    return _hourly_windscale_str[index % 24];
}
