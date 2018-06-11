#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/* declaration of trie node */
class TrieNode {
private:
    int R = 26;// 26 children at most
    vector<TrieNode*> link;// links to children
    bool is_end = false;

public:
    TrieNode() {
        link = vector<TrieNode*>(R, NULL);
    }

    void set_end() {
        is_end = true;
    }

    bool End() {
        return is_end;
    }

    bool is_contain_key(char ch) {
        return link[ch - 'a'] != NULL;
    }
    TrieNode* put_char(char ch) {
        TrieNode *node = new TrieNode();
        link[ch - 'a'] = node;
        return node;
    }

    TrieNode* get(char ch) {
        return link[ch - 'a'];
    }
};

/* declaration of trie */
class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        assert(word.empty() == false);
        TrieNode *curr = root;
        for (char ch : word) {
            if (curr->is_contain_key(ch))
                curr = curr->get(ch);  
            else
                curr = curr->put_char(ch);     
        }
        curr->set_end();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        assert(word.empty() == false);
        TrieNode *curr = root;
        for (char ch : word) {
            if (curr->is_contain_key(ch))
                curr = curr->get(ch);  
            else
                return false;   
        }
        return curr->End();       
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        assert(prefix.empty() == false);
        TrieNode *curr = root;
        for (char ch : prefix) {
            if (curr->is_contain_key(ch))
                curr = curr->get(ch);  
            else
                return false;   
        }
        return curr->End() == false;    
    }
};

int main() {
    Trie trie;
    trie.insert("a");
    cout << trie.search("a") << endl;   
    cout << trie.startsWith("a") << endl; 
    system("pause");
    return 0;
}