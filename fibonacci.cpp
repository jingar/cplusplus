#include <iostream>

int fibonacci(int n)
{
    if(n==2)
    {
        return 2;
    }
    else if(n==3)
    {
        return 3;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{   int n = 0;
    std::cout << "This program calculates Fibonacci sequence up to N" << std::endl;
    std::cout << "Please enter a number" << std::endl;

    std::cin >> n;
    std::cout << fibonacci(n) << " answer" << std::endl;

}
