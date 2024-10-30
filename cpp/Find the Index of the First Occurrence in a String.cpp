/*
Problem Statement:
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int String(string haystack, string needle) {
        int HS = haystack.size(), ND = needle.size();
        for (int i = 0; i <= HS - ND; i++) {
            if (haystack.substr(i, ND) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string haystack = "sadbutsad";
    string needle = "sad";

    int result = solution.String(haystack, needle);
    cout << result << endl;

    return 0;
}
