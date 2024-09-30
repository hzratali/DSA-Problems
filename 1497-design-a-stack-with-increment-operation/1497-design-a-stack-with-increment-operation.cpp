class CustomStack {
private:
    list<int> st;
    int mxSize;
public:
    CustomStack(int maxSize) {
        this->mxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < mxSize) st.push_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int topElement = st.back();
        st.pop_back();
        return topElement;
    }
    
    void increment(int k, int val) {
        auto it = st.begin();
        for(int i=0; i<k && it!=st.end(); i++, it++) *it += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */