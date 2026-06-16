class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode('\0');
    }

    void insertUtil(int i, string& word, TrieNode* root) {
        if (i == word.length()) {
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            root->children[index] = new TrieNode(word[i]);
            child = root->children[index];
        }
        insertUtil(i+1, word, child);
    }
    
    void insert(string word) {
        insertUtil(0, word, root);
    }

    bool searchUtil(int i, string& word, TrieNode* root) {
        if (i == word.length()) {
            return root->isTerminal;
        }
        int index = word[i] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(i+1, word, child);
    }
    
    bool search(string word) {
        return searchUtil(0, word, root);
    }

    bool startsWithUtil(int i, string& prefix, TrieNode* root) {
        if (i == prefix.length()) {
            return true;
        }
        int index = prefix[i] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return startsWithUtil(i+1, prefix, child);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(0, prefix, root);
    }
};
