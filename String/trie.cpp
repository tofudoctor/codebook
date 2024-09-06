const int MXN = operation * s.length();
int son[MXN][26], cnt[MXN], idx;

void insert(string s){
    int p = 0;
    for(int i = 0;i < s.length();i++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int find(string s){
    int p = 0;
    for(int i = 0;i < s.length();i++){
        int u = s[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

bool find_prefix(string s){
    int p = 0;
    for(int i = 0;i < s.length();i++){
        int u = s[i] - 'a';
        if(!son[p][u]) return false;
        p = son[p][u];
    }
    return true;
}