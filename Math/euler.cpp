// one
int euler(int x){
    int res = x;
    for(int i = 2;i <= x / i;i++){
        if(x % i == 0){
            res = res - res / i;
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res = res - res / x;

    return res;
}

// 1 ~ n
euler[1] = 1;
for(int i = 2;i <= n;i++){
    if(!ch[i]){
        prime.push_back(i);
        euler[i] = i - 1;
    }

    for(int j = 0;prime[j] <= n / i;i++){
        int t = prime[j] * i;
        ch[t] = true;
        if(i % prime[j] == 0){
            euler[t] = euler[i] * prime[j];
            break;
        }
        euler[t] = euler[i] * (prime[j] - 1);
    }
}