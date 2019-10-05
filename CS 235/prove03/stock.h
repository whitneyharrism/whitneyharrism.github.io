/***********************************************************************
* Header:
* STOCK
* Summary:
* This will contain just the prototype for stocksBuySell(). You may
* want to put other class definitions here as well.
* Author
* <your names here>
************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h" // for Dollars defined in StockTransaction
#include "queue.h"   // for QUEUE
#include <iostream>  // for ISTREAM and OSTREAM
//#include <queue>
//using namespace std;
using namespace custom;

// the interactive stock buy/sell function
void stocksBuySell();

/*******************************************
* STOCK TRANSACTION
* A single stock is bought our sold
******************************************/
class StockTransaction
{
public:
    // constructor
    StockTransaction(int a = 0, Dollars b = 0.0, Dollars s = 0.0);
    
    // getters
    bool isBuy() const { return buy; }
    int getAmount() const { return amount; }
    Dollars getPurchase() const { return buyPrice; }
    Dollars getSell() const { return sellPrice; }
    Dollars getProceeds() const;

    // setters
    void setAmount(int amount) { this->amount = amount; }
    void setPurchase(const Dollars & dollars) { this->buyPrice = dollars; }
    void setSell() { this->buy = false; }
    void setBuy() { this->buy = true; }

    // seller
    StockTransaction sell(int sellAmount, Dollars userSellPrice);

    friend std::ostream & operator << (std::ostream & out, const StockTransaction & rhs);

    //display
    void displayTransaction(std::ostream & out);

private:
    bool buy;          // is this a buy transaction?
    int amount;        // how many stock are involved?
    Dollars buyPrice;  // purchase amount
    Dollars sellPrice; // sell amount
};

/*************************************************************
* PORTFOLIO
* A collection of stock purchases and sells
*************************************************************/
class Portfolio
{
public:
    // sell a few stocks
    void sell(int num, Dollars price);

    // add stocks to the list
    void buy(const StockTransaction &st) { held.push(st); }

    // display
    friend std::ostream &operator<<(std::ostream &out,
                                    const Portfolio &portfolio);

private:
    queue<StockTransaction> held;
    queue<StockTransaction> history;
    Dollars proceeds;
};

#endif // STOCK_H