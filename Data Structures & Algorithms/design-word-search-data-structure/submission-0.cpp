
class TrieNode {
	public:
		TrieNode* children[26];
		bool isEndOfWord;

		TrieNode() {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

};


class Trie {
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode();
	}

	void insert(string word){
		TrieNode* current = root;
		for (char ch : word){
			int i = ch - 'a';
			if ( current->children[i] == nullptr ){
				current->children[i] = new TrieNode();
			}
			current = current->children[i];
		}

		current->isEndOfWord = true;
	}

	bool search(string word) {
		TrieNode* current = root;
		vector<char> vec(word.begin(), word.end());

		return dfs(current, vec, 0);
	}

	bool dfs(TrieNode* current,vector<char> chars,int index) {
		if ( current == nullptr ) return false;

		if ( index == chars.size() ) return current->isEndOfWord;
		
		if ( chars[index] != '.' ){
			for ( int i = index; i < chars.size(); i++ ){
				if ( chars[i] == '.') return dfs(current, chars, i);

				int idx = chars[i] - 'a';
				if ( current->children[idx] == nullptr ) return false;
				current = current->children[idx];
			}

			return current->isEndOfWord;
		}

		for ( int i = 0; i < 26; i++ ){
			if ( current->children[i] != nullptr && dfs(current->children[i], chars, index + 1 ) ) {
				return true;
			}
		}

		return false;
	}
	
};

class WordDictionary {
public:
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    void addWord(string word) {
        t->insert(word);
    }
    
    bool search(string word) {
        return t->search(word);
    }
};