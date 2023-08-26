//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int l = 0,r = 0;
        int n = s.length();
        int ans = 0;
        bool f = false;
        unordered_map<char,int>mp;
        while(l<n)
        {
            ++mp[s[l]];
            if(mp.size()==k)f=true;
            while(mp.size()>k)
            {
                --mp[s[r]];
                if(mp[s[r]]==0)
                {
                    mp.erase(s[r]);
                }
                ++r;
            }
            ans = max(ans,l-r+1);
            ++l;
        }
        return f?ans:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends