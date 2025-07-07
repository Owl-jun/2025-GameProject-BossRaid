#pragma once

class Session : public std::enable_shared_from_this<Session>
{
private:
	std::shared_ptr<asio::ssl::stream<tcp::socket>> ssl_stream;
	asio::strand<asio::any_io_executor> strand_;
	std::queue<std::string> write_queue;

	Player player;

public:
	Session(std::shared_ptr<asio::ssl::stream<tcp::socket>> stream);

	void start();
	void enqueue(uint8_t opcode, std::string msg);
	void close();
private:
	void do_read();
	void do_write();
};

