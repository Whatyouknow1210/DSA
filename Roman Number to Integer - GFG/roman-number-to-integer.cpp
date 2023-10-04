//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
         unordered_map<char,int>mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        int ans = 0;
        int n = s.length();
        int i=0;
        for(i=0;i<n-1;++i)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                ans += (mp[s[i+1]]-mp[s[i]]);
                ++i;
            }
            else 
            {
                ans += mp[s[i]];
            }
        }
        if(i<n)
        ans += mp[s[i]];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends