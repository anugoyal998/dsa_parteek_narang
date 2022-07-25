// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<char,Node*> mp;
    bool flag = false;
    //checks if the reference trie is present or not
    bool containKey(char ch) {
        return (mp[ch] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        mp[ch] = node; 
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return mp[ch];
    }
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        //creating new obejct
        root = new Node();
    }

    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    
    return 0;
}