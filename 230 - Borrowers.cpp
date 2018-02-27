#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct book {
	// Book structure
	string title, author;
	bool status;
};

bool compareBooks(struct book a, struct book b) {
	// Book comparator function
	if (a.author.compare(b.author) < 0) {
		return true;
	}
	else if (a.author.compare(b.author) > 0) {
		return false;
	}
	else {
		return a.title.compare(b.title) < 0;
	}
}

int main() {
	string str;
	vector<struct book> stock, pile;
	unordered_map<string, string> lookup;

	// Stock Input
	while (getline(cin, str) && str.compare("END")) {
		string bookName = str.substr(0, str.find("\"", 1) + 1);
		string authorName = str.substr(str.find("by") + 3);
		struct book temp = { bookName, authorName,true };
		stock.push_back(temp);
		lookup[bookName] = authorName;
	}

	// Sorting the stock according to author, title
	sort(stock.begin(), stock.end(), compareBooks);

	while (getline(cin, str) && str.compare("END")) {
		if (str.compare("SHELVE")) {
			string operation = str.substr(0, str.find("\"") - 1);
			string title = str.substr(str.find("\""));
			if (lookup.find(title) != lookup.end()) {
				struct book temp = { title,lookup[title] };
				vector<struct book>::iterator find = lower_bound(stock.begin(), stock.end(), temp, compareBooks);
				if (!operation.compare("BORROW")) {
					stock[find - stock.begin()].status = false;
				}
				else if (!operation.compare("RETURN")) {
					pile.push_back(temp);
				}
			}
		}
		else {

			// Sorting the returned pile
			sort(pile.begin(), pile.end(), compareBooks);
			for (int a = 0; a < pile.size(); a++) {
				vector<struct book>::iterator find = lower_bound(stock.begin(), stock.end(), pile[a], compareBooks);
				int index = find - stock.begin() - 1;
				while (index >= 0) {
					if (stock[index].status) {
						cout << "Put " << pile[a].title << " after " << stock[index].title << endl;
						break;
					}
					index--;
				}
				if (index < 0) {
					cout << "Put " << pile[a].title << " first" << endl;
				}
				stock[find - stock.begin()].status = true;
			}
			pile.clear();
			cout << "END" << endl;
		}
	}
	return 0;
}
