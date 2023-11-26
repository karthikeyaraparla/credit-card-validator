#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool luhnAlgorithm(const string& cardNumber) {
    int total = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        total += digit;
        doubleDigit = !doubleDigit;
    }

    return (total % 10 == 0);
}

bool validateCreditCard(const string& cardNumber) {
    // Remove spaces and dashes from the card number
    std::string cleanedCardNumber;
    for (char c : cardNumber) {
        if (std::isdigit(c)) {
            cleanedCardNumber += c;
        }
    }

    // Check if the cleaned card number has a valid length
    if (cleanedCardNumber.length() < 13 || cleanedCardNumber.length() > 16) {
        return false;
    }

    // Check the validity using the Luhn algorithm
    return luhnAlgorithm(cleanedCardNumber);
}

int main() {
    string creditCardNumber;

    cout << "Enter credit card number: ";
    getline(std::cin, creditCardNumber);

    if (validateCreditCard(creditCardNumber)) {
        cout << "The credit card number is valid.";
    } else {
        cout << "The credit card number is invalid." ;
    }

    return 0;
}
