bool dfs(int u, int c){
    v[u] = c;
    for(auto it : g[u]){
        if(!v[it]){
            if(!dfs(it, 3 - c)) return false;
        }
        else if(v[it] == c) return false;
    }

    return true;
}

bool check(){
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(!v[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }

    return flag;
}