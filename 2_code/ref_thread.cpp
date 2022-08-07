#include <thread>
#include <iostream>
#include <unistd.h>

using std::string;

void func(int i, const string& str) {
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