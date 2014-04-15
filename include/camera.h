#ifndef CATCHER_CAMERA
#define CATCHER_CAMERA

#include "common.h"

class camera
{
public:
	camera(uint w = 320, uint h = 200);  
	~camera(); 
	
	const cv::Mat getFrame();  
	
private:
   	cv::VideoCapture *cam;
   	cv::Mat frame;
};





#endif 