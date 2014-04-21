#include "camera.h"
#include "window.h"
#include "process.h"

const uint W = 320;
const uint H = 240;

int main() 
{
    auto cam  = camera(W,H);
   
    auto test = window("test", 400,400);
    auto pr   = process::blur(&test);

   
    while(cv::waitKey(1) != 27) 
    {
        pr.doIt(cam.getFrame());
    }
    
    return 0;
}