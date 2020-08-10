/*
 Given an array of integers and a value k, return the maximum median that can be obtained by 
 performing 'k' increment operations on any of  the elements of the array.
 Approach - No point in incrementing the first n/2 numbers.
 While k>= 0, increment the middle element and increment all the numbers after that are equal to the
 original value of the middle element.
*/
#include <iostream>
#include<vector>
#include<bits/stdc++.h> 
using namespace std;
             
int maxMedian(vector<int>& A, int k)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int mid = n/2;
    int index = mid;
    int temp;
    while(k > 0)
    {
        A[mid]++;
        k--;
        while(index < n-1 && A[mid]-1 == A[index+1] && k >=1)
        {
                        
            index++;
            A[index]++;
            k--;
        }
                     
        index = mid;
                    
    }
    sort(A.begin(), A.end());
    return A[(n/2)];
}
             
int main()
{
    int n,i,k,x;
    vector<int> A;
    cin>>n;
    cin>>k;
    for(i=0;i<n;i++)
    {
        cin>>x;
        A.push_back(x);
    }
    cout<<maxMedian(A,k);
}