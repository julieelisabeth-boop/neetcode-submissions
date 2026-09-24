class Solution {
public:

    string encode(vector<string>& strs) {
    std::string ec;
        for (auto &s : strs)
        {
            ec+= to_string(s.size())+ "#" + s;
        }
        return ec;
    }

    vector<string> decode(string s) {
        vector<string> dc;
        int antal=0;
        int p=0;
        while (p < s.size())
        {
            size_t pos = s.find('#',p); 
            int tal=stoi(s.substr(p, pos-p)); //substr udlkipper string fra i og klippe pos-1 antal
            string ord = s.substr(pos+1,tal); //igen starter vi ved pos+1 for at komme over # og klipper tal antal;
            dc.push_back(ord);
            p=pos+1+tal;
        }
        return dc;

    }
};
