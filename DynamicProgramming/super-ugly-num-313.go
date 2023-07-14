package main

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func nthSuperUglyNumber(n int, primes []int) int {
    dp := make([]int, n+1) // size n+1
    dp[1] = 1

    exp := make([]int, len(primes))
    num := make([]int, len(primes))

    copy(num, primes)

    for i := 0; i < len(primes); i++ {
        exp[i] = 1
    }

    for i := 2; i <= n; i++ {
        m := num[0]
        for j := 1; j < len(num); j++ {
            m = min(m, num[j])
        }
        dp[i] = m
        for j := 0; j < len(num); j++ {
            if num[j] == m {
                exp[j]++
                num[j] = dp[exp[j]] * primes[j]
            }
        }
    }
    return dp[n]
}

func main() {

}
