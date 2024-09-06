// string hash
// according to experience P = 131 || 13331 & mod 2^64 is best
// 1 base
unsigned long long h[MXN], p[MXN];
// init
p[0] = 1;
for(int i = 1;i <= n;i++){
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

unsigned long long int find(int l, int r){
    return h[r] - h[l - 1] * P[r - l + 1];
}