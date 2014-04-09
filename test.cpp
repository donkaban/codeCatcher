
#include "camera.h"
#include <functional>

using icref = const cv::Mat &;
 
struct process
{
public:    
    using process_t = std::function<cv::Mat(const cv::Mat&)>; 

    process(const std::string &tag,const process_t &cb) : 
        tag(tag),
        callback(std::move(cb))
        {}

    const cv::Mat &invoke(icref im)
    {
        image = callback(im);
        imshow(tag,image);
        return image;
    }    
    static void add(const std::string &tag,const process_t &cb)
    {
        chain.push_back(new process(tag, cb));

    }  
    static bool start(icref im)
    {
        cv::Mat current = im;
        for(auto &p : chain)
        {
            current = p->invoke(current); 
        } 
        if(cv::waitKey(30) >= 0) return false;
        return true;   
    }

private:
    std::string tag;
    process_t   callback;
    cv::Mat     image;


    static std::vector<process *> chain;
};

std::vector<process *> process::chain;

int main() 
{
    auto cam = camera(200,200);
    process::add("grab", [&](icref im)->cv::Mat  {return im;});
    process::add("flip", [&](icref im)->cv::Mat  {cv::Mat ret; cv::flip(im,ret,1); return ret;} );



    while(process::start(cam.getFrame())) {}
   
    return 0;
}