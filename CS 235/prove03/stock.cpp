/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream> // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>   // for STRING
#include <cassert>  // for ASSERT
#include <sstream>  // for StringStream
#include "stock.h"  // for STOCK_TRANSACTION
#include "queue.h"  // for QUEUE
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
    // instructions
    cout << "This program will allow you to buy and sell stocks. "
         << "The actions are:\n";
    cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
    cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
    cout << "  display         - Display your current stock portfolio\n";
    cout << "  quit            - Display a final report and quit the program\n";

    // your code here...

    cout << "   > ";
    cin.ignore;
    string input;
    Portfolio p;

    while (getline(cin, input))
    {

        stringstream s;
        s.str(input);

        string menuInput;
        int numberShares;
        Dollars price;

        s >> menuInput;
        if (menuInput == "buy")
        {
            s >> numberShares >> price;
            StockTransaction st = StockTransaction(numberShares, price);
            p.buy(st);
        }
        else if (menuInput == "sell")
        {
            s >> numberShares >> price;
            p.sell(numberShares, price);
        }
        else if (menuInput == "display")
        {
            cout << p;
        }
        else if (menuInput == "quit")
        {
            break;
        }
        else
        {
            cout << "Not a valid option, try again.\n";
        }

        cout << "> ";
    }
}

StockTransaction :: StockTransaction(int a, Dollars b, Dollars s)
{
    amount = a;
    buyPrice = b;
    sellPrice = s;
    buy = true;

    if (s > 0)
    {
        buy = false;
    }
}

StockTransaction StockTransaction ::sell(int sellAmount, Dollars userSellPrice)
{
    amount -= sellAmount;
    StockTransaction t = StockTransaction(sellAmount, buyPrice, userSellPrice);

    return t;
}

Dollars StockTransaction ::getProceeds() const
{
    if (!buy)
    {
        return (sellPrice - buyPrice) * amount;
    }
    else
    {
        return Dollars(0);
    }
}

ostream &operator<<(ostream &out, const StockTransaction &st)
{
    if (st.isBuy())
    {
        out << "\tBought " << st.amount << " shares at " 
            << st.buyPrice << endl;
        return out;
    }
    else{
        out << "\tSold " << st.amount << " shares at " 
            << st.sellPrice << " for a profit of " 
            << st.getProceeds << endl;
        return out;
    }
}

void Portfolio :: sell(int num, Dollars price){
    while (num > 0 && !held.empty())
    {
        StockTransaction st = held.front().sell(num, price);
        num -= st.getAmount();
        proceeds += st.getProceeds();
        history.push(st);

        if(held.front().getAmount() == 0){
            held.pop();
        }
    }
    
}

ostream & operator << (ostream & out, const Portfolio & portfolio){
    if(!portfolio.held.empty()){
        queue<StockTransaction> bH = portfolio.held;
        out << "Currently held:\n";

        while (!bH.empty())
        {
            out << bH.front();
            bH.pop();
        }
        
    }

    if(!portfolio.history.empty()){
        queue<StockTransaction> sH = portfolio.history;

        while (!portfolio.history.empty())
        {
            out << sH.front();
            sH.pop();
        }
        
    }

    out << "Proceeds: " << portfolio.proceeds << endl;

    return out;
}
