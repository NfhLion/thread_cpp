#include <iostream>
#include <thread>

// void doSomeThing() {
//     std::cout << "run doSomeThing()\n" << std::endl;
// }

class BackgroundTask {
public:
    void operator()() const {
        std::cout << "run doSomeThing()\n" << std::endl;
    }
};

int main() {
    BackgroundTask task;
    std::thread t(task);
    t.join();
    // std::thread t(BackgroundTask()); // 不能这么写，原因是编译器会把t当做是一个函数

    return 0;
}
