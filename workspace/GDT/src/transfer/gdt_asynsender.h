/*
 * GDT_AsynSender.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_ASYNSENDER_H_
#define GDT_ASYNSENDER_H_



#include "gdt_sender.h"

namespace gdt {
namespace transfer {
/*
 * The SynSender class is implemented by asynchronize communication
 * by boost::asio
 *
 * Meanwhile, It needs rewrite the template functions.
 */

template <class T1,class T2>
class AsynSender: public Sender<T1> {
public:
	AsynSender();
	virtual ~AsynSender();

	virtual void PreSender(const T2& ins){

	}
	virtual void DoSender(const T2&){

	}
	virtual void PostSender(const T2&){

	}

private:

};
}
}

#endif /* GDT_ASYNSENDER_H_ */
