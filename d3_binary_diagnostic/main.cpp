#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<cassert>

using namespace std;

unsigned long long part1(ifstream&);
int binary_to_decimal(int);
unsigned long long part2(ifstream&);
void print(vector<string> input, vector<int> idx);


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
	vector<string> input;
	string s;
	int num_ones;
	int gamma = 0;
	int epsilon = 0;

	while(!fin.eof()){
		fin >> s;
		if(fin.eof()){
			break;
		}
		input.push_back(s);
	}

	for(int i=input[0].length()-1; i>=0 ; i--){
		num_ones = 0;
		for(int j=0; j<input.size(); j++){
			if(input[j][i] == '1'){
				num_ones++;
			}
		}

		//what to do in case of tie is not defined
		assert(num_ones != input.size()/2);
		
		//add the decimal representation to gamma or epsilon
		if(num_ones > input.size()/2){
			gamma += 1*pow(2, input[0].length()-1-i);
		}
		else{
			epsilon += 1*pow(2, input[0].length()-1-i);
		}
	}

	return gamma * epsilon;
}

/*
int binary_to_decimal(int bin){
	int dec = 0;
	int i = 0;
	int last;
	cout << "binary: " << bin << endl;
	while(bin > 0){
		last = bin%10;
		bin = bin/10;
		dec += last*pow(2, i);
		i++;
	}
	cout << "decimal: " << dec << endl;
	return dec;
}
*/

unsigned long long part2(ifstream& fin){
	vector<string> input;
	vector<int> oxy_idx;
	vector<int> co2_idx;
	string s;
	int num_ones;
	int oxygen = 0;
	int co2 = 0;
	int match;

	while(!fin.eof()){
		fin >> s;
		if(fin.eof()){
			break;
		}
		input.push_back(s);
	}

	//add all numbers to be considered
	for(int i=0; i<input.size(); i++){
		oxy_idx.push_back(i);
		co2_idx.push_back(i);
	}

	//calculate oxygen levels
	for(int i=0; i<input[0].size(); i++){
		//count number of 1's in nums still in consideration
		num_ones = 0;
		for(int j=0; j<oxy_idx.size(); j++){
			if(input[oxy_idx[j]][i] == '1'){
				num_ones++;
			}
		}

		//choose whichever is larger
		if(num_ones >= oxy_idx.size()/2.0){
			match = '1';
		}
		else{
			match = '0';
		}
		
		//remove the nums that don't match the more common
		for(int j=0; j<oxy_idx.size(); j++){
			if(input[oxy_idx[j]][i] != match){
				oxy_idx[j] = -1;
			}
		}
		for(int j=0; j<oxy_idx.size(); j++){
			if(oxy_idx[j] == -1){
				oxy_idx.erase(oxy_idx.begin()+j);
				j--;
			}
		}
		
		assert(oxy_idx.size() >= 1);

		//if only one number left, it is the oxygen
		if(oxy_idx.size() == 1){
			//convert to decimal
			for(int j=0; j<input[0].length(); j++){
				oxygen += ((int)input[oxy_idx[0]][j]-48) * pow(2, input[0].length()-1-j);
			}
			break;
		}
	}

	//calculate co2 levels
	for(int i=0; i<input[0].size(); i++){
		//count number of ones
		num_ones = 0;
		for(int j=0; j<co2_idx.size(); j++){
			if(input[co2_idx[j]][i] == '1'){
				num_ones++;
			}
		}

		//pick the lesser common digit
		if(num_ones >= co2_idx.size()/2.0){
			match = '0';
		}
		else{
			match = '1';
		}
		
		//remove numbers that don't match the least common digit
		for(int j=0; j<co2_idx.size(); j++){
			if(input[co2_idx[j]][i] != match){
				co2_idx[j] = -1;
			}
		}
		for(int j=0; j<co2_idx.size(); j++){
			if(co2_idx[j] == -1){
				co2_idx.erase(co2_idx.begin()+j);
				j--;
			}
		}

		assert(co2_idx.size() >= 1);

		//if one number left, it is the co2
		if(co2_idx.size() == 1){
			//convert to decimal
			for(int j=0; j<input[0].length(); j++){
				co2 += ((int)input[co2_idx[0]][j]-48) * pow(2, input[0].length()-1-j);
			}
			break;
		}
	}

	return oxygen * co2;
}


void print(vector<string> input, vector<int> idx){
	for(int i=0; i<idx.size(); i++){
		for(int j=0; j<input[0].length(); j++){
			cout << input[idx[i]][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
