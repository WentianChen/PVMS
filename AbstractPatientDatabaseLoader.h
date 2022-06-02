#pragma once

#include <vector>

// forward declare the Patient class
class Patient;

class AbstractPatientDatabaseLoader {
public:
	// initialise the database connection
	virtual void initialiseConnection() = 0;

	// load patients from that database.
	// This method should allocate dynamic (i.e. new-ed) Patients into
	// the vector reference. The function caller must take responsibility for
	// cleaning up the memory.
	virtual void loadPatients(std::vector<Patient*>& patientIn) = 0;

	virtual void closeConnection() = 0;
};