#include<iostream>
using namespace std;

int t[101][101] = {-1};

int knapsack(int wts[], int val[], int n, int w) {
  // Base Case
  if(n==0 or w==0) {
    return 0;
  }

  // Memoization
    // it takes O(n*w) for both time and space complexity
    // as we are using 2-d array
  if(t[n][w] != -1) {
    return t[n][w];
  }

  // Recursive Statement
  // 2 options
    // 1. the element can be put in the knapsack
      // a. take the element
      // b. dont take the element

    // 2. the element cannot be put in the knapsack (wts[i]>w)
      // a. dont take that element

  if(wts[n-1] > w) {
    return t[n][w] = knapsack(wts, val, n-1, w);
  }
  else {
    return t[n][w] = max(val[n-1] + knapsack(wts, val, n-1, w - wts[n-1]),
                knapsack(wts, val, n-1, w));
  }
  // without memoizaton --
    // it will take exponential time O(2^n)
    // it computes the same subproblem again and again

}

int main(int argc, char const *argv[]) {
  int wts[100], val[100], n, w;
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>wts[i];
  }

  for(int i = 0; i<n; i++) {
    cin>>val[i];
  }

  cin>>w;

  cout<<knapsack(wts, val, n, w)<<endl;
  return 0;
}
