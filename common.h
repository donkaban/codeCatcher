#ifndef CATCHER_COMMON
#define CATCHER_COMMON

#define ASSERT(cond, ...)  if(!cond) {printf(__VA_ARGS__); exit(-1);} 


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#endif
