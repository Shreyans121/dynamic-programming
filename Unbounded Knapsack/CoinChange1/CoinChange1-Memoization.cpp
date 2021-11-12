#include<iostream>
using namespace std;

int coinChange(int coins[], int n, int sum) {
  // Base Case
  if(n <= 0 and sum >= 1) {
    return 0;
  }
  if(sum == 0) {
    return 1;
  }
  if(sum < 0) {
    return 0;
  }
  // Memoization
  // Recursive Statements
  if(coins[n-1] <= sum) {
    return coinChange(coins, n-1, sum) + coinChange(coins, n, sum - coins[n-1]);
  }
  else {
    return coinChange(coins, n-1, sum);
  }
}

int main(int argc, char const *argv[]) {
  int coins[100], n, sum;
  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>coins[i];
  }
  cin>>sum;

  cout<<coinChange(coins, n, sum);

  return 0;
}
