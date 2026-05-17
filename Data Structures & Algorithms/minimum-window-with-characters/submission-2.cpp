class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        unordered_map<char, int> freqNeed;

        int i=0;
        int ansi = -1, ansj = -1;

        //maintain need 
        for (int k=0; k<t.length(); k++) {
            freqNeed[t[k]]++;
        }

        int len = freqNeed.size();

        // maintain have
        unordered_map<char, int> freqHave;
        for (int j=0; j<s.length(); j++) {

            freqHave[s[j]]++;
            if (freqHave[s[j]] == freqNeed[s[j]]) len--;

            while (len == 0 && i<=j) {
                // update indices
                if (ansj == -1 || (j - i) < (ansj - ansi)) {
                    ansi = i; ansj = j;
                }

                freqHave[s[i]]--;
                if (freqHave[s[i]] < freqNeed[s[i]]) len++;
                i++;
            }
        }
        if (ansi != -1) {
            return s.substr(ansi, ansj - ansi + 1);
        }
        return "";
    }
};
