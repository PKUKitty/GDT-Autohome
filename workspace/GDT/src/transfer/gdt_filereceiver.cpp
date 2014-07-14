/*
 * GDT_FileReceiver.cpp
 *
 *  Created on: May 8, 2014
 *      Author: autoyujun
 */

#include "gdt_filereceiver.h"

using namespace gdt::transfer;


tcp::socket& Session::Socket() {
	return socket_;
}

void Session::Start() {
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
			boost::bind(&Session::HandleRead, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
}

void Session::HandleRead(const boost::system::error_code& error,
		size_t bytes_transferred) {
	if (!error) {
		boost::asio::async_write(socket_,
				boost::asio::buffer(data_, bytes_transferred),
				boost::bind(&Session::HandleWrite, this,
						boost::asio::placeholders::error));
	} else {
		delete this;
	}
}

void Session::HandleWrite(const boost::system::error_code& error) {
	if (!error) {
		socket_.async_read_some(boost::asio::buffer(data_, max_length),
				boost::bind(&Session::HandleRead, this,
						boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));
	} else {
		delete this;
	}
}

