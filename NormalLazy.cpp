int left(int index){
    return 2 * index;
}

int right(int index){
    return 2 * index + 1;
}

int merge(int left, int right){
    return left + right;
}
void build(int start, int end, int index, vector<int>& sgt, vector<int>& arr){
    if(start == end){
        sgt[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(start, mid, left(index), sgt, arr);
    build(mid + 1, end, right(index), sgt, arr);
    sgt[index] = merge(sgt[left(index)], sgt[right(index)]);
}

void apply(int start, int end, int index, vector<int>& sgt, vector<int>& lazy, int x){
    sgt[index] = x * (end - start + 1);  
    lazy[index] = x;
}

void pushdown(int start, int end, int index, vector<int>& sgt, vector<int>& lazy){
    if(start != end){
        int mid = (start + end) / 2;
        apply(start, mid, left(index), sgt, lazy, lazy[index]);
        apply(mid + 1, end, right(index), sgt, lazy, lazy[index]);
    }
    lazy[index] = 0;
}

void update(int start, int end, int index, vector<int>& sgt, vector<int>& lazy, int l, int r, int x){
    if(lazy[index] != 0){
        pushdown(start, end, index, sgt, lazy);
    }
    // disjoint case
    if(start > r || end < l){
        return;
    }
    
    // complete overlap
    if(l <= start && end <= r){
        apply(start, end, index, sgt, lazy, x);
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, left(index), sgt, lazy, l, r, x);
    update(mid + 1, end, right(index), sgt, lazy, l, r, x);
    sgt[index] = merge(sgt[left(index)], sgt[right(index)]);
}


int query(int start, int end, int index, vector<int>& sgt, vector<int>& lazy, int l, int r){
    if(lazy[index] != 0){
        pushdown(start, end, index, sgt, lazy);
    }
    
    // disjoint case
    if(start > r || end < l){
        return 0;
    }
    
    // complete overlap
    if(l <= start && end <= r){
        return sgt[index];
    }
    
    
    int mid = (start + end) / 2;
    int left1 = query(start, mid, left(index), sgt, lazy, l, r);
    int right1 = query(mid + 1, end, right(index), sgt, lazy, l, r);
    return merge(left1, right1);
}


// set all values from L to R to be X (1 <= X <= 1e6)
// range sum queries

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    
    vector<int> sgt(4 * n);
    vector<int> lazy(4 * n, 0);
    build(0, n - 1, 1, sgt, arr);
    
    cout << query(0, n - 1, 1, sgt, lazy, 0, 1) << endl;
    
    update(0, n - 1, 1, sgt, lazy, 0, 3, 5);
    
    cout << query(0, n - 1, 1, sgt, lazy, 0, 2);
    
}