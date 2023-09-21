class Solution {
    // Optimal
    int f(vector<int>&nums1,vector<int>&nums2,int k,int al,int ar,int bl,int br)
    {
        if(ar<al)
        {
            return nums2[k-al];
        }
        if(br<bl)
        {
            return nums1[k-bl];
        }
        int Inda = (al+ar)/2,Indb = (bl+br)/2;
        int a_val = nums1[Inda];
        int b_val = nums2[Indb];
        if(Inda+Indb<k)
        {
            if(a_val > b_val)
            {
                return f(nums1,nums2,k,al,ar,Indb+1,br);
            }
            else return f(nums1,nums2,k,Inda+1,ar,bl,br);
        }
        else
        {
            if(a_val>b_val)
            {
                return f(nums1,nums2,k,al,Inda-1,bl,br);
            }
            else return f(nums1,nums2,k,al,ar,bl,Indb-1);
        }
        return -1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if((n+m)&1)
        {
            return f(nums1,nums2,(n+m)/2,0,n-1,0,m-1);
        }
        else
        {
            return (1.0*(f(nums1,nums2,(n+m)/2-1,0,n-1,0,m-1)+f(nums1,nums2,(n+m)/2,0,n-1,0,m-1)))/2;
        }
    }
};
/* 
    Brute :
        store all numbers and sort and return the answer;
        space and time O(n+m)
        int n = nums1.size();
        int m = nums2.size();
        double res = 0;
        vector<int>v(n+m);
        int i=0,j=0,k=0;
        while(i<n && j<m)
        {
            v[k++] = (nums1[i]<=nums2[j])?nums1[i++]:nums2[j++];
        }
        while(i<n)
        {
            v[k++] = nums1[i++];
        }
        while(j<m)
        {
            v[k++] = nums2[j++];
        }
        res = v[(n+m)/2];
        res += v[(n+m-1)/2];
        res/=2;
        return res;
    Better :
        Can use similar logic and stop when I get one of the index to (n+m+2)
        Instead of using extra space this can be done in 
        Time O(n+m)
        Space O(1)
        int n = nums1.size();
        int m = nums2.size();
        double res = 0;
        if(n==0)
        {
            res = (nums2[m/2]+nums2[(m-1)/2]);
            res/=2;
            return res;
        }
        else if(m==0)
        {
            res = (nums1[n/2]+nums1[(n-1)/2]);
            res/=2;
            return res;
        }
        int i=0,j=0,k = (n+m);
        int fs = -1,ss= -1;
        while(i<n && j<m && i+j<=k/2)
        {
            if(nums1[i]<=nums2[j])
            {
                fs = ss;
                ss = nums1[i++];
            }
            else
            {
                fs = ss;
                ss = nums2[j++];
            }
        }
        while(i<n && i+j<=k/2)
        {
            fs = ss;
            ss = nums1[i++];
        }
        while(j<m && i+j<=k/2)
        {
            fs = ss;
            ss = nums2[j++];
        }
        // cout<<i<<" "<<j<<" "<<fs<<" "<<ss<<endl;
        if(k%2)
        {
            fs = ss;
        }
        res = (fs+ss);
        res/=2;
        return res;

*/