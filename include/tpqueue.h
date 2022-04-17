// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
  T arr[size] = { 0 };
  int pervi, posled;
 public:
  void push(T x) {
    int j = posled;
    for (; (j >= pervi) && arr[j % size].prior < x.prior; --j) {
      arr[(j+1) % size] = arr[j % size];
    }
    arr[(j + 1) % size] = x;
    ++posled;
  }
  T pop() {
    return arr[(pervi++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
