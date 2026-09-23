#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//functon to check if string is palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
//skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        //compare characters
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    string input;
    cout << "Enter a string: ";
    cin>>input;
    if(isPalindrome(input)){
        cout<<"The string is a palindrome."<<endl;
    }
    else{
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}
