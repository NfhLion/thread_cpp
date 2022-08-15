#include <thread>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "BlockVector.h"

using std::string;

BlockVector<int> gBuffer;
int count = 0;
void getBufferThreadFunc() {
  while (true) {
    std::vector<int> buff;
    gBuffer.swap(buff);

    if (!buff.empty()) {
      std::cout << "thread_ID = [ " << std::this_thread::get_id() << " ] ===> get > "
                << buff[0] << std::endl;
    } else {
      std::cout << "thread_ID = [ " << std::this_thread::get_id() << " ] ===> get > NULL" << std::endl;
    }
    sleep(2);
  }
}

void setBufferThreadFunc() {
  while (true) {
    gBuffer.swap(std::vector<int>({count}));
    std::cout << "thread_ID = [ " << std::this_thread::get_id() << " ] ===> set > " << count << std::endl;
    count++;
    if (count == 10)
      count = 0;
    sleep(1);
  }
}

int main() {

  std::thread getThread(getBufferThreadFunc);
  std::thread setThread(setBufferThreadFunc);
  getThread.join();
  setThread.join();

  return 0;
}