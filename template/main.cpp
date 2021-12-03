#include<iostream>
#include<fstream>

using namespace std;

unsigned long long part1(ifstream&);
unsigned long long part2(ifstream&);


int main(){
	ifstream finput;
	ifstream ftest;

	finput.open("input.txt");
	ftest.open("test.txt");

	if(!finput.is_open() || !ftest.is_open()){
		cout << "Error opening file" << endl;
	}

	unsigned long long output = part1(finput);
	cout << endl << "Part 1 sample input result: " << output << endl;
	output = part1(ftest);
	cout << "Part 1 test result: " << output << endl << endl;

	output = part2(finput);
	cout << "Part 2 sample input result: " << output << endl;
	output = part2(ftest);
	cout << "Part 2 test results: " << output << endl << endl;

	return 0;
}


unsigned long long part1(ifstream& fin){

	return 0;
}


unsigned long long part2(ifstream& fin){

	return 0;
}
