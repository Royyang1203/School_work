// UVa 10534

// Description

// Wavio is a sequence of integers. It has some interesting properties.

// Wavio is of odd length i.e., L-2 \times n + 1L−2×n+1.
// The first (n + 1)(n+1) integers of Wavio sequence makes a strictly increasing sequence.
// The last (n + 1)(n+1) integers of Wavio sequence makes a strictly decreasing sequence.
// NO two adjacent integers are same in a Wavio sequence.
// For example 1, 2, 3, 4, 5, 4, 3, 2, 0 is an Wavio sequence of length 9. But 1, 2, 3, 4, 5, 4, 3, 2, 2 is not a valid Wavio sequence. In this problem. You will be given a sequence of integers. You have to find out the length of the longest, Wavio sequence which is a subsequence of the given sequence. Consider, the given sequence as :

// 1, 2, 3, 2, 1, 2, 3, 4, 3, 2, 1, 5, 4, 1, 2, 3, 2, 2, 1.

// Here the longest Wavio sequence is : 1, 2, 3, 4, 5, 4, 3, 2, 1

// Input
// The input file contains less than 75 test cases. The description of each test case is given below. Input is terminated by end of file.

// Each file starts with a positive integer, N,(1 ≤ N ≤ 10000). In next few lines there will be N integers.

// Output
// For each set of input print the length of longest  Wavio sequence in a line.

// Sample Input 1

// 10
// 1 2 3 4 5 4 3 2 1 10
// 19
// 1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1
// 5
// 1 2 3 4 5
// Sample Output 1

// 9
// 9
// 1