/*
 * Configure.cpp
 *
 *  Created on: May 5, 2014
 *      Author: autoyujun
 */

#include "gdt_configure.h"


GDTConfigure* GDTConfigure::g_conf;

GDTConfigure::GDTConfigure() {

}

GDTConfigure::~GDTConfigure() {
	// TODO Auto-generated destructor stub
}

string GDTConfigure::getIpAddress() const {
	return ipaddress;
}

void GDTConfigure::setIpAddress(string ipAddress) {
	this->ipaddress = ipAddress;
}

string GDTConfigure::getMode() const {
	return mode;
}

void GDTConfigure::setMode(string mode) {
	this->mode = mode;
}

string GDTConfigure::getName() const {
	return name;
}

void GDTConfigure::setName(string name) {
	this->name = name;
}

int GDTConfigure::getPort() const {
	return port;
}

void GDTConfigure::setPort(int port) {
	this->port = port;
}

string GDTConfigure::getRole() const {
	return role;
}

void GDTConfigure::setRole(string role) {
	this->role = role;
}

/*string Configure::getConfigFilePath() const {
 return configFilePath;
 }

 void Configure::setConfigFilePath(string configFilePath) {
 this->configFilePath = configFilePath;
 }*/

string GDTConfigure::getContentFilePath() const {
	return content_file_path;
}

void GDTConfigure::setContentFilePath(string contentFilePath) {
	this->content_file_path = contentFilePath;
}

string GDTConfigure::getChangedAction() const {
	return changed_action;
}

void GDTConfigure::setChangedAction(string changedAction) {
	this->changed_action = changedAction;
}

bool GDTConfigure::IsSpace(char c) {
	if (' ' == c || '\t' == c)
		return true;
	return false;
}

bool GDTConfigure::IsCommentChar(char c) {
	switch (c) {
	case '#':
		return true;
	default:
		return false;
	}
}

void GDTConfigure::TrimSpace(string& str) {
	if (str.empty()) {
		return;
	}

	unsigned int i, start_pos, end_pos;
	for (i = 0; i < str.size(); ++i) {
		if (!IsSpace(str[i]))
			break;
	}

	if (i == str.size()) {
		str = "";
		return;
	}
	start_pos = i;
	for (i = str.size() - 1; i >= 0; --i) {
		if (!IsSpace(str[i])) {
			break;
		}
	}
	end_pos = i;

	str = str.substr(start_pos, end_pos - start_pos + 1);
}

string GDTConfigure::ParseConfFile(const string&filename,
		const string& keyname) {

	string line="";
	string new_line="";

	ifstream *infile = new ifstream(filename.c_str());

	if (!infile) {
		return "";
	}
	while (getline(*infile, line)) {
		if (line.empty()) {
			return "";
		}
		int start_pos = 0, end_pos = line.size() - 1, pos;
		if ((pos = line.find('#')) != -1) {
			if (0 == pos) { // 行的第一个字符就是注释字符
				return "";
			}
			end_pos = pos - 1;
		}
		new_line = line.substr(start_pos, start_pos + 1 - end_pos); // 预处理，删除注释部分
		if ((pos = new_line.find('=')) == -1) {
			return ""; // 没有=号
		}
		string na = new_line.substr(0, pos);
		TrimSpace(na);
		if (na == keyname) {
			string value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));
			TrimSpace(value);
			return value;
		}
	}
	return "";
}

bool GDTConfigure::WriteConfFile(const string& name, const string& value) {
	//TODO
	return true;
}

void GDTConfigure::InitConf(const string& filename) {
	//TODO
	g_conf->setName(ParseConfFile(filename, "serviceName"));
	g_conf->setRole(ParseConfFile(filename, "role"));
	g_conf->setMode(ParseConfFile(filename, "mode"));
	g_conf->setIpAddress(ParseConfFile(filename, "ipAddress"));
	g_conf->setPort(atoi(ParseConfFile(filename, "port").c_str()));
	g_conf->setContentFilePath(ParseConfFile(filename, "contentFilePath"));
	g_conf->setChangedAction(ParseConfFile(filename, "changedAction"));
}

long GDTConfigure::getFileLength(const string& path) {

	ifstream* in = new ifstream(path.c_str());
	in->seekg(0, ios::end);
	streampos ps = in->tellg();
	long size = ps;
	in->close();
	return size;
}
void GDTConfigure::ParseConfByYaml(const string& confFilePath) {
	YAML::Node config = YAML::LoadFile(confFilePath);

	this->name = config["serviceName"].as<string>();
	this->role = config["role"].as<string>();
	this->ipaddress = config["ipAddress"].as<string>();
	this->port = config["port"].as<int>();
	this->mode = config["mode"].as<string>();
	this->content_file_path = config["contentFilePath"].as<string>();
	this->changed_action = config["changedAction"].as<string>();
}

void GDTConfigure::WriteConfByYaml(const string& confFilePath,
		const string& keyName, const string& value) {
	YAML::Node config = YAML::LoadFile(confFilePath);
	config[keyName] = value;
	std::ofstream fout(confFilePath);
	fout << config;
}

boost::mutex GDTConfigure::getMutex(){
	return this->io_mutex;
}
GDTConfigure* GDTConfigure::GetInstant() {
	//mutex
	boost::mutex::scoped_lock lock(getMutex());
	if(g_conf == NULL)
		g_conf= new GDTConfigure();

	return g_conf;
}
