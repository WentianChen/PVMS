#ifndef PVMS_AlertStrategy_H
#define PVMS_AlertStrategy_H


#include "Patient.h"

class AlertStrategy {

public:
    virtual AlertLevel calculateAlertLevel(Patient* p) = 0;
    virtual ~AlertStrategy()= default;;
};


#endif //PVMS_AlertStrategy_H
