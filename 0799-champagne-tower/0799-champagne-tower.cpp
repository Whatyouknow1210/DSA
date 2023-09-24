class Solution {
    double arr[102][102];
    // double ans = 0;
    // double f(int qr,int qg,double left,double right)
    // {
    //     if(poured<=0 || qr<0 || qg<0)return 0;
    //     if(qr==0 && qg==0)
    //     {
    //         return poured;
    //     }
    //     int curr = poured;
    //     if(curr>=1.0f)
    //     curr-=1.0;
    //     curr/=2.0;
    //     double ans = 0;
    //     ans = max(0f,f(qr-1,))
    //     return 0;
    // }
public:
    double champagneTower(int poured, int qr, int qg) {
        memset(arr,0,sizeof arr);
        arr[0][0] = (double)poured;
        for(int i=0;i<=qr;++i)
        {
            for(int j=0;j<=qg;++j)
            {
                double extra = double(arr[i][j]-1.0)/2.0;
                if(extra > 0.0)
                {
                    arr[i+1][j] += extra;
                    arr[i+1][j+1] += extra;
                }
            }
        }
        return min(1.0,arr[qr][qg]);
        // return max(f(qr-1,qg-1,0,(double(poured-1)/2.0)),f(qr-1,qg+1,0,(double(poured-1)/2.0)));
    }
};