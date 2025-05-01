## Program Specification: Game Inventory Management System

### Overview:

- Maintains a catalog of games and available copies
- Allows customers to check out and return games
- Tracks which customer has which game
- Prevents checking out games with zero availability

#### Nouns:
- game
    - std::string title
    - int totalCopies
    - int availableCopies
- customer
    - std::string name
    - std::vector<std::string> checkedOutGames
- gameInventory
    - std::vector<Game> games
    - std::vector<Customer> customers

#### Verbs:
- addGame
    - getGameTitle
    - getTotalCopies
- addCustomer
    - getCustomerName
- checkOutGame 
    - removes 1 copy of the game from game inventory
    - adds game to customer's checked-out list
- returnGame
    - returns game back to game inventory
    - removes game from customer's checked-out list
- listAvailableGames
    - getGameTitle
    - getAvailableCopies
- listCheckedOutGames
    - lists games checked out by a specific customer

```c++
//Game.h
class Game {
private:
    std::string title;
    int totalCopies;
    int availableCopies;

public:
    Game(const std::string& title, int totalCopies);

    std::string getTitle() const;
    int getTotalCopies () const;
    int getAvailableCopies () const;

    bool checkout();
    void returnCopy();
};

//Customer.h
class Customer {
private:
    std::string name;
    std::vector<std::string> checkedOutGames;

public:
    Customer(const std::string& name);

    std::string getCustomerName() const;
    void checkOutGame(std::string& gameTitle);
    bool returnGame(std::string& gameTitle);
    const std::vector<std::string>& getCheckedOutGames() const;

};

//GameInventory.h
class gameInventory {
private:
    std::vector<Game> games;
    std::vector<Customer> customers;

    Game* findGame(const std::string& title);
    Customer* findCustomer(constd std::string& name);

public:
    void addGame(const std::string& title, int copies);
    void addCustomer(const std::string& name);

    bool checkoutGame(const std::string& customerName, const std::string& gameTitle);
    bool returnGame(const std::string& customerName, const std::string& gameTitle);

    void listAvailableGames() const;
    void listCustomerGames(const std::string& customerName) const;
}

```mermaid
---
title: Game Inventory Management System
---
classDiagram
        GameInventory "1" --> "*" Game : manages
        GameInventory "1" --> "*" Customer : manages
        class GameInventory {
            -Vector~Game~ games
            -Vector~Customer~ customers
            +findGame()
            +findCustomer()
            +addGame()
            +addCustomer()
            +listAvailableGames()
            +listCustomerGames()
            +checkoutGame()
            +returnGame()
        } 
        class Game {
          -String title
          -int totalCopies
          -int availableCopies
          +getTotalCopies()
          +getAvailableCopies()
          +checkout()
          +returnCopy
        }
        class Customer {
            -String name
            -Vector checkedOutGames
            +getCustomerName()
            +getCheckedOutGames()
            +checkOutGame()
            +returnGame()
        }