/*
 * GDT_MemoryPool.h
 *
 *  Created on: May 11, 2014
 *      Author: autoyujun
 */

#ifndef GDT_MEMORYPOOL_H_
#define GDT_MEMORYPOOL_H_

#include "gdt_sys.h"

namespace gdt {
/*
 * The memory pool class
 */

class MemoryPool {
public:
	MemoryPool();
	virtual ~MemoryPool();

	template <class T1,class T2>
	static void ConstructObject(T1 className,T2 objectValue){
	}

	template<class T>
	static void DestructObject(T objectName){
	}
};

} /* namespace gdt */
#endif /* GDT_MEMORYPOOL_H_ */
