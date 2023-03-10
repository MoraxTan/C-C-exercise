#include<iostream>

int main()
{
    unsigned long long num;
    while(std::cin >> num)
    {
        num = num / 2 + 1;
        num = num * num;

        std::cout << 6 * num - 9 << "\n";
    }
    return 0;
}
