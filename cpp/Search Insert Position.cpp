
/*
Problem Statement:
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the insert position of target_Num in a sorted array
    int SearchInsert(vector<int> array, int target_Num) {
        int left = 0, right = array.size() - 1;

        // Binary search loop
        while (left <= right) {
            // Calculate mid index to split the array
            int mid = left + (right - left) / 2;

            // Check if target_Num is found at mid
            if (array[mid] == target_Num) {
                return mid; // Return the index if target_Num is found
            }
            // If target_Num is greater, ignore the left half
            else if (array[mid] < target_Num) {
                left = mid + 1;
            }
            // If target_Num is smaller, ignore the right half
            else {
                right = mid - 1;
            }
        }
        // Return the position where target_Num would be inserted
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> array = { 1, 3, 5, 6 };
    int target_Num = 5;

    // Call the function and store the returned index
    int index = solution.SearchInsert(array, target_Num);

    // Output the index where target_Num is found or should be inserted
    cout << index << endl;

    return 0;
}
