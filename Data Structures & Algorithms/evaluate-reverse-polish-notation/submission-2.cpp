class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sum;
        for (auto t: tokens)
        {
            if (t=="+")
            {
                int first=sum.top();
                sum.pop();
                int second=sum.top();
                sum.pop();
                sum.push(first+second);
            }
            else if (t=="-")
            {
                int first=sum.top();
                sum.pop();
                int second=sum.top();
                sum.pop();
                sum.push(second-first);
            }
            else if (t=="*")
            {
                int first=sum.top();
                sum.pop();
                int second=sum.top();
                sum.pop();
                sum.push(first*second);
            }
            else if (t=="/")
            {
                int first=sum.top();
                sum.pop();
                int second=sum.top();
                sum.pop();
                sum.push(second/first);
            }
            else
            sum.push(stoi(t));
        }
        
        return sum.top();
    }
};
