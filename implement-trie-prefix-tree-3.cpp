// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* t = root;
        for(char c : word){
            if (!t->next[c-'a'])
                t->next[c-'a'] = new node();
            t = t->next[c-'a'];
        }
        
        t->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* t = findEnd(word);
        return t ? t->end : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* t = findEnd(prefix);
        return t ? true : false;
    }
    
private:
    struct node {
        vector<node*> next;
        bool end;
        
        node() {
            next.resize(26, NULL);
            end = false;
        }
    };
    node* root;
    node* findEnd(string str){
        node* t = root;
        for(char c : str){
            if (!t->next[c - 'a']) return NULL;
            t = t->next[c-'a'];
        }
        return t;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
