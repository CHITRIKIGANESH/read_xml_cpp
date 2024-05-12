#include <iostream>  
#include <fstream>
#include <regex>  
using namespace std;

void RemoveTags(string s)
{
	//const regex pattern("\\<.*?\\>");

	const regex pattern("\\<");
	const regex patt("/.*");
	const regex pat("\\>");
	

	s = regex_replace(s, pattern, "");
	s = regex_replace(s, patt, "");
	s = regex_replace(s, pat, ": ");

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
