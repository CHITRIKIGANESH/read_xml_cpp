#include <iostream>  
#include <fstream>
#include <regex>  
using namespace std;

void RemoveTags(string s)
{
	const regex pattern("\\<.*?\\>");

	s = regex_replace(s, pattern, "");

	cout << s << "\n";

	return;
}

int main () {  
  string srg;  
  ifstream filestream("example.xml");  
  if (filestream.is_open())  
  {  
    while ( getline (filestream,srg) )  
    {  
       RemoveTags(srg);  
    }  
    filestream.close();  
  }  
  else {  
      cout << "File opening is fail."<<endl;   
    }  
  return 0;  
}  




/*
// C++ program for the above approach
#include <iostream>
#include <regex>
using namespace std;

// Function to remove the HTML tags
// from the given string
void RemoveHTMLTags(string s)
{
	const regex pattern("\\<.*?\\>");

	// Use regex_replace function in regex
	// to erase every tags enclosed in <>
	s = regex_replace(s, pattern, "");

	// Print string after removing tags
	cout << s;

	return;
}

// Driver Code
int main()
{

	// Given String
	string str = "<div><b>Geeks for Geeks</b></div>";

	// Function call to print the
	// HTML string after removing tags
	RemoveHTMLTags(str);

	return 0;
}
*/
// This code is contributed by yuvraj_chandra