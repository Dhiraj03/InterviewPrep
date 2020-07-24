/* Given a dictionary and a string that is composed of words present 
in the dictionary - return all space separated decompositions of the string.
Approach :  Trie with DP - the memoisation should be done using a vector of strings, which stores
all possible space-separated decompositions of a substring of the string - m[i] - all decompositions
from ith index to the end.
findAll function takes the dictionary and string -
1. if the solution has already been computed for this substring - then it just returns the array of strings.
2. Else, if the entirety of the string is a valid word, then the word itself is returned - a trie is used to 
implement the dictionary.
3. Run a loop from the first index of the substring and for every subsequent index, if a valid word exists,
recursively run the decomposition and concatenate each of the decompositions of the rest of the substring
with this valid word to compose the entire list for that particular word.
Similarly, check for other words that exist in this substring and keep adding all these decompositions to the result.
4. Exit the loop, store the result in dp array, and return this result.
5. if the answer is needed in sorted order, take the result and sort it, and return the result.
*/
class Solution
{
public:
    unordered_map<string, vector<string>> m;
    struct TrieNode
    {
        struct TrieNode *children[26];
        bool isEnd;
    };

    TrieNode *getNode()
    {
        struct TrieNode *pNode = new TrieNode;
        pNode->isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            pNode->children[i] = NULL;
        }
        return pNode;
    }

    void insert(TrieNode *root, string key)
    {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEnd = true;
    }

    bool search(TrieNode *root, string key)
    {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != NULL && pCrawl->isEnd);
    }

    vector<string> combine(string word, vector<string> prev)
    {
        for (int i = 0; i < prev.size(); ++i)
        {
            prev[i] += " " + word;
        }
        return prev;
    }

    vector<string> findAll(string s, vector<string> &dict, TrieNode *root)
    {
        if (m.count(s))
            return m[s];
        vector<string> result;

        if (search(root, s))
        {
            result.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i)
        {

            string word = s.substr(i);

            if (search(root, word))
            {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, findAll(rem, dict, root));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int i;
        int m = wordDict.size();
        TrieNode *root = getNode();
        for (i = 0; i < m; i++)
        {
            insert(root, wordDict[i]);
        }
        return findAll(s, wordDict, root);
    }
}