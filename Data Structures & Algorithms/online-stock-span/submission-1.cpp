class StockSpanner {
    stack<pair<int,int>> s; // {price, span}
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!s.empty() && price >= s.top().first) {
            span += s.top().second; // absorb the span of the popped element
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */