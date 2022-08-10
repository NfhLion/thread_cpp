#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>
using std::string;

void threadFunc(string str) {
    int i = 10;
    while (i--) {
        std::cout << "threadFunc thread id = " << std::this_thread::get_id() << "----------" << i << std::endl;
        sleep(1);
    }
}

void threadFunc2(string str) {
    int i = 5;
    while (i--) {
        std::cout << "threadFunc2 thread id = " << std::this_thread::get_id() << "----------" << i << std::endl;
        sleep(1);
    }
}

int main() {
    std::thread t(threadFunc, "t");
    std::thread t2(threadFunc2, "t2");
    //t.join();
    t2.join();

    t = std::move(t2);
    return 0;
}