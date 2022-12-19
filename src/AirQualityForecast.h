#ifndef _AIRQUALITY_FORECAST_H
#define _AIRQUALITY_FORECAST_H

#include <QWeatherApi.h>
// #define DEBUG   // 调试用

class AirQualityForecast :public QWeatherApi{
  public:
    AirQualityForecast();
    bool get() override;
    int getAqi(int index);
    String getCategory(int index);
    String getPrimary(int index);
    String getFxDate(int index);
  protected:
    void _parseNowJson(String payload) override;
  private:
    int _aqi_int[5] = {999,999,999,999,999};               // 实时空气质量指数
    String _category_str[5] = {"no_init","no_init","no_init","no_init","no_init"}; // 实时空气质量指数级别
    String _primary_str[5] = {"no_init","no_init","no_init","no_init","no_init"};  // 实时空气质量的主要污染物，优时返回 NA
    String _fx_date_str[5] = {"no_init","no_init","no_init","no_init","no_init"};  
};
#endif
