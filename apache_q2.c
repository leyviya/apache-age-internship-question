//Q2 - Function 1 

int F_recursive(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else return F_recursive(n-3) + F_recursive(n-2);
}

// Q2 - Function 2

int F_memoization(int n, int memo[]) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (memo[n] != -1) return memo[n];
    else {
        memo[n] = F_memoization(n-3, memo) + F_memoization(n-2, memo);
        return memo[n];
    }
}

int F(int n) {
    int memo[n+1];
    memset(memo, -1, sizeof(memo));
    return F_memoization(n, memo);
}

// Q2 - Function 3

int F_iterative(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else {
        int a = 0, b = 1, c = 2, d;
        for (int i = 3; i <= n; i++) {
            d = a + b;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
}
