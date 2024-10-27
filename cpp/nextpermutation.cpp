#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such element is found, reverse the entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the element just larger than nums[idx] from the right
        int largerIdx = -1;
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                largerIdx = i;
                break;
            }
        }

        // Step 4: Swap the elements at idx and largerIdx
        swap(nums[idx], nums[largerIdx]);

        // Step 5: Reverse the elements to the right of idx
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
