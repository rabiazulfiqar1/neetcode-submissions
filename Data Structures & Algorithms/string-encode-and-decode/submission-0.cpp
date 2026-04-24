class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (int i=0; i<strs.size(); i++) {
            ans+=to_string(strs[i].length());
            ans+="#";
            ans+=strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for (int i=0; i<s.length(); ) {
            string n="";
            while (s[i] != '#') {
                n+=s[i];
                i++;
            }
            i++; // pass #
            int cnt = stoi(n);
            string str = s.substr(i, cnt);
            i += cnt;
            decoded.push_back(str);
        }
        return decoded;
    }
};
