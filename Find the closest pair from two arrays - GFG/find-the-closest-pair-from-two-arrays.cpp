//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int target) {
        int i=0;
        --m;
        int dis = INT_MAX;
        vector<int>ans{-1,-1};
        while(i<n && m>=0)
        {
            int currdis = abs(target-arr[i]-brr[m]);
            if(currdis<dis)
            {
                ans[0] = arr[i];
                ans[1] = brr[m];
                dis = currdis;
            }
            if(arr[i]+brr[m]<target)
            {
                ++i;
            }
            else --m;
            // else ++i,--m;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends