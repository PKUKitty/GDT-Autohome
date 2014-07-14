/*
 * GDT_TriggerAction.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_TRIGGERACTION_H_
#define GDT_TRIGGERACTION_H_

#include "../gdt_sys.h"

namespace gdt {
namespace filemonitor {

/*
 * The abstract class
 * It is used to support a DoAction function
 */
template<class T>
class TriggerAction {
public:
	virtual void DoAction(const T&)=0;

	TriggerAction() {
	}
	virtual ~TriggerAction() {
	}
};

}
}

#endif /* GDT_TRIGGERACTION_H_ */
