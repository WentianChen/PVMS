#include "HospitalNotificationSystemFacade.h"

#include <iostream>


HospitalNotificationSystemFacade::HospitalNotificationSystemFacade()
{ }

HospitalNotificationSystemFacade::~HospitalNotificationSystemFacade()
{ }

void HospitalNotificationSystemFacade::sendAlertForPatient(Patient* p)
{
    if (p->alertLevel() == AlertLevel::Red) {
        // A mocked alert message. A real message would use an SMS/pager gateway or similar
        std::cout << std::endl;
        std::cout << "This is an alert to the hospital:" << std::endl;
        std::cout << "Patient: " << p->humanReadableID() << " has a critical alert level" << std::endl;
    }
}