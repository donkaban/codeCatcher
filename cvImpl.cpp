#include "camera.h"
#include "window.h"

camera::camera(uint w, uint h)  
{
	cam = new cv::VideoCapture(0);
	ASSERT(cam->isOpened(), "can't open camera");
	cam->set(CV_CAP_PROP_FRAME_WIDTH,w);
	cam->set(CV_CAP_PROP_FRAME_HEIGHT,h);
}
camera::~camera() 
{
	delete cam;
}

const cv::Mat camera::getFrame()  
{
	cam->read(frame);
	return frame;
}



window::window(const std::string &tag, uint w, uint h, uint x, uint y, const gl_callback &glc) :
	tag(tag),
	_width(w),
	_height(h),
	_posX(x),
	_posY(y),
	glc(glc)
{
    cv::namedWindow(tag,cv::WINDOW_NORMAL | cv::WINDOW_OPENGL);
    refill();
}



window::~window()
{
    cv::destroyWindow(tag);
}

void window::refill()
{
    cv::resizeWindow(tag, _width,_height);
    cv::moveWindow(tag, _posX, _posY);
}
	
void window::update(const cv::Mat &im)
{
	//cv::setOpenGlContext(tag); //todoit!
    imshow(tag, im);
    if(glc) glc();
}

