//Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; 
        int el; 

      
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }

        
        if (cnt1 > (n / 2)) {
            return el;
        }
        return -1; // Return -1 if no majority element is found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3}; // Example input
    int result = solution.majorityElement(nums);
    cout << "The majority element is: " << result << endl; 
    return 0;
}
