void lowbit(int x){
    return x & -x;
}

void add(int x, int c){
    for(int i = x;i <= n;i += lowbit(i))
        tr[i] += c;
}

// a[1] + ... + a[n]
int sum(int x){
    int res = 0;
    for(int i = x;i >= 0;i -= lowbit(i))
        res += tr[i];
    return res;
}