class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ']') {
              
                string tmp = "";
                while (!st.empty() && st.top() != '[') {
                    tmp = st.top() + tmp;
                    st.pop();
                }

                st.pop();

               
                string num = "";
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int freq = stoi(num);

                
                string expanded = "";
                for (int i = 0; i < freq; ++i) {
                    expanded += tmp;
                }

               
                for (char ch : expanded) {
                    st.push(ch);
                }

            } else {
                st.push(c);
            }
        }

       
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
