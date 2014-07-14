/*
 * GDT_FileMonitor.h
 *	Copyright 2014 AutoHome Inc.
 *  Created on: May 11, 2014
 *      Author: autoyujun
 */

#ifndef GDT_FILEMONITOR_H_
#define GDT_FILEMONITOR_H_

#include "../gdt_sys.h"
#include "gdt_changedobserver.h"
#include "../gdt_configure.h"
#include "../transfer/gdt_sender.h"
#include "../transfer/gdt_synsender.h"

using namespace gdt::filemonitor;
using namespace gdt::transfer;

namespace gdt {
namespace filemonitor {

/*
 * The class is used by monitoring the special file according to the config file
 * It includes two attributes filepath & triggeraction
 *  a function for client;
 */
class GDTFileMonitor {
public:
	GDTFileMonitor(const string&, const string&);
	virtual ~GDTFileMonitor();

	/*
	 *start file monitor function
	 */
	void RunFileMonitor();

private:
	string file_path; // The file that be monitored
	string trigger_action; // trigger action when the file changed
};
}

} /* namespace gdt */
#endif /* GDTFILEMONITOR_H_ */
