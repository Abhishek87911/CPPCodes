int left(int index){
    return 2 * index;
}
int right(int index){
    return 2 * index + 1;
}

int merge(int left, int right){
    return __gcd(left, right);
}

int default_value(){
    return 0;
}

// O(n)
void build(int start, int end, int index, vector<int>& SGT, vector<int>& arr){
    if(start == end){
        SGT[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, left(index), SGT, arr);  // built left part
    build(mid + 1, end, right(index), SGT, arr); // build right part
    SGT[index] = merge(SGT[left(index)], SGT[right(index)]); // merge two answer;
}

// O(logn)
void update(int start, int end, int index, vector<int>& SGT, int pos, int val){
    if(start == end){ // reached your destination
        SGT[index] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(pos <= mid){
        update(start, mid, left(index), SGT, pos, val); // update left side
    }else{
        update(mid + 1, end, right(index), SGT, pos, val); // update right side
    }
    SGT[index] = merge(SGT[left(index)], SGT[right(index)]); // merge two answer;
}

// O(logn)
int query(int start, int end, int index, vector<int>& SGT, int l, int r){
    // complete overlap
    // [l..... start... end.... r]
    if(l <= start && r >= end){
        return SGT[index];
    }
    // disjoint
    // [start.... end... l... r] or [l... r.... start ... end]
    if(end < l || r < start){
        return default_value();
    }
    int mid = (start + end) / 2;
    int leftAns = query(start, mid, left(index), SGT, l, r);
    int rightAns = query(mid + 1, end, right(index), SGT, l, r);
    return merge(leftAns, rightAns);
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i;
    }
    vector<int> SGT(4 * n + 1);
    build(0, n - 1, 1, SGT, arr); // built the segment tree
 
    cout << query(0, n - 1, 1, SGT, 0, 1) << endl;
    cout << query(0, n - 1, 1, SGT, 2, 3) << endl;
    cout << query(0, n - 1, 1, SGT, 2, 6) << endl;
    
    update(0, n - 1, 1, SGT, 0, 100);
    
    cout << query(0, n - 1, 1, SGT, 0, 1) << endl;
}
 
