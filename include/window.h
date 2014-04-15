#ifndef CATCHER_WINDOW
#define CATCHER_WINDOW
#include "common.h"

class window
{
public:
	using gl_callback = std::function<void()>;

    window(const std::string&, uint, uint, uint, uint,const gl_callback &gls = gl_callback());
  
    virtual ~window();
    void update(const cv::Mat &);

    inline void width(uint w)  {_width  = w; refill();}
    inline void height(uint h) {_height = h; refill();}
    inline void posx(uint x)   {_posX  = x;  refill();}
    inline void posy(uint y)   {_posY = y;   refill();}

	inline uint width()  const {return _width;}
    inline uint height() const {return _height;}
	inline uint posx()   const {return _posX;}
    inline uint posy()   const {return _posY;}
        


private:

	void refill();

    std::string tag;
    uint _width;
    uint _height;
    uint _posX;
    uint _posY; 
    gl_callback glc = gl_callback();       

};

class windowGrid
{
public:
	windowGrid(uint,uint) {}

private:



};


#endif