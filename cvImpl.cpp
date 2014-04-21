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

uint window::counter = 0; 

window::window(const std::string &tag, uint w, uint h) :
	_tag(tag),
	_width(w),
	_height(h)
{
    cv::namedWindow(tag,cv::WINDOW_NORMAL | cv::WINDOW_OPENGL);
    _posX = 100 + (counter%gridWidth)  * (_width + 2);
    _posY = (counter/gridWidth)  * (_height + 30);
    refill();
   counter++;

}

window::~window()
{
    cv::destroyWindow(_tag);
    counter--;
}

void window::refill()
{
    cv::resizeWindow(_tag, _width,_height);
    cv::moveWindow(_tag, _posX, _posY);
}
	
cv::Mat window::update(const cv::Mat &im)
{
    imshow(_tag, im); 
    return im;
}

 

chain::chain(uint w, uint h) : width(w), height(h) {}

chain::~chain()
{
    for(auto w: windows) delete w;
}

chain &chain::add(const std::string &tag)
{
    windows.push_back(new window(tag,width, height));
    return *this;
}  


void chain::processing(const cv::Mat &im)
{
    if(windows.empty()) return;
    cv::Mat cur = im;
    for(auto w : windows)
        cur = w->update(cur);
}

