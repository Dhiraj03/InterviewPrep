/*
Given a dictionary and a beginWord and an endWord - return the minimum number of steps (number of words in the 
transformation process - including the beginWord and endWord) that are required to transform the bgeinWord to the endWord.

Approach - Simple BFS - Start with the beginWord and initialize the result to 1.
Then, explore all the words that can be formed from the beginWord by changing just one letter and are present in
the dictionary (essentially the 'neighbours' of this word) and push them into the queue.
Increment the result variable at this point.
After all the nighbours have been pushed, extract each one, remove them from the dictionary (essentially marking
them as visited) and do the same with its neighbours.
Check whether the extracted word is the endWord - if it is, then return the result. 
*/
int Solution::solve(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> words;
        int res = 1,n;
        words.push(beginWord);
        string temp;
        while(!words.empty())
        {
            n = words.size();
            for(int i = 0; i<n;i++)
            {
                temp = words.front();
                words.pop();
                
                if(temp == endWord)
                    return res;
                dict.erase(temp);
                for (int j = 0; j < temp.size(); j++) {
                    char c = temp[j];
                    for (int k = 0; k < 26; k++) {
                        temp[j] = 'a' + k;
                        if (dict.find(temp) != dict.end()) {
                            words.push(temp);
                        }
                    }
                    temp[j] = c;

                }
                }
                        res++;


        }
        return 0;
}
