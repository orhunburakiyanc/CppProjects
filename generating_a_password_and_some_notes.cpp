/*      UNFAMILIAR FUNCTION TRICKS
    NOTE 
Overloaded functions which have same name but different function. Furthermore, for seperation those functions there are requirements
that have to be different parameters in each function. 
--
void constaminate()                 constaminate() will run first void function
void constaminate(int a)            constaminate(number) will run second void function
void constaminate(inta,double b)    constaminate(number,doublenumber) will run third void function
so it can be clearly seen, the program can specify the function for the given above.

// ASCII table #33-#47 and #58-#64 
// Ascii to letter, use this char(number)
// Letter to ascii, use this toascii(letter)

      NOTE 
-to find length of a array.
int array[] = {2,3,4,5,6};
int sizeArray = sizeof(array)/sizeof(array[0]);
*/

//Random Password Generator !!
// NOTE = the program can't run properly when user enters the day as a letter however, when it comes to year it runs.
    // ASK THIS PROBLEM !
#include <iostream>
bool checkVariable(const std::string birthdayyearstring) // 'const' = > after assign as a const the value can't be changed.
{
    for (int iteration = 0;iteration < birthdayyearstring.length();iteration++)
    {
        if (isdigit(birthdayyearstring[iteration])==false)
        {
            return false;
        }
    }
    return true;
}
void passwordgenerator(const std::string birthdaystring, const std::string birthyearstring, const std::string name)
{
    srand(time(NULL));

    int lengthSigncodes,index,iteration;
    std::string mixedintegers,mixedname,mixedsign,password = "";

    int signcodes[] = {33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64};
    lengthSigncodes = sizeof(signcodes)/sizeof(signcodes[0]);
   
    //mixing year's and day's integers.
    std::string integers= birthdaystring + birthyearstring;
    for(iteration=0;iteration<3;iteration++)
    {
        index = rand() % (birthdaystring.length()+birthyearstring.length());
        mixedintegers += integers[index];
        iteration++;
    }
    //mixing name's letter.
    for(iteration=0;iteration<4;iteration++)
    {
        index = rand() % name.length();
        mixedname += name[index];
        iteration++;
    }
    //mixing signs.
    for(iteration=0;iteration<3;iteration++)
    {
        index = rand() % lengthSigncodes;
        mixedsign += char(signcodes[index]);
    }
    //generating the password.
    std::string pseudopassword;
    pseudopassword = mixedsign + mixedintegers + mixedname;
    for(iteration=0;iteration < pseudopassword.length();iteration++)
    {
        index = rand() % pseudopassword.length();
        password += pseudopassword[index];
    }
    std::cout << "\nHere it's your new password: " << password;
}
int fdecision()
{   
    int decision; 
    std::cout <<"\nPress any key to actiave the process once again.\nPress '2' to exit.\n";
    std::cin >> decision;
    std::cin.clear();
    fflush(stdin);
    return decision;
}
int main()
{
    int birthday,birthyear;
    std::string name;
      
    std::cout << "Please enter your name: ";
    std::cin >> name;


    //------birthday------
    std::cout << "Please enter your birth day: ";
    std::cin >> birthday;
    std::string birthdaystring = std::to_string(birthday);

    std::cin.clear();
    fflush(stdin);

    while(checkVariable(birthdaystring)==false || birthday > 31 || birthday < 0)
    {
        std::cout << "Please enter your birth day: ";
        std::cin >> birthday;
        std::string birthdaystring = std::to_string(birthday);

        std::cin.clear();
        fflush(stdin);
    }
    


    //------birthyear------ 
    std::cout << "Please enter your birth year: ";
    std::cin >> birthyear;
    std::string birthyearstring = std::to_string(birthyear);

    std::cin.clear();
    fflush(stdin);

    while(checkVariable(birthyearstring)==false || birthyear < 1900 || birthyear > 2100)
    {
        std::cout << "Please enter your birth year: ";
        std::cin >> birthyear;
        std::string birthyearstring = std::to_string(birthyear);
        
        std::cin.clear();
        fflush(stdin);
    }
    
    //Main transaction.
    int decision;
    do
    { 
        passwordgenerator(birthdaystring,birthyearstring,name);
    } while (fdecision() != 2);
}

/* IMPORTANT NOTES
1- When you ask an integer from user in a 'do while' loop, the user might enter(std::cin >> number) a letter then your loop stucks in unending loop.
-> ask the solution (found)
solution: write in an order these after input entered => 
std::cin.clean()
fflush(stdin);
*/