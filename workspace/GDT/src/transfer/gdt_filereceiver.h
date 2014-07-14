/*
 * GDT_FileReceiver.h
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#ifndef GDT_FILERECEIVER_H_
#define GDT_FILERECEIVER_H_

#include "gdt_receiver.h"
using boost::asio::ip::tcp;

namespace gdt {
namespace transfer {

class Session {
public:
	Session(boost::asio::io_service& io_service) :
			socket_(io_service) {
	}
	tcp::socket& Socket();
	void Start();

private:
	void HandleRead(const boost::system::error_code& error,
			size_t bytes_transferred);

	void HandleWrite(const boost::system::error_code& error);

	tcp::socket socket_;
	enum {
		max_length = 1024
	};
	char data_[max_length];
};

/*
 * The FileReceiver class is used by the special file
 */
template<class T1, class T2>
//This class for file message
class FileReceiver: public Receiver<T1> {
public:
	FileReceiver(boost::asio::io_service& io_service, short port) :
			io_service_(io_service), acceptor_(io_service,
					tcp::endpoint(tcp::v4(), port)) {
		StartAccept();
	}
	virtual ~FileReceiver();

	//Impl base class functions
	virtual void PreReceive();
	virtual void DoReceive();
	virtual void PostReceive();

private:

	void StartAccept() {
		Session* new_session = new Session(io_service_);
		acceptor_.async_accept(new_session->Socket(),
				boost::bind(&FileReceiver::HandleAccept, this, new_session,
						boost::asio::placeholders::error));
	}
	void HandleAccept(Session* new_session,
			const boost::system::error_code& error) {
		if (!error) {
			new_session->Start();
		} else {
			delete new_session;
		}

		StartAccept();
	}

	boost::asio::io_service& io_service_;
	tcp::acceptor acceptor_;
};

}
}

#endif /* GDT_FILERECEIVER_H_ */
