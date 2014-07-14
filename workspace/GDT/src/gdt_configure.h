/*
 * Configure.h
 *
 *  Created on: May 5, 2014
 *      Author: autoyujun
 */

#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#include "gdt_sys.h"
using namespace std;
/*
 * The class includes all
 * informations of system.
 *
 * It also implement a signleton object
 */

class GDTConfigure {
public:

	virtual ~GDTConfigure();

	string getIpAddress() const;
	void setIpAddress(string);

	string getMode() const;
	void setMode(string);

	string getName() const;
	void setName(string);

	int getPort() const;
	void setPort(int);

	string getRole() const;
	void setRole(string);

	/*string getConfigFilePath() const;
	 void setConfigFilePath(string );*/

	string getContentFilePath() const;
	void setContentFilePath(string);

	string getChangedAction() const;
	void setChangedAction(string);

	//parse the configure file
	static bool IsSpace(char);
	static bool IsCommentChar(char);
	static void TrimSpace(string&);

	static string ParseConfFile(const string&, const string&);
	bool WriteConfFile(const string&, const string&);

	static void InitConf(const string&);
	static long getFileLength(const string&);

	void ParseConfByYaml(const string&);
	void WriteConfByYaml(const string&, const string&, const string&);

	static GDTConfigure* GetInstant(); //used by get the only instant
	static boost::mutex getMutex();
private:
	string name;
	string role;
	string mode;
	string ipaddress;
	int port;
	//string configFilePath;
	string content_file_path;
	string changed_action;

	GDTConfigure();
	static GDTConfigure* g_conf; //  a global varible  & the only instant
	boost::mutex io_mutex;
};

#endif /* CONFIGURE_H_ */
