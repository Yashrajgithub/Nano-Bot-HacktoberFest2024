#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int k, vector<int> &arr)
{
    // your code here

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {

        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(arr[dq.front()]);

    for (int i = k; i < arr.size(); i++)
    {

        if (!dq.empty() && i - dq.front() + 1 == k + 1)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main(){
    vector<int>arr = {1,2,3,7,3,9};
    int k = 3;
    vector<int>ans = max_of_subarrays(k , arr);
    return 0;
}