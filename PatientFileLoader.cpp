#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"
#include "Helper.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
        string myText;
        vector<string> words;
        while (inFile >> myText) {
            words.push_back(myText);
        }
        inFile.close();

        std::vector<string> res;
        for(auto & word : words) { // loop each line
            std::cout << word << endl;
            vector<string> ws = Helper::splitString(word, "|"); // split line by "|"
            for(auto & w : ws) {
                std::cout << w << endl;
            }
        }
    }


    return patients;
}




