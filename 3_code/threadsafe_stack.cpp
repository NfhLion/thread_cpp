#include <exception>
#include <mutex>
#include <memory>
#include <stack>

struct empty_stack : std::exception {
	const char* what() const throw ();
};

template<typename T>
class threadsafe_stack {
	public:
		threadsafe_stack() : data_(), mutex_() {}
		threadsafe_stack(const threadsafe_stack& other) {
			std::lock_guard<std::mutex> lock(mutex_);
			data_ = other.data_;
		}
		threadsafe_stack& operator=(const threadsafe_stack&) = delete;

		void push(T value) {
			std::lock_guard<std::mutex> lock(mutex_);
			data_.push(value);
		}
		
		std::shared_ptr<T> pop() {
			std::lock_guard<std::mutex> lock(mutex_);
			if (data_.empty()) 
				throw empty_stack();
			std::shared_ptr<T> res(std::make_shared<T>(data_.top()));
			data_.pop();
			return res;
		}
		
		void pop(T& value) {
			std::lock_guard<std::mutex> lock(mutex_);
			if (data_.empty()) 
				throw empty_stack();
			value = data_.top();
			data_.pop();
		}

		bool empty() const {
			std::lock_guard<std::mutex> lock(mutex_);
			return data_.empty();
		}
	private:
		std::stack<T> data_;
		mutable std::mutex mutex_;
};