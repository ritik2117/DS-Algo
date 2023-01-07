/*
You are given an array of N integers, A1, A2, .... AN.
Return the maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as 
|A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
*/

int Solution::maxArr(vector<int> &A)
{
    int i,N,Xmax,Xmin,Ymax,Ymin,x,y;
    N = A.size();
    Xmax = Ymax = INT_MIN;
    Xmin = Ymin = INT_MAX;
    for (i=0; i<N; i++)
    {
        x = A[i] + i;
        Xmax = max(x, Xmax);
        Xmin = min(x, Xmin);  

        y = A[i] - i;
        Ymax = max(y, Ymax);
        Ymin = min(y, Ymin);
    }
    return max((Xmax-Xmin), (Ymax-Ymin));
}