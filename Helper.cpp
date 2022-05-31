#include "Helper.h"
#include <vector>

using namespace std;


// https://blog.csdn.net/Mary19920410/article/details/77372828
vector<string> Helper::splitString(const string &str, const string &delimiter) {
    vector<string> rest;
    if(str.empty()) return rest;
    // First convert the string to char* type
    char * strs = new char[str.length() + 1] ;
    strcpy(strs, str.c_str());

    char * d = new char[delimiter.length() + 1];
    strcpy(d, delimiter.c_str());

    char *p = strtok(strs, d);
    while(p) {
        string s = p; //Convert the split string to a string type
        rest.push_back(s); //The results are stored in an array
        p = strtok(NULL, d);
    }

    return rest;
}
