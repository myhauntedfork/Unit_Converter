#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

unordered_map<string, double> lengthConversionFactors;

void initializeLengthConversionFactors() {
    lengthConversionFactors["m"] = 1.0;
    lengthConversionFactors["km"] = 1000.0;
    lengthConversionFactors["cm"] = 0.01;
    lengthConversionFactors["mm"] = 0.001;
    lengthConversionFactors["mi"] = 1609.34;
    lengthConversionFactors["yd"] = 0.9144;
    lengthConversionFactors["ft"] = 0.3048;
    lengthConversionFactors["in"] = 0.0254;
}

double convertLength(double value, const string &fromUnit, const string &toUnit) {
    double valueInMeters = value * lengthConversionFactors[fromUnit];
    return valueInMeters / lengthConversionFactors[toUnit];
}

double convertTemperature(double value, const string &fromUnit, const string &toUnit) {
    double valueInCelsius;

    if (fromUnit == "C") {
        valueInCelsius = value;
    } else if (fromUnit == "F") {
        valueInCelsius = (value - 32) * 5.0 / 9.0;
    } else if (fromUnit == "K") {
        valueInCelsius = value - 273.15;
    } else {
        throw invalid_argument("Unsupported temperature unit");
    }

    if (toUnit == "C") {
        return valueInCelsius;
    } else if (toUnit == "F") {
        return valueInCelsius * 9.0 / 5.0 + 32;
    } else if (toUnit == "K") {
        return valueInCelsius + 273.15;
    } else {
        throw invalid_argument("Unsupported temperature unit");
    }
}

int main() {
    initializeLengthConversionFactors();

    cout << "Unit Converter - Length and Temperature\n";
    cout << "Supported length units: meters (m), kilometers (km), centimeters (cm),\n";
    cout << "millimeters (mm), miles (mi), yards (yd), feet (ft), inches (in)\n";
    cout << "Supported temperature units: Celsius (C), Fahrenheit (F), Kelvin (K)\n";
    
    int choice;
    cout << "\nSelect conversion type:\n1. Length\n2. Temperature\n";
    cin >> choice;

    if (choice == 1) {
        double value;
        string fromUnit, toUnit;

        cout << "\nEnter the value to convert: ";
        cin >> value;
        
        cout << "Enter the unit to convert from (e.g., m, km, cm, mm, mi, yd, ft, in): ";
        cin >> fromUnit;
        
        cout << "Enter the unit to convert to (e.g., m, km, cm, mm, mi, yd, ft, in): ";
        cin >> toUnit;

        if (lengthConversionFactors.find(fromUnit) == lengthConversionFactors.end() ||
            lengthConversionFactors.find(toUnit) == lengthConversionFactors.end()) {
            cout << "Unsupported unit entered. Please use one of the listed units.\n";
            return 1;
        }

        double convertedValue = convertLength(value, fromUnit, toUnit);

        cout << fixed << setprecision(4);
        cout << value << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << "\n";

    } else if (choice == 2) {
        double value;
        string fromUnit, toUnit;

        cout << "\nEnter the temperature to convert: ";
        cin >> value;
        
        cout << "Enter the unit to convert from (C, F, K): ";
        cin >> fromUnit;
        
        cout << "Enter the unit to convert to (C, F, K): ";
        cin >> toUnit;

        try {
            double convertedValue = convertTemperature(value, fromUnit, toUnit);
            cout << fixed << setprecision(4);
            cout << value << " " << fromUnit << " is equal to " << convertedValue << " " << toUnit << "\n";
        } catch (const invalid_argument &e) {
            cout << e.what() << "\n";
            return 1;
        }

    } else {
        cout << "Invalid choice. Please select 1 or 2.\n";
        return 1;
    }

    return 0;
}
