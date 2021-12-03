#include <iostream>
#include <fstream>

using namespace std;


int main(){
	ifstream fin;
	fin.open("test.txt");

	int first[3];
	int second[3];
	int p_sum = 0;
	int c_sum = 0;
	int count = 0;

	int num;
	for(int i=1; i<4; i++){
		fin >> num;
		if(i < 3){
			first[i] = num;
			p_sum += num;
		}
		if(i > 0){
			second[i-1] = num;
			c_sum += num;
		}
	}

	while(!fin.eof()){
		p_sum -= first[0];
		first[0] = first[1];
		first[1] = first[2];
		first[2] = second[2];
		p_sum += first[2];

		c_sum -= second[0];
		second[0] = second[1];
		second[1] = second[2];
		fin >> second[2];
		c_sum += second[2];

		if(c_sum > p_sum){
			count++;
		}
	}

	cout << "Count: " << count << endl;

	return 0;
}
