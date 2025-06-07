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
    
    while (true) {
        countOp++;
        if (current->light) {
            if (current == first) {
                break;
            } else {
                current->light = false;
                countOp++;
            }
        }
        
        length++;
        current = current->next;
        
        if (length > 10000) break;
    }
    
    first->light = markerLight;
    return length - 1;
}

int Train::getOpCount() {
    return countOp;
}
