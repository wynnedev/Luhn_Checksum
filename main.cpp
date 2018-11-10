/*
 * Project Name: Luhn Checksum
 *
 * Description: The program will take an undetermined number of integers and determine if they have a valid
 * checksum using Luhn Checksum standard.  If the checksum is invalid the program will give the next needed
 * integer to make the system valid.
 *
 * Constraints:  You may not store the numbers entered.  Each value must be processed one at a time.
 */

#include <iostream>

#define EOL 10      //end of line character

int double_digit(char);
int main() {

    int even_total{0};
    int odd_total{0};
    int counter{0};
    char user_entry;

    std::cout << "***Luhn Checksum***" << std::endl;
    std::cout << "Enter Valid Sequence: " <<std::endl;
    user_entry = std::cin.get();

    while(user_entry!= EOL){

        if(++counter % 2){
            odd_total += int(user_entry) - 48;
            even_total += double_digit(user_entry);
        }
        else{
            even_total += int(user_entry) - 48;
            odd_total += double_digit(user_entry);
        }
        user_entry = std::cin.get();
    }

    if(counter%2){
        if(odd_total % 10)
            std::cout << "Checksum Invalid";
        else
            std::cout << "Checksum Valid";
    }

    else {
        if (even_total % 10)
            std::cout << "Checksum Invalid ";
        else
            std::cout << "Checksum Valid";
    }

    return 0;
}

int double_digit(char c){
    int num = (int(c) - 48) * 2;

    if(num >= 10)
        return 1 + num%10;
    else
        return num;
}