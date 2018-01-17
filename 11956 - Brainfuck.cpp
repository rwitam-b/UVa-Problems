#include<iostream>
#include<sstream>
#include<string>
#define MEM_FIRST 0
#define MEM_LAST 99

using namespace std;

int main()
{
	int T, *mem, ptr, count = 1;
	string command;
	stringstream output;
	cin >> T;
	getline(cin, command);
	while (T--) {
		getline(cin, command);
		mem = new int[MEM_LAST + 1];
    
    // Initializing memory to zero
		for (int a = MEM_FIRST; a <= MEM_LAST; a++) {
			mem[a] = 0;
		}
    
    // Initializing memory pointer and output string stream
		ptr = MEM_FIRST;
		output.clear();
    
    // Process Simulation
		for (int a = 0; a < command.size(); a++) {
			switch (command[a]) {
			case '>':ptr++;
				break;
			case '<':ptr--;
				break;
			case '+':mem[ptr]++;
				break;
			case '-':mem[ptr]--;
				break;
			}
      
      // Handling cyclic behavior
			if (mem[ptr] < 0) {
				mem[ptr] = 256 + mem[ptr];
			}
			else if (mem[ptr] > 255) {
				mem[ptr] %= 256;
			}
			ptr = (ptr < MEM_FIRST) ? MEM_LAST : ((ptr > MEM_LAST) ? MEM_FIRST : ptr);
		}
    
    // Putting memory contents into a stringstream object in hex format
		for (int a = MEM_FIRST; a <= MEM_LAST; a++) {
			if (a != MEM_FIRST) {
				output << " ";
			}
      
      // Zero padding for values of F and below
			if (mem[a] > 15) {
				output << hex << mem[a];
			}
			else {
				output << hex << 0 << mem[a];
			}
		}
		string temp;
		getline(output, temp);
    
    // Output formatting
		for (int a = 0; a < temp.size(); a++) {
			temp[a] = toupper(temp[a]);
		}
		cout << "Case " << count++ << ": " << temp << endl;
	}
	return 0;
}
