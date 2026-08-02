#include <bits/stdc++.h>
using namespace std;

// Stock Buy And Sell
// Given array represents the stock prices, a[i] is price on ith day,
// Find the maximum profit you can make by buying the stock on some day and selling it in future day. "You cannot sell before you buy - buy first sell after"

// # Brute Force - TC: O(N^2) & SC: (1)
/* int findMaxProfit(vector<int> &prices) {

   int n = prices.size();
   int maxProfit = 0;

   for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
         int profit = prices[j] - prices[i];
         maxProfit = max(maxProfit, profit);
      }
   }

   return maxProfit;
}
 */

 // # Optimal - TC: O(N) & SC: O(1)
int findMaxProfit(vector<int> &prices) {
   int maxProfit = 0;
   int miniPrice = prices[0];

   for(int i = 1; i < prices.size(); i++) {
      int currentProfit = prices[i]-miniPrice;
      maxProfit = max(maxProfit, currentProfit); // if ur getting maximum profit here, means currentPrice > miniPrice
      miniPrice = min(miniPrice, prices[i]); // then this is of no use
   }

   return maxProfit;
}

// # variant 2 - get buy & sell day as well
pair<int, int> findBuySellDay(vector<int> &prices) {
   int n = prices.size();
   int buyDay = 0;
   int sellDay = 0;
   int minPrice = prices[0];
   int minPriceDay = 0;
   int maxProfit = 0;

   for(int i = 1; i < n; i++) {
      int currentProfit = prices[i] - minPrice;
      
      if(currentProfit > maxProfit) {
         maxProfit = currentProfit;
         buyDay = minPriceDay;
         sellDay = i;
      }
      else if(prices[i] < minPrice) {
         minPrice = prices[i];
         minPriceDay = i;
      }
   }

   return {buyDay, sellDay};
}

int main() {
vector<int> prices = {7, 3, 6, 2, 4, 1, 5, 8, 0, 2};
   int profit = findMaxProfit(prices);
   cout << profit << endl;

   // variant 2
   pair<int, int> days = findBuySellDay(prices);
   cout << days.first << " " << days.second << endl;

   return 0;
}