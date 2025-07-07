#include "pch.h"
#include "Session.hpp"
#include "Player.hpp"

Session::Session(std::shared_ptr<asio::ssl::stream<tcp::socket>> stream)
	: ssl_stream(std::move(stream))
	, strand_(ssl_stream->get_executor())
	, player()
{

}

void Session::enqueue(uint8_t opcode, std::string msg)
{

}
