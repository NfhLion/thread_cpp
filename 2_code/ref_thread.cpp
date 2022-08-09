#include <thread>
#include <iostream>
#include <unistd.h>

using std::string;

void func(int i, const string&& str) {  // 这里只能是右值、值传递，或者const引用，原因见《C++并发编程实战》P23页
    sleep(1);
    // str = "abcde";
}

int main() {
    string s = "12345";
    std::thread t(func, 10, s);
    t.join();
    sleep(2);

    std::cout << s << std::endl;

    return 0;
}