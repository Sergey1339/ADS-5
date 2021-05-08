// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
  T core;
  TPQueue* next;
  TPQueue* prev;
  TPQueue* begin;
 public:
  TPQueue() {
    next = NULL;
    prev = NULL;
    begin = NULL;
  }
 void push(const T &element) {
    if (begin != NULL) {
      TPQueue* step = new TPQueue; // создание нового элемента
      step->core = element;        //захват значения 
      step->prev = prev;           //cвязь с предыдущем элементом
      prev = step;
      next->next = step;           //cвязь с предыдущем элементом
      next = step;
      if (step->core.prior > step->prev->core.prior) {
        TPQueue* step_prev = step->prev;
        TPQueue* step_this = step;
        while (step_prev && step_this->core.prior > step_prev->core.prior) {
          T x = step_this->core;
          step_this->core = step_prev->core;
          step_prev->core = x;
          step_this = step_this->prev;
          step_prev = step_prev->prev;
        }
      }
    } else {
      TPQueue* step = new TPQueue;
      step->core = element;
      begin = step;
      prev = step;
      next = step;
    }
  }
 char pop() {
   if (begin != NULL) {
     char x = begin->core.ch;
     begin = begin->next;
     return x;
   } else {
     return '/';
   }
 }
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
