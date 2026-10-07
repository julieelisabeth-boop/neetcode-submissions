class Solution {
public:
    bool isValid(string s) {
        // syntaks stack
unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
stack<int> st;

    for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);              // c er en åbner: læg den på stakken
            } 
            else
{
    if (st.empty())
    {
        return false;
    }
    else if (st.top() == match[c]) //hvis det på toppen af stacken er lig valuen til key c (lukkeren)
    {
        st.pop();
    }
    else
    {
        return false;
    }
}
        }
        return st.empty();
    }
};
