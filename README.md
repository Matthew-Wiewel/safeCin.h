# safeCin.h
The safeCin.h header provides some templated functions to assist in reading values with std::cin and not having issues with invalid inputs. 
If an input causes std::cin.fail() to yield a true result, the input will be ignored and the user will be able to reenter the input. 

Each safeCin function takes in a prompt, variable by reference, optional bounds, and an error message.
Prompts and error messages may be either const char[] or std::string. They should be the same type for a particular function call. 

The template name of the datatype is DataT.

All functions has a default error message of: "\nBad input. Try again."
If you do not wish to have an error message, pass in a either a const char[] or std::string (depending on which function you call)
with a value of "".

# functions contained in safeCin.h

# functions taking const char[] prompts and error messages

inline bool wasGood(const bool, const char[])
This is a helper function used throughout the safeCin functions that take const char[] prompts and error messages.
It clears the input, ignores until the newline, and will print the error message.

void safeCin(const char prompt[], DataT& input, const char[] errorMessage[])
This function is the basic safeCin. It will print the prompt for the user and ask for input. 
If the entered data caused a cin.fail(), it will call wasGood and prompt the user to retry the input.

void safeCinBoundedIn(const char prompt[], DataT& input, const DataT& lowerBound, const DataT& upperBound, const char errorMessage[])
This function adds in boundaries for the input. These boundaries are inclusive of the bounds.

void safeCinBoundedEx(const char prompt[], DataT& input, const DataT& lowerBound, const DataT& upperBound, const char errorMessage[])
The boundaries of this function are exclusie.

void safeCinLowerIn(const char prompt[], DataT& input, cosnt DataT& lowerBound, const char errorMessage[])
This function has an inclusive lower bound.

void safeCinLowerEx(const char prompt[], DataT& input, const DataT& lowerBound, const char errorMessage[])
This function has an exclusive lower bound.

void safeCinUpperIn(const char prompt[], DataT& input, const DataT& upperBound, const char errorMessage[])
This function has an inclusive upper bound.

void safeCinUpperEx(const char prompt[], DataT& input, const DataT& upperBound, const char errorMessage[])
This function has an exclusive upper bound.

void safeCinTwo(const char prompt[], DataT& input, const DataT& option1, const DataT& option2, const char errorMessage[])
This function will check that the input value is both valid and equivalent to one of the passed options.
It was written with "Do you want to do X? (y/n): " type prompts in mind.

# functions taking std::string prompts and error messages

For the following functions, please refer to the above function with the same name to know the functionality.

inline bool wasGood(const bool, const std:string&)

void safeCin(const std::string& prompt, DataT& input, const std::string& errorMessage)

void safeCinBoundedIn(const std::string& prompt, DataT& input, const DataT& lowerBound, const DataT& upperBound, const std::string& errorMessage)

void safeCinBoundedEx(const std::string& prompt, DataT& input, const DataT& lowerBound, const DataT& upperBound, const std::string& errorMessage)

void safeCinLowerIn(const std::string& prompt, DataT& input, const DataT& lowerBound, const std:string& errorMessage)

void safeCinLowerEx(const std::string& prompt, DataT& input, const DataT& lowerBound, const std:string& errorMessage)

void safeCinUpperIn(const std::string& prompt, DataT& input, const DataT& upperBound, const std::string& errorMessage)

void safeCinUpperEx(const std::string& prompt, DataT& input, const DataT& upperBound, const std::string& errorMessage)

void safeCinTwo(const std::string& prompt, DataT& input, const DataT& option1, const DataT& option2, const std::string& errorMessage)
