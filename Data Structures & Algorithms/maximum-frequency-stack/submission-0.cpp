class FreqStack {
    unordered_map<int,int> freq;          // val → its current frequency
    unordered_map<int, stack<int>> group; // freq → stack of vals at that freq
    int maxFreq = 0;

public:
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        group[f].push(val);
        maxFreq = max(maxFreq, f);
    }
    
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if(group[maxFreq].empty()) maxFreq--;  // no more elements at this freq
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */