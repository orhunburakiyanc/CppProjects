//
//  main.cpp
//  CppProject
//
//  Created by Orhun Burak Kıyanç on 15.05.2023.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

struct port {
    string Rstart;
    string Rend;
    string time;
};
struct STtime {
    string departureTime;
    int routeID;
};
struct STdeparture {
    string routeStart;
    string routeEnd;
    int routeID;
};


vector<port> compare(vector<STdeparture>& v1, const vector<STtime>& v2, const string& time,const string& departure) {
    vector<port> portvector;
    int inhour, inminute,vhour,vminute;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i].routeStart == departure) {
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i].routeID == v2[j].routeID) {
                    inhour = stoi(time.substr(0, 2));
                    inminute = stoi(time.substr(3));

                    vhour = stoi(v2[j].departureTime.substr(0, 2));
                    vminute = stoi(v2[j].departureTime.substr(3));

                    if (vhour > inhour) {
                        portvector.push_back({ v1[i].routeStart,v1[i].routeEnd,v2[j].departureTime });
                    }
                    else if ((vhour == inhour && vminute > inminute) || (vhour == inhour && vminute == inminute) ) {
                        portvector.push_back({ v1[i].routeStart,v1[i].routeEnd,v2[j].departureTime });
                    }
                }
            }
        }
    }
    return portvector;
}

bool digitcheck(string& v) {
    for (int x = 0; x < v.size(); x++) {
        if (!isdigit(v[x])) {
            return false;
        }
    }
    return true;
}
bool checktimeinput(string& input) {
    if (input.find(":") == 2 && input.size() == 5) {
        string hour = input.substr(0, 2);
        string minute = input.substr(3);
        if (!digitcheck(hour)) {
            return false;
        }
        else {
            int checkhour = stoi(hour);
            if (checkhour > 23) {
                return false;
            }
        }
        if (!digitcheck(minute)) {
            return false;
        }
        else {
            int checkminute = stoi(minute);
            if (checkminute > 59 || checkminute < 0) {
                return false;
            }
            return true;
        }
    }
    else {
        return false;
    }
}

vector<STdeparture> departurevector(const string& file) {
    ifstream input;
    string line;
    string word;
    int countline = 0;
    vector<string> vport;

    //Counts how many lines it has  => determines the vector size.
    input.open(file.c_str());
    while (getline(input, line)) {
        countline++;
    }
    input.close();
    vector<STdeparture> vector(countline);
    //-----------------------------------


    //Takes the strings from file and put it into an array.
    // arr[0] = '2' , arr[1] = "Istanbul" , arr[2] = "Ankara" , arr[3] = '9'
    input.open(file.c_str());
    while (input >> word) {
        vport.push_back(word);
    }
    input.close();
    //-----------------------------------

    int index = 0;
    int arrIndex = 0;
    //Takes the strings from array and attends to the struct's vector
    while (index < countline) {
        vector[index] = { vport[arrIndex + 1],vport[arrIndex + 2], stoi(vport[arrIndex]) };
        index++;
        arrIndex += 3;
    }
    return vector;
}

vector<STtime> timevector(const string& file) {
    ifstream input;
    string line;
    string word;
    int countline = 0;
    vector<string> vport;

    //Counts how many lines it has  => determines the vector size.
    input.open(file.c_str());
    while (getline(input, line)) {
        countline++;
    }
    input.close();
    vector<STtime> vector(countline);
    //----------------------------------------------------------


    //Takes the strings from file and put it into an array.
    // arr[0] = '1' , arr[1] = "10:00" , arr[2] = "12" , arr[3] = "12:00"
    int vport_size = countline * 2;
    input.open(file.c_str());
    while (input >> word) {
        vport.push_back(word);
    }
    input.close();
    //-----------------------------------------------------


    int index = 0;
    int arrIndex = 0;
    //Takes the strings from array and attends to the struct's vector
    while (index < countline) {
        vector[index] = { vport[arrIndex + 1],stoi(vport[arrIndex]) };
        index++;
        arrIndex += 2;
    }
    return vector;
}

string routefileInput() {
    string filename;
    cout << "Please enter a filename for route database: ";
    cin >> filename;
    while (filename != "routes.txt" && filename != "EXIT") {
        if (filename != "routes.txt") {
            cout << "cannot open routes database file" << endl;
        }
        cout << "Please enter a filename for route database: ";
        cin >> filename;
    }
    return filename;
}
string timefileInput() {
    string filename;
    cout << "Please enter a filename for time database: ";
    cin >> filename;
    while (filename != "times.txt" && filename != "EXIT") {
        if (filename != "times.txt") {
            cout << "cannot open times database file" << endl;
        }
        cout << "Please enter a filename for time database: ";
        cin >> filename;
    }
    return filename;
}

int main(int argc, const char* argv[]) {
    vector<STdeparture> departureVector;
    vector<STtime> timeVector;
    string fileroute,filetime,timeinput,departureinput;
    fileroute = routefileInput();
    filetime = timefileInput();

    // convert the info into the vector from txt files.
    departureVector = departurevector(fileroute); // +
    timeVector = timevector(filetime); // +

    cout << "Please enter departure location: ";
    cin >> departureinput;
    while (departureinput != "EXIT" && timeinput != "EXIT")
    {
        do {

            cout << "Please enter start time of travel: ";
            cin >> timeinput;
            if (timeinput == "EXIT")
            {
                break;
            }
            else if (checktimeinput(timeinput) == false) {
                cout << "Time is not in correct format" << endl;
            }
            else {

                break;
            }
        } while (true);
        if (timeinput == "EXIT")
        {
            break;
        }
        vector<port> portvector = compare(departureVector, timeVector, timeinput,departureinput);
        cout << "The search results are: " << endl;
        for (int i = 0; i < portvector.size(); i++) {
            cout << portvector[i].Rstart << " " << portvector[i].Rend << " " << portvector[i].time << endl;
        }
        cout << "Please enter departure location: ";
        cin >> departureinput;
    }

    return 0;
}
