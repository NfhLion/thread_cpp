#include <thread>
#include <iostream>

// RAII
class thread_guard {
public:
    explicit thread_guard(std::thread& t)
        : t_(t)
    {

    }
    ~thread_guard() {
        if (t_.joinable()) {
            t_.join();
        }
    }

    thread_guard(const thread_guard& tg) = delete;
    thread_guard& operator=(const thread_guard& tg) = delete;

private:
    std::thread& t_;
};

class scoped_thread {
public:
    explicit scoped_thread(std::thread t)
        : t_(std::move(t)) 
    {
        if (!t_.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() {
        t_.join();
    }

    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;

private:
    std::thread t_;
};

int main() {

    return 0;
}