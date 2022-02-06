// UVa 760
// Description

// A DNA molecule consists of two strands that wrap around each other to resemble a twisted ladder whose sides,made of sugar and phosphate molecules, are connected by rungs of nitrogen-containing chemicals called bases.Each strand is linear arrangement of repeating similar units called nucleotides, which are each composed of one sugar,one phosphate, and a nitrogenous base.Four different bases are present in DNA: adenine (A), thymine (T), cytosine (C), and guanine (G).The particular order of the bases arranged along the sugar-phosphate backbone is called the DNA sequence;the sequence specifies the exact genetic instructions required to create a particular organism with its own unique traits.

// Geneticists often compare DNA strands and are interested in finding the longest common base sequence in the two strands.Note that these strands can be represented as strings consisting of the letters a, t, c and g.So, the longest common sequence in the two strandsatgcandtgaistg.It is entirely possible that two different common sequences exist that are the same length and are the longest possible common sequences.For example in the strandsatgsandgctg, the longest common sequences aregcandtg.

// Write a program that accepts as input two strings representing DNA strands, and print as output the longest common sequence(s) in lexicographical order.

// Input
// The input file contains several test cases with a blank line between two consecutive.

// The string are at most 300 characters-long.

// Output
// For each test case, print all the longest common sequences, one per line, in lexicographical order.

// If there isn't any common sequence between the two strings, just print: 'No common sequence.'

// Print a blank line between the output of consecutive datasets.

// Sample Input 1

// atgc
// tga

// atgc
// gctg
// Sample Output 1

// tg

// gc
// tg