// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        newCar->next = first;
        newCar->prev = first->prev;
        first->prev->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    bool markerLight = first->light;
    first->light = true;
    countOp++;

    int length = 1;
    Car* current = first->next;

    while (current != first) {
        countOp++;
        if (current->light) {
            current->light = false;
            countOp++;
            break;
        }
        length++;
        current = current->next;
    }

    first->light = markerLight;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
