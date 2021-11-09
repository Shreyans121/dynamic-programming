#include<iostream>
using namespace std;

fslkgj
int knapsack(int wts[], int val[], int n, int w) {
  int** t;
  t = new int*[n];

  for (int i = 0; i < n; i++)
    t[i] = new int[w + 1];

  for(int i = 0; i<n+1; i++) {
    for(int j = 0; j<w+1; j++) {
      if(i == 0 or j == 0) {
        t[i][j] = 0;
      }
      else if(wts[i-1] <= j) {
        t[i][j] = max((val[i-1] + t[i-1][(j-wts[i-1])]), t[i-1][j]);
      }
      else {
        t[i][j] = t[i-1][j];
      }
    }
  }

  return t[n][w];
}

int main(int argc, char const *argv[]) {
  int n, w, wts[100], val[100];
  cin>>n>>w;

  for(int i = 0; i<n; i++) {
    cin>>wts[i];
  }
  for(int i = 0; i<n; i++) {
    cin>>val[i];
  }

  cout<<knapsack(wts, val, n, w)<<endl;

  return 0;
}
