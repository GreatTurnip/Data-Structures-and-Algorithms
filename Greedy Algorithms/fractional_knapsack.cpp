#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item
{
    int id;
    double profit;
    double weight;
};

bool compare(Item a, Item b)
{
    return (a.profit / a.weight) > (b.profit / b.weight);
}

int main()
{
    int n;
    
    cout << "Enter number of items : ";
    cin >> n;

    vector <Item> items(n);

    cout << "Enter profit and weight for each item : " << endl;

    for(int i = 0; i < n; i++)
    {
        items[i].id = i + 1;
        cin >> items[i].profit >> items[i].weight;
    }

    double capacity; 
    cout << "Knapsack Capacity : ";
    cin >> capacity;

    sort(items.begin(), items.end(),compare);

    double totalProfit = 0.0;

    cout << "Selected Items : " << endl;

    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
            break;
        if(items[i].weight <= capacity)
        {
            cout << "Item" << items[i].id << endl;
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            double weight_profit_ratio = items[i].profit / items[i].weight;
            cout << "Item" << items[i].id << " " << weight_profit_ratio * 100 << endl;
            totalProfit += capacity * weight_profit_ratio;
            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;
    return 0;
}