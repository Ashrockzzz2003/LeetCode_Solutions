class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        int shortest_word_length;
        int shortest_word_index;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }

            shortest_word_length = INT_MAX;
            shortest_word_index = -1;
        }
    };

    void insertWordIntoTrie(TrieNode *root, string word, int word_index) {
        int word_length = word.size();
        reverse(word.begin(), word.end());

        for(int i = 0; i < word_length; i++) {
            int char_index = word[i] - 'a';
            if (root->children[char_index] == nullptr) {
                // create new node to insert
                TrieNode *new_node = new TrieNode();
                new_node->shortest_word_length = word_length;
                new_node->shortest_word_index = word_index;
                
                // insert node
                root->children[char_index] = new_node;
                root = root->children[char_index];
            } else {
                root = root->children[char_index];
                // update shortest word to current word if it's short
                if (word_length < root->shortest_word_length) {
                    root->shortest_word_length = word_length;
                    root->shortest_word_index = word_index;
                }
            }
        }
    }

    int search_for_suffix(TrieNode *root, string word) {
        reverse(word.begin(), word.end());
        int word_length = word.size();

        for(int i = 0; i < word_length; i++) {
            int char_index = word[i] - 'a';

            if (root->children[char_index] != nullptr) {
                root = root->children[char_index];
            } else {
                break;
            }
        }

        return root->shortest_word_index;
    }


    vector<int> stringIndices(vector<string>& words_container, vector<string>& words_query) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> final_indices;

        TrieNode *root = new TrieNode();
        // Beauty of the question: the definition of Trie is the question!!

        // Building the Trie
        for(int i = 0; i < words_container.size(); i++) {
            if (words_container[i].size() < root->shortest_word_length) {
                root->shortest_word_length = words_container[i].size();
                root->shortest_word_index = i;
            }
            insertWordIntoTrie(root, words_container[i], i);
        }


        // Processing the queries!
        for(int i = 0; i < words_query.size(); i++) {
            int suffix_index = search_for_suffix(root, words_query[i]);
            final_indices.push_back(suffix_index);
        }

        return final_indices;
    }
};