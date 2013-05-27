#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>


void print(const std::vector<int>& input)
{
    for(unsigned int i = 0; i < input.size();++i)
    {
        std::cout << input[i];
    }
    std::cout << "\n";
}


void initialize_numbers(std::vector<int>& numbers)
{
    srand(time(NULL));
    for(unsigned int i = 0; i < numbers.size(); ++i)
    {
        numbers[i] = rand()%10;
    }
}


void split_input(std::vector<int>& input,int number,int number_size)
{
    if(number > 9999 || < )
    for(int i = 0; i < number_size; ++i)
    {
        input[i] = number%10;
        number = number/10;
    }
    std::reverse(input.begin(),input.end());
}

int occurences(std::vector<int> input,int number)
{
    int counter = 0;
    for(unsigned int i = 0; i < input.size();++i)
    {
        if(input[i] == number)
        {
            ++counter;
        }
    }

    return counter;
}

std::vector<int> unique_numbers(std::vector<int> input)
{
    std::vector<int> output;

    sort(input.begin(),input.end());

    for(unsigned int i = 0; i < input.size();++i)
    {
        if(i == 0 || input[i-1] != input[i])
        {
            output.push_back(input[i]);
        }
    }

    return output;
}
int calculate_cows(std::vector<int>& secret_cow_number,std::vector<int>& user_cow_number)
{
    int cows = 0;
    std::vector<int> unique_user_cow_numbers = unique_numbers(user_cow_number);

  for(unsigned int i = 0; i < unique_user_cow_numbers.size();++i)
    {
        int oc_user_cow_number = occurences(user_cow_number,unique_user_cow_numbers[i]);
        int oc_secret_cow_number = occurences(secret_cow_number,unique_user_cow_numbers[i]);

        //std::cout << "occurence user cow number: " << unique_user_cow_numbers[i] << " " << oc_user_cow_number << "\n";
       //std::cout << "occurence secret cow number: " << unique_user_cow_numbers[i] << " " << oc_secret_cow_number << "\n";

        if(oc_user_cow_number > 0 && oc_secret_cow_number > 0)
        {
            if(oc_user_cow_number > oc_secret_cow_number)
            {
                cows+= oc_secret_cow_number;
            }
            else if(oc_user_cow_number < oc_secret_cow_number)
            {
                cows+= oc_user_cow_number;
            }
            else if (oc_user_cow_number == oc_secret_cow_number)
            {
                cows+= oc_user_cow_number;
            }
        }
    }
    return cows;
}
int calculate_bulls(std::vector<int>& secret_cow_number,std::vector<int>& user_cow_number,const std::vector<int>& user_guess, const std::vector<int>& secret_number)
{
    int bulls = 0;
    for(unsigned int i = 0; i < user_guess.size();++i)
    {
        if(secret_number[i] == user_guess[i])
        {
            ++bulls;
            /*std::cout << "matching" << "\n";
            std::cout << "user guess " << user_guess[i] << "\n";
            std::cout << "secret number " << secret_number[i] << "\n";*/


        }
        else if(secret_number[i] != user_guess[i])
        {
            //std::cout << "not matching" << "\n";
            secret_cow_number.push_back(secret_number[i]);
            user_cow_number.push_back(user_guess[i]);

        }
    }
    //print(secret_cow_number);
    //print(user_cow_number);

    return bulls;

}

int main()
{
    const int max_input = 4;
    int input = 0;
    int bulls = 0;
    int cows = 0;
    int guesses = 0;
    std::vector<int> user_guess(max_input);
    std::vector<int> secret_number(max_input);

    initialize_numbers(secret_number);


    std::vector<int> secret_cow_number;
    std::vector<int> user_cow_number;

    std::cout << "This is a number guessing game called bulls and cows, the number of bulls"
    << " repersent how many numbers you got correct and in the correct position" << "\n";

    std::cout << "The number of of cows repersent how many numbers you got correct but not in the right position " << "\n";
    std::cout << "If a number is a bull then it will not get counted as a cow " << "\n";
    std::cout << "\n";

    std::cout << "I have thought of a number, now you try and guess it" << "\n";
    std::cout << "\n";

    while(bulls < max_input)
    {
        user_cow_number.clear();
        secret_cow_number.clear();
        std::cout << "Enter your guess" << "\n";
        std::cin >> input;

        if(std::cin.fail())
        {
            std::cout << "Invalid input , now exiting," << std::endl;
            std::cin.clear();
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        split_input(user_guess,input,max_input);

        bulls = calculate_bulls(secret_cow_number,user_cow_number,user_guess,secret_number);

        cows = calculate_cows(secret_cow_number,user_cow_number);
        ++guesses;
        std::cout << bulls << " Bull(s) "  << cows << " Cow(s) " << "\n";
        std::cout << "Guesses: " << guesses << "\n";
        std::cout << "\n";
    }
    std::cout << "YOU WIN!" << "\n";
    std::cout << "You took " << guesses << " Guesses " << "\n";


    std::cout << "Press to continue " << "\n";
    std::cin.clear();
    std::cin >> input;
    return 0;


}
