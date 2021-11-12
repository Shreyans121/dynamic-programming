#include<iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
  bool t[n+1][sum+1];

  for(int i = 0; i<=n; i++) {
    t[i][0] = true;
  }

  for(int j = 1; j<=sum; j++) {
    t[0][j] = false;
  }

  for(int i = 1; i<=n; i++) {
    for(int j = 1; j<=sum; j++) {
      if(arr[i-1] <= j) {
        t[i][j] = t[i-1][j] or t[i-1][j-arr[i-1]];
      }
      else {
        t[i][j] = t[i-1][j];
      }
    }
  }
  return t[n][sum];
}

int main(int argc, char const *argv[]) {
  int n, arr[100], sum;

  cin>>n;
  for(int i = 0; i<n; i++) {
    cin>>arr[i];
  }
  cin>>sum;

  cout<<subsetSum(arr, n, sum)<<endl;
  return 0;
}
