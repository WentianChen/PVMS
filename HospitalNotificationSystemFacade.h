#pragma once

#include "Patient.h"


class HospitalNotificationSystemFacade
{
public:
    HospitalNotificationSystemFacade();
    virtual ~HospitalNotificationSystemFacade();

    void sendAlertForPatient(Patient* p);

};
