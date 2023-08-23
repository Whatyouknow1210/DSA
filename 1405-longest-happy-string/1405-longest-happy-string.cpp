class Solution {
    /*
    PQ Solution:

        priority_queue<pair<int,char>>pq;
        string ans = "";
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        while(!pq.empty())
        {
           if(pq.size()>1)
            {
                auto f = pq.top();
                pq.pop();
                auto s = pq.top();
                pq.pop();
                int fcnt = min(2,f.first);
                int scnt = min(1,s.first);
                if(ans.size() && f.second==ans.back())
                {
                    ans += string(scnt,s.second);
                    ans+=string(fcnt,f.second);
                }
                else
                {
                    ans+=string(fcnt,f.second);
                    ans += string(scnt,s.second);
                }
                f.first-=fcnt;
                if(f.first)
                pq.push(f);
                s.first-=scnt;
                if(s.first)
                pq.push(s);
            }
            else
            {
                auto p = pq.top();
                ans += string(min(2,p.first),p.second);
                return ans;
            }
        }
        return ans;
        */
        // More Optimal Approach
    string LongestDiverseString(int a, int b, int c, char a2 = 'a', char b2 = 'b', char c2 = 'c')
    {
        if (a < b)
        {
            return LongestDiverseString(b, a, c, b2, a2, c2);
        }
        if (b < c)
        {
            return LongestDiverseString(a, c, b, a2, c2, b2);
        }
        if (b == 0)
        {
            return string(min(2, a), a2);
        }
        int a_used = min(2, a), b_used = a - a_used >= b ? 1 : 0;
        return string(a_used, a2) + string(b_used, b2) + LongestDiverseString(a - a_used, b - b_used, c, a2, b2, c2);
    }
public:
    string longestDiverseString(int a, int b, int c) {
       return LongestDiverseString(a,b,c);
    }
};