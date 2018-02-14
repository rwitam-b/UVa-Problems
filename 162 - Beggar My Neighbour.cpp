#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ") {
	return ltrim(rtrim(str, chars), chars);
}

void playGame(stack<int> player1, stack<int> player2) {
	stack<int> game;
	bool playFlag = true;
	int cover = 0;
	while ((!player1.empty() && !playFlag) || (!player2.empty() && playFlag)) {
		stack<int> t;
		int play;
		if (playFlag) {
			play = player2.top();
			player2.pop();
		}
		else {
			play = player1.top();
			player1.pop();
		}
		game.push(play);
		if (cover > 0 && play <= 10) {
			cover--;
			
			// Completed the cover
			if (cover == 0) {				
				stack<int> activePlayer, temp;
				activePlayer = (!playFlag) ? player2 : player1;

				// Store player stack to a temporary stack
				while (!activePlayer.empty()) {
					temp.push(activePlayer.top());
					activePlayer.pop();
				}

				// Push game stack to player stack
				while (!game.empty()) {
					activePlayer.push(game.top());
					game.pop();
				}

				// Push back player stack from temporary stack
				while (!temp.empty()) {
					activePlayer.push(temp.top());
					temp.pop();
				}
				// Assign working copy of player stack to actual variables
				if (!playFlag) {
					player2 = activePlayer;
				}
				else {
					player1 = activePlayer;
				}
			}
			else {
				continue;
			}
		}
		if (play > 10) {
			cover = play % 10;
		}
		playFlag = !playFlag;
	}
	stack<int> winner;
	int winCount = 0;
	if (player1.empty() && !playFlag) {
		winner = player2;
		cout << "2 ";
	}
	if (player2.empty() && playFlag) {
		winner = player1;
		cout << "1 ";
	}
	while (!winner.empty()) {
		winner.pop();
		winCount++;
	}
	printf("%2d\n", winCount);
}

int main() {
	string str;
	int handCounter = 0;
	bool dealFlag;

	// Player card stacks
	stack<int> p1, p2;
	while (getline(cin, str) && str.size() > 0 && str.compare("#")) {
		// Check whether this is a new card deal
		if (handCounter == 0) {
			p1 = stack<int>();
			p2 = stack<int>();
			dealFlag = true;
		}
		trim(str);
		stringstream s(str);
		while (s.good()) {
			string temp;
			int cardValue;
			s >> temp;
			// Converting all cards to integers for ease of processing
			switch (temp[1]) {
			case 'T':cardValue = 10; break;
			case 'J':cardValue = 11; break;
			case 'Q':cardValue = 12; break;
			case 'K':cardValue = 13; break;
			case 'A':cardValue = 14; break;
			default:cardValue = temp[1] - '0';
			}
			// Dealing alternatively between player 1 and 2
			if (dealFlag) {
				p2.push(cardValue);
			}
			else {
				p1.push(cardValue);
			}
			dealFlag = !dealFlag;
		}
		handCounter++;
		// Check whether a card deal just finished
		if (handCounter == 4) {
			// Do the game processing			
			playGame(p1, p2);
			handCounter = 0;
		}
	}
	return 0;
}
