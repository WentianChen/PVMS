#ifndef PVMS_ALERTSTRATEGYCONTEXT_H
#define PVMS_ALERTSTRATEGYCONTEXT_H


#include "AlertStrategy.h"
#include "BoneitisAlertStrategy.h"
#include "GreyscaleAlertStrategy.h"
#include "SimianFluAlertStrategy.h"

class AlertStrategyContext {

private:
    AlertStrategy *AlertStrategy_;

public:
    explicit AlertStrategyContext(const std::string& diagnosis){
        if (diagnosis == Diagnosis::BONEITIS){
            AlertStrategy_ = new BoneitisAlertStrategy();
        }else if (diagnosis == Diagnosis::GREYSCALE){
            AlertStrategy_ = new GreyscaleAlertStrategy();
        }else {
            AlertStrategy_ = new SimianFluAlertStrategy();
        }
    };
    explicit AlertStrategyContext(AlertStrategy* AlertStrategy = nullptr) : AlertStrategy_(AlertStrategy){};

    ~AlertStrategyContext(){
        delete AlertStrategy_;
    }


    AlertLevel alertLevel(Patient* p) const
    {
        return AlertStrategy_->calculateAlertLevel(p);

    }


};



#endif //PVMS_ALERTSTRATEGYCONTEXT_H
