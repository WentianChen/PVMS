#include "PatientFileLoader.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Patient.h"
#include "Vitals.h"
#include "Helper.h"


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};
    stringstream ss;
    string line;
    vector<string> lines;
    std::ifstream inFile(file);

    if (inFile.is_open()) {
        // TODO: load your file here

        while (inFile >> line) {
            lines.push_back(line);
        }
        inFile.close();
    }

    std::string nickName;
    std::string firstName;
    std::string lastName;
    std::tm birthday{};
    vector<string> tmp;
    int year;
    int month;
    int date;
    std::string diagnosis;

    for(auto & l : lines) { // loop each line
        std::vector<string> ws = Helper::splitString(l, "|"); // split line by "|"
        for (size_t i = 0; i < ws.size(); i++) {
            string w = ws[i];
            if (i == 0) { //  get nickname
                nickName = w;
            } else if (i == 1) { // get first and last name
                tmp = Helper::splitString(w, ",");
                firstName = tmp[0];
                lastName = tmp[1];
            } else if (i == 2) { // get birthday
                tmp = Helper::splitString(w, "-");
                std::istringstream(tmp[0]) >> year;
                std::istringstream(tmp[1]) >> month;
                std::istringstream(tmp[2]) >> date;
            } else if (i == 3) { // get diagnosis
                if (w == "Boneitis") {
                    diagnosis = Diagnosis::BONEITIS;
                } else if (w == "Greyscale") {
                    diagnosis = Diagnosis::GREYSCALE;
                } else {
                    diagnosis = Diagnosis::SIMIAN_FLU;
                }
            } else { // get vitals
            }
        }

        birthday.tm_year = year;
        birthday.tm_mon = month;
        birthday.tm_mday = date;
        Patient newPatient = Patient(firstName, lastName, birthday);
        newPatient.addDiagnosis(diagnosis);

        // add vitals
        if (ws.size() == 5){
            string vitalParts =  ws[4];
            vector<string> vs = Helper::splitString(vitalParts, ";");
            for(auto & v : vs) { // loop each vital
                vector<string> params = Helper::splitString(v, ",");
                float bt;
                int bp;
                int hr;
                int rr;
                std::istringstream ( tmp[0] ) >> bt;
                std::istringstream ( tmp[1] ) >> bp;
                std::istringstream ( tmp[2] ) >> hr;
                std::istringstream ( tmp[3] ) >> rr;
                Vitals newV = Vitals(bt,bp, hr, rr);
                newPatient.addVitals(&newV);
            }
        }
        patients.push_back(&newPatient);

    }
    return patients;
}




