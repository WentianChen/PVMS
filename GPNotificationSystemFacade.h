#pragma once

#include "Patient.h"
#include "NotificationSystem.h"


class GPNotificationSystemFacade : public NotificationSystem
{
public:
    void sendNotification(Patient *p) override;
};

