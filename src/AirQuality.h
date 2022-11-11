#ifndef _AIRQUALITY_H
#define _AIRQUALITY_H

#include <QWeatherApi.h>
// #define DEBUG   // 调试用

class AirQuality :public QWeatherApi{
  public:
    AirQuality();
    bool get() override;
    int getAqi();
    String getCategory();
    String getPrimary();
  protected:
    void _parseNowJson(String payload) override;
  private:
    int _now_aqi_int = 999;               // 实时空气质量指数
    String _now_category_str = "no_init"; // 实时空气质量指数级别
    String _now_primary_str = "no_init";  // 实时空气质量的主要污染物，优时返回 NA
};
#endif
