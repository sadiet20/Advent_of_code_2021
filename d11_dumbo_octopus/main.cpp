#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>

using namespace std;


struct oct{
	int energy;
	bool flashed;
};


unsigned long long part1(ifstream&);
int flash(vector< vector<struct oct> >&, int, int);
void print(vector< vector<struct oct> >);
void print_flash(vector< vector<struct oct> >);
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
	vector< vector<struct oct> > octopi(10, vector<struct oct>(10));
	string s_num;
	int num_flashes = 0;

	for(int i=0; i<10; i++){
		fin >> s_num;
		for(int j=0; j<10; j++){
			octopi[i][j].energy = s_num[j] - 48;
		}
	}

	for(int step=0; step<100; step++){
		//1 point energy increases
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				octopi[i][j].energy++;
				octopi[i][j].flashed = false;
			}
		}

		//flashes
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(octopi[i][j].energy > 9 && false == octopi[i][j].flashed){
					num_flashes += flash(octopi, i, j);
				}
			}
		}

		
		//reset flashed octopi to to zero energy
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(true == octopi[i][j].flashed){
					octopi[i][j].energy = 0;
				}
			}
		}
	}

	return num_flashes;
}


//returns number of flashes completed
int flash(vector< vector<struct oct> >& octopi, int row, int col){
	int num_flashes = 0;

	//check out of bounds
	if(row < 0 || row > 9 || col < 0 || col > 9){
		return 0;
	}

	octopi[row][col].energy++;

	//check if able to flash
	if(octopi[row][col].energy > 9 && false == octopi[row][col].flashed){
		octopi[row][col].flashed = true;

		//add to neighbors
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				//skip itself
				if(i == 0 && j == 0){
					continue;
				}
				num_flashes += flash(octopi, row+i, col+j);
			}
		}
		return 1 + num_flashes;
	}
	return 0;
}


void print(vector< vector<struct oct> > octopi){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout << octopi[i][j].energy << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void print_flash(vector< vector<struct oct> > octopi){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(true == octopi[i][j].flashed)
				cout << "T ";
			else
				cout << "F ";
		}
		cout << endl;
	}
	cout << endl;
}


unsigned long long part2(ifstream& fin){
	vector< vector<struct oct> > octopi(10, vector<struct oct>(10));
	string s_num;
	bool all_flashing;
	int step = 0;

	for(int i=0; i<10; i++){
		fin >> s_num;
		for(int j=0; j<10; j++){
			octopi[i][j].energy = s_num[j] - 48;
		}
	}

	while(1){
		step++;

		//1 point energy increases
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				octopi[i][j].energy++;
				octopi[i][j].flashed = false;
			}
		}

		//flashes
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(octopi[i][j].energy > 9 && false == octopi[i][j].flashed){
					flash(octopi, i, j);
				}
			}
		}

		
		//reset flashed octopi to to zero energy
		//check if all are flashing
		all_flashing = true;
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if(true == octopi[i][j].flashed){
					octopi[i][j].energy = 0;
				}
				else{
					all_flashing = false;
				}
			}
		}
		if(true == all_flashing){
			return step;
		}
	}
}
