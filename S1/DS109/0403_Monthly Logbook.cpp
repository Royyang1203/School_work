// https://hackmd.io/MPifk3meSI2WDiD0zvPSNw?view

// The purpose of this laboratory is to explore how to use C++ classes for implementing an abstract data type (ADT). We use a monthly logbook as our example. A monthly logbook consists of a set of entries, one for each day of the month. These entries might be the daily sales of some certain product in a month. A typical logbook displayed in the calendar form is shown below.

// A. Defining the ADT
// class Logbook {
//     private:
//         int logMonth; // Month for the logbook
//         int logYear; // Year for the logbook
//         int entries[31]; // Daily entries for the logbook
//     public:
//         Logbook(int month, int year); // Create a logbook for the specified year and month
//         void putEntry(int day, int value); // Add the specified value into the existing entry for the specified day
//         int getEntry(int day) const; // Return entry for day
//         int getMonth() const; // Return the month
//         int getYear() const; // Return the year
//         int getDaysInMonth() const; // Number of days in month
//         void displayCalendar() const; // Output the monthly entries in calendar form
//         int operator [](int day) const; // Returns the logbook entry for the specified day
//         void operator += (const Logbook &rightLogbook); // Adds logbooks cover the same month

//     private:
//         // Helper functions
//         bool isLeapYear() const; // Check if the year is leap year
//         int getDayOfWeek(int day) const; // On which day of the week the specified day of the month occurs
// }
// B. Test Plan of the Lab
// Tasks to be completed in the lab.
// Construct the following logbooks for the specified dates

// coffee (2003/1)
// apple1 (2020/10)
// apple2 (2020/10)
// Test your getDaysInMonth() member function

// Print the number of days in the coffee logbook
// Record the entries of 100 and 200 respectively for the 1st and 15th day in the coffee logbook.
// Record the entry of 300 into the last day of the coffee logbook.
// Record an entry of 150 into all the Fridays in the coffee logbook.
// Hint: in order to produce a calendar for a given month, you need to know on which day of the week the first day of the month occurs.
// The day of the week corresponding to a data month/day/year can be computed using the following formula:
// day_of_week = (day + y +(y / 4) - (y / 100) + (y + 400) + ((31 * m) / 12)) % 7
// where a =(14 - month) / 12, y = year - a, and m = month + (12 * a) - 2

// Record an entry of 100 for the 1st day twice.
// Output the logbook in calendar form

// Output the monthly entries of the coffee logbook using displayCalendar().
// Test the two defined operators.

// Access the entry of the last day of the coffee logbook using the [] operator.
// Record the entry of 100 and 200 to the 2nd and 10th days of the apple1 logbook, respectively.
// Record the entry of 50 and 120 to the 2nd and 20th days of the apple2 logbook, respectively.
// Add the apple1 logbook to the apple2 logbook using the += operator.
// Output the apple2 logbook in calendar form.