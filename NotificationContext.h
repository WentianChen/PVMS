#ifndef PVMS_NOTIFICATIONCONTEXT_H
#define PVMS_NOTIFICATIONCONTEXT_H


#include "NotificationSystem.h"

class NotificationContext {

private:
    NotificationSystem *notificationSystem_;

public:
    NotificationContext();
    NotificationContext(NotificationSystem *notificationSystem = nullptr) : notificationSystem_(notificationSystem){};

    ~NotificationContext(){
        delete this->notificationSystem_;
    }

    void set_notification(NotificationSystem *notificationSystem)
    {
        delete this->notificationSystem_;
        this->notificationSystem_ = notificationSystem;
    }

    void send(Patient* p) const
    {
        this->notificationSystem_->sendNotification(p);

    }

};


#endif //PVMS_NOTIFICATIONCONTEXT_H
