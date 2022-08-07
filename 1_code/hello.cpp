#include <iostream>
#include <thread>

void threadFunc() {
    std::cout << "hello Concurrent world\n" << std::endl;
}

int main() {
    std::thread t(threadFunc);
    t.join();

    return 0;
}