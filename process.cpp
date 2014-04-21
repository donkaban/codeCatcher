#include "process.h"
#define DECLARE_PROCESS(name, ...) process::name::name(window *w) : IProcess(w,{__VA_ARGS__}) {} void process::name::doIt(const cv::Mat &in)

static void track_callback(int v, void *ret) {*static_cast<int *>(ret) = v;}

IProcess::IProcess(window *parent, const dictionary<int> &def) :
	_parent(parent),
	_params(def)
{
	if(_parent)
		for(auto &p : _params)
			cv::createTrackbar(p.first, parent->tag(), &p.second, 10, track_callback, &p.second);
}
IProcess::~IProcess() 
{}

window * IProcess::parent()            {return _parent;}
int  IProcess::get(strref k)           {return _params[k];}
void IProcess::set(strref k, int val)  {_params[k] = val;}
void IProcess::show(icref im)          {if(_parent) _parent->update(im);}

cv::Mat IProcess::copy(icref im)       
{
	cv::Mat out(im);
	doIt(out);
	return out;
} 


DECLARE_PROCESS(blur,{"x",2},{"y",2})
{
	cv::blur(in,in,cv::Size(clamp<int>(get("x"),1,20),clamp<int>(get("y"),1,20)));
	show(in);
}	
DECLARE_PROCESS(flip,{})
{
	cv::flip(in,in,1);
	show(in);
}	
DECLARE_PROCESS(gray,{})
{
	cv::cvtColor(in, in,CV_RGB2GRAY);
	show(in);
}	








// 	auto edges = [](icref im)->cv::Mat
// 	{
// 		cv::Mat res;
// 		cv::Canny(im, res,10, 300, 3);
// 		return res;
// 	};

// }







#undef DECLERE_PROCESS






