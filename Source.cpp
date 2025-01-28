#include <iostream>
#include <string>
#include <unordered_set>
#include <cassert>
#include <chrono>

using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to print all unique palindromic substrings
int countPalindromicSubstrings(const string& s) {
    auto start = std::chrono::high_resolution_clock::now();

    int n = s.length();
    unordered_set<string> palindromes;  // Set to store unique palindromes

    // Iterate over all possible substrings
    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            // Check if the current substring is a palindrome
            if (isPalindrome(s, start, end)) {
                // Add the palindrome to the set (duplicates are automatically handled)
                palindromes.insert(s.substr(start, end - start + 1));
            }
        }
    }

    // Print all unique palindromes
    std::cout << "\n count of palindromes for string " << s << " , " <<  palindromes.size() << std::endl;
    for (const auto& palindrome : palindromes) {
        cout << palindrome << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff = end - start;
    std::cout << "\n Time Taken : " << diff.count();
    
    return palindromes.size();
}

int main() {

    // Test cases
    assert(countPalindromicSubstrings("") == 0);
    assert(countPalindromicSubstrings("a") == 1);
    assert(countPalindromicSubstrings("aa") == 2);
    assert(countPalindromicSubstrings("abc") == 3);
    assert(countPalindromicSubstrings("aaaa") == 4);
    assert(countPalindromicSubstrings("abacdfgdcaba") == 7);

    // Additional test cases
    assert(countPalindromicSubstrings("ab") == 2);  // "a", "b"
    assert(countPalindromicSubstrings("ababa") == 5);  // "a", "b", "aba", "ababa", "bab"
    assert(countPalindromicSubstrings("abcba") == 5);  // "a", "b", "c", "b", "a", "aba", "abcba"
    assert(countPalindromicSubstrings("abcde") == 5);  // "a", "b", "c", "d", "e"
    assert(countPalindromicSubstrings("abcdcba") == 7);  // 7 single chars, 6 palindromes (aba,cdc,abcba,etc)

    return 0;
}
