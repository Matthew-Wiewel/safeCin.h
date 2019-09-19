#include "safeCin.h"
#include <iostream>
#include <string>
using namespace std;

enum choices{ base = 1, boundedIn, boundedEx, lowerIn, lowerEx, upperIn, upperEx,
two, arrayChoices, vectorChoices, baseString, boundedInString, boundedExString,
lowerInString, lowerExString, upperInString, upperExString, twoString, 
arrayChoicesString, vectorChoicesString, quit };

int menu();
void showResult(int res);
void showResult(char res);

int main()
{	
	bool stopTesting = false;
	int input = 0;
	char charInput = ' ';
	string prompt = " ";
	char nonDef[28] = "\nNon-default error message.";
	string nonDefString = "\nNon-default error message.";
	const int arraySize = 4;
	char arrayOptions[arraySize] = { 'a', 'b', 'c', 'd' };
	vector<char> vectorOptions = { 'a', 'b', 'c', 'd' };
	
	do
	{
		switch(menu())
		{
			case base:
			{
				safeCin<int>("\nEnter an integer: ", input, nonDef);
				showResult(input);
				break;
			}
			case boundedIn:
			{
				safeCinBoundedIn<int>("\nEnter an integer from 1 to 5: ", 
				input, 1, 5);
				showResult(input);
				break;
			}
			case boundedEx:
			{
				safeCinBoundedEx<int>("\nEnter an integer between 1 and 5: ",
				input, 1, 5);
				showResult(input);
				break;
			}
			case lowerIn:
			{
				safeCinLowerIn<int>("\nEnter an integer greater or equal to 1: ",
				input, 1);
				showResult(input);
				break;
			}
			case lowerEx:
			{
				safeCinLowerEx<int>("\nEnter an integer above 1: ", input, 1);
				showResult(input);
				break;
			}
			case upperIn:
			{
				safeCinUpperIn<int>("\nEnter an integer less than or equal to 5: ",
				input, 5);
				showResult(input);
				break;
			}
			case upperEx:
			{
				safeCinUpperEx<int>("\nEnter an integer less than 5: ", 
				input, 5);
				showResult(input);
				break;
			}
			case two:
			{
				safeCinTwo<char>("\nChoose yes or no. (y/n): ", charInput, 'y', 'n');
				showResult(charInput);
				break;
			}
			case arrayChoices:
			{
				safeCinList<char>("\nEnter a, b, c, or d: ", charInput, 
				arrayOptions, arraySize);
				showResult(charInput);
				break;
			}
			case vectorChoices:
			{
				safeCinList<char>("\nEnter a, b, c, or d: ", charInput, 
				vectorOptions);
				showResult(charInput);
				break;
			}
			case baseString:
			{
				prompt = "\nEnter an integer: ";
				safeCin<int>(prompt, input, nonDefString);
				showResult(input);
				break;
			}
			case boundedInString:
			{
				prompt = "\nEnter an integer from 1 to 5: ";
				safeCinBoundedIn<int>(prompt, input, 1, 5);
				showResult(input);
				break;
			}
			case boundedExString:
			{
				prompt = "\nPlease enter an integer between 1 and 5: ";
				safeCinBoundedEx<int>(prompt, input, 1, 5);
				showResult(input);
				break;
			}
			case lowerInString:
			{
				prompt = "\nPlease enter an integer greater or equalt to 1: ";
				safeCinLowerIn<int>(prompt, input, 1);
				showResult(input);
				break;
			}
			case lowerExString:
			{
				prompt = "\nPlease enter an integer greater than 1: ";
				safeCinLowerEx<int>(prompt, input, 1);
				showResult(input);
				break;
			}
			case upperInString:
			{
				prompt = "\nPlease enter an integer less than or equal to 5: ";
				safeCinUpperIn<int>(prompt, input, 5);
				showResult(input);
				break;
			}
			case upperExString:
			{
				prompt = "\nPlease enter an integer less than 5: ";
				safeCinUpperEx<int>(prompt, input, 5);
				showResult(input);
				break;
			}
			case twoString:
			{
				prompt = "\nPlease choose yes or no. (y/n): ";
				safeCinTwo<char>(prompt, charInput, 'y', 'n');
				showResult(charInput);
				break;
			}
			case arrayChoicesString:
			{
				prompt = "\nEnter a, b, c, or d: ";
				safeCinList<char>(prompt, charInput, arrayOptions, arraySize);
				showResult(charInput);
				break;
			}
			case vectorChoicesString:
			{
				prompt = "\nEnter a, b, c, or d: ";
				safeCinList<char>(prompt, charInput, vectorOptions);
				showResult(charInput);
				break;
			}
			case quit:
			{
				stopTesting = true;
				break;
			}
			default:
			{
				cout << "\nSomething went wrong.";
				cout << "\nHorribly. Horribly. Wrong.";
			}
		}
	}while(!stopTesting);
	
	return 0;
}

int menu()
{
	int choice = 0;
	
	cout << "\n\nHere are your options to test.";
	cout << "\n1:  Basic safeCin. (has non-default errorMessage)";
	cout << "\n2:  Bounded on two sides, inclusive.";
	cout << "\n3:  Bounded on two sides, exclusive.";
	cout << "\n4:  Lower bound, inclusive.";
	cout << "\n5:  Lower bound, exclusive.";
	cout << "\n6:  Upper bound, inclusive.";
	cout << "\n7:  Upper bound, exclusive.";
	cout << "\n8:  Two options.";
	cout << "\n9:  Array of options.";
	cout << "\n10: Vector of options.";
	cout << "\n11: Basic safeCin with std::string. (has non-default erroMessage)";
	cout << "\n12: Bounded on two sides, inclusive with std::string.";
	cout << "\n13: Bounded on two sides, exclusive with std::string.";
	cout << "\n14: Lower bound, inclusive with std::string.";
	cout << "\n15: Lower bound, exclusive with std::string.";
	cout << "\n16: Upper bound, inclusive with std::string.";
	cout << "\n17: Upper bound, exclusive with std::string.";
	cout << "\n18: Two options, with std::string.";
	cout << "\n19: Array of options with std::string.";
	cout << "\n20: Vector of options with std::string.";
	cout << "\n21: Quit.";

	//get choice
	safeCinBoundedIn<int>("\n\nWhich test would you like to do? ",choice, 
	base, quit);
	
	return choice;
}
void showResult(int res)
{
	cout << "\nHere is what we got: " << res;
}
void showResult(char res)
{
	cout << "\nHere is what we got: " << res;
}
