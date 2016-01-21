#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<double> prices { 19.35, 19.30, 18.88, 18.93, 18.95, 19.03, 19.00, 18.97, 18.97, 18.98};
                            
    double lowest = prices[0];
    double highest = prices[0];
    double bestProfit = 0.0;
    for(unsigned int i=0; i < prices.size();i++)
    {
        for (unsigned int j= i+2;j < prices.size();j++)
        {
            double difference = prices[j] - prices[i];
            if (difference > bestProfit)
            {
                lowest = prices[i];
                highest = prices[j];
                bestProfit = difference;
            }
        }
    }
    
    cout << "The best prices to buy and sell at are: " << lowest << ", " << highest << endl;

	return 0;
}
