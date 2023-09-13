//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string s="";
        int d = S/9;
        int r = S%9;
        
        if((d>N) || ( N>1 && S==0) || (d==N && r!=0)) return "-1";
        for(int i=1; i<=d; i++) s+='9';
        if(s.length()<N) s+=to_string(r);
        for(int i=s.length(); i<N; i++) s+='0';
        
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends