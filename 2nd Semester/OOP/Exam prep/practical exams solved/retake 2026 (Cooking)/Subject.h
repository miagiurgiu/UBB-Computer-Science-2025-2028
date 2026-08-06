//
// Created by Maria on 07/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_SUBJECT_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_SUBJECT_H
#include "Observer.h"
#include <vector>

class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};



#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_SUBJECT_H
