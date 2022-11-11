#ifndef _WEATHERNOW_H_
#define _WEATHERNOW_H_

#include <QWeatherApi.h>
// #define DEBUG // 调试用

class WeatherNow :public QWeatherApi{
  public:
    WeatherNow();
    bool get() override;
    int getTemp();
    int getFeelLike();
    int getIcon();
    String getWeatherText();
    String getWindDir();
    int getWindScale();
    float getHumidity();
    float getPrecip();
  protected:
    void _parseNowJson(String payload);  // 解析json信息
  private:
    int _now_temp_int = 999;             // 实况温度
    int _now_feelsLike_int = 999;        // 实况体感温度
    int _now_icon_int = 999;             // 当前天气状况和图标的代码
    String _now_text_str = "no_init";    // 实况天气状况的文字描述
    String _now_windDir_str = "no_init"; // 实况风向
    int _now_windScale_int = 999;        // 实况风力等级
    float _now_humidity_float = 999;     // 实况相对湿度百分比数值
    float _now_precip_float = 999;       // 实况降水量,毫米
};

#endif
