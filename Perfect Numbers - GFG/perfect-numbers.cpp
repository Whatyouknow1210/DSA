//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long M = N;
        for(long long i=1;i*i<=N;++i)
        {
            if(i==N)break;
            if(N%i==0)
            {
                if(i==1 || i==N/i)
                {
                    M-=i;
                }
                else
                {
                    M-=i;
                    M-=N/i;
                }
            }
        }
        return M==0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends