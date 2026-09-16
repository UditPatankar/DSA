#include <bits/stdc++.h>
using namespace std;
/* 
Best Time to Buy and Sell Stock
Given an array of prices by day, find the maximum profit from one buy and one sell.
Input: nums = {7,1,5,3,6,4}
*/
int maxProfit(vector<int> &prices) {
   int maxProfit = 0;
   int buyDay = 0;
   int sellDay = 0;
   for(int i = 0; i < prices.size(); i++) {
      int profit = prices[i] - prices[buyDay];   // today's profit
      if(profit > maxProfit) {   // update the maxProfit
         maxProfit = profit;
         sellDay = i;
      }
      else if(prices[i] < prices[buyDay]) {
         buyDay = i;
      }
   }
   return maxProfit;
}

int main() {
   vector<int> prices = {7,1,5,3,6,4};
   int result = maxProfit(prices);
   cout << result << endl;
   return 0;
}