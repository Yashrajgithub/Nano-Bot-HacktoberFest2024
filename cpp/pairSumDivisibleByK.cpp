#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int>& arr, int k) {

    vector<int> vis(k, 0);  // Create a frequency array for remainders

    // Calculate remainder for each element and update the frequency array
    for(int i = 0; i < arr.size(); i++) {
        int rem = (arr[i] % k + k) % k;  // Handle negative remainders correctly
        vis[rem]++;
    }

    // Check if the count of numbers divisible by k is even
    if(vis[0] & 1) return false;

    // Check if the count of complementary remainders are equal
    for(int i = 1; i <= k / 2; i++) {
        if(vis[i] != vis[k - i]) return false;
    }

    return true;
}

int main(){

    vector<int>arr = {1,2,3,4,5,6};
    int k = 7;

    if(canArrange(arr , k)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}