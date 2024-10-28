#include <iostream>
#include <string>
#include <iomanip>


double lengthConverter(double value, std::string fromUnit, std::string toUnit) {
    if (fromUnit == "km") value *= 1000;
    else if (fromUnit == "ft") value /= 3.281;
    else if (fromUnit == "mi") value *= 1609.34;

    if (toUnit == "km") return value / 1000;
    else if (toUnit == "ft") return value * 3.281;
    else if (toUnit == "mi") return value / 1609.34;
    else return value;
}

double temperatureConverter(double value, std::string fromUnit, std::string toUnit) {
    if (fromUnit == "C" && toUnit == "F") return (value * 9/5) + 32;
    else if (fromUnit == "C" && toUnit == "K") return value + 273.15;
    else if (fromUnit == "F" && toUnit == "C") return (value - 32) * 5/9;
    else if (fromUnit == "F" && toUnit == "K") return (value - 32) * 5/9 + 273.15;
    else if (fromUnit == "K" && toUnit == "C") return value - 273.15;
    else if (fromUnit == "K" && toUnit == "F") return (value - 273.15) * 9/5 + 32;
    else return value;
}

void convertLength() {
    std::string fromUnit, toUnit;
    double value;
    
    std::cout << "Enter the value: ";
    std::cin >> value;
    
    std::cout << "Choose the unit to convert from (m, km, ft, mi): ";
    std::cin >> fromUnit;
    std::cout << "Choose the unit to convert to (m, km, ft, mi): ";
    std::cin >> toUnit;
    
    double result = lengthConverter(value, fromUnit, toUnit);
    std::cout << "Converted value: " << std::fixed << std::setprecision(2) << result << " " << toUnit << std::endl;
}

void convertTemperature() {
    std::string fromUnit, toUnit;
    double value;
    
    std::cout << "Enter the temperature: ";
    std::cin >> value;
    
    std::cout << "Choose the unit to convert from (C, F, K): ";
    std::cin >> fromUnit;
    std::cout << "Choose the unit to convert to (C, F, K): ";
    std::cin >> toUnit;
    
    double result = temperatureConverter(value, fromUnit, toUnit);
    std::cout << "Converted temperature: " << std::fixed << std::setprecision(2) << result << " " << toUnit << std::endl;
}

int main() {
    int choice;
    std::cout << "Welcome to the Unit Converter!" << std::endl;
    std::cout << "Select a type of conversion:\n";
    std::cout << "1. Length\n";
    std::cout << "2. Temperature\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;
    
    if (choice == 1) {
        convertLength();
    } else if (choice == 2) {
        convertTemperature();
    } else {
        std::cout << "Invalid choice, please run the program again." << std::endl;
    }
    
    return 0;
}
