// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    if (first == nullptr) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;

    first->light = true;
    countOp++;
    
    int length = 1;
    Car* current = first->next;
    
    while (current != first) {
        if (current->light) {
            current->light = false;
            countOp++;
            break;
        }
        length++;
        current = current->next;
        countOp++;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}
