#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class CableEstimator {
private:
    string loadName;
    double supplyVoltage;
    double loadPower;
    double cableLength;
    double voltageDropFactor;
    double loadCurrent;
    double voltageDrop;
    string recommendedCable;
    string advisoryMessage;
    string vdStatus;

public:
    CableEstimator() {
        loadName = "";
        supplyVoltage = 0.0;
        loadPower = 0.0;
        cableLength = 0.0;
        voltageDropFactor = 0.0;
        loadCurrent = 0.0;
        voltageDrop = 0.0;
        recommendedCable = "";
        advisoryMessage = "";
        vdStatus = "";
    }

    void setLoadDetails() {
        cout << "\n" << string(59, '-') << endl;
        cout << "Enter load name: ";
        cin.ignore();
        getline(cin, loadName);

        cout << "Enter supply voltage in volts: ";
        cin >> supplyVoltage;

        cout << "Enter load power in watts: ";
        cin >> loadPower;

        cout << "Enter cable length in metres: ";
        cin >> cableLength;

        cout << "Enter voltage drop factor: ";
        cin >> voltageDropFactor;
    }

    bool validateDetails() {
        if (supplyVoltage <= 0) {
            cout << "ERROR: Supply voltage must be greater than zero." << endl;
            return false;
        }
        if (loadPower <= 0) {
            cout << "ERROR: Load power must be greater than zero." << endl;
            return false;
        }
        if (cableLength <= 0) {
            cout << "ERROR: Cable length must be greater than zero." << endl;
            return false;
        }
        if (voltageDropFactor <= 0) {
            cout << "ERROR: Voltage drop factor must be greater than zero." << endl;
            return false;
        }
        return true;
    }

    void calculateCurrent() {
        loadCurrent = loadPower / supplyVoltage;
    }

    void calculateVoltageDrop() {
        voltageDrop = loadCurrent * cableLength * voltageDropFactor;
    }

    void recommendCableSize() {
        if (loadCurrent <= 5.0) {
            recommendedCable = "1.5 mm2 lighting cable";
            advisoryMessage = "Suitable for small lighting loads";
        }
        else if (loadCurrent <= 13.0) {
            recommendedCable = "2.5 mm2 socket/light duty cable";
            advisoryMessage = "Suitable for light socket or small appliance loads";
        }
        else if (loadCurrent <= 20.0) {
            recommendedCable = "4.0 mm2 medium load cable";
            advisoryMessage = "Suitable for moderate appliance loads";
        }
        else if (loadCurrent <= 32.0) {
            recommendedCable = "6.0 mm2 high load cable";
            advisoryMessage = "Suitable for higher current circuits";
        }
        else {
            recommendedCable = "Special design required";
            advisoryMessage = "Consult a qualified electrical engineer or standard cable table";
        }

        double vdLimit = supplyVoltage * 0.04;
        if (voltageDrop <= vdLimit) {
            vdStatus = "Acceptable Voltage Drop";
        }
        else {
            vdStatus = "High Voltage Drop";
        }
    }

    void displayReport() {
        cout << "\n" << string(59, '=') << endl;
        cout << "LOAD: " << loadName << endl;
        cout << string(59, '-') << endl;
        cout << fixed << setprecision(2);
        cout << "Load Current:           " << loadCurrent << " A" << endl;
        cout << "Approximate Voltage Drop: " << voltageDrop << " V" << endl;
        cout << "Recommended Cable:      " << recommendedCable << endl;
        cout << "Advisory:               " << advisoryMessage << endl;
        cout << "Voltage Drop Status:    " << vdStatus << endl;
        cout << string(59, '=') << endl;
    }

    void saveReportToFile(ofstream& outFile) {
        if (outFile.is_open()) {
            outFile << string(59, '=') << endl;
            outFile << "LOAD: " << loadName << endl;
            outFile << string(59, '-') << endl;
            outFile << fixed << setprecision(2);
            outFile << "Load Current:           " << loadCurrent << " A" << endl;
            outFile << "Approximate Voltage Drop: " << voltageDrop << " V" << endl;
            outFile << "Recommended Cable:      " << recommendedCable << endl;
            outFile << "Advisory:               " << advisoryMessage << endl;
            outFile << "Voltage Drop Status:    " << vdStatus << endl;
            outFile << string(59, '=') << endl << endl;
        }
    }

    string getLoadName() const { return loadName; }
    double getLoadCurrent() const { return loadCurrent; }
    double getVoltageDrop() const { return voltageDrop; }
    string getRecommendedCable() const { return recommendedCable; }
    string getVdStatus() const { return vdStatus; }
};

int main() {
    cout << "\n";
    cout << "=**********************************************************=" << endl;
    cout << "   CABLE SIZING AND VOLTAGE DROP ESTIMATOR SYSTEM" << endl;
    cout << "============================================================" << endl;
    cout << "   BEE 208 - C++ Programming" << endl;
    cout << "   Group [2.5]" << endl;
    cout << "============================================================" << endl;
    cout << "\nThis application helps you estimate cable size and" << endl;
    cout << "voltage drop for electrical installations." << endl;
    cout << "\nNOTE: This is for educational estimation only." << endl;
    cout << "=**********************************************************=" << endl;


    int numCircuits = 0;
    bool validInput = false;

    while (!validInput) {
        cout << "\nEnter number of circuits to analyse: ";
        cin >> numCircuits;

        if (cin.fail() || numCircuits <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
        else {
            validInput = true;
        }
    }

    ofstream outFile("cable_sizing_report.txt");
    if (!outFile.is_open()) {
        cout << "ERROR: Could not create report file." << endl;
        return 1;
    }

    outFile << "=*************************************************=" << endl;
    outFile << "   CABLE SIZING AND VOLTAGE DROP ESTIMATOR SYSTEM" << endl;
    outFile << "===================================================" << endl;
    outFile << "   REPORT GENERATED ON: " << __DATE__ << " " << __TIME__ << endl;
    outFile << "=*************************************************=" << endl << endl;

    vector<CableEstimator> circuits;
    int successCount = 0;

    for (int i = 1; i <= numCircuits; i++) {
        cout << "\n" << string(15, '-') << endl;
        cout << "CIRCUIT " << i << " OF " << numCircuits << endl;
        cout << string(15, '-') << endl;

        CableEstimator estimator;

        bool valid = false;
        while (!valid) {
            estimator.setLoadDetails();

            if (estimator.validateDetails()) {
                valid = true;
            }
            else {
                cout << "Please re-enter all details for this circuit." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        estimator.calculateCurrent();
        estimator.calculateVoltageDrop();
        estimator.recommendCableSize();

        estimator.displayReport();
        estimator.saveReportToFile(outFile);

        circuits.push_back(estimator);
        successCount++;
    }

    outFile.close();

    cout << "\n" << string(59, '=') << endl;
    cout << "SUMMARY" << endl;
    cout << string(59, '=') << endl;
    cout << "\nTotal circuits analysed: " << successCount << endl;
    cout << "Report saved to: cable_sizing_report.txt" << endl;
    cout << string(59, '=') << endl;
    cout << "\n";
    cout << "Thank you for using the Cable Sizing Estimator!" << endl;
    cout << "=*************************************************=" << endl;
    cout << "\nDeveloped by: [Group 2.5]" << endl;
    cout << "For: BEE 208 - C++ Programming" << endl;
    cout << "=*************************************************=" << endl;

    return 0;
}
