class TrieNode
{
public:
	TrieNode* chars[26];
	bool IsLast;

	TrieNode() {
		for ( int i = 0; i < 26; i++ ){
			chars[i] = nullptr;
		}

		IsLast = false;
	}
	
};

class Trie
{
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode();
	}

	void insert(const string& word) {
		TrieNode* current = root;
		for ( int i = 0; i < word.size(); i++ ){
			int idx = word[i] - 'a';
			if ( current->chars[idx] == nullptr ) {
				current->chars[idx] = new TrieNode(); 
			}

			current = current->chars[idx];
		}

		current->IsLast = true;
	}

	bool search(const string& word) {
		TrieNode* current = root;
		for ( int i = 0; i < word.size(); i++ ){
			int idx = word[i] - 'a';
			if ( current->chars[idx] == nullptr ) {
				return false;
			}

			current = current->chars[idx];
		}

		return current->IsLast == true;
	}


	void backtrack(TrieNode* current, vector<vector<char>>& board, int row, int col, string& word, vector<string>& res) {
		if ( row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
			|| current == nullptr || board[row][col] == ' ' ) return;

		char alphabet = board[row][col];
		int idx = alphabet - 'a';
		if ( current->chars[idx] == nullptr ) return;

		board[row][col] = ' ';
		word += alphabet;
		current = current->chars[idx];
        if ( current->IsLast ) {
            res.push_back(word);
            current->IsLast = false;
        }
        

		backtrack(current, board, row + 1, col, word, res);
		backtrack(current, board, row - 1, col, word, res);
		backtrack(current, board, row, col - 1, word, res);
		backtrack(current, board, row, col + 1, word, res);

		board[row][col] = alphabet;

        if (!word.empty()) word.pop_back();
		return;
	}
	
};

class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> res;
    	Trie trie;
    	for (string word : words) trie.insert(word);

    	for ( int row = 0; row < board.size(); row++ ){
    		for ( int col = 0; col < board[0].size(); col++ ) {
                string str;
    			trie.backtrack(trie.root, board, row, col, str, res);
    		}
    	}

        return res;
    }
};