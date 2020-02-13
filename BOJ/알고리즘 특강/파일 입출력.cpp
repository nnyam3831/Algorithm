#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void){
	ofstream writeFile;
	writeFile.open("sample.txt");
	
	writeFile.write("ACAYKP\n", 7);
	writeFile.write("CAPCAK\n", 7);
	writeFile.close();
	return 0;
}
