/* Given a 2D array called books, which contains n books, with their width and height, and the maximum
width of the bookshelf, return the height of the smallest bookcase that can hold all these books.
Approach : Top-Down DP
min[i][w] is a helper array that indicates the minimum height when book i is placed at position w on the shelf,
for all the other books.
For each book : 
1. If it is the last book, then return the height.
2. If the position has been memoised, return that value.
3. Else - two possibilities can arise -
a. Place the book in the same shelf - then increment the width, if this exceeds shelf_width, return INT_MAX, else
return widht+books[i][width] and max(h, books[i][height])
b. Place the book in the next shelf - h + recursive_call(books[i][height], books[i][width])
*/

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
    int m[1001][1001];
    int minHeightShelves(vector<vector<int>> &books, int shelf_width, int i = 0, int w = 0, int h = 0)
    {
        if (i >= books.size())
            return h;
        if (m[i][w] != 0)
            return m[i][w];
        return m[i][w] = min(h + minHeightShelves(books, shelf_width, i + 1, books[i][0], books[i][1]),
                             w + books[i][0] > shelf_width ? INT_MAX : minHeightShelves(books, shelf_width, i + 1, books[i][0] + w, max(h, books[i][1])));
    }
};