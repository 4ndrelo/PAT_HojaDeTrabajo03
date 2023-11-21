#include "Ejercicio01.h"

int Ejercicio01::findMin(int nums[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return nums[left];
}
