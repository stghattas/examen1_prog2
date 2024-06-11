#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    string genders[5] = {"non-binary", "transgender", "female", "agender", "male"};
    ifstream dataFile("./data/dataExamen.csv");
    string line, word, temp;

    int genderCount[5] = {0}; // non-binary, transgender, female, agender, male
    int locationCount[5][2] = {0}; // africa, america, asia, europe, oceania

    while (getline(dataFile, line)) {
        stringstream s(line);
        string id, first_name, email, gender, location, final_note;

        getline(s, id, ',');
        getline(s, first_name, ',');
        getline(s, email, ',');
        getline(s, gender, ',');
        getline(s, location, ',');
        getline(s, final_note, ',');

        if (gender == "non-binary") genderCount[0]++;
        else if (gender == "transgender") genderCount[1]++;
        else if (gender == "female") {
            genderCount[2]++;
            if (location == "africa") locationCount[0][0]++;
            else if (location == "america") locationCount[1][0]++;
            else if (location == "asia") locationCount[2][0]++;
            else if (location == "europe") locationCount[3][0]++;
            else if (location == "oceania") locationCount[4][0]++;
        }
        else if (gender == "agender") genderCount[3]++;
        else if (gender == "male") {
            genderCount[4]++;
            if (location == "africa") locationCount[0][1]++;
            else if (location == "america") locationCount[1][1]++;
            else if (location == "asia") locationCount[2][1]++;
            else if (location == "europe") locationCount[3][1]++;
            else if (location == "oceania") locationCount[4][1]++;
        }

        ofstream locationFile(location + ".csv", ios_base::app);
        locationFile << line << endl;
    }

    cout << "Gender count:" << endl;

            int total = 0;
        for (int i = 0; i < 5; i++) {
            total += genderCount[i];
        }
        for (int i = 0; i < 5; i++) {
            cout << genders[i] << ": " << genderCount[i] << " (" << (double)genderCount[i] / total * 100 << "%)\n";
        }



    cout << "Location count:" << endl;
    cout << "Africa - Female: " << locationCount[0][0] << ", Male: " << locationCount[0][1] << endl;
    cout << "America - Female: " << locationCount[1][0] << ", Male: " << locationCount[1][1] << endl;
    cout << "Asia - Female: " << locationCount[2][0] << ", Male: " << locationCount[2][1] << endl;
    cout << "Europe - Female: " << locationCount[3][0] << ", Male: " << locationCount[3][1] << endl;
    cout << "Oceania - Female: " << locationCount[4][0] << ", Male: " << locationCount[4][1] << endl;

    return 0;
}