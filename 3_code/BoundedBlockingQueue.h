#ifndef _BOUNDED_BLOCKING_QUEUE_H_
#define _BOUNDED_BLOCKING_QUEUE_H_

#include <mutex>
#include <condition_variable>
#include <deque>

using std::deque;
using std::mutex;
using std::condition_variable;
using std::lock_guard;

template<typename T>
class BoundedBlockQueue {
  public:
    BoundedBlockQueue(int maxSize = 10) : 
  private:
    mutable mutex mutex_;
    deque<T> queue_;
    condition_variable cond_;
};

#endif // _BOUNDED_BLOCKING_QUEUE_H_