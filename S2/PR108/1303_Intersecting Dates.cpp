// Description

// A research group is developing a computer program that will fetch historical stock market quotes from

// a service that charges a fixed fee for each day’s quotes that it delivers. The group has examined the

// collection of previously-requested quotes and discovered a lot of duplication, resulting in wasted money.

// So the new program will maintain a list of all past quotes requested by members of the group. When

// additional quotes are required, only quotes for those dates not previously obtained will be fetched from

// the service, thus minimizing the cost.

// You are to write a program that d etermines when new quotes are required. Input for the program

// consists of the date ranges for which quotes have been requested in the past and the date ranges for

// which quotes are required. The program will then determine the date ranges for which quotes must be

// fetched from the service.

// Input
// There will be multiple input cases. The input for each case begins with two non-negative integers NX

// and NR, (0 ≤ NX, NR ≤ 100). NX is the number of existing date ranges for quotes requested in

// the past. NR is the number of date ranges in the incoming requests for quotes. Following these are

// NX + NR pairs of dates. The first date in each pair will be less than or equal to the second date in

// the pair. The first NX pairs specify the date ranges of quotes which have been requested and obtained

// in the past, and the next NR pairs specify the date ranges for which quotes are required.

// Two zeroes will follow the input data for the last case.

// Each input date will be given in the form Y Y Y Y MMDD. Y Y Y Y is the year (1700 to 2100), MM

// is the month (01 to 12), and DD is the day (in the allowed range for the given month and year). Recall

// that months 04, 06, 09, and 11 have 30 days, months 01, 03, 05, 07, 08, 10, and 12 have 31 days, and

// month 02 has 28 days except in leap years, when it has 29 days. A year is a leap year if it is evenly

// divisible by 4 and is not a century year (a multiple of 100), or if it is divisible by 400.

// Output
// For each input case, display the case number (1, 2, . . . ) followed by a list of any date ranges for which

// quotes must be fetched from the service, one date range per output line. Use the American date format

// shown in the sample output below. Explicitly indicate (as shown) if no additional quotes must be

// fetched. If two date ranges are contiguous or overlap, then merge them into a single date range. If a

// date range consists of a single date, print it as a single date, not as a range consisting of two identical

// dates. Display the date ranges in chronological order, starting with the earliest date range.

// Sample Input 1

// 1 1
// 19900101 19901231
// 19901201 20000131
// 0 3
// 19720101 19720131
// 19720201 19720228
// 19720301 19720301
// 1 1
// 20010101 20011231
// 20010515 20010901
// 0 0
// Sample Output 1

// Case 1:
// 1/1/1991 to 1/31/2000
// Case 2:
// 1/1/1972 to 2/28/1972
// 3/1/1972
// Case 3:
// No additional quotes are required.