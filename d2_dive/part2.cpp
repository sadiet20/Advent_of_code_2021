#include <iostream>
#include <fstream>

using namespace std;


int main(){
	ifstream fin;
	fin.open("test.txt");

	int h_pos = 0;
	int depth = 0;
	int aim = 0;
	string direction;
	int distance;
	
	while(!fin.eof()){
		fin >> direction;
		fin >> distance;

		if(direction == "forward"){
			h_pos += distance;
			depth += aim*distance;
		}
		else if(direction == "down"){
			aim += distance;
		}
		else if(direction == "up"){
			aim -= distance;
		}
		else{
			cout << "BAD INPUT" << endl;
			return 1;
		}
	}

	cout << "Horizontal position times depth = " << h_pos*depth << endl;


	return 0;
}
