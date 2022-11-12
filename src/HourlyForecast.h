#ifndef _HOURLY_FORECAST_H_
#define _HOURLY_FORECAST_H_
#include <QWeatherApi.h>

// 24小时天气
// 以下来自API文档描述 https://dev.qweather.com/docs/api/weather/weather-hourly-forecast/
// hourly.fxTime 预报时间
// hourly.temp 温度，默认单位：摄氏度
// hourly.icon 天气状况和图标的代码，图标可通过天气状况和图标下载
// hourly.text 天气状况的文字描述，包括阴晴雨雪等天气状态的描述
// hourly.wind360 风向360角度
// hourly.windDir 风向
// hourly.windScale 风力等级
// hourly.windSpeed 风速，公里/小时
// hourly.humidity 相对湿度，百分比数值
// hourly.precip 当前小时累计降水量，默认单位：毫米
// hourly.pop 逐小时预报降水概率，百分比数值，可能为空
// hourly.pressure 大气压强，默认单位：百帕
// hourly.cloud 云量，百分比数值。可能为空
// hourly.dew 露点温度。可能为空

//  单条数据样例
//     { "fxTime": "2021-02-17T00:00+08:00",
//       "temp": "-4",
//       "icon": "150",
//       "text": "晴",
//       "wind360": "354",
//       "windDir": "北风",
//       "windScale": "3-4",
//       "windSpeed": "16",
//       "humidity": "16",
//       "pop": "0",
//       "precip": "0.0",
//       "pressure": "1027",
//       "cloud": "0",
//       "dew": "-27" }
class HourlyForecast : public QWeatherApi
{
public:
    HourlyForecast();
    bool get() override;

    String getFxtime(int index);
    int getTemp(int index);
    int getIcon(int index);
    String getText(int index);
    int getWind360(int index);
    String getWindDir(int index);
    int getWindSpeed(int index);
    float getHumidity(int index);
    float getPrecip(int index);
    float getPop(int index);
    float getPressure(int index);
    float getCloud(int index);
    float getDew(int index);
    String getWindScale(int index);
    

protected:
    void _parseNowJson(String payload) override; // 解析json信息
private:
    String _hourly_fxtime_str[24];
    int _hourly_temp_int[24];
    int _hourly_icon_int[24];
    String _hourly_text_str[24];
    int _hourly_wind360_int[24];
    String _hourly_winddir_str[24];
    String _hourly_windscale_str[24];
    int _hourly_windspeed_int[24];
    float _hourly_humidity_float[24];
    float _hourly_precip_float[24];
    float _hourly_pop_float[24];
    float _hourly_pressure_float[24];
    float _hourly_cloud_float[24];
    float _hourly_dew_float[24];


    // int _now_temp_int = 999;             // 实况温度
    // int _now_feelsLike_int = 999;        // 实况体感温度
    // int _now_icon_int = 999;             // 当前天气状况和图标的代码
    // String _now_text_str = "no_init";    // 实况天气状况的文字描述
    // String _now_windDir_str = "no_init"; // 实况风向
    // int _now_windScale_int = 999;        // 实况风力等级
    // float _now_humidity_float = 999;     // 实况相对湿度百分比数值
    // float _now_precip_float = 999;       // 实况降水量,毫米
};
#endif