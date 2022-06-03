
#ifndef PVMS_GREYSCALEALERTSTRATEGY_H
#define PVMS_GREYSCALEALERTSTRATEGY_H


#include "AlertStrategy.h"
#include "Vitals.h"

class GreyscaleAlertStrategy  :public  AlertStrategy{
public:
    AlertLevel calculateAlertLevel(Patient* p) override{
        AlertLevel level = AlertLevel::Green;
        Vitals* v = const_cast<Vitals *>(p->vitals().back());
        if( (v->HR() > 120) &&  (p->age() < 12) ){
            level = AlertLevel::Red;
        }
        if( (v->HR() > 100) &&  (p->age() >= 12) ){
            level = AlertLevel::Red;
        }
        return level;
    }
};


#endif //PVMS_GREYSCALEALERTSTRATEGY_H
