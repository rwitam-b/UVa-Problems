#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	int temp, N;
	cin >> N;
	temp = 0;
	string *names = new string[N];
	string words[16] = { "Happy","birthday","to","you","Happy","birthday","to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you" };
	getline(cin, names[0]);
	while (temp < N) {
		getline(cin, names[temp++]);
	}
	int nameIndex = -1, songIndex = -1;
	bool songFlag = true, nameFlag = true;
	while (songFlag || nameFlag) {
		nameIndex++;
		songIndex++;
		cout << names[nameIndex] << ": " << words[songIndex] << endl;
		if (nameIndex == (N - 1)) {
			nameFlag = false;
			nameIndex = -1;
		}
		if (songIndex == 15) {
			songIndex = -1;
			if (!nameFlag) {
				songFlag = false;
			}
		}
	}
	return 0;
}
