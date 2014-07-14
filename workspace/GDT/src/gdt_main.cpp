//============================================================================
// Name        : gdt_main.cpp
// Author      : Yu Jun
// Version     : 0.1
// Copyright   : Autohome Inc. 2014
// Description : General Data Transfer
//============================================================================


#include "gdt_sys.h"
#include "gdt_configure.h"
#include "gdt_memorypool.h"
#include "filemonitor/gdt_filemonitor.h"

using namespace std;
using namespace gdt;
using namespace gdt::transfer;
using namespace gdt::filemonitor;

static void CMDHelp(void) {
	cout<<endl;
	cout<<"GenealDataTransfer - 0.1"<<endl;
	cout<<"Usage: ";
	cout<<"GDT -r role name [-f][-a][-p][-m][-M][-h][-c][...]\n\n";
	cout<<"The following options can also be supplied to the command:\n\n";
	cout<<" -r <rolename>                 ";
	cout<<"Input the role name: server and client.\n";
	cout<<" -a <ip address>               ";
	cout<<"The service ip address.\n";
	cout<<" -p <port>                     ";
	cout<<"The service listen port.\n";
	cout<<" -c <changedaction Trans&Write>";
	cout<<"The two actions for the changed data.\n";
	cout<<" -m <mode>                     ";
	cout<<"Input the mode of transfering data.\n";
	cout<<" -M <to send file path>        ";
	cout<<"The file increment message to be sent.\n";
	cout<<" -h <help>                     ";
	cout<<"This help.\n";

	cout<<"Examples can be found by running `man gdt`.\n\n";
	cout<<"\n\n";
}


int main(int argc, char* argv[]) {

	const string confFilePath = "config.ini";

	GDTConfigure* conf = GDTConfigure::GetInstant();
	//Read the config file
	conf->InitConf(confFilePath);

	//get long opt
	int oc;
	while ((oc = getopt(argc, argv, "r:a:c:p:m:M:h")) != -1) {
		if (-1 == oc || EOF == oc)
			break;
		switch (oc) {
		case 'r'://role
			conf->setRole(optarg);
			//conf->WriteConfByYaml(confFilePath,"role",optarg);
			break;
		case 'a'://ipaddress
			conf->setIpAddress(optarg);
			//conf->WriteConfByYaml(confFilePath,"ipAddress",optarg);
			break;
		case 'p'://port
			conf->setPort(atoi(optarg));
			//conf->WriteConfByYaml(confFilePath,"port",optarg);
			break;
		case 'c': //chandedAction
			conf->setChangedAction(optarg);
			//conf->WriteConfByYaml(confFilePath,"changedAction",optarg);
			break;
		case 'm': //mode
			conf->setMode(optarg);
			//conf->WriteConfByYaml(confFilePath,"mode",optarg);
			break;
		case 'M': //Message
			conf->setContentFilePath(optarg);
			break;
		case 'h':
			CMDHelp();
			break;
		default:
			CMDHelp();
			break;
		}
	}

	//start monitoring the content file;
	boost::object_pool<GDTFileMonitor> alloc;
	GDTFileMonitor* fileMonitor = alloc.construct(conf->getContentFilePath(),conf->getChangedAction());
	fileMonitor->RunFileMonitor();
	alloc.destroy(fileMonitor);


	delete GDTConfigure::GetInstant(); // explicit delete the conf


	/*if (conf->getMode().compare("SYN") == 0) {
				CommStrategy* pstr = new SynCommStrategy();
				CommContext* pcon = new CommContext(pstr);
				pcon->DataTransfer();
			} else {
				CommStrategy* pstr = new AsynCommStrategy();
				CommContext* pcon = new CommContext(pstr);
				pcon->DataTransfer();
			}*/
	//call template function example
	/*Receiver* pAbstract = new FileReceiver();
	pAbstract->Reveive();
	delete pAbstract;*/

	return 0;
}
