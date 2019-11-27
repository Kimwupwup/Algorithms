#include <iostream>

using namespace std;

struct node
{
    int u;
    int v;
    int cost;

    bool operator<(const node &e)
    {
        return cost < e.cost;
    }
};

int main()
{

    return 0;
}