#include <iostream>
#include <thread>
#include <unistd.h>

// void doSomeThing() {
//     std::cout << "run doSomeThing()\n" << std::endl;
// }

class BackgroundTask {
public:
    void operator()() const {
        sleep(1);
        std::cout << "run doSomeThing()\n" << std::endl;
    }
};

void testThread() {
    BackgroundTask task;
    std::thread t(task);
    t.join();
}

int main() {
    BackgroundTask task;
    std::thread t(task);
    // std::cout << "this is main thread" << std::endl;
    // t.join();
    t.detach();
    // std::thread t(BackgroundTask()); // 不能这么写，原因是编译器会把t当做是一个函数
    //testThread();
    std::cout << "this is main thread" << std::endl;
    while(1);

    return 0;
}
