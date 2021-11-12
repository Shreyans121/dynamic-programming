#include<iostream>
using namespace std;

bool equalSumPartition(int arr[], int n, int sum) {
  // Base Case
  // Memoization
  // Recursive Statement
}

int main(int argc, char const *argv[]) {
  int n, arr[100], sum = 0;
  cin>>n;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
    sum += arr[i];
  }

  if(sum % 2 != 0) {
    cout<<"NO"<<endl;
  }

  // Gets changed to Subset Sum Problem

  cout<<equalSumPartition(arr, n, sum);

  return 0;
}
