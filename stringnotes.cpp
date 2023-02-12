/*    
    STRING NOTES
std::string sentence;
char char1;

        NOTE
determine a character if is it digit or char -> include <ctype> 

-- isalpha(sentence.at(index)) or isalpha(char1)
-- isdigit(sentence.at(index)) or isdigit(char1) consider "0-9" not above 9 otherwise the function returns false

        NOTE
convert a character or a string as a lower case or upper case use those ;
-- tolower(char) for upper to lower
-- toupper(char) for lower to upper
<if those functions are written in a 'std::cout' then it will display ascii table equivalent.> e.g. std::cout << tolower("F"); 102
                                                                                                  
        NOTE
there are multiple ways to display the length of the string
--.size() e.g. sentence.size()
--.length() e.g. sentence.length() 
<the only difference between those is length() is more readable.>

        NOTE 
        sentence ="Hey, Naber"
--.clean() e.g. sentence.clean() => ""
--.empty() e.g. sentence.empty() => false
--.append(string) e.g. sentence.append("burrak") => "Hey, Naberburrak"
--.at(index) e.g. sentence.at(3) ==> ',' 
--.insert(index,string or character or symbol) e.g. sentence.insert(0,"x") => "xHey, Naber"
--.find(character) e.g. sentence.find('N') => 5
-.erase(startindex,endindex) e.g. sentence.erase(0,3) => ", Naber"


        NOTE (Random Number Function)
--srand(time(NULL))
int number = rand() => this function generate a number between 0 and 32767(both include).  
how about generate a number in specific interval e.g. between 0 and 6. And perform that you should use remainders. 
rand() % 7 => 0-6
(rand() % 7) +1 => 1-7
*/
#include <iostream>

int main()
{
    char x;
    std::cout << "Please enter an upper case: ";
    std::cin >> x;
    x = tolower(x);
    std::cout <<"\nThe converted version of the case: " << x << std::endl <<"Ascii table equivalent: " << tolower(x) << "\n\n";

    std::string sentence;
    std::string newsentence;
    std::cout <<"Please enter a string: ";
    std::getline(std::cin >> std::ws, sentence);
    for (int loop=0;loop<sentence.length();loop++)
    {
        newsentence += tolower(sentence[loop]);
        if(sentence[loop] == 32)
        {
            continue;
        }
        else if(sentence[loop] != tolower(sentence[loop]))
        {
          std::cout << "The word ->" << sentence[loop]<<" has converted as a lower case.\n";
        }
    }
    std::cout <<"Here is the converted sentence: "<<newsentence;
    std::cout << std::endl <<"How long is this sentence: " << newsentence.size() <<"\nWithout whitespace(s): " << newsentence.size() - 1;
    std::cout << "\n\nDo you want to clean the sentence ?\nwrite 'yes' or 'no': ";

    std::string decision;
    std::getline(std::cin , decision);
    if(decision == "yes")
    {
        newsentence.clear();
        std::cout <<"\nCleaned sentence: "<< newsentence<<"\t";
    }
    
}