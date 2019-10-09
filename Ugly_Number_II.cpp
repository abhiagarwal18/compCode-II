//https://leetcode.com/problems/ugly-number-ii/

/*
We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then

k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:

k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both 
pointers of 2 and 3.
*/

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if(n <= 0) return 0; 
        if(n == 1) return 1; 
        
        //pointers for 2, 3, 5
        int p2 = 0, p3 = 0, p5 = 0; 
        vector <int> v(n);
        
        v[0] = 1;
        
        for(int i = 1; i < n ; i++)
        {
            v[i] = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
            if(v[i] == v[p2]*2) p2++; 
            if(v[i] == v[p3]*3) p3++;
            if(v[i] == v[p5]*5) p5++;
        }
        return v[n-1];
    }
};
