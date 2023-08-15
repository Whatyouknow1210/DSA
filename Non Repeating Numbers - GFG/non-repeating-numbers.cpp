//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int m=0;
        for(auto it : nums)
        {
            m^=it;
        }
        int cnt=0;
        while(m)
        {
            if(m&1)
            break;
            else
            {
                cnt++;
                m>>=1;
            }
        }
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(1&(nums[i]>>cnt))
            xor1^=nums[i];
            else
            xor2^=nums[i];
        }
        if(xor1>xor2)
        {
            return {xor2,xor1};
        }
        return{xor1,xor2};;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends