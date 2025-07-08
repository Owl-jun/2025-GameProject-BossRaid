#pragma once
#include "Player.hpp"

class Session : public std::enable_shared_from_this<Session>
{
public:
	Session(std::shared_ptr<asio::ssl::stream<tcp::socket>> stream);

	void start();
	void enqueue(uint8_t opcode, std::string msg);
	void close();

	std::shared_ptr<Player> GetPlayer();

private:
	void do_read();
	void do_write();
	void handle_packet(const std::string& msg);

private:
	std::shared_ptr<asio::ssl::stream<tcp::socket>> ssl_stream_;
	asio::strand<asio::any_io_executor> strand_;

	std::queue<std::string> write_queue_;
	std::array<char, 8192> read_buffer_;

	size_t expected_body_size_ = 0;
	std::shared_ptr<Player> player_;
	std::weak_ptr<BattleRoom> battleRoom_;
};

