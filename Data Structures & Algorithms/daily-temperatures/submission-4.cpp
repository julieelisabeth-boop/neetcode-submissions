class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stacks;
        vector<int> facit(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); i++)
        {
            while (!stacks.empty() && temperatures[stacks.top()]<temperatures[i])
            {
                facit[stacks.top()] = i - stacks.top();
                stacks.pop();
            }
            stacks.push(i);
        }
     return facit;
    }
};
