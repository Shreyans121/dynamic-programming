// this is a NP complete problem
// We can optimize this to a pseudo polynomial time

#include<iostream>
using namespace std;

int t[101][101] = {-1};

bool subsetSum(int arr[], int n, int sum) {
  // Base Case
  if(n == 0) {
    return false;
  }
  if(sum == 0) {
    return true;
  }
  // Memoization -- pseudo polynomial time
  if(t[n-1][sum] != -1) {
    return t[n-1][sum];
  }

  // Recursive Statement -- exponential time
  // I have 2 options
    // 1. that number is less than or equal to sum
      // a. include that element
      // b. dont include that element

    // 2. that number is more than the sum
      // a. cannot include that number in the sum

  if(arr[n-1] <= sum) {
    return t[n-1][sum] = subsetSum(arr, n-1, sum) or subsetSum(arr, n-1, sum-arr[n-1]);
  }
  else {
    return t[n-1][sum] = subsetSum(arr, n-1, sum);
  }
}

int main(int argc, char const *argv[]) {
  int arr[100], n, sum;
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }

  cin>>sum;

  cout<<subsetSum(arr, n, sum)<<endl;

  return 0;
}
