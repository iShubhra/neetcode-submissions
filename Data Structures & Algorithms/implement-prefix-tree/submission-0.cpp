class PrefixTree {
    PrefixTree* children[26];
    bool isEndWord;

public:
    PrefixTree* current = this;
    PrefixTree() {
        for ( int i = 0; i < 26; i++ ){
            children[i] = nullptr;
        }

        isEndWord = false;
    }
    
    void insert(string word) {
        PrefixTree* current = this;
        for ( char ch : word ) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new PrefixTree();
            }

            current = current->children[index];
        }

        current->isEndWord = true;
    }
    
    bool search(string word) {
        PrefixTree* current = this;
        for ( char ch : word ) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        return current->isEndWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* current = this;
        for ( char ch : prefix ) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }

        return true;
    }
};


