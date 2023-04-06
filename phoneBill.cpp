#include <iostream>
using namespace std;

void displayResults(const double &totalCost, string type, const int &basePackageTL)
{
    if (type == "turkey")
    {
        if(totalCost == basePackageTL)
        {
            cout << "Total cost of your phone usage in Turkey is " << totalCost << " TL. You did not exceed your package." << endl; 
        }
        else if(totalCost >= basePackageTL*2)
        {
            cout << "Total cost of your phone usage in Turkey is " << totalCost << " TL. You exceeded your package too much. We suggest you to change your package." << endl; 
        }
        else if (totalCost > basePackageTL && totalCost < basePackageTL*2)
        {
            cout << "Total cost of your phone usage in Turkey is " << totalCost << " TL. You exceeded your package." << endl; 
        }
    }
    if (type == "international")
    {
        if(totalCost == basePackageTL)
        {
            cout << "Total cost of your phone usage Internationally is " << totalCost << " TL. You did not exceed your package." << endl; 
        }
        else if(totalCost >= basePackageTL*2)
        {
            cout << "Total cost of your phone usage Internationally is " << totalCost << " TL. You exceeded your package too much. We suggest you to change your package." << endl; 
        }
        else if (totalCost > basePackageTL && totalCost < basePackageTL*2)
        {
            cout << "Total cost of your phone usage Internationally is " << totalCost << " TL. You exceeded your package." << endl; 
        }
    }
}
double costCalculate(int &nMinutes,int &nSms, int &nMb, int &nCallpackages, int &nSmspackages, int &nInternetpackages, int &basePackageTL, int &P_minutes, int &P_sms, int &P_mb, int price_additionalpackage, int additionalpackage_minute,int additionalpackage_sms, int additionalpackage_mb, int STR_call,int STR_mb, int STR_sms)
{
    double totalCost = 0;
        
    int mb_to_kb = nMb*1024;
    if(P_minutes == 250)
    {
        
        if (nCallpackages !=0)
        {
            totalCost+= nCallpackages * price_additionalpackage;
            P_minutes+= nCallpackages * additionalpackage_minute;
        }
        if (nSmspackages !=0)
        {
            totalCost+= nSmspackages * price_additionalpackage;
            P_sms+= nSmspackages * additionalpackage_sms;
        }
        if (nInternetpackages !=0)
        {
            totalCost+= nInternetpackages * price_additionalpackage;
            P_mb+= nInternetpackages * additionalpackage_mb;
        }
        if (nMinutes > P_minutes)
        {
            int STR_callCost = (nMinutes - P_minutes) * STR_call;
            totalCost+= STR_callCost ;
        }
        if (nSms > P_sms)
        {
            int STR_smsCost = (nSms - P_sms) * STR_sms;
            totalCost+= STR_smsCost;
        }
        if(nMb > P_mb)
        {
            int STR_mbCost = ((mb_to_kb - (P_mb*1024))/100) * STR_mb;
            totalCost+=STR_mbCost;
        }
        totalCost+=basePackageTL;
        if (totalCost <= basePackageTL)
        {
            return basePackageTL;
        }
        else
        {
            return totalCost;
        }
    }
    else
    {
        
        if (nCallpackages !=0)
        {
            totalCost+= nCallpackages*100;  
            P_minutes+= nCallpackages*50; 
        }
        if (nSmspackages !=0)
        {
            totalCost+= nSmspackages*100;
            P_sms+= nSmspackages*100;
        }
        if (nInternetpackages !=0)
        {
            totalCost+= nInternetpackages*100;
            P_mb+= nInternetpackages*1024;
        }
        if (nMinutes > P_minutes)
        {
            int STR_callCost = (nMinutes - P_minutes)*15;
            totalCost+= STR_callCost;
        }
        if (nSms > P_sms)
        {
            int STR_smsCost = (nSms - P_sms)*3;
            totalCost+= STR_smsCost;
        }
        if(nMb > P_mb)
        {
            int STR_mbCost = ((mb_to_kb - (P_mb*1024))/100)*5;
            totalCost+=STR_mbCost;
        }
        totalCost+=basePackageTL;
        if (totalCost <= basePackageTL)
        {
            return basePackageTL;
        }
        else
        {
            return totalCost;
        }
    }   
}
bool inputCheck(string type_service,int &service)
{
    if ( (type_service == "call") && (service < 0) )
    {
        cout << "Number of minutes cannot be smaller than 0." << endl;
        return false;
    }
    if ( (type_service == "sms") && (service < 0) )
    {
        cout << "Number of SMSs cannot be smaller than 0." << endl;
        return false;
    }
    if ( (type_service == "mb") && (service < 0) )
    {
        cout << "Number of MBs cannot be smaller than 0." << endl;
        return false;
    }
    if ( (type_service == "callpackage") && (service < 0) )
    {
        cout << "Number of additional minutes packages cannot be smaller than 0.";
        return false;
    }
    if ( (type_service == "smspackage") && (service < 0) )
    {
        cout << "Number of additional SMS packages cannot be smaller than 0.";
        return false;
    }
    if ( (type_service == "internetpackage") && (service <0) )
    {
        cout << "Number of additional internet packages cannot be smaller than 0.";
        return false;
    }
    return true;
}
bool getInputs(string type, int &nMinutes, int &nSms, int &nMb, int &nCallpackages, int &nSmspackages, int &nInternetpackages)
{
    string type_service;
    if (type == "turkey")
    {
        cout << "Please enter how many minutes you used this month in Turkey: ";
        cin >> nMinutes;
        type_service = "call";
        if (inputCheck(type_service,nMinutes) == false)
        {   
            return false;
        }

        cout << "Please enter how many SMSs you sent this month in Turkey: ";
        cin >> nSms;
        type_service = "sms";
        if (inputCheck(type_service,nSms) == false)
        {
            return false;
        }

        cout << "Please enter how many MBs you used this month in Turkey: ";
        cin >> nMb;
        type_service = "mb";
        if (inputCheck(type_service,nMb) == false)
        {
            return false;
        }

        cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
        cin >> nCallpackages >> nSmspackages >> nInternetpackages;
        type_service = "callpackage";
        if (inputCheck(type_service,nCallpackages) == false)
        {
            return false;
        }
        type_service = "smspackage";
        if (inputCheck(type_service,nSmspackages) == false)
        {
            return false;
        }
        type_service = "internetpackage";
        if (inputCheck(type_service,nInternetpackages) == false)
        {
            return false;
        }
        return true;
    }
    else 
    {
        cout << "Please enter how many minutes you used this month Internationally: ";
        cin >> nMinutes;
        type_service = "call";
        if (inputCheck(type_service,nMinutes) == false)
        {   
            return false;
        }

        cout << "Please enter how many SMSs you sent this month Internationally: ";
        cin >> nSms;
        type_service = "sms";
        if (inputCheck(type_service,nSms) == false)
        {
            return false;
        }

        cout << "Please enter how many MBs you used this month Internationally: ";
        cin >> nMb;
        type_service = "mb";
        if (inputCheck(type_service,nMb) == false)
        {
            return false;
        }

        cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
        cin >> nCallpackages >> nSmspackages >> nInternetpackages;
        type_service = "callpackage";
        if (inputCheck(type_service,nCallpackages) == false)
        {
            return false;
        }
        type_service = "smspackage";
        if (inputCheck(type_service,nSmspackages) == false)
        {
            return false;
        }
        type_service = "internetpackage";
        if (inputCheck(type_service,nInternetpackages) == false)
        {
            return false;
        }
        return true;
    }
}   
int main()
{
    int nMinutes = 1,nSms = 1,nMb = 1,nCallpackages = 1,nSmspackages = 1,nInternetpackages = 1 ;
    
    string type = "turkey";
    int STR_mb = 2;
    int STR_sms = 1;
    int STR_call= 2;
    int basePackageTL = 120;
    int P_minutes = 250;
    int P_sms = 1000;
    int P_mb = 5*1024;
    int price_additionalpackage = 30;
    int additionalpackage_minute = 250;
    int additionalpackage_sms = 250;
    int additionalpackage_mb = 1*1024;

    if(getInputs(type,nMinutes,nSms,nMb,nCallpackages,nSmspackages,nInternetpackages) == true)
    {
        displayResults(costCalculate(nMinutes,nSms,nMb,nCallpackages,nSmspackages,nInternetpackages,basePackageTL,P_minutes,P_sms,P_mb,price_additionalpackage,additionalpackage_minute,additionalpackage_sms,additionalpackage_mb,STR_call,STR_mb,STR_sms),type,basePackageTL);
        type ="international";
        if (getInputs(type,nMinutes,nSms,nMb,nCallpackages,nSmspackages,nInternetpackages) == true)
        {
            //Internationally
            basePackageTL = 300;
            P_minutes = 100;
            P_sms = 2000;
            P_mb = 2*1024;
            price_additionalpackage = 100;
            additionalpackage_minute = 50;
            additionalpackage_sms = 100;
            additionalpackage_mb = 1*1024;
            STR_mb = 5;
            STR_sms = 3;
            STR_call= 15;
            displayResults(costCalculate(nMinutes,nSms,nMb,nCallpackages,nSmspackages,nInternetpackages,basePackageTL,P_minutes,P_sms,P_mb,price_additionalpackage,additionalpackage_minute,additionalpackage_sms,additionalpackage_mb,STR_call,STR_mb,STR_sms),type,basePackageTL);
        }
    }    
}