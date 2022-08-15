#ifndef _BLOCK_VECTOR_H_
#define _BLOCK_VECTOR_H_

#include <vector>
#include <mutex>

// gloabl thread safe vector
template <typename T>
class BlockVector {
  public:
    BlockVector() : buffer_(), mutex_()
    {
    }

    BlockVector(const T* buff, size_t size) {
      std::lock_guard<std::mutex> lock(mutex_);
      buffer_.insert(buff, buff + size);
    }
    BlockVector(std::vector<T>& buff) {
      std::lock_guard<std::mutex> lock(mutex_);
      buffer_.swap(buff);
    }

    void swap(std::vector<T>&& buff) {
      std::lock_guard<std::mutex> lock(mutex_);
      buffer_.swap(buff);
    }

    void swap(std::vector<T>& buff) {
      std::lock_guard<std::mutex> lock(mutex_);
      buffer_.swap(buff);
    }

    bool empty() {
      std::lock_guard<std::mutex> lock(mutex_);
      return buffer_.empty();
    }

    void clear() {
      std::lock_guard<std::mutex> lock(mutex_);
      buffer_.clear();
    }

  private:
    std::vector<T> buffer_;
    mutable std::mutex mutex_;
};

#endif // _BLOCK_VECTOR_H_