/*
Given 4 array of integers A, B, C and D of same size, 
find and return the maximum value of 
| A [ i ] - A [ j ] | + | B [ i ] - B [ j ] | + | C [ i ] - C [ j ] | + | D [ i ] - D [ j ] | + | i - j| 
where i != j and |x| denotes the absolute value of x.
*/
int Solution::solve(vector < int > & A, vector < int > & B, vector < int > & C, vector < int > & D) 
{
    int n = A.size();
    int e[n + 1];
    int mx = 0;
    
    // Expand the given expression in 32 different ways
    for (int p = 0; p < 32; ++p) 
    {
        for (int i = 0; i < n; ++i) 
            e[i] = 0;
        int mxx = INT_MIN, mn = INT_MAX;
        for (int i = 0; i < n; ++i) 
        {
            for (int k = 0; k < 5; ++k) 
            {
                int temp;
                if (k == 0) 
                    temp = A[i];
                else if (k == 1) 
                    temp = B[i];
                else if (k == 2) 
                    temp = C[i];
                else if (k == 3) 
                    temp = D[i];
                else 
                    temp = i;
                
                if (p & (1 << k)) 
                    e[i] += temp;
                else
                    e[i] -= temp;
            }
            mxx = max(mxx, e[i]);
            mn = min(mn, e[i]);
        }
        mx = max(mx, mxx - mn);
    }
    return mx;
}