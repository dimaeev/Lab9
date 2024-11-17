/****************************************************
* Автор: Алексеев Д.К.                              *
* Дата: 19.11.2024                                  *
* Название: Арабские числа                          *
****************************************************/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string arabicToRoman(int number) {
    vector<pair<int, string>> romanNumerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result;
    for (const auto& [value, symbol] : romanNumerals) {
        while (number >= value) {
            result += symbol;
            number -= value;
        }
    }
    return result;
}

int romanToArabic(const string& roman) {
    int result = 0;
    int prev = 0;

    for (int i = roman.length() - 1; i >= 0; i--) {
        int num = 0;
        switch (roman[i]) {
            case 'I': num = 1; break;
            case 'V': num = 5; break;
            case 'X': num = 10; break;
            case 'L': num = 50; break;
            case 'C': num = 100; break;
            case 'D': num = 500; break;
            case 'M': num = 1000; break;
            default:
                cout << "Ошибка: некорректный символ '" << roman[i] << "'\n";
        }

        if (num >= prev) {
            result += num;
        } else {
            result -= num;
        }
        prev = num;
    }

    return result;
}

int main() {
    
    int number;
    cout << "Введите арабское число: ";
    cin >> number;

    cout << "Римское число: " << arabicToRoman(number) << endl;
    
    string roman;
    int result = romanToArabic(roman);
    cout << "\nВведите римское число: ";
    cin >> roman;
    
    cout << "Арабское число: " << result << endl;
    
    return 0;
}