#include <thread>
#include <functional>
class joining_thread {
public:
    joining_thread() = delete;
    template<typename Callable, typename ... Args>
    explicit joining_thread(Callable&& func, Args&& ... args)
        : t_(std::forward<Callable>(func), std::forward<Args>(args)...)
    {}
    explicit joining_thread(std::thread t) noexcept
        : t_(std::move(t))
    {}
    joining_thread& operator=(joining_thread&& other) noexcept {
        if (joinable()) {
            join();
        }
        t_ = std::move(other.t_);
        return *this;
    }
    joining_thread& operator=(std::thread t) noexcept {
        if (joinable()) {
            join();
        }
        t_ = std::move(t);
        return *this;
    }
    ~joining_thread() noexcept {
        if (joinable()) {
            join();
        }
    }

    void swap(joining_thread& other) noexcept {
        t_.swap(other.t_);
    }

    std::thread::id get_id() const noexcept {
        return t_.get_id();
    }

    bool joinable() const noexcept {
        return t_.joinable();
    }
    void join() {
        t_.join();
    }
    void detach() {
        t_.detach();
    }

    std::thread& as_thread() noexcept {
        return t_;
    }

    const std::thread& as_thread() const noexcept {
        return t_;
    }

private:
    std::thread t_;
};