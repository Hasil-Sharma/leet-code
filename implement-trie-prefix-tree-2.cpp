// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
private:
    struct Node {
        Node* next[26];
        bool isword;
    };
    
    Node* head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* start = head;
        for(int i = 0; i < word.length(); i++){
            int ii = word[i] - 'a';
            if (!start->next[ii])
                start->next[ii] = new Node();
            start = start->next[ii];
        }
        start->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *start = head;
        for(int i = 0; i < word.length(); i++){
            int ii = word[i] - 'a';
            if (!start->next[ii])
                return false;
            start = start->next[ii];
        }
        return start->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *start = head;
        for(int i = 0; i < prefix.length(); i++){
            int ii = prefix[i] - 'a';
            if (!start->next[ii])
                return false;
            start = start->next[ii];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
