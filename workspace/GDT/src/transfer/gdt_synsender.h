/*
 * GDT_SynSender.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_SYNSENDER_H_
#define GDT_SYNSENDER_H_


#include "gdt_sender.h"

namespace gdt {
namespace transfer {
/*
 * The SynSender class is implemented by synchronize communication
 * by boost::asio
 *
 * Meanwhile, It needs rewrite the template functions.
 */
template<class T1,class T2>
class SynSender: public Sender<T1> {
public:
	SynSender(){}
	virtual ~SynSender(){}

	virtual void PreSender(const T2& ins){

	}
	virtual void DoSender(const T2& ins){

	}
	virtual void PostSender(const T2& ins ){

	}

private:

};
}
}

#endif /* GDT_SYNSENDER_H_ */
