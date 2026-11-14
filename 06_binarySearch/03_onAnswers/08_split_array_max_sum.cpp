#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Split Array Largest Sum (LeetCode 410)
 * -----------------------------------------------------------------------------
 * You are given an integer array 'nums' and an integer 'k'.
 * Split 'nums' into 'k' non-empty contiguous subarrays such that the largest sum
 * among these subarrays is minimized.
 *
 * Pattern: Binary Search on Answer (Minimize the Maximum)
 * Time Complexity: O(n * log(sum - max))
 * Space Complexity: O(1)
 * -----------------------------------------------------------------------------
 *
 * Core Intuition:
 * 1. Search Space [low, high]:
 *    - low = max element in nums (kisi na kisi subarray me sabse bada element toh aayega hi, so max sum can't be less than this).
 *    - high = sum of all elements (worst case: if k = 1, poora array ek hi subarray banega).
 *
 * 2. Guess & Check:
 *    - Pick 'mid' as our max allowed subarray sum.
 *    - Check if we can split the array into <= 'k' subarrays without any subarray crossing 'mid'.
 *    - If YES (true): Limit works! Store 'mid' and search LEFT (high = mid - 1) for an even smaller max sum.
 *    - If NO (false): Limit is too tight, we needed more than 'k' subarrays. Search RIGHT (low = mid + 1) to increase the limit.
 */

// Returns the maximum element in the array
int maxi(const vector<int> &nums) {
    int maxVal = INT_MIN;
    for (int num : nums) {
        maxVal = max(maxVal, num);
    }
    return maxVal;
}

// Returns the total sum of all elements in the array
int sumArr(const vector<int> &nums) {
    int total = 0;
    for (int num : nums) {
        total += num;
    }
    return total;
}

// Greedy check: Can we split 'nums' into at most 'k' subarrays with each subarray sum <= 'mid'?
bool isSplitPossible(const vector<int> &nums, int k, int mid) {
    int currentSubArr = 1;      // Start with the 1st subarray
    long long currentSum = 0;   // Sum of current subarray (long long avoids overflow)

    for (int num : nums) {
        // If a single element exceeds 'mid', this limit is impossible
        if (num > mid) return false;

        // If adding 'num' crosses the 'mid' limit, start a new subarray
        if (currentSum + num > mid) {
            currentSubArr++;
            currentSum = num;
        } else {
            currentSum += num;
        }
    }

    // Why '<= k'?
    // Agar array 'k' se kam subarrays me hi split ho gaya, toh bache hue splits hum
    // existing subarrays ko break karke easily bana sakte hain — max sum ('mid') phir bhi break nahi hoga.
    return currentSubArr <= k;
}

int splitArray(vector<int> &nums, int k) {
    // Edge case: More subarrays required than available elements
    if (k > nums.size()) return -1;

    int low = maxi(nums);
    int high = sumArr(nums);
    int ans = -1;

    while (low <= high) {
        int mid = low + ((high - low) / 2);

        if (isSplitPossible(nums, k, mid)) {
            ans = mid;         // Valid limit found, save it and try for a smaller max on the left
            high = mid - 1;
        } else {
            low = mid + 1;     // Limit too small, increase the limit on the right
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    int ans = splitArray(nums, k);
    cout << "Minimized largest sum: " << ans << endl;

    return 0;
}