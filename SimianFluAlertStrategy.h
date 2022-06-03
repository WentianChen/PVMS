
#ifndef PVMS_SIMIANFLUALERTSTRATEGY_H
#define PVMS_SIMIANFLUALERTSTRATEGY_H


#include "AlertStrategy.h"
#include "Vitals.h"

class SimianFluAlertStrategy  : public AlertStrategy{
public:
    AlertLevel calculateAlertLevel(Patient* p) override{
        AlertLevel level = AlertLevel::Green;
        Vitals* v = const_cast<Vitals *>(p->vitals().back());
        if( v->BP() > 140){
            level = AlertLevel::Red;
        }
        if( (v->BP() > 130) &&  (v->BP() <= 140)){
            level = AlertLevel::Orange;
        }
        if( (v->BP() > 110) &&  (v->BP() <= 130)){
            level = AlertLevel::Yellow;
        }
        return level;
    }
};


#endif //PVMS_SIMIANFLUALERTSTRATEGY_H
