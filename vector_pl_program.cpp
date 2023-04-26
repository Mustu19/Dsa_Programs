#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // value and weight vectors
    vector<int> value = {20, 50, 30, 10, 40};
    vector<int> weight = {10, 5, 20, 30, 15};

    // calculate value-to-weight ratios
    int n = value.size();
    vector<double> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = static_cast<double>(value[i]) / weight[i];
    }

    // sort objects based on value-to-weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
                swap(ratio[i], ratio[j]);
            }
        }
    }

    // print sorted objects
    cout << "Object\tValue\tWeight\tRatio\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << value[i] << "\t" << weight[i] << "\t" << ratio[i] << "\n";
    }

    return 0;
}
