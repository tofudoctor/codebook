ll qpow(int a, int k, int p){
    ll res = 1;
    while(k){
        if(a & 1) res = res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }

    return res;
}