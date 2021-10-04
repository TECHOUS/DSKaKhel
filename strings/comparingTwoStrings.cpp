     /*                         
							 ------     ------   |--|    |    |\    |    |----     |----
							 |            |      |  |    |    | \   |    |         |
							 |-----|      |      |--|    |	  |  \  |    |         |----|
								   |      |      |\      |    |   \ |    |   --|        |
							  -----|      |      | \     |    |    \|    |-----|    ----|
							 
							 
	 Strings are defined as an array of characters. The difference between a character array 
	   and a string is the string is terminated with a special null character .
	   
	   Basic Syntax :-      char str_name[size]    ( in C language)
	   
	   */
	   
	   
	   // THIS IS A CODE IN C++ FOR COMPARING 2 STRINGS
	   
	   /* here I am using relational operator but this can also be implemented using compare() .
	   
	   Differences between C++ Relational operators and compare() :-  

       -compare() returns int, while relational operators return boolean value
	   -A single Relational operator is unique to a certain operation, while compare() can perform lots of different operations alone.
	   */
	   
	   
	   
#include <iostream>
 
using namespace std;
 
void compareFunction(string s1, string s2)
{
    // comparing both using inbuilt function
    int x = s1.compare(s2);
 
    if (x != 0) {
        cout << s1
             << " is not equal to "
             << s2 << endl;
        if (x > 0)
            cout << s1
                 << " is greater than "
                 << s2 << endl;
        else
            cout << s2
                 << " is greater than "
                 << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}
 
// Driver Code
int main()
{
    string s1("Hactoberfest");
    string s2("Github");
    compareFunction(s1, s2);
    string s3("Git");
    string s4("anshumanlite");
    compareFunction(s3, s4);
    return 0;
}