#include <iostream>
#include <string>
#include <cctype>

int getDigit(int number);
int sumOddDigits(const std::string& cardNumber);
int sumEvenDigits(const std::string& cardNumber);

int main() {
    std::string cardNumber;

    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    // Validate input
    for(char c : cardNumber){
        if(!isdigit(c)){
            std::cout << "Invalid input! Only digits allowed.\n";
            return 1;
        }
    }

    int result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is VALID\n";
    } else {
        std::cout << cardNumber << " is NOT VALID\n";
    }

    return 0;
}

int getDigit(int number){
    return number % 10 + (number / 10 % 10);
}

int sumOddDigits(const std::string& cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}

int sumEvenDigits(const std::string& cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}