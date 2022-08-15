#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NUMS 8

int* buff = NULL;

void initBUffer() {
  if (!buff) {
    int len = sizeof(int) * NUMS;
    buff = (int*)malloc(len);
    memset(buff, 0, len);
  }
}

bool getBuffer(int** pptr) {
  *pptr = buff;
  return true;
}

bool copyToBuffer(int* ptr, int* buff, int len) {
  if (ptr) {
    memcpy(ptr,buff, len);
    return true;
  }
  return false;
}

int main() {
  int arr[NUMS] = {1, 2, 3, 4, 5, 6, 7, 8};
  int* ptr = NULL;
  initBUffer();
  getBuffer(&ptr);
  bool ret = copyToBuffer(ptr, arr, sizeof(int) * NUMS);
  if (!ret) 
    return 1;
  for (int i = 0; i < NUMS; i++) {
    printf("%d ", buff[i]);
  }
  printf("\n");

  return 0;
}