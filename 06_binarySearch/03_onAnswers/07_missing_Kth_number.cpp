#include <bits/stdc++.h>
using namespace std;

/* 
LeetCode 1539: Kth Missing Positive Number
Given a sorted array and k, find the kth missing positive number.
*/

int findKthPositive(vector<int> &nums, int k) {
    int n = nums.size();
    int low = 0; 
    int high = n - 1;

    // Binary search to find the right partition where missing numbers count crosses k
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        
        // Kitne numbers missing hain nums[mid] tak, uska formula: 
        // Expected value at index mid is (mid + 1). Actual value is nums[mid].
        int missing = nums[mid] - (mid + 1);    

        if (missing < k) {
            // Agar missing numbers 'k' se kam hain, toh answer right side me hoga
            low = mid + 1;
        } else {
            // Agar missing numbers 'k' ya usse zyada ho gaye, toh left me dekho
            high = mid - 1;
        }
    }
    
    // Loop khatam hone ke baad, 'high' piche reh jata hai aur 'low' aage nikal jata hai.
    // Total missing numbers tak pahunchne ke liye: k + high + 1 (ya k + low)
    return k + high + 1; 
}

int main() {
    vector<int> nums = {2, 3, 4, 7, 11};
    int k = 5;
    int ans = findKthPositive(nums, k);
    cout << "The " << k << "th missing number is: " << ans << endl;
    return 0;
}