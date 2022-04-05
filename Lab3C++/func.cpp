#include "func.h"
tetrahedron* gen_arr(int SIZE)
{
    tetrahedron* p_arr = new tetrahedron[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        p_arr[i] = tetrahedron();
    }
    return p_arr;
}
void remove(tetrahedron* p_arr)
{
    delete[] p_arr;
}
float max(tetrahedron* p_arr, int length, int* id)
{
    float max_value = 0;
    for (int i = 0; i < length; i++)
    {
        if (p_arr[i].getVolume() > max_value)
        {
            max_value = p_arr[i].getVolume();
            *id = i+1;
        }
    }
    printf("\nMaximum volume: %.2f have tetrahedron number: %d\n", max_value, *id);
    return max_value;
}
void output(tetrahedron* p_arr, int length)
{
    for (int i = 0; i < length; i++)
        p_arr[i].getInfo();
}