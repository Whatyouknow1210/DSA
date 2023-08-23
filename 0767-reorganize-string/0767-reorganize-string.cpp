class Solution {
    // priority_queue<pair<int,char>>pq;
    // for(int i=0;i<26;i++)
        // {
        //     if(mp[i])
        //     pq.push({mp[i],char(i+'a')});
        // }
    // while(!pq.empty())
        // {
        //     if(pq.size()>1)
        //     {
        //         auto f = pq.top();
        //         pq.pop();
        //         auto s = pq.top();
        //         pq.pop();
        //         ans+=f.second;
        //         ans+=s.second;
        //         --f.first;
        //         --s.first;
        //         if(f.first)
        //         pq.push(f);
        //         if(s.first)
        //         pq.push(s);
        //     }
        //     else
        //     {
        //         auto p = pq.top();
        //         pq.pop();
        //         if(p.first>1)return "";
        //         ans+=p.second;
        //         --p.first;
        //         // cout<<ans<<" "<<p.second<<endl;
        //         return ans;
        //     }
        // }
public:
    string reorganizeString(string s) {
        int n = s.length();
        int mp[26]={0};
        int maxi = 0;
        char x = 'a';
        for(char &c:s)
        {
            ++mp[c-'a'];
            if(mp[c-'a']>maxi)
            {
                maxi = mp[c-'a'];
                x = c;
            }
        }
        if((n+1)/2<maxi)return "";
        string ans(n,'a');
        int ind = 0;
        while(maxi)
        {
            --maxi;
            --mp[x-'a'];
            ans[ind] = x;
            ind+=2;
        }
        for(int i=0;i<26;i++)
        {
            while(mp[i])
            {
               
                if(ind>=n)ind=1;
                --mp[i];
                ans[ind] = i+'a';
                 ind+=2;
            }
        }
        return ans;
    }
};