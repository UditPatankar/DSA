// 1. Create a vector<pair<int,int>>, add 3 pairs representing {studentID, marks}, 
   // then loop through and print each in the format ID: X, Marks: Y.
// 2. Write a function pair<int,int> minMax(vector<int>& v) 
   //that returns a pair containing the minimum and maximum values in the vector (.first = min, .second = max).
// 3. Given a string s = "programming", use substr to extract and print just "gram" from it.
// 4. Write a function bool isPalindrome(string s) 
   //that checks if a string reads the same forwards and backwards (hint: compare s with its reversed version, 
   //or use two-pointer comparison — try two-pointer if you want a small challenge).

#include<bits/stdc++.h>
using namespace std;

pair<int, int> minMax(vector<int> &v) {
   int minVal =v[0];
   int maxVal = v[0];
   for(auto val : v) {
      minVal = (val < minVal) ? val : minVal;
      maxVal = (val > maxVal) ? val : maxVal;
   }
   return {minVal, maxVal};
}

bool isPalindrome(string s) {
   // string rev = s;
   // reverse(rev.begin(), rev.end());
   // return (s == rev) ? true : false;
   auto p1 = s.begin();
   auto p2 = s.end()-1;

   while(p1<p2) {
      if(*p1 != *p2) return false;
      p1++;
      p2--;
   }
   return true;
}

int main() {
   //1:
   vector<pair<int, int>> v;
   v.push_back({101, 70});
   v.emplace_back(102, 80);
   v.push_back({103, 90});
   
   for(auto p : v) {
      cout << "ID: " << p.first << ' ' << "Marks: " << p.second << endl;
   }

   //2:
   vector<int> v1 = {2, 4, 5, 7, 9, 1, 3, 22, 10};
   cout << minMax(v1).first << ' ' << minMax(v1).second << endl;

   //3:
   string s = "programming";
   int index = s.find("gram");
   cout << s.substr(index, 4) << endl;

   //4:
   cout << isPalindrome("hello")<< endl;
   cout << isPalindrome("lol") << endl;
   cout << isPalindrome("racecar") << endl;

   return 0;
}