class TrieNode
{
public:
    string word;  // word up to this point
    bool complete;  // if this is a word in words
    TrieNode* next[26];  // next chars (a-z)
};

class Solution
{
public:
    void addWord(TrieNode* root, string& w)
    {
        TrieNode* iter = root;
        for(int i = 0; w[i] != '\0'; i++)
        {
            // if already child
            if(iter->next[w[i] - 'a'])
            {
                iter = iter->next[w[i] - 'a'];
            }
            // else, add it
            else
            {
                iter->next[w[i] - 'a'] = new TrieNode();
                iter->next[w[i] - 'a']->word = w.substr(0, (i + 1));
                iter = iter->next[w[i] - 'a'];
            }
        }
        // declare end of word
        iter->complete = true;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode* node, vector<string>& ans, vector<vector<bool>>& visited, int r, int c)
    {
        int nrows = board.size();  // # of rows
        int ncols = board[0].size();  // # of cols
        // if out of bounds OR already visited OR node null
        if((r < 0) || (r == nrows) || (c < 0) || (c == ncols) || visited[r][c] || !(node->next[board[r][c] - 'a']))
        {
            return;
        }
        char curr = board[r][c];  // char @ (r, c)
        // if word found
        if(node->next[curr - 'a']->complete)
        {
            // add to ans
            ans.emplace_back(node->next[curr - 'a']->word);
            // set complete to false so no duplicates
            node->next[curr - 'a']->complete = false;
        }
        // update visited
        visited[r][c] = true;
        // run dfs down, right, up, left
        dfs(board, node->next[curr - 'a'], ans, visited, (r + 1), c);
        dfs(board, node->next[curr - 'a'], ans, visited, r, (c + 1));
        dfs(board, node->next[curr - 'a'], ans, visited, (r - 1), c);
        dfs(board, node->next[curr - 'a'], ans, visited, r, (c - 1));
        // reset visited
        visited[r][c] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int nrows = board.size();
        int ncols = board[0].size();
        TrieNode* root = new TrieNode();
        // fill trie w/ words
        int words_size = words.size();
        for(int i = 0; i < words_size; i++)
        {
            // if word can't fit in board
            if(words[i].size() > (nrows * ncols))
            {
                // don't add it
                continue;
            }
            addWord(root, words[i]);
        }
        vector<string> ans;
        // dfs search through board
        for(int r = 0; r < nrows; r++)
        {
            for(int c = 0; c < ncols; c++)
            {
                vector<vector<bool>> visited(nrows, vector<bool>(ncols, 0));
                dfs(board, root, ans, visited, r, c);
            }
        }
        return ans;
    }
};