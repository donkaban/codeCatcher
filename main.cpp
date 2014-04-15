#include "camera.h"
#include "window.h"


int main() 
{
    auto cam = camera(640,480);
    auto win = window("test",300,300,100,100);
   

    while(cv::waitKey(1) != 27) 
    {
       win.update(cam.getFrame());
    }
    return 0;
}