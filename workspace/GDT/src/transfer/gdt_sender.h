/*
 * GDT_Sender.h
 *
 *  Created on: May 6, 2014
 *      Author: autoyujun
 */

#ifndef GDT_SENDER_H_
#define GDT_SENDER_H_

#include "../gdt_sys.h"

using boost::asio::io_service;
using boost::asio::ip::tcp;
using namespace std;

namespace gdt {
namespace transfer {
/*
 * The abstract class supports a interface send()
 * Meanwhile It includes threes template functinos
 * Pre,Do,Post functions.
 */
template<class T>
class Sender {
public:
	Sender(){}
	Sender(const string & hostname, unsigned short port) :
			io_service_(new io_service()), socket_(
					new tcp::socket(*io_service_)) {
		 tcp::resolver resolver(*io_service_);
		    tcp::resolver::query query(hostname, boost::lexical_cast<string, unsigned short>(port));

		    boost::system::error_code ec;
		    tcp::resolver::iterator iter = resolver.resolve(query, ec);
		    tcp::resolver::iterator end;

		    // pick the first endpoint
		    if (iter != end && ec == 0)
		    {
		        tcp::endpoint endpoint = *iter;
		        std::cout << "Connecting to: " << endpoint << std::endl;

		        socket_->connect(endpoint, ec);
		        if (ec)
		        {
		            std::cerr << "Error: " << ec << std::endl;
		            throw ec;
		        }
		    }
	}
	virtual ~Sender(){
		if (socket_ != NULL) {
				delete socket_;
			}
			if (io_service_ != NULL) {
				delete io_service_;
			}
	}

	//Abstract Functions, Impl subclass
	virtual void PreSender(const T&)=0;
	virtual void DoSender(const T&)=0;
	virtual void PostSender(const T&)=0;
	// methods
	void Send(const T& ins) {
		this->PreSender(ins);
		this->DoSender(ins);
		this->PostSender(ins);
	}

private:
	io_service * io_service_;
	tcp::socket * socket_;
};

}
}

#endif /* GDT_SENDER_H_ */

