#include <bits/stdc++.h>
using namespace std;

/* 
Aggressive Cows Problem
Given stall positions and number of cows, find the maximum possible minimum distance between any two cows.
*/

// Helper function to check if we can place 'k' cows with at least 'mid' distance apart
bool isPlacementPossible(const vector<int> &nums, int k, int mid) {
    int currentCow = 1; 
    int lastStall = nums[0]; // Pehli cow ko pehle stall pe bitha diya

    for (int i = 1; i < nums.size(); i++) {
        // Agar current stall aur last placed stall ke beech ki distance 'mid' se zyada ya barabar hai
        if (nums[i] - lastStall >= mid) {
            currentCow++;        // Ek aur cow bitha do
            lastStall = nums[i]; // Last placed stall update kar do
        }
        // Agar saari cows successfully baith gayi, toh yeh distance possible hai
        if (currentCow >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int k) {
    // Step 1: Stalls ko sort karna zaroori hai taaki hum consecutive distances check kar sakein
    sort(nums.begin(), nums.end());
    
    // Range of minimum distance: [1, max_position - min_position]
    int low = 1; 
    int high = nums.back() - nums.front(); // Sorted array me last minus first element
    
    int ans = 0;
    while(low <= high) {
        int mid = low + ((high - low) / 2);

        if (isPlacementPossible(nums, k, mid)) {
            ans = mid;     // Ye distance possible hai, store kar lo
            low = mid + 1; // Aur bada distance try karne ke liye right side jao
        } else {
            high = mid - 1; // Distance bohot zyada hai, cows fit nahi ho rahi, chota karo
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9}; // Unsorted input
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << endl;
    return 0;
}