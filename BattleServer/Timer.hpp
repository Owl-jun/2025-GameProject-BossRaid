#pragma once

class Timer : public std::enable_shared_from_this<Timer> {
public:
	explicit Timer(asio::io_context& io)
		: timer_(io)
		, running_(false)
	{ }

	void StartOnce(std::chrono::milliseconds duration, std::function<void()> cb)
	{
		running_ = true;
		timer_.expires_after(duration);

		auto self = shared_from_this();
		timer_.async_wait([self, cb](const asio::error_code& ec) {
			if (!ec && self->running_) {
				cb();
			}
			self->running_ = false;
			});
	}

	void StartRepeat(std::chrono::milliseconds interval, std::function<void()> cb)
	{
		running_ = true;
		Repeat(interval, cb);
	}

	void Stop()
	{
		running_ = false;
		asio::error_code ec;
		timer_.cancel(ec);
	}

	bool IsRunning() const
	{
		return running_;
	}
private:
	void Repeat(std::chrono::milliseconds interval, std::function<void()> cb)
	{
		if (!running_) return;
		timer_.expires_after(interval);
		auto self = shared_from_this();
		timer_.async_wait([self, interval, cb](const asio::error_code& ec) {
			if (!ec && self->running_) {
				cb();
				self->Repeat(interval, cb);
			}
			});
	}
private:
	asio::steady_timer timer_;
	bool running_ = false;
};