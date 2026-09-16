#include <bits/stdc++.h>
using namespace std;
/* 
Array has numbers from 1 to n(size)
Each elements appears once but A appear twice & B is missing, return [A, B]
*/
pair<int,int> findMissingAndRepeating(vector<int> &nums) {
   int n = nums.size();

   // Sum & square Sum
   long long sumN = (n*(n+1)) / 2;
   long long sqSumN = (n*(n+1)*(2*n+1)) / 6;

   long long sum = 0; long long sqSum = 0;

   for(auto x : nums) {
      sum += x;
      sqSum += (long long)x*x;
   }

   // expressions 
   long long exp1 = sum - sumN; 
   long long exp2 = (sqSum - sqSumN) / exp1;
   
   int x = (exp1 + exp2) / 2;
   int y = x - exp1;

   return {x, y};
}

int main() {
   vector<int> nums = {3, 6, 4, 2, 2, 1};
   pair<int, int> result = findMissingAndRepeating(nums);

   cout << result.first << " " << result.second;

   return 0;
}