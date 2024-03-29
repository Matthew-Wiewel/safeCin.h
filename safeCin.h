#ifndef WIEWEL_SAFE_CIN_H
#define WIEWEL_SAFE_CIN_H
#include <string>
#include <vector>
#include <iostream>

/*
	This library is intended to be a helpful library with guaranteeing
	user inputs are in the expected range and type. If a user enters a
	bad input, the safeCin functions will clear the input and ask for the 
	user to try again. (Though you may overload the errorMessage with ""
	to get rid of that.) The first set uses const char[] prompts and error
	messages. The second set uses the exact same logic but will work with
	std::string. 
	
	As a note for the bounded safeCin functions, I do not recommend using
	them for advanced or large datatypes. In order to allow primitives to
	be directly entered into the function 
	(eg: safeCinBoundedIn<int>("prompt", var, 1, 5) without needing to create a 
	variable of the desired type to pass into the function, the bounds are
	passed by value and not by reference.
*/


/*********************************************************************
* 	THESE FUNCTION USED AS HELPER REGARDLESS OF STRING OR CONST CHAR[]	
*********************************************************************/


//helper function to check if an input is within the list of options provided
template <typename DataT>
bool isInOptionsList(const DataT& input, DataT optionsList[], int n)
{	
	//search for input in the options
	for(int i = 0; i < n; i++)
	{
		//if we find input in the array, then it is in the list and we ret true
		if(optionsList[i] == input)
			return true;
	}
	
	//we went through the array and didn't find in put, so we return false
	return false;
}
//helper function to do the same as the function above, but with vectors
template <typename DataT>
bool isInOptionsList(const DataT& input, const std::vector<DataT>& optionsList)
{
	int length = optionsList.size(); //get length of vector
	
	//search the vector
	for(int i = 0; i < length; i++)
	{
		if(optionsList[i] == input)
			return true;
	}
	
	//didn't find input in the vector, return false
	return false;
}

/*********************************************
*	THIS SECTION USES CONST CHAR[] FOR PROMPTS
*********************************************/


//a helper function for the safeCin functions that will clear and
//print the error message if the input is bad.
inline bool wasGood(const bool cinFail, const char errorMessage[])
{
	if(cinFail)
	{
		//input was not good. we will clear, ignore, and give the error message
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << errorMessage;
	}
	
	//return the opposite of cinFail to tell if the input was good
	return !cinFail;
}
//helper function 
//standard safeCin function for one parameter, no bounds
template <typename DataT>
void safeCin(const char prompt[], DataT& input, 
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		//give prompt and get input
		std::cout << prompt;
		std::cin >> input;
		
		//see if input was valid.
		//function will take care of clear, ignore, and error message
		good = wasGood(std::cin.fail(), errorMessage);
		
	}while(!good);
}
//bounded between two values with those values being inclusive to the valid range
//note that the upper and lower bounds are passed by value. This is because
//these functions are intended for use with primitive data types where passing
//by value is optimal
template <typename DataT>
void safeCinBoundedIn(const char prompt[],DataT& input,const DataT& lowerBound,
const DataT& upperBound, const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//in addition to cin.fail(), the bool parameter of 
		//wasGood also checks the bounds of the value.
		//as it uses or checks, it will only compare the values
		//if cin.fail() is false, so we know the input will be
		//good at that point.
		good = wasGood(std::cin.fail() || input < lowerBound 
						|| input > upperBound, errorMessage);
	}while(!good);
}
//bounded with exclusive bounds.
template <typename DataT>
void safeCinBoundedEx(const char prompt[], DataT& input, const DataT& lowerBound,
const DataT& upperBound, const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//now that the bounds are exclusive, <= and >= instea of < and >
		good = wasGood(std::cin.fail() || input <= lowerBound 
						|| input >= upperBound, errorMessage);
	}while(!good);
}
//lower bound inclusive
template <typename DataT>
void safeCinLowerIn(const char prompt[], DataT& input, const DataT& lowerBound,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		good = wasGood(std::cin.fail() || input < lowerBound, errorMessage);
	}while(!good);
}
//lower bound exclusive
template <typename DataT>
void safeCinLowerEx(const char prompt[], DataT& input, const DataT& lowerBound,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		good = wasGood(std::cin.fail() || input <= lowerBound, errorMessage);
	}while(!good);
}
//upper bounded inclusive
template <typename DataT>
void safeCinUpperIn(const char prompt[], DataT& input, const DataT& upperBound,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		good = wasGood(std::cin.fail() || input > upperBound, errorMessage);
	}while(!good);
}
//upper bounded exclusive
template <typename DataT>
void safeCinUpperEx(const char prompt[], DataT& input, const DataT& upperBound,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		good = wasGood(std::cin.fail() || input >= upperBound, errorMessage);
	}while(!good);
}
//limited response to two options. Ideal for yes or no prompts.
template <typename DataT>
void safeCinTwo(const char prompt[], DataT& input, const DataT& option1, 
const DataT& option2, const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		//tests if cin failed or if the input is equal to neither option
		good = wasGood(std::cin.fail() || (input != option1 && input != option2), 
		errorMessage);
	}while(!good);
}
//will check that the input falls into the range of options provided
//n is size of array
template <typename DataT>
void safeCinList(const char prompt[], DataT& input, DataT optionsList[], int n,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//checks cin.fail() and whether input is in the array provided
		good = wasGood(std::cin.fail() || !isInOptionsList(input, optionsList, n),
		errorMessage);
	}while(!good);
}
//will check input is withing vector of options given
template <typename DataT>
void safeCinList(const char prompt[], DataT& input, 
const std::vector<DataT>& optionsList,
const char errorMessage[] = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//check for cin.fail() and that input is in list of options
		good = wasGood(std::cin.fail() || !isInOptionsList(input, optionsList),
		errorMessage);
	}while(!good);
}


