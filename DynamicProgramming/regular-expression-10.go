func isMatch(s string, p string) bool {
    patLen := len(p)
    txtLen := len(s)

    dp := make([][]bool, patLen+1)
    for i := 0; i <= patLen; i++ {
        dp[i] = make([]bool, txtLen+1)
    }

    // init, the other elements are all false
    dp[0][0] = true
    for i := 1; i <= patLen; i++ {
        if p[i-1] != '*' {
            dp[i][0] = false // . can not match null string
        } else {
            dp[i][0] = dp[i-2][0]
        }
    }

    // dp[i][j] means p[0:i+1] matches s[0:j+1] 
    for i := 0; i < patLen; i++ {
        for j := 0; j < txtLen; j++ {
            if p[i] == '*' {
                if p[i-1] == s[j] || p[i-1] == '.' {
                    dp[i+1][j+1] = dp[i-1][j+1] || dp[i+1][j]
                } else {
                    dp[i+1][j+1] = dp[i-1][j+1]
                }
            } else if p[i] == '.' || p[i] == s[j] {
                dp[i+1][j+1] = dp[i][j]
            } else {
                dp[i+1][j+1] = false
            }
        }
    }

    return dp[patLen][txtLen]
}
