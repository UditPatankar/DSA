#include <bits/stdc++.h>
using namespace std;

// Given array contains distinct numbers, such that the smallest & largest number is present for sure
// however, there may be some missing elements bw them, return an sorted list of missing elements

// # Brute force - TC: O(N*(max-min)) & SC: O(1) excluding one used for output
// why not O(n^2), coz if nums : {1, 100000} so the inner loop runs 100000-1 times 2 for each time - 2*(10000-1)
/* vector<int> findMissingElements(vector<int> &nums) {

   vector<int> missingEls;
   int mini = INT_MAX;
   int maxi = INT_MIN;

   for(auto x : nums) {
      mini = min(mini, x);
      maxi = max(maxi, x);
   }

   for(int i = mini+1; i < maxi; i++) {
      int found = 0;
      for(auto x : nums) {
         if(x == i) {
            found = 1;
            break;
         }
      }
      if(found == 0) missingEls.push_back(i);
   }

   return missingEls;
} */

// # Better - TC: O(maxi-mini) & SC: O(n) 
vector<int> findMissingElements(vector<int> &nums) {

   unordered_set<int> uniq_elements(nums.begin(), nums.end()); // for O(1) Lookups
   vector<int> missingEls;
   int mini = INT_MAX;
   int maxi = INT_MIN;

   for(auto x : nums) {
      mini = min(mini, x);
      maxi = max(maxi, x);
   }

   // bw min and max you are pushing the missing els in sorted fashion only
   for(int i = mini+1; i < maxi; i++) {
      if(uniq_elements.find(i) == uniq_elements.end()) {
         missingEls.push_back(i);
      }
   }

   return missingEls;
}

int main() {
   vector<int> nums = {8, -3, 7, 5, 4, 10};
   vector<int> missingEls = findMissingElements(nums);

   for(auto x : missingEls) {
      cout << x << " ";
   }

   return 0;
}