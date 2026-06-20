class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    void dfs(vector<vector<int>>& image, int sr, int sc, int originalClr, int color) {

        
        int x = sr;
        int y = sc;

        for (auto &dir : directions) {

            int new_x = x + dir[0];
            int new_y = y + dir[1];

             if((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && image[new_x][new_y] == originalClr) {

                image[new_x][new_y] = color;
                dfs(image, new_x, new_y, originalClr, color);

             }
        } 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        m = image.size();
        n = image[0].size();

        int originalClr = image[sr][sc];
        
        if(originalClr == color)
            return image;

        image[sr][sc] = color;
        dfs(image, sr, sc, originalClr, color);
        return image;
    } 
};