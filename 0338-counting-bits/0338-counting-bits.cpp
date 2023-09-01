class Solution {
    // private:
    // int bit_count(int j)
    // {
    //     int m=0;
    //     while(j>0)
    //     {
    //         j&=(j-1);m++;
    //     }
    //     return m;
    // }
public:
    vector<int> countBits(int n) {
    //    vector<int>bits;
    //    bits.push_back(0);
    //    for(int i=1;i<=n;i++)
    //    {
    //        bits.push_back(bit_count(i));
    //    }
    //    return bits;
    // Found a very easy and well explained approach..
//     if X is ODD

// then the (LSB) Least Significant Bit will always be set and dividing by 2 means right shifting the number by 1 bit.
// so if last bit is set and right shift it by 1 bit than the last set bit will be lost.
// therfore the new number Y has 1 set bit less than in compare to X
// But if X is Even

// then LSB will be equal to 0, therefore even we do right shift by1 bit then only this 0 bit will be lost and no set bit got lost
// so When we have X has Even,

// no of set bit in X = no of set bit in Y
// and When X is ODD

// no of set bit in X = 1 + no of set bit in Y
      vector<int>bits(n+1);
      bits[0]=0;
      for(int i=1;i<=n;i++)
      {
          bits[i] = bits[i/2] + i%2;// Using memoization concept and calculating bits using concept explained above..
      }
      return bits;
    }
};