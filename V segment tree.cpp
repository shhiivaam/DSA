 int n = grid.size();
        int m = grid[0].size();

        // dp_in: incoming paths starting with 1
        vector<vector<int>> dp_in_dr(n, vector<int>(m, 0));
        vector<vector<int>> dp_in_dl(n, vector<int>(m, 0));
        vector<vector<int>> dp_in_ul(n, vector<int>(m, 0));
        vector<vector<int>> dp_in_ur(n, vector<int>(m, 0));
        
        // dp_out: outgoing paths with alternating 2,0 pattern
        // p2 -> starts with 2, p0 -> starts with 0
        vector<vector<int>> dp_out_p2_dr(n, vector<int>(m, 0)), dp_out_p0_dr(n, vector<int>(m, 0));
        vector<vector<int>> dp_out_p2_dl(n, vector<int>(m, 0)), dp_out_p0_dl(n, vector<int>(m, 0));
        vector<vector<int>> dp_out_p2_ul(n, vector<int>(m, 0)), dp_out_p0_ul(n, vector<int>(m, 0));
        vector<vector<int>> dp_out_p2_ur(n, vector<int>(m, 0)), dp_out_p0_ur(n, vector<int>(m, 0));

        int max_len = 0;

        // ## Step 1: Calculate incoming paths (start with 1)
        // Pass 1.1: Top-Left to Bottom-Right (dr)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dp_in_dr[i][j] = 1;
                } else if (i > 0 && j > 0 && dp_in_dr[i - 1][j - 1] > 0) {
                    int prev_len = dp_in_dr[i - 1][j - 1];
                    int expected = (prev_len % 2 != 0) ? 2 : 0;
                    if (grid[i][j] == expected) dp_in_dr[i][j] = prev_len + 1;
                }
                max_len = max(max_len, dp_in_dr[i][j]);
            }
        }
        // Pass 1.2: Top-Right to Bottom-Left (dl)
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                 if (grid[i][j] == 1) {
                    dp_in_dl[i][j] = 1;
                } else if (i > 0 && j < m - 1 && dp_in_dl[i - 1][j + 1] > 0) {
                    int prev_len = dp_in_dl[i - 1][j + 1];
                    int expected = (prev_len % 2 != 0) ? 2 : 0;
                    if (grid[i][j] == expected) dp_in_dl[i][j] = prev_len + 1;
                }
                max_len = max(max_len, dp_in_dl[i][j]);
            }
        }
        // Pass 1.3: Bottom-Right to Top-Left (ul)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    dp_in_ul[i][j] = 1;
                } else if (i < n - 1 && j < m - 1 && dp_in_ul[i + 1][j + 1] > 0) {
                    int prev_len = dp_in_ul[i + 1][j + 1];
                    int expected = (prev_len % 2 != 0) ? 2 : 0;
                    if (grid[i][j] == expected) dp_in_ul[i][j] = prev_len + 1;
                }
                max_len = max(max_len, dp_in_ul[i][j]);
            }
        }
        // Pass 1.4: Bottom-Left to Top-Right (ur)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dp_in_ur[i][j] = 1;
                } else if (i < n - 1 && j > 0 && dp_in_ur[i + 1][j - 1] > 0) {
                    int prev_len = dp_in_ur[i + 1][j - 1];
                    int expected = (prev_len % 2 != 0) ? 2 : 0;
                    if (grid[i][j] == expected) dp_in_ur[i][j] = prev_len + 1;
                }
                max_len = max(max_len, dp_in_ur[i][j]);
            }
        }

        // ## Step 2: Calculate outgoing continuation paths
        // Pass 2.1: dr & dl paths (depend on i+1, so iterate i backwards)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) { // dr
                if (grid[i][j] == 2) dp_out_p2_dr[i][j] = 1 + (i < n - 1 && j < m - 1 ? dp_out_p0_dr[i + 1][j + 1] : 0);
                if (grid[i][j] == 0) dp_out_p0_dr[i][j] = 1 + (i < n - 1 && j < m - 1 ? dp_out_p2_dr[i + 1][j + 1] : 0);
            }
            for (int j = 0; j < m; ++j) { // dl
                 if (grid[i][j] == 2) dp_out_p2_dl[i][j] = 1 + (i < n - 1 && j > 0 ? dp_out_p0_dl[i + 1][j - 1] : 0);
                 if (grid[i][j] == 0) dp_out_p0_dl[i][j] = 1 + (i < n - 1 && j > 0 ? dp_out_p2_dl[i + 1][j - 1] : 0);
            }
        }
        // Pass 2.2: ul & ur paths (depend on i-1, so iterate i forwards)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { // ul
                 if (grid[i][j] == 2) dp_out_p2_ul[i][j] = 1 + (i > 0 && j > 0 ? dp_out_p0_ul[i - 1][j - 1] : 0);
                 if (grid[i][j] == 0) dp_out_p0_ul[i][j] = 1 + (i > 0 && j > 0 ? dp_out_p2_ul[i - 1][j - 1] : 0);
            }
            for (int j = m - 1; j >= 0; --j) { // ur
                if (grid[i][j] == 2) dp_out_p2_ur[i][j] = 1 + (i > 0 && j < m - 1 ? dp_out_p0_ur[i - 1][j + 1] : 0);
                if (grid[i][j] == 0) dp_out_p0_ur[i][j] = 1 + (i > 0 && j < m - 1 ? dp_out_p2_ur[i - 1][j + 1] : 0);
            }
        }

        // ## Step 3: Assemble V-shapes at each cell (i,j) as a vertex
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int l1, l2;

                // Turn: dr -> dl; Path: ... -> (i-1,j-1) -> (i,j) -> (i+1,j-1) -> ...
                l1 = dp_in_dr[i][j];
                if (l1 > 0 && i + 1 < n && j - 1 >= 0) {
                    l2 = (l1 % 2 != 0) ? dp_out_p2_dl[i + 1][j - 1] : dp_out_p0_dl[i + 1][j - 1];
                    if (l2 > 0) max_len = max(max_len, l1 + l2);
                }

                // Turn: dl -> ul; Path: ... -> (i-1,j+1) -> (i,j) -> (i-1,j-1) -> ...
                l1 = dp_in_dl[i][j];
                if (l1 > 0 && i - 1 >= 0 && j - 1 >= 0) {
                    l2 = (l1 % 2 != 0) ? dp_out_p2_ul[i - 1][j - 1] : dp_out_p0_ul[i - 1][j - 1];
                    if (l2 > 0) max_len = max(max_len, l1 + l2);
                }

                // Turn: ul -> ur; Path: ... -> (i+1,j+1) -> (i,j) -> (i-1,j+1) -> ...
                l1 = dp_in_ul[i][j];
                if (l1 > 0 && i - 1 >= 0 && j + 1 < m) {
                    l2 = (l1 % 2 != 0) ? dp_out_p2_ur[i - 1][j + 1] : dp_out_p0_ur[i - 1][j + 1];
                    if (l2 > 0) max_len = max(max_len, l1 + l2);
                }
                
                // Turn: ur -> dr; Path: ... -> (i+1,j-1) -> (i,j) -> (i+1,j+1) -> ...
                l1 = dp_in_ur[i][j];
                if (l1 > 0 && i + 1 < n && j + 1 < m) {
                    l2 = (l1 % 2 != 0) ? dp_out_p2_dr[i + 1][j + 1] : dp_out_p0_dr[i + 1][j + 1];
                    if (l2 > 0) max_len = max(max_len, l1 + l2);
                }
            }
        }

        return max_len;
    }
};
