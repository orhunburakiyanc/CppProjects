#include <iostream>
/*
    NOTES 
1) When you pass an array to a function, its address is passed to the function as a pointer.

*/



void final (double total, double vat, double serviceFee,int studentdecision)
{
  if (studentdecision == 1)
    {
        std::cout << "Student discount: " << "-" << ((total + vat)*0.25) << " TL\n";
        total = (total + vat) - ((total + vat)*0.25);
        if (total < 175)
        {
            serviceFee = total * 0.1;
        }
        else if (total > 175 && total < 375)
        {
            serviceFee = total * 0.08;
        }
        else if (total >=375)
        {
            serviceFee = total * 0.06;
        }

        total += serviceFee;
        std::cout << "Service fee: " << serviceFee << " TL\n";
        std::cout << "Total price: " << total << " TL";
    }
    else if (studentdecision == 0)
    {
        total += vat;
        if (total < 175)
        {
            serviceFee = total * 0.1;
        }
        else if (total >= 175 && total < 375)
        {
            serviceFee = total * 0.08;
        }
        else if (total >=375)
        {
            serviceFee = total * 0.06;
        }

        total += serviceFee;
        std::cout << "Service fee: " << serviceFee << " TL\n";
        std::cout << "Total price: " << total << " TL";
    }
}


int main()
{
    char products[4][11] = {"Water","Soda","Fries","Hamburgers"};
    int count [4];
    int studentdecision,decision;

    std::cout <<"Enter the quantity of each product you have ordered:\nWater: ";
    std::cin >> count[0];

    std::cout << "Soda: ";
    std::cin >> count[1];

    std::cout << "Fries: ";
    std::cin >> count[2];
   
    std::cout << "Hamburger: ";
    std::cin >> count[3];

    int loopchecker=0;
    int size = sizeof(count) / sizeof(*count);
    for (int checker = 0; checker < size ;checker++)
    {   
        if (count[checker] == 0)
        {
            loopchecker++;
        }
    }
    if (loopchecker == 4)
    {
        std::cout << "Are you a student? (1 for yes, 0 for no): ";
        std::cin >> studentdecision;
        if (studentdecision == 1 && loopchecker !=4)
        {
            std::cout << "Student discount applied!";
        }
        std::cout << "\n===================================\n         Restaurant Invoice\n===================================\n";
        std::cout << "The customer has not made a purchase or placed an order!";

    }
    else 
    {
        double serviceFee,vat;
        double total = 0;
        double price[4] = {10,30,59.5,100};
        double vat_price[4] = {0,15,5.95};

        if (count[3] != 0)
        {
            std::cout << "Add cheese to your hamburger(s)? (1 for yes, 0 for no): ";
            std::cin >> decision;
        }
        else
        {
            decision = 0;
        }
        std::cout << "Are you a student? (1 for yes, 0 for no): ";
        std::cin >> studentdecision;
        if (studentdecision == 1)
        {
            std::cout << "Student discount applied!";
        }

        std::cout << "\n===================================\n         Restaurant Invoice\n===================================\n";

        for(int loop=0;loop < size-1 ;loop++)
        {
            if(count[loop] != 0)
            {
                std::cout << products[loop] << " (" << count[loop] << "): " << count[loop]*price[loop] << " TL\n";
                total += (count[loop]*price[loop]);
                vat += (count[loop]*vat_price[loop]);
            }
        }
        if (decision == 1)
        {
            total += (count[3]*(100+11));
            vat += (count[3]*11.1);

            std::cout << "Hamburgers (" << count[3] << "): " << count[3]*(100+11) << " TL\n";
            std::cout << "Subtotal: " << total << " TL\n\n";
            std::cout << "VAT: " << vat << " TL\n";
        }
        else if (decision == 0 && count[3] != 0)
        {
            total += (count[3]*100);
            vat += (count[3]*10);

            std::cout << "Hamburgers (" << count[3] << "): " << count[3]*100 << " TL\n";
            std::cout << "Subtotal: " << total << " TL\n\n";
            std::cout << "VAT: " << vat << " TL\n";
        }
        else
        {
            total =  (count[0]*10)+(count[1]*30)+(count[2]*59.5);
            vat = (count[1]*15)+(count[2]*5.95);

            std::cout << "Subtotal: " << total << " TL\n\n";
            std::cout << "VAT: " << vat << " TL\n";
        }
        final(total,vat,serviceFee,studentdecision);
    }
}