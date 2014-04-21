#ifndef CATCHER_COMMON
#define CATCHER_COMMON

#define ASSERT(cond, ...)  if(!cond) {printf(__VA_ARGS__); exit(-1);} 

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <functional>
#include <unordered_map>

namespace screen // todo: use real screen sizes!
{
    constexpr uint width()  {return 1920;};
    constexpr uint height() {return 1080;};
}

using icref  = const cv::Mat &;
using strref = const std::string &;

template<typename T>
using dictionary = std::unordered_map<std::string,T>; 


template<typename T>
T clamp(int val, T min, T max)
{
    return static_cast<T>(val * max/10 + min);
} 



#endif
