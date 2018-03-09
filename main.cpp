/**
*
*  Myles Crouther
*  Text file to HTML Converter
*  First draft
*
**/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main(){

//step 1; Declare variables
int lineCount;
string nextPage;
char ch;

//Open infile and outfile for augmentation
ifstream infile;
ofstream outfile;

infile.open("1765.txt");

//Check if file is open correctly
if (!infile){
cout << "Cannot Open the input file." << endl;
return 1;
}

//initializes input file stream starting character & page #
infile.get(ch);
int i = 1;

//Page creation loop
while(infile){

//file name creation
string filename;
stringstream a;
a << i;

if     (i < 10)    filename = "page000" + a.str();
else if(i < 100)   filename = "page00" + a.str();
else if(i < 1000)  filename = "page0" + a.str();
else if(i < 10000) filename = "page" + a.str();
filename += ".html";

//open file by name
outfile.open(filename.c_str());
lineCount = 1;

//HTML Tags
outfile << "<!doctype html>" << endl;
outfile << "<html lang =\"en\">" << endl;
outfile << "<head>" << endl;
outfile << "<meta charset = \"utf-8\">" << endl;
outfile << "<title>The Good Book</title>" << endl;
outfile << "<link rel=\"stylesheet\" href=\"css/style.css\">" << endl;
outfile << "</head>" << endl;
outfile << "<body>" << endl; 

//Body Paragraph
outfile << "<div class = \"main\">" << endl;
outfile << "<pre>" << endl;
outfile << "<p>" << endl;

//Copies a hundred lines from the input file
while(lineCount <= 100){
while(ch != '\n'){
outfile << ch;
infile.get(ch);
} //end of single line loop

outfile << endl;
lineCount++;
infile.get(ch);
} //end of 100 line loop

//Closing Text  Tags
outfile << endl;
outfile << "</p>" << endl;
outfile << "</pre>" << endl;
outfile << "</div>" << endl;

//Next page condition check
if (infile){
string next;
stringstream b;
b << ++i;

if     (i < 10)    next = "page000" + b.str();
else if(i < 100)   next = "page00" + b.str();
else if(i < 1000)  next = "page0" + b.str();
else if(i < 10000) next = "page" + b.str();
next += ".html";
nextPage = next;
i--;
}

//Navigation Bar Div
outfile << "<div class=\"navbar\">" << endl;
outfile << "<a href=\"index.html\">Index</a>" << endl;
outfile << "<a href=\"page0001.html\">First</a>" << endl;
outfile << "<a href=\"" << nextPage << "\"/>Next</a>" << endl;
outfile << "<a href=\"page0037.html\">Last</a>" << endl;
outfile << "</div>" << endl;

//Closing HTML Tags
outfile << endl;
outfile << "</body>" << endl;
outfile << "</html>" << endl;

//closes completed file
outfile.close();

i++;
}//end of file generating loop

//closes input file stream
infile.close();

return 0;
} //End of main function
