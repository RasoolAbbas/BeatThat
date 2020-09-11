#include <iostream>
#include <ctime>

using namespace std;

int rollDice(int& rollOne, int& rollTwo) {

	int diceOne, diceTwo;

	rollOne = diceOne = rand() % 6 + 1;
	rollTwo = diceTwo = rand() % 6 + 1;

	if (diceOne >= diceTwo) {
		return (diceOne * 10) + diceTwo;
	}
	else {
		return (diceTwo * 10) + diceOne;
	}
}

void printScore(int humanScore, int computerScore) {
	cout << "The current score is - Human: " << humanScore << ", Computer: " << computerScore << endl;
}

void startGame(int& humanScore, int& computerScore) {
	srand(time(NULL));

	int currentScore = 1, previousScore = 0, rollOne, rollTwo;
	string curTurn = "Human";
	
	do {
		if (currentScore > 1) {
			cout << "\n" << currentScore << " is the number to beat!" << endl;
		}
		
		curTurn = "Human";
		cout << "Rolling 2 dice for " << curTurn << ":" << endl;
		currentScore = rollDice(rollOne, rollTwo);
		cout << "Rolled " << rollOne << " and " << rollTwo << ", making " << currentScore << endl;
		

		if (currentScore < previousScore) {
			break;
		} else {
			previousScore = currentScore;
		}

		curTurn = "Computer";
		cout << "\n" << currentScore << " is the number to beat!" << endl;
		cout << "Rolling 2 dice for " << curTurn << ":" << endl;
		currentScore = rollDice(rollOne, rollTwo);
		cout << "Rolled " << rollOne << " and " << rollTwo << ", making " << currentScore << endl;


	} while (currentScore >= previousScore);

	cout << "\nToo bad! Unlucky roll for the " << curTurn << " player." << endl;

	if (curTurn == "Human") {
		computerScore++;
	} else {
		humanScore++;
	}

	printScore(humanScore, computerScore);
}

int main() {
	int humanScore = 0, computerScore = 0;

	char keepPlayingAnswer = 'Y';
	
	while (keepPlayingAnswer != 'N' && keepPlayingAnswer != 'n') {
		startGame(humanScore, computerScore);

		cout << "\nWould you like to go again? [Y/N]?";
		cin >> keepPlayingAnswer;
	}

	return 0;
}