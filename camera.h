#ifndef CATCHER_CAMERA
#define CATCHER_CAMERA

#include "common.h"

class camera
{
public:
	camera(uint16_t w = 320, uint16_t h=200)  
	{
		cam = new cv::VideoCapture(0);
 		ASSERT(cam->isOpened(), "can't open camera");
 		cam->set(CV_CAP_PROP_FRAME_WIDTH,w);
		cam->set(CV_CAP_PROP_FRAME_HEIGHT,h);
	}
	~camera() 
	{
		delete cam;
	}

	const cv::Mat getFrame() 
	{
		cam->read(frame);
		return frame;
	}
   
private:
   	cv::VideoCapture *cam;
   	cv::Mat frame;
};










#endif 