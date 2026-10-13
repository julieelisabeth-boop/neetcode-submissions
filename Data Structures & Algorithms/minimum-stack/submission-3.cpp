class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        if (mins.empty() || val < mins.back())
        {
            mins.push_back(val);
        }
        else
        {
            mins.push_back(mins.back());
        }
    
    }
    
    void pop() {
        stack.pop_back();
        mins.pop_back();

    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mins.back();
    }

    private:
    vector<int> stack;
    list<int> mins;

};
