/*
 * WriteFileAction.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_WRITEFILEACTION_H_
#define GDT_WRITEFILEACTION_H_


#include "gdt_triggeraction.h"


namespace gdt{
namespace filemonitor{

/*
 * The class is used for writing file
 *  accoring the configure file
 */
template <class T1,class T2>
class WriteFileAction : public TriggerAction<T1> {
public:
	WriteFileAction();
	virtual ~WriteFileAction();

	void DoAction();

};

}
}

#endif /* WRITEFILEACTION_H_ */
