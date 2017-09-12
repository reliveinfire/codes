#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
	root = NULL;
    }
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
    	if (root == NULL)
		root = new TrieNode();
	for (string s : dict){
		TrieNode* idx = root;
		for (char c : s){
			if (idx->next[c - 'a'] == NULL){
				idx->next[c-'a'] = new TrieNode();
			}
			idx = idx->next[c-'a'];
		}
		idx->word = 1;
	}
    }
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
	for (int i = 0 ; i < word.size() ; i++){
		int ret = _search(word, 0, i, root);
		if (ret)
			return true;
	}
	return false;
    }
private:
	struct TrieNode{
		int word;
		TrieNode* next[26];
		TrieNode(){
		word = 0; 
		for (int i = 0 ; i < 26 ; i++)
			next[i] = NULL;
		}
	};
	TrieNode* root;
	bool _search(string word, int curr, int diff, TrieNode* node){
		if (curr == word.size()){
			if (node->word)
				return true;
			else
				return false;
		}
		if (curr!=diff){
			if (node->next[word[curr]-'a']!=NULL){
				return _search(word, curr+1, diff, node->next[word[curr]-'a']);
			}
		} else {
			int ret;
			for (int i = 0 ; i < 26 ; i++){
				if (word[curr]-'a' != i && node->next[i]!=NULL){
					ret = _search(word, curr+1, diff, node->next[i]);
					if (ret)
						return true;
				}
			}
		}
		return false;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	MagicDictionary md;
	vector<string> dict = {"hello","hallo"};
	md.buildDict(dict);
	cout << md.search("hello");

	return 0;
}
