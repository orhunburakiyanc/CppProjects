#include <iostream> 
void uppertriangle(int row ,char symbol)
{
    for(int count= 1; count<=row; count++){
       int countblank= row-count;
       for(int blank=0;blank < countblank;blank++){
            std::cout << " ";
       }
       for(int countsymbol =1; countsymbol<=(2*count) - 1; countsymbol++){
            std::cout << symbol;
       }
       std::cout <<"\n";
    }
}

void bottomtriangle(int row , char symbol)
{
    int count = row;
    for(count; count>0; count--){
       int countblank= row - count;
       for(int blank = 0; blank < countblank ; blank++){
            std::cout << " ";
       }
        for(int countsymbol =1; countsymbol<=(2*count) - 1; countsymbol++){
            std::cout << symbol;
       }
       std::cout << "\n";
       
        
    }
}

int main(){
    char symbol;
    int row;
    std::string decision;
     
    do{
        std::cout << "Which symbol u want to use: "; 
        std::cin >> symbol;
        if (isdigit(symbol) == false && isalpha(symbol)==false) // the user must write letters from English keyboard otherwise program won't work properly. 
        {
            std::cout << "How many rows would u like to make: ";
            std::cin >> row;
        
            uppertriangle(row,symbol);
            bottomtriangle(row,symbol);
            std::cout << "Would you want to proceed again ?\nWrite 'yes' or 'no': ";
            std::cin >> decision;
            
        }
        else{
            std::cout << "You've entered mistaken word\nProgram has shut down ! ";
            break;
        }

        
        
    }while(decision=="yes");
}


