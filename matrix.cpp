#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > multiply(vector<vector<int> > &vector1, vector<vector<int> > &vector2)
{
    vector<vector<int> > matrix(vector1.size(),vector<int>(vector1.size()));
    for(int i = 0; i < vector1.size(); i++)
    {
        for(int j = 0; j < vector2[0].size(); j++)
        {
            for(int p = 0; p < vector2.size(); p++)
            {
                matrix[i][j] += vector1[i][p]*vector2[p][j];
            }
        }
    }
    return matrix;
}

void vectorPrint(const vector<vector<int> > &vector)
{
    for (int row=0; row<vector.size();row++)
    {
        for (int column=0; column < vector[0].size(); column++)
        {
            cout << vector[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void addition(const int &firstVectorD1,const int &firstVectorD2 , const int &secondVectorD1 ,const int &secondVectorD2)
{ 
    if (firstVectorD1 == secondVectorD1 && secondVectorD2 == firstVectorD2)
    {
        vector<vector<int> > V1(firstVectorD1,vector<int>(firstVectorD2));
        vector<vector<int> > V2(secondVectorD1,vector<int>(secondVectorD2));


        cout << "The two matrices have the same dimensions. Addition can be performed." << "\n\n";


        cout << "Please enter the numbers for the first matrix." << endl;
        for (int row=0; row < firstVectorD1; row++)
        {
            cout << "Enter the numbers for row #" << row+1 << ": ";
            for (int column=0; column < firstVectorD2; column++)
            {
                (cin >> V1[row][column]);
            }
        }
        cout << "The first matrix is: "<< endl;
        vectorPrint(V1);


        vector<vector<int> > portVector(firstVectorD1,vector<int>(firstVectorD2));
        cout << "Please enter the numbers for the second matrix." << endl;
        for (int row=0; row < secondVectorD1;row++)
        {
            cout << "Enter the numbers for row #" << row+1 << ": ";
            for (int column=0; column < secondVectorD2; column++)
            {
                (cin >> V2[row][column]);
                portVector[row][column] = V1[row][column]+ V2[row][column]; 
            }
        }
        cout << "The second matrix is: "<< endl;
        vectorPrint(V2);

        cout << "Result of the Sum Operation: " << endl;
        vectorPrint(portVector);
    }
    else
    {
        cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
    }
}

void multiplication(const int &firstVectorD1,const int &firstVectorD2 , const int &secondVectorD1 ,const int &secondVectorD2)
{
    if(firstVectorD2 == secondVectorD1)
    {
        vector<vector<int> > V1(firstVectorD1,vector<int>(firstVectorD2));
        vector<vector<int> > V2(secondVectorD1,vector<int>(secondVectorD2));

        cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed." << endl;
        cout << "Please enter the numbers for the first matrix." << endl;
        for (int row = 0; row < firstVectorD1; row++)
        {
            cout << "Enter the numbers for row #" << row+1 << ": ";
            for (int column = 0; column < firstVectorD2; column++)
            {
                (cin >> V1[row][column]);
            }
        }
        cout << "The first matrix is: "<< endl;
        vectorPrint(V1);

        
        cout << "Please enter the numbers for the second matrix." << endl;
        for (int row = 0; row < secondVectorD1; row++)
        {
            cout << "Enter the numbers for row #" << row+1 << ": ";
            for (int column = 0; column < secondVectorD2; column++)
            {
                (cin >> V2[row][column]);
            }
        }
        cout << "The second matrix is: "<< endl;
        vectorPrint(V2);

        vector<vector<int> >portVector(firstVectorD1,vector<int>(secondVectorD2));
        cout << "Result of the Multiplication Operation: " << endl;
        for(int i = 0; i < firstVectorD1; i++)
        {
            for(int j = 0; j < secondVectorD2; j++)
            {
                for(int p = 0; p < firstVectorD2; p++)
                {
                    portVector[i][j] += V1[i][p] * V2[p][j];
                }
            }
        }
        vectorPrint(portVector);
    }
    else
    {
        cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix."<< endl <<"Multiplication cannot be performed." << endl;
    }
}

void power(const int &firstVectorD1,const int &firstVectorD2)
{ 
    if(firstVectorD1 == firstVectorD2)
    {
        int power;
        vector<vector<int> > V1(firstVectorD1,vector<int>(firstVectorD2));

        cout << "The matrix has the same number of rows as columns. Power can be performed." << "\n\n";
        cout << "Please enter the numbers for the matrix." << endl;
        for (int row = 0; row < V1.size(); row++)
        {
            cout << "Enter the numbers for row #" << row+1 << ": ";
            for (int column = 0; column < V1[0].size(); column++)
            {
                (cin >> V1[row][column]);
            }
        }
        cout << "The matrix is: "<< endl;
        vectorPrint(V1);
        cout << "Please enter the power: ";
        cin >> power;
        
        
        
        int count=1;
        vector<vector<int> > resultVector = V1;
        while(count != power)
        {
            resultVector = multiply(resultVector,V1);
            count++;
        }
        cout << "Result of the Power Operation:" << endl;
        vectorPrint(resultVector);
    }
    else
    {
        cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << "\n\n";
    }
}

void transpose(const int &firstVectorD1,const int &firstVectorD2)
{
    vector<vector<int> > V1(firstVectorD1,vector<int>(firstVectorD2));
    cout << "Please enter the numbers for the matrix." << endl;
    for (int row=0; row<V1.size();row++)
    {
        cout << "Enter the numbers for row #" << row+1 << ": ";
        for (int column=0; column < V1[0].size(); column++)
        {
            (cin >> V1[row][column]);
        }
    }
    cout << "The matrix is: "<< endl;
    vectorPrint(V1);

    // you rewrote the column and rows. 
    cout << "Result of the Transpose Operation:" << endl;
    for (int column=0; column<firstVectorD2;column++)
    {
        for (int row=0; row < firstVectorD1; row++)
        {
            cout << V1[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int choice;
    int firstVectorD1, firstVectorD2, secondVectorD1, secondVectorD2; //D1 = dimension 1 (rows) D2 = dimension 2 (Column)
    do{
    cout << "Pick a choice from the list:\n1- Addition Operation\n2- Multiplication Operation\n3- Power Operation\n4- Transpose Operation\n5- Exit\nChoice: ";
    cin>>choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        cout << "Please enter the dimensions of the first matrix: ";
        (cin >> firstVectorD1) >> firstVectorD2;
        cout << "Please enter the dimensions of the second matrix: ";
        (cin >> secondVectorD1) >> secondVectorD2;
        addition(firstVectorD1,firstVectorD2,secondVectorD1,secondVectorD2);
        break;
    case 2:
        cout << "Please enter the dimensions of the first matrix: ";
        (cin >> firstVectorD1) >> firstVectorD2;
        cout << "Please enter the dimensions of the second matrix: ";
        (cin >> secondVectorD1) >> secondVectorD2;
        multiplication(firstVectorD1,firstVectorD2,secondVectorD1,secondVectorD2);
        break;
    case 3:
        cout << "Please enter the dimensions of the matrix: ";
        (cin >> firstVectorD1) >> firstVectorD2;
        power(firstVectorD1,firstVectorD2);
        break;
    case 4:
        cout << "Please enter the dimensions of the matrix: ";
        (cin >> firstVectorD1) >> firstVectorD2;
        transpose(firstVectorD1,firstVectorD2);
        break;
    }
    }while(choice != 5);
    return 0;
}