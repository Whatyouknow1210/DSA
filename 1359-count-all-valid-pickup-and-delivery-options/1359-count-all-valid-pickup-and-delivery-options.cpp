class Solution {
    const int mod = 1e9+7;
    long long pow(long long base,long long exp)
    {
        long long res = 1;
        while(exp)
        {
            if(exp&1)
            {
                res = (res*1ll*base)%mod;
            }
            base = (base*1ll*base)%mod;
            exp>>=1;
        }
        return res%mod;
    }
public:
    int countOrders(int n) {
        // if(n==1)return 1;
        // return (((countOrders(n-1)*1ll*(n))%mod)*(2ll*n-1))%mod;
        long long ans = 1;
        for (long long i = 1; i <= 2 * n; ++i) {
            ans = (ans * i) % mod;
        }
        long long power = pow(2, n - 1);
        long long inverse_power = pow(power, mod - 2);
        long long inverse_2 = pow(2, mod - 2);
        ans = (ans * inverse_power) % mod;
        ans = (ans * inverse_2) % mod;

        return ans;
    }
};
//  1  1  1  1  1  1
//  -  -  -  -  -  -