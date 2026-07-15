class Solution{
    public:
    int gcdOfOddEvenSumm(int n){
        return n;
    }
};

// Explaination:
// Better Observation

// First n odd numbers sum to:

// n²

// Example:

// 1 = 1²
// 1+3 = 2²
// 1+3+5 = 3²

// First n even numbers sum to:

// n(n+1)

// Example:

// 2+4+6 = 12
// 3×4 = 12

// So the problem becomes:

// gcd(n*n, n*(n+1))

// Factor out n:

// gcd(n², n(n+1))
// = n × gcd(n, n+1)

// Consecutive numbers always have gcd = 1.

// Therefore:

// answer = n