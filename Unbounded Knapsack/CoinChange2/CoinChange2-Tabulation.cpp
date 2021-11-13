#include<iostream>
#include<climits>
using namespace std;

int t[101][101] = {-1};

int knapsack(int coins[], int n, int sum) {
  // Base Case
  if(n == 0) {
    return INT_MAX - 1;
  }

  if(sum == 0) {
    return 0;
  }
  // Memoization
  if(t[n][sum] != -1) {
    return t[n-1][sum];
  }
  // Rercursive Statements
  if(coins[n-1] <= sum) {
    return t[n][sum] = min(knapsack(coins, n, sum - coins[n-1]) + 1, knapsack(coins, n-1, sum));
  }
  else {
    return t[n][sum] = knapsack(coins, n-1, sum);
  }

}

int main(int argc, char const *argv[]) {
  int coins[100], n, sum;
  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>coins[i];
  }
  cin>>sum;

  cout<<knapsack(coins, n, sum)<<endl;

  return 0;
}
