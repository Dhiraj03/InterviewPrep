/*
Given two strings - A and B, find the minimum length of the window in A that 
contains all the characters in B.
Approach : Two-Pointer - Fast-Slow approach - Extend the window with the fast 
pointer until you reach a point when the frequencies of all the characters present 
in B match - then shrink the window to minimize the length
*/
string Solution::minWindow(string A, string B) {
    int lowStart = -1, lowEnd=0,i,m,n,start=0,end=0,formed=0,required,minSize ;
    minSize = 1000;
    string res;
    map<char,int> freq,found;
    m = A.size();
    n = B.size();
    for(i=0;i<n;i++)
    {
        freq[B[i]]++;
    }
    required = freq.size();
    start = 0;
    end = 0;
    while(end < m)
    { 
        found[A[end]]++;
        if(found[A[end]] == freq[A[end]])
        formed++;
        if(formed == required)
        {
            
            if( (end - start + 1) < minSize)
            {
                minSize = end-start+1;
                lowStart = start;
                lowEnd = end;
            }
             
            while(formed == required && start <= end)
            {
                found[A[start]]--;
                if(found[A[start]] < freq[A[start]])
                    formed--;
                start++;
                if( (end - start + 1) < minSize)
                {
                minSize = end-start+1;
                lowStart = start;
                lowEnd = end;
                }  
                 
            }
        }
        end++;
    }
    if(lowStart == -1)
    return "";
    return A.substr(lowStart-1, (lowEnd - lowStart +2));
}
