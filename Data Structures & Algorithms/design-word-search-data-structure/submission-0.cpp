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

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
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
    
    void addWord(string word) {
        insertUtil(0, word, root);
    }

    bool searchUtil(int i, string& word, TrieNode* root) {
        if (i == word.length()) {
            return root->isTerminal;
        }
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {

                TrieNode* child = root->children[j];

                if (child != NULL) {

                    if (searchUtil(i + 1, word, child)) {
                        return true;
                    }
                }
            }

            return false;
        }
        int index = word[i] - 'a';
        TrieNode* child = root->children[index];
        if (child == NULL) {
            return false;
        } 
        return searchUtil(i+1, word, child);
    }
    
    bool search(string word) {
        return searchUtil(0, word, root);
    }
};
