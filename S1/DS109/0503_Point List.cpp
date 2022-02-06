// https://hackmd.io/PvRpeCVzQj6OHaj4Bne-ig?view
// In this laboratory, you will practice using an array to store a list of 2-D points with each represented with a coordinate
// (
// x
// ,
// y
// )
// . Point lists are routinely used in computer graphics, computer-aided design to represent lines, curves, edges, and so on. For example, a polyline contains five points is shown below.

// A. Defining the ADT
// class Point {
// public:
//     float x, y;
//     Point(); // Default constructor
//     Point(float a, float b); // Initializer
//     Point(const Point& p); // Copy constructor
//     bool operator==(const Point& p); // Equality testing operator
// };

// class PointList {
// public:
//     PointList(); // Constructor
//     PointList(PointList& pl); // Copy constructor
//     void append(Point newPoint); // Append a point (newPoint) to list
//     void clear(); // Clear list
//     bool isEmpty() const; // Return true if list is empty
//     bool isFull() const; // Return true if list is full
//     int find(Point& p) const; // Find where the given point (p) appears in the PointList (using 0-based index)
//     int find(PointList& pl) const; // Find where a given PointList (pl) appears in the PointList (You must implment the Knuth-Morris-Pratt algorithm introduced in the textbook)
//     void insert(Point& p, int at); // Insert a point at the specified position (at)
//     void insert(PointList& pl, int at); // Insert a point list (pl) at the specified position (at) to get a longer point list
//     void del(int at, int len); // Delete the sub list of the length (len) starting from the specified position (at)
//     Point& operator[](int index); // Operator for accessing the point at the specified position (index)
//     friend ostream& operator<<(ostream& os, const PointList pl); // Stream the point list to cout
// private:
//     // Data members
//     int* failure(); // Compute the failure function for the point list using the Knuth-Morris-Pratt algorithm
//     int size; // Actual number of points in the list
//     Point points[maxListSize]; // Allocated point array of the maximum capacity (maxListSize)
// }
// B. Test Plan of the Lab
// Tasks to be completed in the lab.
// Construct the following point list, say plst1:
// (1,1) - (2,2) - (3,3) - (1,1) - (2,2) - (3,3) - (1,1) - (3,3) - (1,1) - (2,2)
// Use the << operator to display the constructed point list plst1.
// Show where the points (1,2), (2,2), and (3,3) appear in the point list plist1.
// Copy the constructed list plist1 to another list plist2 and insert plist2 at the position 4 in plist1. Display the resultant point list.
// Compute the failure function for plist2 using the KMP algorithm (See Section 2.6.2 in CCC’s lecture note or the textbook). Print out the values of the function at each position in plist2. (It’s values should be -1 -1 -1 0 1 2 3 -1 0 1.)
// Hint: you can do this by modifying the code given in the lecture note.
// Search where plist2 appears in plist1 using the KMP algorithm.
// Hint: you can do this by modifying the code given in the lecture note.