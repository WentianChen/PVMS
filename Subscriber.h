#ifndef PVMS_Subscriber_H
#define PVMS_Subscriber_H


#include "Patient.h"
#include "NotificationContext.h"
#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"

class Subscriber {
private:
    Patient* _patient;
public:
    Subscriber(Patient* p){
        _patient = p;
    }
    void Update(){
        NotificationContext *notificationContext = new NotificationContext(new HospitalAlertSystemFacade());
        notificationContext->send(_patient);
        notificationContext->set_notification(new GPNotificationSystemFacade());
        notificationContext->send(_patient);
    };
};

#endif //PVMS_Subscriber_H
