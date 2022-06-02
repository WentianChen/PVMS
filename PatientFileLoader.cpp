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

    std::tm birthday{};
    vector<string> tmp;
    std::string diagnosis;
    std::string nickName;
    std::string firstName;
    std::string lastName;

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
                std::istringstream ss(w);
                ss >> std::get_time(&birthday, "%d-%m-%Y");
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
        auto* newPatient = new Patient(firstName, lastName, birthday);
        newPatient->addDiagnosis(diagnosis);

        // add vitals
        if (ws.size() == 5){
            string vitalParts =  ws[4];
            vector<string> vs = Helper::splitString(vitalParts, ";");
            for(auto & v : vs) { // loop each vital
                vector<string> params = Helper::splitString(v, ",");
//                cout <<  << endl;
                auto* newV = new Vitals(std::stof(params[0]), std::stoi(params[1]),
                                        std::stoi(params[2]), std::stoi(params[3]));
                newPatient->addVitals(newV);
            }
        }
        patients.push_back(newPatient);

    }
    return patients;
}




