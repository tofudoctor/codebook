// find nearest min or max of ith element
stack<int> s;

for(int i = 0;i < n;i++){
    while(!s.empty() && check(a[i], s.top())) s.pop();
    if(s.empty()) cout << -1;
    else cout << s.top();

    s.push(nums2[i]);
}