#ifndef PVMS_Subscriber_H
#define PVMS_Subscriber_H


#include "Patient.h"
#include "AlertStrategyContext.h"
#include "GPNotificationSystemFacade.h"
#include "HospitalNotificationSystemFacade.h"

class Subscriber {
private:
    Patient* _patient;
public:
    Subscriber(Patient* p){
        _patient = p;
    }
    void Update(){
        auto* gpNotificationSystemFacade = new GPNotificationSystemFacade();
        gpNotificationSystemFacade->sendGPNotificationForPatient(_patient);
        auto* hospitalAlertStrategyFacade = new HospitalNotificationSystemFacade();
        hospitalAlertStrategyFacade->sendAlertForPatient(_patient);

    };
};

#endif //PVMS_Subscriber_H
