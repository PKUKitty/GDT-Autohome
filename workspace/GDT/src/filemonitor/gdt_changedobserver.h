/*
 * GDT_ChangedObserver.h
 *	Copyright 2014 AutoHome Inc.
 *  Created on: May 6, 2014
 *      Author: autoyujun
 */

#ifndef GDT_CHANGEDOBSERVER_H_
#define GDT_CHANGEDOBSERVER_H_

#include "../gdt_sys.h"
#include "gdt_triggeraction.h"
#include "gdt_transferaction.h"
#include "gdt_writefileaction.h"

using namespace gdt::filemonitor;

const int BUFFER_SIZE = 1024;

namespace gdt{
namespace filemonitor{

/*
 * The observer interface class
 */
class Observer {
public:
	virtual void ProcessFileChanged() {
	}

	Observer();
	virtual ~Observer();

};

/*
 * The file interface class
 */
template<class T>
class File {
public:
	File(){}
	virtual ~File(){}

	/*
	 * Attach and Remove ,Notify the all
	 * observers
	 */
	void Attach(Observer* observer) {
		m_observers.push_back(observer);
	}

	void Remove(Observer* observer) {
		m_observers.remove(observer);
	}

	void Notify() {
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++)
			(*iter)->ProcessFileChanged();
	}

	virtual void SetContent(T ins) {
		m_content = ins;
	}
	virtual T GetContent() {
		return m_content;
	}
protected:
	T m_content;
private:
	list<Observer*> m_observers;
};

/*
 * the gdt file class
 */
template<class T1, class T2>
class GDTFile: public File<T1> {

public:
	GDTFile() {}
	virtual ~GDTFile() {}

	void SetContent(T2 ins) {
		this->m_content = ins;
	}
	T2 GetContent() const {
		return this->m_content;
	}
};

/*
 * The file observer class is used for handling the action when
 * the file changed.
 */
template<class T>
class FileObserver: public Observer {
public:
	FileObserver();
	FileObserver(File<T>* file, TriggerAction<T>* ta) :
			observer_file(file), trigger_action(ta) {
	}
	~FileObserver() {
		delete this->observer_file;
		delete this->trigger_action;
	}

	void setObserverFile(File<T>* observerFile){
		this->observer_file = observerFile;

	}
	File<T>* getObserverFile() const
	{
	    return observer_file;
	}

	TriggerAction<T>* getTriggerAction() const
	{
	    return trigger_action;
	}

	void setTriggerAction(TriggerAction<T>* triggerAction)
	{
	    this->trigger_action = triggerAction;
	}

	void ProcessFileChanged() {
		this->trigger_action->DoAction(this->observer_file->GetContent()); //strategy pattern
	}

	void FileMonitor(){
		Observer* observer = new FileObserver<T>(this->observer_file, this->trigger_action);
		this->observer_file->Attach(observer);
		this->observer_file->Notify();
		delete observer;
	}
private:
	//T observerFileName;
	File<T>* observer_file;
	TriggerAction<T>* trigger_action;
};
}
}
#endif /* GDT_CHANGEDOBSERVER_H_ */
