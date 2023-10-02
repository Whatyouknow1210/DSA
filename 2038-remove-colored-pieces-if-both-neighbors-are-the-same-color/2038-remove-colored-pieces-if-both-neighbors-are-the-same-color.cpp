class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int cntA=0,cntB=0;
        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            if(colors[i]=='A')
            {
                if(cnt>=0)
                {
                    ++cnt;
                }
                else
                {
                    cntB += max(0,abs(cnt)-2);
                    cnt = 1;
                }
            }
            else
            {
                if(cnt<=0)
                {
                    --cnt;
                }
                else
                {
                    cntA += max(0,cnt-2);
                    cnt = -1;
                }
            }
        }
        cout<<cntA<<" "<<cntB<<endl;
        cout<<cnt<<endl;
        if(cnt>=0)
        {
            cntA += max(0,cnt-2);
        }
        else
        cntB += max(0,abs(cnt)-2);
        return cntA>cntB;
    }
};