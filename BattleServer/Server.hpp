#pragma once

class Server {
private:
	asio::ip::tcp::acceptor acceptor;
	asio::io_context& io_context;
	asio::ssl::context ssl_ctx;
	std::vector<std::thread> thread_pool;
public:
	Server(asio::io_context& io_context, short port);
private:
	void start_accept();
};

