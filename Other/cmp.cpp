// a = b 時 必為false
// 5 4 3 2 1  sort(a, a + n, greater<int>());
bool cmp(int lhs, int rhs){
    return lhs > rhs;
}

bool cmp(struct lhs, struct rhs){
    if(s1.age==s2.age)return s1.name <s2.name;
    else  return s1.age < s2.age;
}