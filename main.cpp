#include <iostream>
#include <math.h>
#include <time.h>
#include <fstream>

bool simplicityTest(unsigned number);

int main()
{
    unsigned number = 1000000;
    unsigned count = 1;
    std::ofstream fsave;
    fsave.open("simple_table.txt");
    if(!fsave.is_open())
        std::cout << "\n File open error" << std::endl;
    else
    {
        std::cout << "\n File is open" << std::endl;
        fsave << 2 << std::endl;
        double start = clock() * 1.0 / CLOCKS_PER_SEC;

        for(unsigned i = 3 ; i < number; i+=2)
            if(simplicityTest(i))
            {
                fsave << i;
                fsave << std::endl;
                ++count;
            }

        std::cout << "\n Save completed" << std::endl;
        std::cout << "\n File lines: " << count << std::endl;
        double end = clock() * 1.0 / CLOCKS_PER_SEC;
        std::cout << end - start << "sec" << std::endl;
    }

    fsave.close();
    return 0;
}

bool simplicityTest(unsigned number)
{
    for(unsigned i = 3; i < (sqrt(number)+1); i+=2)
        if(number % i == 0)
            return false;
    return true;
}