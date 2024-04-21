#include<stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0; // Cannot make a profit with less than 2 prices
    }
    
    int minPrice = prices[0]; // Initialize the minimum price to the first price
    int maxProfit = 0; // Initialize the maximum profit to 0
    
    for (int i = 1; i < pricesSize; i++) {
        // Update the minimum price if the current price is smaller
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Update the maximum profit if selling at the current price gives a higher profit
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}


int main() {
    int prices[] = {1, 2, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, pricesSize);
    printf("Maximum profit: %d\n", result);
    return 0;
}