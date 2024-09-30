class CustomStack {
private:
    vector<int> st;
    int topIndex;
public:
    CustomStack(int maxSize) {
        st.resize(maxSize);
        topIndex = -1;
    }
    
    void push(int x) {
        if(topIndex < (int)(st.size())-1) st[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex >= 0) return st[topIndex--];
        return -1;
    }
    
    void increment(int k, int val) {
        int limit = min(k, topIndex+1);
        for(int i=0; i<limit; i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */