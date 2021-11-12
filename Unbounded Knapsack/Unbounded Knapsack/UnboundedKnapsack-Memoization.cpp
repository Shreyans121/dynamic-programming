// Here multiple instances are possible for the one that we select

#include<iostream>
using namespace std;

int knapsack(int wts[], int val[], int n, int w) {
  // Base Case
  if(n == 0 or w == 0) {
    return 0;
  }
  // Memoization
  // Recursive Statements
  if(wts[n-1] <= w) {
    return max(knapsack(wts, val, n-1, w),
      val[n-1] + knapsack(wts, val, n, w - wts[n-1]));
  }
  else {
    return knapsack(wts, val, n-1, w);
  }
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
