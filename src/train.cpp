// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  Car* current = first;
  if (!current->light)
    current->light = true;
  countOp++;
  int length = 1;
  current = current->next;
  countOp++;
  while (!current->light) {
    length++;
    current = current->next;
    countOp++;
  }
  return length;
}

int Train::getOpCount() {
  return countOp;
}

int Train::getOpCount() {
    return countOp;
}
