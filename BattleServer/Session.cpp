#include "pch.h"
#include "Player.hpp"
#include "Session.hpp"
#include "structs.hpp"
#include "BattleRoom.hpp"
#include "helpers.hpp"

void Session::start()
{
	do_read();
}

void Session::enqueue(uint8_t opcode, std::string msg)
{
	auto self = shared_from_this();
	asio::post(strand_, [this, self, opcode, msg]() {
		std::string packet = MakePacket(opcode, msg);
		write_queue_.push(packet);
		if (write_queue_.size() == 1)
		{
			do_write();
		}
		}
	);
}

void Session::do_read()
{
	auto self = shared_from_this();

	ssl_stream_->async_read_some(asio::buffer(read_buffer_),
		asio::bind_executor(strand_,
			[this, self](std::error_code ec, std::size_t bytes_transferred)
			{
				if (ec) return close();

				do_read();
			}
		)
	);
}

void Session::do_write()
{
	auto self = shared_from_this();
	asio::async_write(*ssl_stream_, asio::buffer(write_queue_.front()),
		asio::bind_executor(strand_,
			[this, self](std::error_code ec, std::size_t)
			{
				if (ec) return close();

				write_queue_.pop();
				if (!write_queue_.empty())
				{
					do_write();
				}
			}
		)
	);
}


