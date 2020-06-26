#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x.size())

vector<vector<int>> adj;
vector<int> in;
vector<vector<int>> paths;

void dfs(int v, vector<int> path = {}) {
  path.push_back(v);
  if(SZ(adj[v]) == 0)
  paths.push_back(path);
  for(auto x: adj[v]) {
    dfs(x, path);
  }
  path.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin>>n;
  adj.resize(n, vector<int>(0));
  in.resize(n);
  int x, y;
  string st;
  char ch;
  getline(cin, st);
  while(getline(cin, st)) {
    stringstream ss(st);
    ss>>x;
    ss>>ch;
    ss>>y;
    adj[x].push_back(y);
    in[y]++;
  }
  for(int i = 0; i<n; i++) {
    if(in[i] == 0) {
      dfs(i);
    }
  }
  for(auto p: paths) {
    for(int i = 0; i<SZ(p); i++) {
      cout<<p[i];
      if(i != SZ(p)-1) cout<<"->";
    }
    cout<<endl;
  }
}

