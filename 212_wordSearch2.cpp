#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    struct Node {
        char ch;
        Node* child[26];
        int ends = 0;
        string word = "";

        Node() {
            ch = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }

        bool containsKey(char ch) {
            return (child[ch - 'a'] != NULL);
        }

        void put(char ch, Node* node) {
            child[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return child[ch - 'a'];
        }

        void addEnd() {
            ends++;
        }

        void reduceEnd() {
            ends--;
        }

        int getEnd() {
            return ends;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->addEnd();
        node->word = word; // Store the word at the end node
    }

    Node* getRoot() {
        return root;
    }
};

class Solution {
    Trie tri;

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m, Trie::Node* curr, vector<string>& res) {
        // Boundary check
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$' || curr->get(board[i][j]) == NULL) {
            return;
        }

        char ch = board[i][j];
        curr = curr->get(ch);
        if (curr->getEnd() > 0) {
            res.push_back(curr->word);
            curr->reduceEnd();
        }

        board[i][j] = '$'; // Mark as visited

        dfs(board, i + 1, j, n, m, curr, res);
        dfs(board, i - 1, j, n, m, curr, res);
        dfs(board, i, j + 1, n, m, curr, res);
        dfs(board, i, j - 1, n, m, curr, res);

        board[i][j] = ch; // Restore for backtracking
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int n = board.size();
        int m = board[0].size();

        for (auto& word : words) {
            tri.insert(word);
        }

        Trie::Node* root = tri.getRoot();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, n, m, root, res);
            }
        }

        return res;
    }
};
