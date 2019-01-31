// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete as many transactions 
* as you like (ie, buy one and sell one share of the stock multiple times). However, 
* you may not engage in multiple transactions at the same time (ie, you must sell the 
* stock before you buy again).
*               
**********************************************************************************/

class Solution {
public:
    //
    // find all of ranges: which start a valley with the nearest peak after
    // add their delta together 
    //
    int maxProfit(vector<int> &prices) {

        if ( prices.size() < 1 ) return 0;

        int max = 0;
        int low = -1;
        for (int i=0; i < prices.size() - 1; i++){
            //meet the valley, then goes up
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            //meet the peak, then goes down
            if (prices[i] > prices[i+1] && low >= 0) {
                max += ( prices[i] - prices[low] ) ;
                low = -1; // reset the `low`
            }
        }

        // edge case
        if ( low >= 0 ) {
            max += ( prices[prices.size()-1] - prices[low] );
        }

        return max;
    }
};
