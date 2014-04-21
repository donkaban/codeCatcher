#ifndef CATCHER_WINDOW
#define CATCHER_WINDOW
#include "common.h"

class window
{
public:
	const uint gridWidth  = 4;
  
    window(const std::string&, uint, uint);
   
    virtual ~window();
    cv::Mat update(const cv::Mat &);
    
	inline strref tag()    const {return _tag;}
    inline uint   width()  const {return _width;}
    inline uint   height() const {return _height;}
	inline uint   posx()   const {return _posX;}
    inline uint   posy()   const {return _posY;}

    inline void resize(uint w, uint h)  {_width  = w; _height = h; refill();}
    inline void place(uint x, uint y)   {_posX   = x; _posY   = y; refill();}
    inline void scale(uint w, uint h)   {_width  = _width * w; _height = _height * h; refill();}

    
    inline void transform(uint w, uint h, uint x, uint y)   
    {
    	_width  = w; 
    	_height = h;
    	_posX   = x; 
    	_posY   = y; 
    	refill();
    }

private:

    static uint counter; 

	void refill();

    std::string _tag;
    uint _width;
    uint _height;
    uint _posX;
    uint _posY; 
};

class chain
{
public:
    chain(uint, uint);
    ~chain();
    chain &add(const std::string &);
    void processing(const cv::Mat &);

private:
    uint width;
    uint height;
    std::vector<window *> windows;

};































#endif