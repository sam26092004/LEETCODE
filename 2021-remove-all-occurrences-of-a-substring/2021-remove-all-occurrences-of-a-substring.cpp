class Solution {
public:
    string removeOccurrences(string s, string part) {
        string tmp = "";
        for (auto c : s) {
            tmp.push_back(c);
            if (tmp.size() >= part.size()) {
                string substr = tmp.substr(tmp.size() - part.size(), part.size());
                if (substr == part) {
                    tmp.erase(tmp.find(part),part.size());
                }
            }
        }
        return tmp;
    }
};