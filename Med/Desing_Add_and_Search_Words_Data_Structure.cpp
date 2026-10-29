#include "string"
#include "iostream" 
#include <ios>

using namespace std;

/**

Design a data structure that supports adding new words and finding if a string matches any previously added string.

*/

class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false){
            for (int index = 0; index < 26; index++){
                children[index] = nullptr;
            }
        }
    };

    TrieNode* root;
    bool dfs(const string& word, int index, TrieNode* node){
        if (index == word.size()) return node->isEnd;
        char c = word[index];
        if (c == '.'){
            for (int i = 0; i < 26; i++) if (node->children[i] != nullptr && 
                                            dfs(word, index + 1, node->children[i])) return true;
            return false;
        }
        int pos = c - 'a';
        if (node->children[pos] == nullptr) return false;
        return dfs(word, index + 1, node->children[pos]);
    }
    void deleteTrie(TrieNode* node){
        if(!node) return;
        for(int i = 0; i < 26; i++) deleteTrie(node->children[i]);
        delete node;
    }

public:
    // WordDictionary() Initializes the object.

    // Default constructor
    WordDictionary() {root = new TrieNode();}

    // Destructor
    ~WordDictionary(){deleteTrie(root);}

    // Copy constructor
    WordDictionary(const WordDictionary&) = delete;

    // Copy assignment
    WordDictionary& operator=(const WordDictionary&) = delete;

    // Move constructor
    WordDictionary(WordDictionary&& other) noexcept : root(other.root) {other.root = nullptr;}

    // Move Assignment
    WordDictionary& operator=(WordDictionary&& other) noexcept {
        if (this != &other){
            deleteTrie(root);
            root = other.root;
            other.root = nullptr;
        }
        return *this;
    }

    // void addWord(word) Adds word to the data structure, it can be matched later.
    void addWord(string word) {
        TrieNode* current = root;
        for (char c: word){
            int index = c - 'a';
            if(current->children[index] == nullptr) current->children[index] = new TrieNode();
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    // bool search(word) Returns true if there is any string in the data structure that matches 
    // word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

int main(){
    WordDictionary word;

    word.addWord("bad");
    word.addWord("dad");
    word.addWord("mad");

    cout << boolalpha;
    cout << "Want : false, Was : " << word.search("pad") << endl;
    cout << "Want :  true, Was : " << word.search("bad") << endl;
    cout << "Want :  true, Was : " << word.search(".ad") << endl;
    cout << "Want :  true, Was : " << word.search("b..") << endl;


    return 0;
}