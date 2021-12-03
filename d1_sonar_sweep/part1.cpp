#include <iostream>
#include <fstream>


using namespace std;


int main(){
	ifstream fin;
   	fin.open("test.txt", ifstream::in);

	int num1, num2;
	int count = 0;

	fin >> num1;
	while(!fin.eof()){
		fin >> num2;

		if(num2 > num1){
			count++;
		}
		
		num1 = num2;
	}

	cout << "Increasing: " << count << endl;

	fin.close();

	return 0;
}
