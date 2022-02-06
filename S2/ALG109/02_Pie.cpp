// UVa 12097

// Description

// My birthday is coming up and traditionally I'm serving pie.
// Not just one pie, no, I have a number NN of them, of various tastes and of various sizes.
// FF of my friends are coming to my party and each of them gets a piece of pie.
// This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though.

// My friends are very annoying and if one of them gets a bigger piece than the others,
// they start complaining. Therefore all of them should get equally sized (which is better than spoiling the party).
// Of course, I want a piece of pie for myself too, and that piece should also be of the same size.

// What is the largest possible piece size all of us can get?
// All the pies are cylindrical in shape and they all have the same height 11, but the radii of the pies can be different.

// Input
// One line with a positive integer: the number of test cases. Then for each test case:

// One line with two integers N and F with 1 <= N, F <= 10000: the number of pies and the number of friends.
// One line with N integers r(i), with 1 <= r(i) <= 10000 the radii of the pies.

// Output
// For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V.
// The answer should be given as a floating point number with an absolute error of at most 10^-3.

// Sample Input 1

// 3
// 3 3
// 4 3 3
// 1 24
// 5
// 10 5
// 1 4 2 3 4 5 6 5 4 2

// Sample Output 1

// 25.1327
// 3.1416
// 50.2655