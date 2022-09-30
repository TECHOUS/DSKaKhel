string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        
        int maxx = 0;
        string ans = "";
        for(int gap = 0; gap<n; gap++){
            int i = 0, j = i + gap;
            if(gap == 0){
                while(i < n && j < n){
                    dp[i][j] = true;
                    i++;
                    j++;
                    if(maxx < (j-i+1)){
                        ans = s.substr(i, j-i+1);
                        maxx = j-i+1;
                    }
                }
            }
            else if(gap == 1){
                while(i < n && j < n){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        if(maxx < (j-i+1)){
                        ans = s.substr(i, j-i+1);
                        maxx = j-i+1;
                    }
                    }
                    else{
                        dp[i][j] = false;
                    }
                    i++;
                    j++;
                }
            }
            else{
                while(i<n && j<n){
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1];
                        if(dp[i][j]){
                            if(maxx < (j-i+1)){
                            ans = s.substr(i, j-i+1);
                            maxx = j-i+1;
                        }
                        }
                    }
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
