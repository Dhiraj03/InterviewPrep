/*
 Given an integer A, return the total number of distinct heaps that can be formed with
 A distinct integers 
*/
long int factorial(long int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

int Solution::solve(int A) {
    vector<long int> dp(A+1);
    if(A == 0)
    return 0;
    else if(A <= 2)
    return 1;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    int  i = 1;
    int h = 0;
    int j;
    
    for(i=3;i<=A;i++)
    {   h = 0;
        j=1;
        while(j <= i)
    {
        j*=2;
        h++;
    }
    h--;
    int l;
    int m = pow(2,h);
    int p = i - pow(2,h) + 1;
    if(p >= m/2)
    l = pow(2,h)-1;
    else 
    l = pow(2,h)-1-(m/2 - p);
    int r = (i-1) - l;
        dp[i] = dp[r]*dp[l]*(factorial(i-1)/(factorial(i-1-l)*factorial(l))); 
    }
    return int(dp[A] % long(pow(10,9) + 7));
}
