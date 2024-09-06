#include<bits/stdc++.h>

using namespace std;

const int N = 60;
int timestamp, dfn[N], low[N];
vector<int> g[N];
set<int> ap;

void add(int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
}

void tarjan(int x){
    int child = 0;
    dfn[x] = low[x] = ++timestamp;

    for(auto u : g[x]){
        if(!dfn[u]){    
            tarjan(u);
            child++;
            low[x] = min(low[x], low[u]);
            if(dfn[x] != 1 && low[u] >= dfn[x]) ap.insert(x);
        }
        else low[x] = min(low[x], dfn[u]);
    }

    if(dfn[x] == 1 && child > 1) ap.insert(x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    while(cin >> a >> b) add(a, b);

    tarjan(a);
    
    if(ap.size()){
        cout << "false\n";
        int cnt = 0;
        for(auto it : ap){
            cout << it;
            if(++cnt < ap.size()) cout << " ";
        }
    }
    else cout << "true\n";

    return 0;
}