#ifndef __CPP_THREAD_H_
#define __CPP_THREAD_H_

/**
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007
 *
 * (C) 2020, Bernd Porr <mail@bernporr.me.uk>
 **/
#include <iostream>
#include <thread>

#ifndef PLAYING_VAR
#define PLAYING_VAR
#include "../VirtualHardwareController.h"
#endif

// abstract thread which contains the inner workings of the thread model
class CppThread {

public:
        void start(VirtualHardwareController* hw) {
                uthread = new std::thread(CppThread::exec, this,  hw);
	}

	void join() {
		uthread->join();
		delete uthread;
		uthread = NULL;
	}

	CppThread() {};
	
	virtual ~CppThread() {
		if (uthread) {
			delete uthread;
		}
	}

protected:
	// is implemented by its ancestors
        virtual void run(VirtualHardwareController* hw) = 0;

private:
	std::thread* uthread = NULL;

	// static function which points back to the class
        static void exec(CppThread* cppThread, VirtualHardwareController* hw) {
                cppThread->run(hw);
	}
};


#endif
