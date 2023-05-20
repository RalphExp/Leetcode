class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) {
            nil = true;
            return;
        }

        nil = false;
        idx = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        /* initialize column 0 */
        for (int i = 0; i < matrix.size(); i++) {
            idx[i][0] = matrix[i][0];
            if (i > 0)
                idx[i][0] += idx[i-1][0];
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                idx[i][j] = idx[i][j-1] + matrix[i][j];
                if (i > 0) {
                    idx[i][j] += idx[i-1][j];
                    idx[i][j] -= idx[i-1][j-1];
                }
            }
        }

        /*
    　　for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                printf("%3d ", idx[i][j]);
            }
            puts("\n");
        }
        */
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (nil)
            return 0;

        int res = idx[row2][col2];
        // printf("res = %d\n", res);

        if (row1 && col1)
            res += idx[row1-1][col1-1];
        if (row1)
            res -= idx[row1-1][col2];
        if (col1)
            res -= idx[row2][col1-1];
        
        return res;
    }

public:
    vector<vector<int>> idx;
    bool nil;
};
