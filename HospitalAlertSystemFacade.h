#pragma once

#include "Patient.h"
#include "NotificationSystem.h"


class HospitalAlertSystemFacade : public NotificationSystem
{
public:
    void sendNotification(Patient *p) override;
};

