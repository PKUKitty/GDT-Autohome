/*
 * GDT_TransferAction.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_TRANSFERACTION_H_
#define GDT_TRANSFERACTION_H_

#include "../gdt_sys.h"
#include "../transfer/gdt_sender.h"
#include "../transfer/gdt_synsender.h"
#include "../transfer/gdt_asynsender.h"
#include "gdt_triggeraction.h"

using namespace gdt::transfer;

namespace gdt {
namespace filemonitor {

/*
 * The commnication strategy context
 * It is used by the transfer action class
 */
template<class T>
class SenderContext {
public:
	SenderContext(Sender<T>* sender) {
		this->sender = sender;
	}
	~SenderContext() {
		delete this->sender;
	}

	void DoSend(const T& ins) {
		this->sender->Send(ins);
	}
private:
	Sender<T> * sender;
};

/*
 * Transfer action class
 * It is used by file monitor
 */
template<class T1, class T2>
class TransferAction: public TriggerAction<T1> {
public:
	TransferAction();
	TransferAction(const string& mode) {
		this->mode = mode;
	}
	virtual ~TransferAction() {
	}

	void DoAction(const T2& ins) {
		if (this->mode.compare("SYN") == 0) {
			SenderContext<T2>* psc = new SenderContext<T2>(
					new SynSender<T2, T2>());
			psc->DoSend(ins);
		} else if (this->mode.compare("ASYN") == 0) {
			SenderContext<T2>* psc = new SenderContext<T2>(
					new AsynSender<T2, T2>());
			psc->DoSend(ins);
		} else
			std::cerr << "MODE ERROR!" << endl;
	}
private:
	string mode;//SYN or ASYN

};
}
}

#endif /* GDT_TRANSFERACTION_H_ */
