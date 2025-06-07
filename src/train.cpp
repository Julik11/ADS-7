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

    bool initialLight = first->light;
    first->light = true;
    countOp++;

    int length = 0;
    Car* current = first;

    while (true) {
        int steps = 0;
        Car* temp = current;
        do {
            temp = temp->next;
            steps++;
            countOp++;
            if (temp->light) {
                temp->light = false;
                countOp++;
                break;
            }
        } while (temp != current);

        length += steps;

        if (steps == 1) break;
    }

    first->light = initialLight;
    return length;
}

int Train::getOpCount() {
    return countOp;
}
