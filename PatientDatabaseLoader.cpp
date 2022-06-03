#include "PatientDatabaseLoader.h"

#include <iomanip>
#include <sstream>

#include "Patient.h"
#include "Vitals.h"


void PatientDatabaseLoader::initialiseConnection()
{
    // pretend this initialises a database connection
}

void PatientDatabaseLoader::loadPatients(std::vector<Patient*>& patientIn){

    // we simulate loading patients from a database here.

    // initialise a birthday from a string. This code can be reused to when loading a birthday from a file
    std::tm t{ };
    std::istringstream ss("18-02-1980");
    ss >> std::get_time(&t, "%d-%m-%Y");

    // push back a new Patient
    Patient* p = new Patient("Bloggs", "Joe", t);
    p->addDiagnosis(Diagnosis::BONEITIS);

    Vitals* v = new Vitals(37.5f, 80, 60, 16);
    p->addVitals(v);

    patientIn.push_back(p);

    // load patients from a file
    std::vector<Patient*> patientsFromFile = _patientFileLoader->loadPatients("../patients.txt");
    for (Patient* _p : patientsFromFile) {
        patientIn.push_back(_p);
    }

}

void PatientDatabaseLoader::closeConnection()
{
    // pretend this closes the database connection
}
