// UVa 10986

// Description

// "A new internet watchdog is creating a stir in
// Springfield. Mr. X, if that is his real name, has
// come up with a sensational scoop."

// Kent Brockman

// There are n SMTP servers connected by network cables. Each of the  m  cables
// connects two computers and has a certain latency measured in milliseconds
// required to send an email message. What is the shortest time required
// to send a message from server  S  to server  T  along a sequence of cables?

// Input
// The first line of input gives the number of cases, ~N N. N~N  test cases follow.
// Each one starts with a line containing  n(2 ≤ n ≤ 20000), m(0 ≤ m ≤ 50000), S(0 ≤ S < n)  and  T(0 ≤ T < n).​
// S = T. The next  m  lines will each contain 3 integers: 2 different servers (in the range [0, n-1][0,n−1])
// that are connected by a biderectional cable and the latency, w, along with cable ($0 \le w \le 10000).

// Output
// For each test case, output the line 'Case #x:'
// followed by the number of milliseconds required to send a message from ~S~ S  to ~T T.
// Print 'unreachable' if there is no route from ~S~ S  to ~T T.

// Sample Input 1

// 3

// 2 1 0 1
// 0 1 100

// 3 3 2 0
// 0 1 100
// 0 2 200
// 1 2 50

// 2 0 0 1
// Sample Output 1

// Case #1: 100
// Case #2: 150
// Case #3: unreachable