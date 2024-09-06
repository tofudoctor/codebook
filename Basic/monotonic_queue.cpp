// max or min of sliding window(k size)
deque<int> q; // index

for(int i = 0;i < n;i++){
    if(!q.empty() && i - q.front() + 1 > k) q.pop_front();
    while(!q.empty() && check(arr[i], q.back())) q.pop_back();

    q.push_back(i);

    if(i + 1 >= k) cout << q.front();
}