#ifndef PVMS_NOTIFICATIONSYSTEM_H
#define PVMS_NOTIFICATIONSYSTEM_H


#include "Patient.h"

class NotificationSystem {

public:
    virtual void sendNotification(Patient* p) = 0;
    virtual ~NotificationSystem()= default;;
};


#endif //PVMS_NOTIFICATIONSYSTEM_H
