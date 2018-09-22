/* Jose Guerrero
 * V00900773
 * 12th September, 2018
 * Description: Ladder Game accepts valid words to form a word ladder whereby the
				 the only acceptable changes are in a one specific character and word
				 has to be of the same length.
 */


#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>



int process_Fail(int count, std::vector<std::string>& word_Bank);

int main()
{
	
		//setting up the GUI interface
		std::cout << "****************************************************\n";
		
		std::cout << "*        Welcome to the Word Ladder Game!          *\n";

		std::vector<std::string> word_Bank;
		std::vector<std::string> check_Bank;

		std::string temp{ "Hello" };

		std::cout << "*       Please enter a word ladder.                *\n";
		std::cout << "*       Press E to finish the ladder               *\n";

		//input flag
		int signal = 0;

		//reading input stream
		while (temp != "E")
		{	
		    

			std::cin >> temp;

			

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "CIN:: FAILED                              " << std::endl;
			}

			if (temp == "E") break;
			
			word_Bank.push_back(temp);
			signal += 1;

	     }

	    if(signal == 0){std::cout << "*Word Ladder not found! Try again!";  return -1; }
		check_Bank = word_Bank;

		//processing the list and validating the ladder
		int word_Length = check_Bank.at(0).length();
		int minus_Points = 0;
		int count = 0;

		std::string inter = check_Bank.at(0);

		for (auto& temp : inter) { temp = tolower(temp); }

		for (auto it=check_Bank.begin()+1; it != check_Bank.end(); it++)
		{
			count += 1;

			for (auto& in : (*it)) { in = tolower(in); }

			
			if ((unsigned int)it->length() != (unsigned int) word_Length) 
			{
				return(process_Fail(count, word_Bank));
			}

			if (*it == inter) { return (process_Fail(count, word_Bank)); }		
			
			
			for (int i = 0; i < word_Length-1; i++)
			{
				if(it->at(i) !=  inter.at(i)){minus_Points +=1;}
				if (minus_Points > 1) { return (process_Fail(count, word_Bank)); }
			}

			

			inter = *it;
			minus_Points = 0;

		
			
			
		}
		
		// prints the success message that the word ladder is valid if it passed through the screening
		std::cout << "Word Ladder is Valid" << std::endl;

		for (auto& elem : word_Bank)
		{
			for (auto& in : elem) { in = tolower(in); }

			std::cout << elem << std::endl;
		}

     
	

	return 0;

}




// function to process the invalid ladder tranistions encountered
int process_Fail(int count, std::vector<std::string> &word_Bank)
{
	std::cout << "Error: Invalid Transition from [" << word_Bank.at(count-1) << "] --> [" << word_Bank.at(count) <<"]" << std::endl;
    std::cout << "****************************************************";
	return 0;
}