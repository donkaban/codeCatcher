#ifndef CATCHER_WINFX
#define CATCHER_WINFX
#include "common.h"
#include "window.h"

#define DECLARE_PROCESS(name) struct name : public IProcess {name(window *parent);virtual void doIt(const cv::Mat &in) override;};

class IProcess
{
public:
	using copy_lambda = std::function<cv::Mat (icref)>;
	using self_lambda = std::function<void(icref)>;
	
	IProcess(window *parent = nullptr, const dictionary<int> &def = {});
	virtual ~IProcess(); 
	virtual void doIt(const cv::Mat &) = 0;	

protected:
	window * parent();
	int  	 get(strref k);
	void 	 set(strref k, int val);
	void 	 show(icref im);
	cv::Mat  copy(icref im);

private:	
	window *		_parent;
    dictionary<int> _params;
};


namespace process
{
	DECLARE_PROCESS(blur)
	DECLARE_PROCESS(flip)
	DECLARE_PROCESS(gray)
	DECLARE_PROCESS(edge)
}

#undef DECLARE_PROCESS


#endif