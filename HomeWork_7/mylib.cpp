#include <iostream>

namespace MyLib
{

    float* CreateArray(size_t n)
    {   
        float* M = new float[n];
        for (int i = 0; i < n; i++)
        {
            M[i] = (i % 5 == 0 ? i : -i);
        }
        return M;
    }

    void Print(float* a, const int b)
    {
        for (int i = 0; i < b; i++)
            std::cout << a[i] << " ";
            std::cout << "\n";
    }

    void count(float array[], int size)
    {
        int pos = 0, neg = 0;

        for (int i = 0; i < size; i++)
        {
            if (array[i] >= 0.) pos++;
            else neg++;
        }
        std::cout << "positive: " << pos << "\nnegative: " << neg << "\n";
    }
}