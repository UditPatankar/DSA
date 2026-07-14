#include<bits/stdc++.h>
using namespace std;

// 1. Given vector<int> v = {1,2,2,3,3,3,4,5,5}, use array hashing (assume values 0-10) to count      frequency, then print how many times 3 and 5 appear.
// 2. Given string s = "programming", use character hashing to count frequency of each letter, then   print the highest frequency character and its count.
// 3. Given vector<int> vec = {10, 5, 100, 5, 10, 10, -3}, use unordered_map hashing (since values aren't in a small clean range) to find and print the element with the highest frequency.
// 4. Given vector<int> v = {1,2,3,4,5,6,7,8,9,10} and a set of queries {3, 7, 15}, use array hashing to check existence of each query value (print "Found"/"Not Found" for each) in O(1) per query.

int main() {
   // 1:
   vector<int> v = {1,2,2,3,3,3,4,5,5};
   int hashArr[11] = {0};
   for(auto x : v) {
      hashArr[x]++;
   }
   cout << hashArr[3] << ' ' << hashArr[5] << endl;

   // 2:
   string s = "programming";
   int hArr[256] = {0};
   for(auto c : s) {
      hArr[c]++;
   }
      //find max frequency
   int maxVal = hArr[0];
   for(int i = 0; i < 256; i++) {
      if(hArr[i] > maxVal) {
         maxVal = hArr[i];
      }
   }
      //collect all element with maxVal frequency
   vector<int> indices;
   for(int i = 0; i < 256; i++) {
      if(hArr[i] == maxVal) {
         indices.push_back(i);
      }
   }  
      //print all maxVal frequency element
   for(auto x : indices) {
      cout << (char)x << " ";
   }
   cout << ": " << maxVal << endl;

   //3:
   vector<int> vec = {10, 5, 100, 5, 10, 10, -3};
   unordered_map<int, int> mp;
   for(auto x : vec) {
      mp[x]++;
   }
   int max_freq = 0;
   for(auto x : mp) {
      if(x.second > max_freq) {
         max_freq = x.second;
      }
   }
   vector<int> keys;
   for(auto x : mp) {
      if(x.second == max_freq) {
         keys.push_back(x.first);
      }
   }
   for(auto x : keys) {
      cout << x << " ";
   }
   cout << ": " << max_freq << endl;

   //4:
   vector<int> vec1 = {1,2,3,4,5,6,7,8,9,10};
   int queries[3] = {3, 7, 15};
   int hashArray[12] = {0};
   for(auto x : vec1) {
      hashArray[x]++; // we got the frequencies
   }
   for(auto q : queries) {
      if(q < size(hashArray) && hashArray[q]) {
         cout << q << " : " << "Found" << endl;
      }
      else {
         cout << q << " : " << "Not found" << endl;
      }
   }

   return 0;
}