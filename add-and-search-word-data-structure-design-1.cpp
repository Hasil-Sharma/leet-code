// https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        top = createTNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string s) {
        TNode* curr = top;
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            if (!curr->chars[s[i] - 'a'])
                curr->chars[s[i] - 'a'] = createTNode();
            curr = curr->chars[s[i] - 'a'];
        }
        
        if (n - 1 >= 0)
            curr->finish = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, top);
    }
    

private:
    struct TNode {
        vector<TNode*> chars;
        bool finish;        
    };
    
    TNode *top;
    
    TNode* createTNode(){
        TNode* node = new TNode();
        node->chars.resize(26);
        return node;
    }
    
    bool searchHelper(string& s, int i, TNode* head){
        if (i == s.length()) return head->finish;
        else if (s[i] == '.'){
            for(int j = 0; j < 26; j++){
                if (head->chars[j] && searchHelper(s, i + 1, head->chars[j]))
                    return true;
            }
        } else if (head->chars[s[i] - 'a'])
            return searchHelper(s, i + 1, head->chars[s[i] - 'a']);
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
