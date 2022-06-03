#pragma once

#include <string>
#include <vector>
#include "AbstractPatientDatabaseLoader.h"


// forward declare the patient class
class Patient;

class PatientFileLoader: public AbstractPatientDatabaseLoader
{
public:
	// loads a list of patients from a file and returns a vector of those patients
	std::vector<Patient*> loadPatients(const std::string& file);

    void initialiseConnection() override;

    void loadPatients(std::vector<Patient *> &patientIn) override;

    void closeConnection() override;

};

