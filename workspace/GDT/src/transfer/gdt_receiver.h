#ifndef _GDT_RECEIVER_H_
#define _GDT_RECEIVER_H_


#include "../gdt_sys.h"

namespace gdt {
namespace transfer {
/*
 * The abstract class supports a interface receiver()
 * Meanwhile It includes threes template functinos
 * Pre,Do,Post functions.
 */
template<class T>
class Receiver {
public:
	virtual ~Receiver();

	//Abstract Functions, Impl subclass
	virtual void PreReceive(const T&)=0;
	virtual void DoReceive(const T&)=0;
	virtual void PostReceive(const T&)=0;

	void Receive(const T& ins) {
		this->PreReceive(ins);
		this->DoReceive(ins);
		this->PostReceive(ins);
	}

protected:
	Receiver();

};

}
}

#endif
