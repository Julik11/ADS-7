// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), current(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
        current = first;
    } else {
        newCar->next = first;
        newCar->prev = first->prev;
        first->prev->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    countOp = 0;
    int length = 0;
    bool markerSet = false;

    while (true) {
        if (!markerSet) {
            if (!current->light) {
                current->light = true;
                countOp++;
                markerSet = true;
            }
            current = current->next;
            countOp++;
        } else {
            current = current->next;
            countOp++;
            length++;

            if (current->light) {
                if (current->next == first) {
                    break;
                }
                current->light = false;
                countOp++;
            }
        }
    }

    return length + 1;
}

int Train::getOpCount() {
    return countOp;
}
