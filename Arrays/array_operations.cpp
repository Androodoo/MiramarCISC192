//Name: Andrew Phan
//Course: CISC 192 - C++ Programming
//Date: 11/02/2025
//Assignment: Non-Duplicated Integer Array Operations

//Note: I also added an option to do all functions at once, which is kinda nice i guess lol
//I also made bubble sort in Java so I felt pretty confident with this.

#include <iostream>
#include <array>

//I added this here to include the function in the scope
void unsorted(std::array<int, 5> numbers);
void sortAscending(std::array<int, 5> numbers);
void sortDescending(std::array<int, 5> numbers);
void maximum(std::array<int, 5> numbers);

//--------------------------------------------------------------------
int main(){
    //Array named "numbers", 5 unique numbers
    std::array<int, 5> numbers;


    //CREATING THE ARRAY [0,1,2,3,4]
    int i;
    for(i = 0; i < 5; i++){
        bool repeatedNumber;
        int integerInput;

        //while repeated number is true, we keep asking for number. if its not integer, end program.
        do{

            repeatedNumber = false;
            std::cout << "Enter a unique integer" << std::endl;

            if(!(std::cin >> integerInput)){
                std::cerr << "You must enter an INTEGER.";
                return 1; //1 for error
            }

            for(int f = 0; f < i; f++){
                if(numbers[f] == integerInput){
                    std::cout << "No repeated numbers, enter another one\n";
                    repeatedNumber = true;
                    break;
                }
            }
        } while (repeatedNumber);
        numbers[i] = integerInput;
    }
    
    //MENU SELECTION FOR WHAT FUNCTION U WANNA USE
    enum class menu { unsort = 1, sort = 2, desort = 3, max = 4, all = 5};
    std::cout << "\nDo you want your array unsorted(1), sorted(2), sortedbackwards(3), maximum(4), all(5)\n";

    int selection{}; //user input for the menu
    std::cin >> selection;

    //the switch cases for choosing the function
    switch(static_cast<menu>(selection)){
        case menu::unsort:
            unsorted(numbers);
            break;

        case menu::sort:
            sortAscending(numbers);
            break;

        case menu::desort:
            sortDescending(numbers);
            break;

        case menu::max:
            maximum(numbers);
            break;

        case menu::all:
            unsorted(numbers);
            sortAscending(numbers);
            sortDescending(numbers);
            maximum(numbers);
            break;
        
        default: //if u didnt choose 1-5, end
            std::cout << "Choose from 1-5 please";
            break;
    }
}




    //--------------------------------------------------------------------
    //PRINT OUT UNSORTED
    void unsorted(std::array<int, 5> numbers){
        std::cout << "\nUnsorted Array:\n";
        for(int h = 0; h < 5; h++){
            std::cout << numbers[h] << " ";
        }
        std::cout << "\n";
    }




    //--------------------------------------------------------------------
    //SORT ASCENDING
    void sortAscending(std::array<int, 5> numbers){
        bool sorted = false;
        
        std::cout << "\nSorted Array:\n";
        while(!sorted){
            sorted = true; //keep sorting it until its sorted
            for(int i = 0; i < 4; i++){
                if(numbers[i] > numbers[i+1]){
                    //place holder, so we can swap them, or else both would be the same
                    int temp = numbers[i];
                    numbers[i] = numbers[i+1];
                    numbers[i+1] = temp;
                    sorted = false;
                }
            }
        }
        //PRINT sorted array
        for(int k = 0; k < 5; k++){
            std::cout << numbers[k] << " ";
        }
        std::cout << "\n";
    }




    //--------------------------------------------------------------------
    //SORT DESCENDING, this is literally the exact same as sort ascending but backwards lol
    void sortDescending(std::array<int, 5> numbers){
        bool sorted = false;

        std::cout << "\nBackwards Sorted Array:\n";
        while(!sorted){
            sorted = true; //keep sorting it until its sorted
            for(int i = 4; i > 0; i--){
                if(numbers[i] > numbers[i-1]){
                    //place holder, so we can swap them, or else both would be the same
                    int temp = numbers[i];
                    numbers[i] = numbers[i-1];
                    numbers[i-1] = temp;
                    sorted = false;
                }
            }
        }
        //PRINT sorted array
        for(int j = 0; j < 5; j++){
            std::cout << numbers[j] << " ";
        }
        std::cout << "\n";
    }



    //--------------------------------------------------------------------
    //FIND MAXIMUM
    void maximum(std::array<int, 5> numbers){
        std::cout << "\nMaximum Value of Array:\n";
        int max = numbers[0];
        for(int i = 1; i < 5; i++){
            if(numbers[i] > max){
                max = numbers[i]; //basically keep initial term max, if next one is bigger, replace
            }
        }
        std::cout << max << "\n";
    }
