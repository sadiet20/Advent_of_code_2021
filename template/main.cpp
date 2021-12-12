#include<iostream>
#include<fstream>

using namespace std;

unsigned long long part1(ifstream&);
unsigned long long part2(ifstream&);


int main(){
	ifstream finput;
	ifstream ftest;
	unsigned long long output;

	finput.open("input.txt");
	ftest.open("test.txt");

	if(!finput.is_open() || !ftest.is_open()){
		cout << "Error opening file" << endl;
	}

	output = part1(finput);
	cout << endl << "Part 1 sample input result: " << output << endl;
	output = part1(ftest);
	cout << "Part 1 test result: " << output << endl << endl;

	//reset to beginning of files
	finput.clear();
	ftest.clear();
	finput.seekg(0, ios::beg);
	ftest.seekg(0, ios::beg);

	output = part2(finput);
	cout << "Part 2 sample input result: " << output << endl;
	output = part2(ftest);
	cout << "Part 2 test results: " << output << endl << endl;

	finput.close();
	ftest.close();

	return 0;
}


unsigned long long part1(ifstream& fin){
	while(!fin.eof()){
	
	}
	return 0;
}


unsigned long long part2(ifstream& fin){
	while(!fin.eof()){
	
	}
	return 0;
}
