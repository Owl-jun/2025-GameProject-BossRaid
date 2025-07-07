#include "pch.h"
#include "Session.hpp"
#include "Player.hpp"

Session::Session(std::shared_ptr<asio::ssl::stream<tcp::socket>> stream)
	: ssl_stream(stream)
	, player()
{

}
