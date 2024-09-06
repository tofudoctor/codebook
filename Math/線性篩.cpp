vector<int> prime;
bool ch[N];

void get_prime(){
    for(int i = 2;i <= n;i++){
        if(!ch[i]) prime.push_back(i);
        for(int j = 0;prime[j] <= n / i;j++){
            ch[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}