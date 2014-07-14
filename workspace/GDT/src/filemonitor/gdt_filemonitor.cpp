/*
 * GDT_FileMonitor.cpp
 *
 *  Created on: May 11, 2014
 *      Author: autoyujun
 */
#include "gdt_filemonitor.h"

namespace gdt {
namespace filemonitor {

GDTFileMonitor::GDTFileMonitor(const string& fp, const string& ta) {
	// TODO Auto-generated constructor stub
	this->file_path = fp;
	this->trigger_action = ta;
}

GDTFileMonitor::~GDTFileMonitor() {
	// TODO Auto-generated destructor stub
}

/*
 *@action WRITEFILE or TRANSFER
 */
void GDTFileMonitor::RunFileMonitor() {

	long size1, size2;

	size1 = GDTConfigure::getFileLength(this->file_path);

	while (true) {

		size2 = GDTConfigure::getFileLength(file_path);
		/* file has changed */
		if (size2 != size1) {

			char buffer[BUFFER_SIZE];
			ifstream *infile = new ifstream(file_path.c_str());

			if (!infile) {
				cerr << "Unable to read the file" << endl;
			}

			infile->seekg(size1, ios::beg);
			do {
				infile->read(buffer, BUFFER_SIZE);

				//Process the file changed
				File<string>* file = new GDTFile<string, string>();
				file->SetContent((string) buffer);

				TriggerAction<string>* ta;

				if (this->trigger_action.compare("TRANSFER") == 0) {
					//TransferAction action
					ta = new TransferAction<string, string>(
							GDTConfigure::GetInstant()->getMode());
				} else if (this->trigger_action.compare("WRITEFILE") == 0) {
					//WriteFile action
					//ta = new WriteFileAction<string,string>();
				} else {
					cerr << "trigger action error" << endl;
				}
				FileObserver<string>* fo = new FileObserver<string>(file, ta);
				fo->FileMonitor();

				delete file;
				delete fo;
				delete ta;

			} while (infile->good());

			if (infile->bad() || !infile->eof()) {
				cerr << "ifstream error" << endl;
			}

			infile->close();
			size1 = size2;
		}
		usleep(200000); //0.2 seconds
	}
}
}

} /* namespace gdt */
