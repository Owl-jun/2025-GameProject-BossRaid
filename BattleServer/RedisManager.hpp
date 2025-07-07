#pragma once

class RedisManager {
public:
    static RedisManager& GetInstance();

    bool Set(const std::string& key, const std::string& value, int ttlSeconds = 0);
    std::optional<std::string> Get(const std::string& key);

private:
    RedisManager();
    ~RedisManager();

    std::shared_ptr<redisContext> commandContext;   // GET/SET
    std::shared_ptr<redisContext> subscriberContext; // SUBSCRIBE

    bool Connect(const std::string& host, int port);
    void StartSubscriber(const std::string& host, int port,const std::string& channel);
    void StopSubscriber();
    void HandleMsg(const std::string& msg);

    std::atomic<bool> isRunning = false;
    std::thread subscriberThread;
};
