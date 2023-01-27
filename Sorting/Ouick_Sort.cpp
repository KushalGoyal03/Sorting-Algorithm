#include <iostream>
#include <climits>
#include <ctime>
using namespace std;
int count = 0;

int Partition (int Arr [] , int p , int r)
{
    int x = Arr [r];
    int i = p - 1;
    
    for (int j = p ; j < r ; j++)
    {
        if (Arr [j] <= x)
        {
        	i++;
        	count++;
        	swap (Arr [i] , Arr [j]);
		}
		else
			count++;
	}
	count++;
    swap (Arr [i + 1] , Arr [r]);
    return i + 1;
}

void Quick_Sort (int Arr [] , int p , int r)
{
    if (p < r)
    {
        count++;
        int q = Partition (Arr , p , r);
        Quick_Sort (Arr , p , q - 1);
        Quick_Sort (Arr , q + 1 , r);
    }
    else
        count++;
}

int main ()
{
    //This is for random input.
    srand(time(0));
    int n = rand () % 10 + 5;
    int Arr [n];
    for (int i = 0 ; i < n ; i++)
        Arr [i] = rand () % 100 + 1;
    
    //This is for user input.
    /*int n;
    cout << "Enter the no. of elements you want to insert in your array : ";
    cin >> n;
    int Arr [n];
    
    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter the " << i + 1 << "th element : ";
        cin >> Arr [i];
    }*/
    
    cout << "Array :- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    Quick_Sort (Arr , 0 , n - 1);
    
    cout << "\nSorted Array:- ";
    for (int i = 0 ; i < n ; i++)
        cout << Arr [i] << " ";
    
    cout << "\nTotal no. of comparison : " << count;
    
    return 0;
}
