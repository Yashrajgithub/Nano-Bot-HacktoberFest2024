#include <iostream>
#include <vector>

using namespace std;

// Question Details
// Given an array of distinct integers `candidates` and a target integer `target`,
// find all unique combinations of `candidates` where the chosen numbers sum to `target`.
// Each number in `candidates` may be used an unlimited number of times in the combination.

// Constraints
// - 1 <= candidates.length <= 30
// - 1 <= candidates[i] <= 200
// - All elements of candidates are distinct.
// - 1 <= target <= 500

// Input
// - An integer vector `candidates` of distinct positive integers.
// - An integer `target` representing the desired sum.

// Output
// - A 2D vector of integers where each sub-vector is a unique combination
//   of `candidates` that sums to `target`.

class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& currentCombination, int target, int index, vector<vector<int>>& ans) {
       
        if (target == 0) {
            ans.push_back(currentCombination);
            return;
        }
      
        if (index >= candidates.size() || target < 0) return;

      
        if (candidates[index] <= target) {
            currentCombination.push_back(candidates[index]);
            helper(candidates, currentCombination, target - candidates[index], index, ans); 
            currentCombination.pop_back(); 
        }
        
    
        helper(candidates, currentCombination, target, index + 1, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentCombination;
        vector<vector<int>> ans;
        helper(candidates, currentCombination, target, 0, ans);
        return ans;
    }
};

int main() {
    vector<int> candidates;
    int n, target;
    
    cout << "Enter the number of candidates: ";
    cin >> n;
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; ++i) {
        int candidate;
        cin >> candidate;
        candidates.push_back(candidate);
    }
    
    cout << "Enter the target sum: ";
    cin >> target;

    Solution solution;
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    cout << "All unique combinations that sum up to target:\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
