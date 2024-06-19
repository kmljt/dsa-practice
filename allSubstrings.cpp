#include <bits/stdc++.h>

using namespace std;

unordered_set<string> st;
string str;

void helper(multiset<char>& chars, int len) {
    if (str.size() == len) {
        st.insert(str);
        // cout << str << " " << st.size() << endl;
        return;
    }

    for (char c : vector<char>(chars.begin(), chars.end())) {
        str.push_back(c);
        chars.erase(chars.find(c));

        helper(chars, len);

        str.pop_back();
        chars.insert(c);
    }
}

int allSubstrings(string s) {
    multiset<char> chars;
    chars.insert(s.begin(), s.end());

    for (int len = 1; len <= chars.size(); len++)
        helper(chars, len);

    return st.size();
}

int main() {
    cout << allSubstrings("ccd") << endl;
    for (string s : st) cout << s << endl;

    return 0;
}
