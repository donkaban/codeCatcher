#ifndef CATCHER_COMMON
#define CATCHER_COMMON

#define ASSERT(cond, ...)  if(!cond) {printf(__VA_ARGS__); exit(-1);} 

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <functional>

namespace screen
{
	constexpr uint width()  {return 1920;};
	constexpr uint height() {return 1080;};
}



#endif
