
#ifndef PVMS_BONEITISALERTSTRATEGY_H
#define PVMS_BONEITISALERTSTRATEGY_H

#include "AlertStrategy.h"
#include "Vitals.h"

class BoneitisAlertStrategy : public AlertStrategy{
public:
    AlertLevel calculateAlertLevel(Patient* p) override{
        AlertLevel level = AlertLevel::Green;
        Vitals* v = const_cast<Vitals *>(p->vitals().back());
        if (v->RR() > 40) {
            level = AlertLevel::Red;
        }
        if( (v->RR() > 30) &&  (v->RR() <= 40)){
            level = AlertLevel::Orange;
        }
        if( (v->RR() > 20) &&  (v->RR() <= 30)){
            level = AlertLevel::Yellow;
        }
        return level;
    }
};


#endif //PVMS_BONEITISALERTSTRATEGY_H
