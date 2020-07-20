/*
Given a number 'n', return the number of structurally unique BSTs that can be 
constructed (should store values 1 ... n)

** Catalan number - DP, keep root fixed and explore possibilities in the left and
right subtree, when the root is fixed, the possibilities in the right and left subtree
narrow down - the left ST can contain only smaller elements and the right subtree can
contain only greater elements  
  G(n) = F(1,n) + F(2,n) + .... + F(n,n)
  where G(n) represents the nth catalan number and F(i,n) is the number of unique BSTs 
  that can be constructed with i as the root and n number of nodes.
  Again, F(i,n) equals G(i-1)*G(j-i), where i-1 and j-i are the number of elements on
  either subtree - we are basically multiplying the number of possibilities of both
  subtrees to find the total.
  Bottom-up DP - dp[0] = 1, dp[1] = 1
  For every i, run a loop from 1 to i, and add dp[j-1]*dp[i-j] to dp[i]
*/