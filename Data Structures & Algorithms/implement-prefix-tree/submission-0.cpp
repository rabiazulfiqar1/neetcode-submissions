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

    void insertUtil(string word, TrieNode* root) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            root->children[index] = new TrieNode(word[0]);
            child = root->children[index];
        }
        insertUtil(word.substr(1), child);
    }
    
    void insert(string word) {
        insertUtil(word, root);
    }

    bool searchUtil(string word, TrieNode* root) {
        if (word.length() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(word.substr(1), child);
    }
    
    bool search(string word) {
        return searchUtil(word, root);
    }

    bool startsWithUtil(string prefix, TrieNode* root) {
        if (prefix.length() == 0) {
            return true;
        }
        int index = prefix[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return startsWithUtil(prefix.substr(1), child);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(prefix, root);
    }
};
