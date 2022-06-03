#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "AlertStrategyContext.h"
#include "Publisher.h"
#include "PatientFileLoader.h"
#include "PatientDatabaseLoader.h"


// forward declare several classes
class AbstractPatientDatabaseLoader;
class HospitalAlertStrategyFacade;
class Patient;


class PatientManagementSystem
{
public:

	PatientManagementSystem();
	~PatientManagementSystem();

	// initialise the patient records
	void init();
	void run();

	// ask the user for a patient and vitals and add those vitals to the patient
	void addVitalsRecord();

	void printWelcomeMessage() const;
	void printMainMenu() const;
	void printPatients() const;

protected:
	std::vector<Patient*> _patients;
	std::map<std::string, Patient*> _patientLookup;
    PatientDatabaseLoader* _patientDatabaseLoader;
    Publisher* _publisher;

};

