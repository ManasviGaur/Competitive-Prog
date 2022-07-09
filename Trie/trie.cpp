#include<bits/stdc++.h>
using namespace std;

class Trie {
public:  
    bool isEnd = false;
    map<char, Trie*> children;

    Trie() {}
    void insert(string word) {
        Trie* curr = this;
        for(char c: word){
            if(!curr->children[c]) curr->children[c] = new Trie();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(char c: word){
            if(!curr->children[c]) return false;
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c: prefix){
            if(!curr->children[c]) return false;
            curr = curr->children[c];
        }
        return true;
    }
};