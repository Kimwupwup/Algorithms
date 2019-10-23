#include <iostream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main()
{
    int r;
    double answer[2];
    cin >> r;
    answer[0] = r * r * M_PI;
    answer[1] = r * r * 2;
    printf("%.6lf\n%.6lf", answer[0], answer[1]);
}