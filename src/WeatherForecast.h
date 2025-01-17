#ifndef _WEATHER_FORECAST_H_
#define _WEATHER_FORECAST_H_

#include <QWeatherApi.h>

// #define DEBUG // 调试用

class WeatherForecast :public QWeatherApi{
  public:
    WeatherForecast();    
    bool get() override;  
    String getSunRise(int index);
    int getTempMax(int index);
    int getTempMin(int index);
    int getIconDay(int index);
    String getTextDay(int index);
    String getWindDirDay(int index);
    String getwindScaleDay(int index);
    int getHumidity(int index);
    float getPrecip(int index);
    int getUvIndex(int index);

  
    
  protected:
    void _parseNowJson(String payload) override; // 解析json信息
  private:
    String _daily_sunrise_str[3] = {"no_init", "no_init", "no_init"}; // 日出时间
    int _daily_tempMax_int[3] = {999, 999, 999}; // 最高气温
    int _daily_tempMin_int[3] = {999, 999, 999}; // 最低气温
    int _daily_iconDay_int[3] = {999, 999, 999}; // 白天天气状况的图标代码
    String _daily_textDay_str[3] = {"no_init", "no_init", "no_init"};      // 天气状况的文字描述
    String _daily_windDirDay_str[3] = {"no_init", "no_init", "no_init"};   // 白天风向
    String _daily_windScaleDay_str[3] = {"no_init", "no_init", "no_init"}; // 白天风力等级
    int _daily_humidity_int[3] = {999, 999, 999};   // 相对湿度百分比数值
    float _daily_precip_float[3] = {999, 999, 999}; // 降水量，毫米
    int _daily_uvIndex_int[3] = {999, 999, 999};    // 紫外线强度指数

};
#endif
