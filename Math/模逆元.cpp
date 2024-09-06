// a * x 同餘 1 (mod p)

// by qpow
ll solve(int a, int p){
    if(a % p == 0) cout << "NO";
    else cout << qpow(a, p - 2, p);
}

// by extgcd
ll solve(int a, int p){
    if(gcd(a, p) != 1) cout << "No";
    else{
        ll ans, k;
        extgcd(a, p, ans, k);
        ans = (ans % p + p) % p;
        cout << ans << "\n";
    }
}
