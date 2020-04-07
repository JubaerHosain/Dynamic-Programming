#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
    string name;
    int weight;
    int value;
}Item;

Item items[] = {
    {"map",                      9,   150},
    {"compass",                 13,    35},
    {"water",                  153,   200},
    {"sandwich",                50,   160},
    {"glucose",                 15,    60},
    {"tin",                     68,    45},
    {"banana",                  27,    60},
    {"apple",                   39,    40},
    {"cheese",                  23,    30},
    {"beer",                    52,    10},
    {"suntan cream",            11,    70},
    {"camera",                  32,    30},
    {"T-shirt",                 24,    15},
    {"trousers",                48,    10},
    {"umbrella",                73,    40},
    {"waterproof trousers",     42,    70},
    {"waterproof over clothes",  43,    75},
    {"note-case",               22,    80},
    {"sunglasses",               7,    20},
    {"towel",                   18,    12},
    {"socks",                    4,    50},
    {"book",                    30,    10},
};

int *knapsack(Item items[], int numberOfItem, int weight)
{
    int **table, *result;

    //Answer 0/1 knapsack
    result = new int[numberOfItem];

    //Allocate memory for two 2D array
    table = new int*[numberOfItem+1];
    for(int i = 0; i <= numberOfItem; i++)
    {
        table[i] = new int[weight+1];
    }

    //Set first row colum as 0
    for(int i = 0; i <= numberOfItem; i++)
    {
        table[i][0] = 0;
    }
    for(int j = 0; j <= weight; j++)
    {
        table[0][j] = 0;
    }


    //Driver algorithm
    for(int i = 1; i <= numberOfItem;  i++)
    {
        for(int j = 0; j <= weight; j++)
        {
            if(items[i-1].weight > j)
            {
                table[i][j] = table[i-1][j];
            }
            else
            {
                int a = table[i-1][j];
                int b = table[i-1][j-items[i-1].weight] + items[i-1].value;
                table[i][j] = a > b ? a : b;
            }
        }
    }


    //Assign answer in the result array
    int w = weight;
    for(int i = numberOfItem; i > 0; i--)
    {
        if(table[i][w] > table[i-1][w])
        {
            result[i-1] = 1;
            w -= items[i-1].weight;
        }
        else
        {
            result[i-1] = 0;
        }
    }

    delete table;

    return result;
}

int main(void)
{
    int numberOfItem, *result, weight = 400, totalWeight = 0, totalValue = 0;

    numberOfItem = sizeof(items) / sizeof(items[0]);
    result = knapsack(items, numberOfItem, weight);

    for(int i = 0; i < numberOfItem; i++)
    {
        if(result[i] == 1)
        {
            cout << items[i].name <<  " " << items[i].weight << " " << items[i].value << endl;
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    cout << "Total: " << "  " << totalWeight << "  " << totalValue << endl;
    for(int i = 0; i < numberOfItem; i++)
    {
        cout << result[i] << " " ;
    }
}
