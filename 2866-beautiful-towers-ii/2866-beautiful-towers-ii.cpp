#define ll long long
class Solution {
    public:
    long long maximumSumOfHeights(vector<int>& mx) {
        int n = mx.size();
        long long pref[n+1],suff[n+1];
        ll ans = 0;
        stack<int>st;
        suff[n] = 0;
        for(int i=n-1;i>=0;--i)
        {
          while(st.size() && mx[st.top()]>mx[i])
          {
            st.pop();
          }
          if(st.empty())
          {
            suff[i] = n;
          }
          else suff[i] = st.top();
          st.push(i);
        }
        for(int i=n-1;i>=0;--i)
        {
          int ind = suff[i];
          if(ind==n)
          {
            suff[i] = (n-i)*1ll*(mx[i]);
          }
          else 
          {
            suff[i] = suff[ind] + (ind-i)*1ll*(mx[i]);
          }
        }
        while(st.size())st.pop();
        // st.clear();
        for(int i=0;i<n;++i)
        {
          while(st.size() && mx[st.top()]>mx[i])
          {
            st.pop();
          }
          if(st.empty())
          {
            pref[i] = -1;
          }
          else pref[i] = st.top();
          st.push(i);
        }
        for(int i=0;i<n;++i)
        {
          int ind = pref[i];
          if(ind==-1)
          {
            pref[i] = (i-ind)*1ll*(mx[i]);// so it doesn;t have any small element to lef tso (i+1)*mx[i] will give us max output to left
          }
          else 
          {
            // if we have a small element to left then till that element we will take current element and add it to result of index of small element to left
            pref[i] = pref[ind] + (i - ind)*1ll*(mx[i]);
          }
        }
        for(int i=0;i<n;++i)
        {
          ans = max(ans,pref[i]+suff[i+1]);
        }
        return ans;
    }
};
/*
Test Cases :
[5,3,4,1,1]
[6,5,3,9,2,7]
[3,2,5,5,2,3]
[6,5,3,9,2,7]
[3,2,5,5,2,3]
[1000000000]
[1,1,4,3,3,3,6]
*/
#undef ll