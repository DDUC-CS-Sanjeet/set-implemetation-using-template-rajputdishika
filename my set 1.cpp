#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename R>
class MySet
{
    private:
        R *elements;
        int CARDI;
    public:
        // Constructor to initialise the instance variables
        MySet(int size = 0)
        {
            CARDI = size;
            elements = new R[size];
        }
        // Function to take input of elements and removing duplicates in the set
        void takeElements()
        {
            for(int I= 0; I< CARDI; ++I)
                cin >> elements[I];
            REMOVE_DUPLICATE();
        }
        // Function to display the set in the readable format
        void display()
        {
            cout << "{ ";
            for(int I= 0; I< CARDI; ++I)
            {
                cout << elements[I];
                if(I != CARDI - 1)
                    cout << ", ";
                else
                    cout << " ";
            } 
            cout << "}" << endl;
        }
        
        // Overloading + operator to find the union of two sets
        MySet operator+ (const MySet obj)
        {
            MySet TEMP(CARDI + obj.CARDI);
            int I= 0;
            for(int copy = 0; copy < CARDI; ++copy)
               TEMP.elements[I++] = elements[copy];
            for(int copy = 0; copy < obj.CARDI; ++copy)
               TEMP.elements[I++] = obj.elements[copy];
           TEMP.REMOVE_DUPLICATE();
            return TEMP;
        }
        // Overloading * operator to find the intersection of two sets
        MySet operator* (const MySet obj)
        {
            int count = 0;
            for(int I= 0; I< CARDI; ++I)
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                        count++;
            MySet TEMP(count);
            count = 0;
            for(int I= 0; I< CARDI; ++I)
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                       TEMP.elements[count++] = elements[I];
            return TEMP;
        }

        // Overloading = operator to assign the values of one set into another
        MySet operator= (const MySet obj)
        {
            MySet TEMP(obj.CARDI);
            for(int I= 0; I< CARDI; ++I)
               TEMP.elements[I] = obj.elements[I];
            return TEMP;
        }

        // Overloading - operator to find the difference between two sets
        MySet operator- (const MySet obj)
        {
            int count = 0;
            for(int I= 0; I< CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet TEMP(count);
            int TEMP_I = 0;
            for(int I= 0; I< CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                   TEMP.elements[I++] = elements[I];
            }
            return TEMP;
        }
       MySet operator^ (const MySet obj)
        {
            int count = 0;
            for(int I= 0; I< CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            for(int I= 0; I< obj.CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < CARDI; ++check)
                    if(obj.elements[I] == elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet TEMP(count);
            count = 0;
            for(int I= 0; I< CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < obj.CARDI; ++check)
                    if(elements[I] == obj.elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                   TEMP.elements[count++] = elements[I];
            }
            for(int I= 0; I< obj.CARDI; ++I)
            {
                int flag = 0;
                for(int check = 0; check < CARDI; ++check)
                    if(obj.elements[I] == elements[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                   TEMP.elements[count++] = obj.elements[I];
            }
            return TEMP;
        }
        // Function to remove duplicates in the set
        void REMOVE_DUPLICATE()
        {
            for(int I= 0; I< CARDI; ++I)
                for(int check = I+ 1; check < CARDI; ++check)
                    if(elements[I] == elements[check])
                    {
                        for(int del = check; del < CARDI; ++del)
                            elements[del] = elements[del+1];
                        CARDI--;
                        check--;
                    }
        }
        
        // Overloading == operator to check if two sets are equal or not
        bool operator== (const MySet obj)
        {
            if(CARDI != obj.CARDI)
                return false;
            else
            {
                int flag = 0;
                for(int I= 0; I< CARDI; ++I)
                    for(int check = 0; check < obj.CARDI; ++check)
                        if(elements[I] == obj.elements[check])
                            flag++;
                if(flag == CARDI)
                    return true;
                else
                    return false;
            }
        }
        // Function to print the CARDI of a set
        void printCARDI()
        {
            cout << CARDI;
        }
        // Function to print the power set of a given set
        void powerSet()
        {
            int powerset_size = pow(2, CARDI);
            for(int counter = 0; counter < powerset_size; ++counter)
            {
                int count_elements = 0;
                cout << "{ ";
                for(int set = 0; set < CARDI; ++set)
                    if(counter & (1 << set))
                    {
                        if(count_elements != 0)
                            cout << ", ";
                        cout << elements[set];
                        count_elements++;
                    }
                cout << " }";
                if(counter != powerset_size - 1)
                    cout << ", ";
            }
        }
};
 // Overloading ^ operator to find the symmetric difference between two sets
        
//Function to print all the sets
template <typename T>
void printSets(MySet <T> firstSet, MySet <T> secondSet, MySet <T> thirdSet, MySet <T> fourthSet, MySet <T> fifthSet, MySet <T> sixthSet, bool answer)
{
    system("cls");
    cout << "Set A: ";
    firstSet.display();
    cout << "\nSet B: ";
    secondSet.display();
    cout << "\nUnion: ";
    thirdSet.display();
    cout << "\nIntersection: ";
    fourthSet.display();
    cout << "\nDifference: ";
    fifthSet.display();
    cout << "\nSymmetric Difference: ";
    sixthSet.display();
    cout << "\nPower Set of A... \n{ ";
    firstSet.powerSet();
    cout << " }\n";
    cout << "\nPower Set of B... \n{ ";
    secondSet.powerSet();
    cout << " }\n";
    if(answer == true)
        cout << "\nEquality: The Sets A and B are equal\n\n";
    else
        cout << "\nEquality: The Sets A and B are not equal\n\n";
}

int main()
{
    int choice_type = 0;
    char choice_iterate = 'N';
    do
    {
        system("cls");
        cout << "*****Menu*****\n";
        cout << "Choose the type of data in the set...\n";
        cout << "1. Integer\n";
        cout << "2. String\n";
        cout << "3. Floating-points\n";
        cout << "Enter your choice: ";
        cin >> choice_type;
        system("cls");
        switch(choice_type)
        {
            case 1: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <int> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <int> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <int> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <int> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <int> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <int> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 2: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <char> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <char> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <char> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <char> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <char> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <char> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 3: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <float> firstSet(size_of_1Set);
                        cout << "Enter the elements of 1st Set...\n";
                        firstSet.takeElements();
                        MySet <float> secondSet(size_of_2Set);
                        cout << "Enter the elements of 2nd Set...\n";
                        secondSet.takeElements();
                        MySet <float> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <float> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <float> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <float> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            default: cout << "Wrong choice of Options!!!";
        }
        cout << "Do you want to operate more (Y/N): ";
        cin >> choice_iterate;
        system("cls");
    } while (choice_iterate == 'Y' || choice_iterate == 'y');
    return 0;
}


