#ifndef VENDINGBANK_H_
#define VENDINGBANK_H_
#include <string>

class VendingBank {
    private:
        int id_; // ID for vending machine
        double machineBalance_; // Total balance of the vending machine
        double customerBalance_; // Total balance for current customer

        // Different types of change the vending machine stores
        int pennies_;
        int nickels_;
        int dimes_;
        int quarters_;
        int dollarCoins_;

        
    public:
        // Constructor 
        VendingBank(); // Default constructor 
        VendingBank(int id); // Sets ID for machine
        VendingBank(int id, int pennies, int nickels, int dimes, int quarters, int dollarCoins); // Constructor that allows you to set values

        // Getters and Setters
        int getId() const; // returns the ID for this machine
        double getMachineBalance() const; // Returns the total of the money in the machine
        double getCustomerBalance() const; // Returns the customer's current balance

        // Getters for all the coins
        int getPennies() const; 
        int getNickels() const;
        int getDimes() const;
        int getQuarters() const;
        int getDollarCoins() const;

        // Setters for all the coins
        bool getPennies(int pennies); 
        bool getNickels(int nickels);
        bool getDimes(int dimes);
        bool getQuarters(int quarters);
        bool getDollarCoins(int dollarCoins);
        
        // Functions
        void insertCoin(std::string type, int count); // Takes coin type * amount and adds it to the customer's balance
        bool hasChange(double amount); // Checks the machine balance to see if there is enough money for change
        bool dispenseChange(double amount); // Removes the amount from the machine balance 
        void reset(); // Resets the machine's and customer's balances

        bool inStock(std::string item); // Checks if item is available
        bool canAfford(std::string item); // Checks if customer's balance is enough for an item
        bool purchaseItem(std::string item); // Purchases the item decreases the stock and customer balance
        
        // Overload 
        friend std::ostream& operator<<(std::ostream& stream, const VendingBank& bank); // For cout

};


#endif