/********************************************
*	THIS SECTION USES STD::STRING FOR PROMPTS
********************************************/

//a helper function for the safeCin functions that will clear and
//print the error message if the input is bad.
inline bool wasGood(const bool cinFail, const std::string& errorMessage)
{
	if(cinFail)
	{
		//input was not good. we will clear, ignore, and give the error message
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << errorMessage;
	}
	
	//return the opposite of cinFail to tell if the input was good
	return !cinFail;
}
//standard safeCin function for one parameter, no bounds
template <typename DataT>
void safeCin(const std::string& prompt, DataT& input, 
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		//give prompt and get input
		std::cout << prompt;
		std::cin >> input;
		
		//see if input was valid.
		//function will take care of clear, ignore, and error message
		good = wasGood(std::cin.fail(), errorMessage);
		
	}while(!good);
}
//bounded between two values with those values being inclusive to the valid range
//note that the upper and lower bounds are passed by value. This is because
//these functions are intended for use with primitive data types where passing
//by value is optimal
template <typename DataT>
void safeCinBoundedIn(const std::string& prompt,DataT& input,const DataT& lowerBound,
const DataT& upperBound, const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//in addition to cin.fail(), the bool parameter of 
		//wasGood also checks the bounds of the value.
		//as it uses or checks, it will only compare the values
		//if cin.fail() is false, so we know the input will be
		//good at that point.
		good = wasGood(std::cin.fail() || input < lowerBound 
						|| input > upperBound, errorMessage);
	}while(!good);
}
//bounded with exclusive bounds.
template <typename DataT>
void safeCinBoundedEx(const std::string& prompt, DataT& input, const DataT& lowerBound,
const DataT& upperBound, const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//now that the bounds are exclusive, <= and >= instea of < and >
		good = wasGood(std::cin.fail() || input <= lowerBound 
						|| input >= upperBound, errorMessage);
	}while(!good);
}
//lower bound inclusive
template <typename DataT>
void safeCinLowerIn(const std::string& prompt, DataT& input, const DataT& lowerBound,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		good = wasGood(std::cin.fail() || input < lowerBound, errorMessage);
	}while(!good);
}
//lower bound exclusive
template <typename DataT>
void safeCinLowerEx(const std::string& prompt, DataT& input, const DataT& lowerBound,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		good = wasGood(std::cin.fail() || input <= lowerBound, errorMessage);
	}while(!good);
}
//upper bounded inclusive
template <typename DataT>
void safeCinUpperIn(const std::string& prompt, DataT& input, const DataT& upperBound,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		good = wasGood(std::cin.fail() || input > upperBound, errorMessage);
	}while(!good);
}
//upper bounded exclusive
template <typename DataT>
void safeCinUpperEx(const std::string& prompt, DataT& input, const DataT& upperBound,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		good = wasGood(std::cin.fail() || input >= upperBound, errorMessage);
	}while(!good);
}
//limited response to two options. Ideal for yes or no prompts.
template <typename DataT>
void safeCinTwo(const std::string& prompt, DataT& input, const DataT& option1, 
const DataT& option2, const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		//tests if cin failed or if the input is equal to neither option
		good = wasGood(std::cin.fail() || (input != option1 && input != option2), 
		errorMessage);
	}while(!good);
}
//will check that the input falls into the range of options provided
//n is size of array
template <typename DataT>
void safeCinList(const std::string& prompt, DataT& input, DataT optionsList[], int n,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//checks cin.fail() and whether input is in the array provided
		good = wasGood(std::cin.fail() || !isInOptionsList(input, optionsList, n),
		errorMessage);
	}while(!good);
}
//will check input is withing vector of options given
template <typename DataT>
void safeCinList(const std::string& prompt, DataT& input, 
const std::vector<DataT>& optionsList,
const std::string& errorMessage = "\nBad input. Try again.")
{
	bool good = false;
	
	do
	{
		std::cout << prompt;
		std::cin >> input;
		
		//check for cin.fail() and that input is in list of options
		good = wasGood(std::cin.fail() || !isInOptionsList(input, optionsList),
		errorMessage);
	}while(!good);
}

#endif
