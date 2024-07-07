#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <map>
#include <functional>
#include <unordered_map>
#include <queue>
#include <unistd.h>
#include <string>
#include <regex>
#include <cmath>
using namespace std;

string hashPassword(const string &password)
{
    return password;
}

class Account
{
private:
    string account_num;
    double balance;

public:
    Account()
    {
        account_num = "";
        balance = 0;
    }

    Account(string acc_nm, double bal)
    {
        account_num = acc_nm;
        balance = bal;
    }
    bool deposite(string acc, double amount)
    {
        // cout<<"acc"<<acc<<" ("<<account_num<<") "<<acc.compare(account_num)<<endl;
        if (!acc.compare(account_num))
        {
            if (amount > 0)
            {
                cout << "\n\t\t    AMOUNT DEPOSITE SUCCESSFULLY....." << endl;
                // cout<<balance<<endl;
                balance += amount;
                // cout<<balance<<endl;
                sleep(1);
                return true;
            }
            else
            {
                cout << "\n\t\t    YOU CANNOT DEPOSIT NEGATIVE BALANCE.\n";
                return false;
            }
        }
        else
        {
            cout << "\n\t\t    INCORRECT ACCOUNT NUMBER" << endl;
            sleep(1);
            return false;
        }
    }
    double withdrawl(string acc, double amount)
    {
        // cout<<acc<<account_num<<endl;
        if (!acc.compare(account_num))
        {
            if (balance >= amount && amount > 0)
            {
                // cout<< "balance"<<balance;
                balance -= amount;
                // cout<< "balance"<<balance;
                cout << "\n\t\t    AMOUNT WITHDRAWL SUCCESSFULLY..." << endl;
                sleep(1);
                return amount;
            }
            else
            {
                cout << "\n\t\t    INSUFFICENT BALANCE ." << endl;
                sleep(1);
                return 0;
            }
        }
        else
        {
            cout << "\n\t\t    INCORRECT ACCOUNT NUMBER...." << endl;
            sleep(1);
            return 0;
        }
        return 0;
    }
    double getBalance() const
    {
        return balance;
    }
    void setBalance(double b)
    {
        balance = b;
    }
    string getAccountNumber() const
    {
        return account_num;
    }
    void setAccountNumber(string acc)
    {
        account_num = acc;
    }
};
class Product;
class User
{
private:
    string name;
    string gmail;
    string hashedPassword;
    Account account;

    unordered_map<int, int> userProducts;
    unordered_map<int, int> boughtProducts;
    unordered_map<int, int> soldProducts;

public:
    User()
    {
        name = "";
        gmail = "";
        hashedPassword = "";
        account = Account();
        userProducts = unordered_map<int, int>();
        boughtProducts = unordered_map<int, int>();
        soldProducts = unordered_map<int, int>();
    }
    User(string n, string gm, string pass, Account Ac)
        : name(n), gmail(gm), hashedPassword(pass), account(Ac)
    {
        userProducts = unordered_map<int, int>();
        boughtProducts = unordered_map<int, int>();
        soldProducts = unordered_map<int, int>();
    }
    User(string n, string gm, string pass, Account Ac, unordered_map<int, int> userProd, unordered_map<int, int> boughtProd, unordered_map<int, int> soldProd)
        : name(n), gmail(gm), hashedPassword(pass), account(Ac), userProducts(userProd), boughtProducts(boughtProd), soldProducts(soldProd)
    {
    }

    bool deposite(string acc, double amount)
    {
        return account.deposite(acc, amount);
    }
    double withdrawl(string acc, double amount)
    {
        return account.withdrawl(acc, amount);
    }
    bool checkGmail(const string &email) const
    {
        return this->gmail == email;
    }

    bool checkPassword(const string &password) const
    {
        return this->hashedPassword == hashPassword(password);
    }
    bool checkaccn(const string &accn) const
    {
        return this->account.getAccountNumber() == accn;
    }
    string getName()
    {
        return name;
    }
    string getGmail()
    {
        return gmail;
    }
    Account getAccount()
    {
        return account;
    }
    int write_to_file(string filename)
    {
        fstream outfile(filename, ios::app);
        if (outfile.is_open())
        {
            outfile << name << endl;
            outfile << gmail << endl;
            outfile << hashedPassword << endl;
            outfile << account.getAccountNumber() << endl;
            outfile << account.getBalance() << endl;
            outfile.close();
            //            cout << "Attributes saved to user file: "  << endl;
        }
        else
        {
            //            cout << "Error: Unable to open user file: " << filename << endl;
        }
        return 0;
    }

    void buyProduct(int productid, int quantity)
    {
        // Check if the product already exists in boughtProducts
        auto it = boughtProducts.find(productid);

        if (it != boughtProducts.end())
        {
            // Product already exists, update the count
            it->second += quantity; // Increment the count
        }
        else
        {
            // Product doesn't exist, add a new entry
            boughtProducts.insert({productid, quantity}); // Initial count is quantity
        }
    }

    void sellProduct(int productid, int quantity)
    {
        // Check if the product already exists in soldProducts
        auto it = soldProducts.find(productid);

        if (it != soldProducts.end())
        {
            // Product already exists, update the count
            it->second += quantity; // Increment the count
        }
        else
        {
            // Product doesn't exist, add a new entry
            soldProducts.insert({productid, quantity}); // Initial count is quantity
        }
    }
    void displaySoldProducts()
    {
        for (const auto &entry : soldProducts)
        {
            int productid = entry.first;
            int count = entry.second;

            // product->fullDisplay();  // Display product information or customize as needed
            cout << "Product ID : " << productid << "\n";
            cout << "Quantity Sold: " << count << "\n";
            cout << "---------------------\n";
        }
        int c;
        cin >> c;
    }
    void displayboughtProducts()
    {
        for (const auto &entry : soldProducts)
        {
            int productid = entry.first;
            int count = entry.second;

            // product->fullDisplay();  // Display product information or customize as needed
            cout << "Product ID : " << productid << "\n";
            cout << "Quantity Bought: " << count << "\n";
            cout << "---------------------\n";
        }
        int c;
        cin >> c;
    }
    void displayUserProducts()
    {
        for (const auto &entry : soldProducts)
        {
            int productid = entry.first;
            int count = entry.second;

            // product->fullDisplay();  // Display product information or customize as needed
            cout << "Product ID : " << productid << "\n";
            cout << "Quantity Bought: " << count << "\n";
            cout << "---------------------\n";
        }
        int c;
        cin >> c;
    }
    bool addProductToUserMap(int productId, int stock)
    {
        // Check if the product ID already exists in the user's map
        auto it = userProducts.find(productId);

        if (it != userProducts.end())
        {
            // Product already exists, increment its stock
            if ((it->second + stock) > 100)
            {
                // Stock exceeds 100, return false to indicate failure
                return false;
            }

            // Increment stock and update the existing product
            it->second += stock;
        }
        else
        {
            // Product doesn't exist, add it to the map
            userProducts[productId] = stock;
        }

        // Return true to indicate success
        return true;
    }
    void readFromFile(ifstream &inFile)
    {
        if (inFile.is_open())
        {
            getline(inFile, name);
            getline(inFile, gmail);
            getline(inFile, hashedPassword);

            string accNumStr, balanceStr;
            getline(inFile, accNumStr);
            getline(inFile, balanceStr);
            account.setAccountNumber(accNumStr);
            account.setBalance(stod(balanceStr));

            // Read userProducts
            userProducts.clear();
            int key, value;
            while (inFile >> key >> value)
            {
                userProducts[key] = value;
            }
            inFile.clear();  // Clear the end-of-file flag
            inFile.ignore(); // Ignore the newline character after the last userProduct entry

            // Read boughtProducts
            boughtProducts.clear();
            while (inFile >> key >> value)
            {
                boughtProducts[key] = value;
            }
            inFile.clear();  // Clear the end-of-file flag
            inFile.ignore(); // Ignore the newline character after the last boughtProduct entry

            // Read soldProducts
            soldProducts.clear();
            while (inFile >> key >> value)
            {
                soldProducts[key] = value;
            }
            inFile.clear();  // Clear the end-of-file flag
            inFile.ignore(); // Ignore the newline character after the last soldProduct entry
        }
        else
        {
            cerr << "Error: Unable to open file for reading\n";
        }
    }
    void writeToFile(ofstream &outFile) const
    {
        if (outFile.is_open())
        {
            outFile << "   " << name << "\n";
            outFile << gmail << "\n";
            outFile << hashedPassword << "\n";
            outFile << account.getAccountNumber() << "\n";
            outFile << account.getBalance() << "\n";

            // Write userProducts, boughtProducts, and soldProducts
            for (const auto &entry : userProducts)
            {
                outFile << entry.first << " " << entry.second << "\n";
            }
            outFile << "\n";

            for (const auto &entry : boughtProducts)
            {
                outFile << entry.first << " " << entry.second << "\n";
            }
            outFile << "\n";

            for (const auto &entry : soldProducts)
            {
                outFile << entry.first << " " << entry.second << "\n";
            }
            outFile << "\n";

            outFile << "\n"; // Add a separator between users
        }
        else
        {
            cerr << "Error: Unable to open file for writing: "
                 << "Users.txt"
                 << "\n";
        }
    }

    void display()
    {
        cout << "      Name        : " << name << endl;
        cout << "      Amount       : " << account.getBalance() << endl;
        cout << "      Gmail  : " << gmail << endl;
        cout << "      Password : " << hashedPassword << endl;
        cout << "      AccountNumber : " << account.getAccountNumber() << endl;
    }
};
class Product
{
private:
    static int ID;
    int id;
    string name;
    string description;
    string category;
    double price;
    int stock;
    string brand;
    int ratingcount;
    vector<string> review;
    User *seller;
    double customerRatings;

public:
    Product() : id(0), name(""), description(""), category(""), price(0.0), stock(0), brand(""), ratingcount(0), customerRatings(0.0)
    {
    }
    Product(string name, string description, string category, double price, int stock, string brand, int ratingcount, vector<string> review, User *seller, double customerRatings) : name(name), description(description), category(category), price(price), stock(stock), brand(brand), ratingcount(ratingcount), review(review), seller(seller), customerRatings(customerRatings)
    {
        ID++;
        this->id = ID;
    }
    Product(int id, string name, string description, string category, double price, int stock, string brand, int ratingcount, vector<string> review, User *seller, double customerRatings) : id(id), name(name), description(description), category(category), price(price), stock(stock), brand(brand), ratingcount(ratingcount), review(review), seller(seller), customerRatings(customerRatings)
    {
    }
    // GETTERSS
    int getID() const
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getDescription()
    {
        return description;
    }
    string getCategory()
    {
        return category;
    }
    double getPrice()
    {
        return price;
    }
    int getStock()
    {
        return stock;
    }
    string getBrand()
    {
        return brand;
    }
    User *getSeller()
    {
        return seller;
    }
    int getRatingCount()
    {
        return ratingcount;
    }
    vector<string> getReviews()
    {
        return review;
    }
    double getCustomerRatings()
    {
        return customerRatings;
    }
    // SETTERS
    void setName(string name)
    {
        this->name = name;
    }
    void setDescription(string description)
    {
        this->description = description;
    }
    void setCategory(string category)
    {
        this->category = category;
    }
    void setPrice(string category, double price)
    {
        this->price = price;
    }
    void setStock(int stock)
    {
        this->stock = stock;
    }
    void setBrand(string brand)
    {
        this->brand = brand;
    }
    void setSeller(User *seller)
    {
        this->seller = seller;
    }
    void setCustomerRatings(double customerRatings)
    {
        this->customerRatings *= ratingcount;
        this->customerRatings += customerRatings;
        this->customerRatings /= ++ratingcount;
    }
    void addReview(const string &review)
    {
        this->review.push_back(review);
    }
    int getCategoryIndex() const
    {
        // Assuming categories are labeled 1 to 5, update accordingly
        if (category == "Electronics")
            return 0;
        else if (category == "Clothing")
            return 1;
        else if (category == "Books")
            return 2;
        else if (category == "HomeAppliances")
            return 3;
        else if (category == "SportsEquipment")
            return 4;
        else
        {
            cerr << "Invalid category: " << category << endl;
            exit(1);
        }
    }
    // OVERLOADING THE OPERATORS
    bool operator==(const Product &other) const
    {
        return this->id == other.id;
    }
    bool operator<(const Product &other) const
    {
        return this->id < other.id;
    }
    bool operator>(const Product &other) const
    {
        return this->id > other.id;
    }
    void shortDisplay()
    {
        cout << "     __________________________________________" << endl;
        cout << "    |            (PRODUCT NO " << id << ")                |" << endl;
        cout << "      Name          : " << name << endl;
        cout << "      Price         : " << price << endl;
        cout << "      Brand         : " << brand << endl;
        cout << "      Ratings       : " << customerRatings << endl;
        cout << "    |__________________________________________|" << endl;
    }
    void fullDisplay()
    {
        cout << "     __________________________________________" << endl;
        cout << "    |            (PRODUCT NO " << id << ")                |" << endl;
        cout << "      Name            : " << name << endl;
        cout << "      Description     : " << endl;
        cout << "               " << description << endl;
        cout << "      Price           : " << price << endl;
        cout << "      Stock           : " << stock << endl;
        cout << "      Brand           : " << brand << endl;
        cout << "      Seller Name     : " << seller->getName() << endl;
        cout << "      Seller gmail ID : " << seller->getGmail() << endl;
        cout << "      Ratings         : " << customerRatings << endl;
        cout << "      Reviews         : " << endl;
        for (auto rev : review)
        {
            cout << "         " << rev << endl;
        }
        cout << "    |__________________________________________|" << endl;
    }
    bool buy(User *buyer, int q)
    {
        if (stock > 0)
        {
            stock -= q;
            cout << "in buy of product " << endl;
            sleep(1);
            // Check if the buyer can withdraw the amount
            if (buyer->withdrawl(buyer->getAccount().getAccountNumber(), price * q))
            {
                // Successful purchase
                // Deposit the amount to the seller's account
                if (seller->deposite(seller->getAccount().getAccountNumber(), price * q))
                {
                    // Update the seller's sold product count
                    //                seller->addSoldProduct(this);
                    buyer->buyProduct(id, q);
                    return true; // Return true if purchase is successful
                }
                else
                {
                    buyer->deposite(buyer->getAccount().getAccountNumber(), price * q);
                }
            }
            stock += q;
        }

        return false; // Return false if the purchase was not successful
    }
};

class Node
{
public:
    Product data;
    Node *left;
    Node *right;
    int height;
    Node(Product data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL
{
public:
    Node *Root = NULL;
    Node *getRoot()
    {
        return Root;
    }
    void insert(Product val)
    {
        Root = insert(Root, val);
        Root = balance(Root);
    }
    void delte(Product key)
    {
        Root = delte(Root, key);
        Root = update_height(Root);
        Root = balance(Root);
    }
    void search(Product key)
    {
        if (search(Root, key))
            cout << endl
                 << "Product "
                 << " Exist" << endl;
        else
            cout << endl
                 << "Product "
                 << " Not Exist" << endl;
    }
    Node *searchById(int key)
    {
        return searchById(Root, key);
    }
    void preOrder()
    {
        cout << "PreOrder" << endl;
        preOrder(Root);
        cout << endl;
    }
    void inOrder()
    {
        cout << "InOrder" << endl;
        inOrder(Root);
        cout << endl;
    }
    void postOrder()
    {
        cout << "PostOrder" << endl;
        postOrder(Root);
        cout << endl;
    }
    void levelOrder()
    {
        cout << "LevelOrder" << endl;
        levelOrder(Root);
        cout << endl;
    }
    void count()
    {
        cout << "Count : " << count(Root) << endl;
    }
    void sum()
    {
        cout << "Sum : " << sum(Root) << endl;
    }
    void height()
    {
        cout << "Height : " << height(Root) << endl;
    }
    void diameter()
    {
        cout << "Diameter : " << diameter(Root) << endl;
    }

private:
    Node *insert(Node *root, Product val)
    {
        if (root == NULL)
        {
            root = new Node(val);
            return root;
        }
        if (root->data.getID() > val.getID())
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
        root = update_height(root);
        return root;
    }
    Node *delte(Node *root, Product key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->data == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            if (root->left == NULL)
            {
                root = root->right;
                return root;
            }
            if (root->right == NULL)
            {
                root = root->left;
                return root;
            }
            Product suc = successor(root->right);
            root->data = suc;
            return root;
        }
        if (root->data > key)
        {
            root->left = delte(root->left, key);
        }
        else
        {
            root->right = delte(root->right, key);
        }
        return root;
    }
    Product successor(Node *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        Product val = root->data;
        root = delte(root, root->data);
        return val;
    }
    bool search(Node *root, Product key)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == key)
        {
            return true;
        }
        if (root->data > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }

    Node *searchById(Node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data.getID() == key)
        {
            return root;
        }
        if (root->data.getID() > key)
        {
            return searchById(root->left, key);
        }
        else
        {
            return searchById(root->right, key);
        }
    }

    void preOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        root->data.shortDisplay();
        preOrder(root->left);
        preOrder(root->right);
        return;
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        root->data.shortDisplay();
        inOrder(root->right);
        return;
    }
    void postOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        root->data.shortDisplay();
        return;
    }

    void levelOrder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                cout << endl;
                if (q.empty())
                {
                    break;
                }
                else
                {
                    q.push(NULL);
                }
            }
            else
            {
                curr->data.shortDisplay();
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
    }
    int count(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return count(root->left) + count(root->right) + 1;
    }
    int sum(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return sum(root->left) + sum(root->right) + root->data.getStock();
    }
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }
    int diameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_dim = diameter(root->left);
        int right_dim = diameter(root->right);

        int left_ht = height(root->left);
        int right_ht = height(root->right);

        int my_dim = left_ht + right_ht + 1;
        return max(max(left_dim, right_dim), my_dim);
    }
    Node *balance(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        root->left = balance(root->left);
        root->right = balance(root->right);
        int bf = balance_factor(root);
        //        cout<<root->data<<" "<<bf<<endl;
        if (bf > 1)
        {
            if (balance_factor(root->left) >= 0)
            {
                // cout<<"LL"<<endl;
                // Left-Left case
                root = Rotate_Right(root);
            }
            else
            {
                //  cout<<"LR"<<endl;
                // Left-Right case
                root->left = Rotate_Left(root->left);
                root = Rotate_Right(root);
            }
        }
        else if (bf < -1)
        {
            if (balance_factor(root->right) <= 0)
            {
                //  cout<<"RR"<<endl;
                // Right-Right case
                root = Rotate_Left(root);
            }
            else
            {
                root->right = Rotate_Right(root->right);
                root = Rotate_Left(root);
            }
        }
        root = update_height(root);
        return root;
    }
    Node *Rotate_Right(Node *root)
    {
        Node *temp = root;
        root = root->left;
        temp->left = root->right;
        root->right = temp;
        return root;
    }
    Node *Rotate_Left(Node *root)
    {
        Node *temp = root;
        root = root->right;
        temp->right = root->left;
        root->left = temp;
        return root;
    }
    int balance_factor(Node *root)
    {

        if (!root)
        {
            return 0;
        }
        return height(root->left) - height(root->right);
    }
    Node *update_height(Node *root)
    {
        if (!root)
        {
            return root;
        }
        root->left = update_height(root->left);
        root->right = update_height(root->right);
        root->height = max(height(root->left), height(root->right) + 1);
        return root;
    }
};

class MaxHeap
{
private:
    vector<Product> heap;

    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index].getCustomerRatings() > heap[parent].getCustomerRatings())
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild].getCustomerRatings() > heap[largest].getCustomerRatings())
        {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].getCustomerRatings() > heap[largest].getCustomerRatings())
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(const Product &value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    Product extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty";
            return heap[0];
        }

        Product maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    bool isEmpty() const
    {
        return heap.empty();
    }
    Product *findProductById(int key)
    {
        for (auto &element : heap)
        {
            if (element.getID() == key)
            {
                return &element;
            }
        }
        return NULL;
    }
    void display()
    {
        for (auto &element : heap)
        {
            element.shortDisplay();
        }
        cout << "\n";
    }
};
int Product::ID = 0;

class OnlineMarketplace
{
private:
    unordered_map<string, User> user;
    AVL categoryAVL[5];
    User *currentUser = NULL;
    void adding_product()
    {
        addProduct(Product("Laptop X1", "It is a laptop", "Electronics", 999.99, 50, "TechMaster", 5, {"verygood"}, &user["ghalibzaidi115@gmail.com"], 4.8));
        addProduct(Product("Stylish Jeans", "It is a jeans", "Clothing", 79.99, 50, "Fationista", 5, {"verygood"}, &user["ghalibzaidi115@gmail.com"], 4.5));
        addProduct(Product("Bestseller Nover", "It is a book", "Books", 19.99, 50, "BookMaster", 5, {"verygood"}, &user["ghalibzaidi115@gmail.com"], 4.7));
        addProduct(Product("Modern Wall Art", "It is a art", "HomeAppliances", 59.99, 0, "ArtistryHome", 5, {"verygood"}, &user["walimohsin786@gmail.com"], 4.6));
        addProduct(Product("Fitness Tracker", "It is a shoes", "SportsEquipment", 89.99, 50, "FitTech", 5, {"verygood"}, &user["walimohsin786@gmail.com"], 4.9));
    }

    void addUser(User newUser)
    {
        // Assuming the Gmail is a unique identifier for a user
        user[newUser.getGmail()] = newUser;
    }
    void addProduct(const Product product)
    {
        //   int categoryIndex = getCategoryIndex(product.getCategory());
        categoryAVL[product.getCategoryIndex()].insert(product);
    }
    int getCategoryIndex(const string &category)
    {
        // Assuming categories are labeled 1 to 5, update accordingly
        if (category == "Electronics")
            return 0;
        else if (category == "Clothing")
            return 1;
        else if (category == "Books")
            return 2;
        else if (category == "HomeAppliances")
            return 3;
        else if (category == "SportsEquipment")
            return 4;
        else
        {
            cerr << "Invalid category: " << category << endl;
            exit(1);
        }
    }
    // Function to get password input with '*' characters
    string getPassword()
    {
        string password;
        char ch;

        while (true)
        {
            ch = _getch(); // Use _getch() for Windows, getch() for Unix-like systems
            if (ch == 13 || ch == 10)
            { // Enter key
                break;
            }
            else if (ch == 8 && !password.empty())
            { // Backspace key
                cout << "\b \b";
                password.pop_back();
            }
            else if (ch != 8)
            {
                cout << '*';
                password.push_back(ch);
            }
        }

        cout << endl;
        return password;
    }

    void inOrderTraversalForDisplay(Node *root, MaxHeap &maxHeap)
    {
        if (root)
        {
            inOrderTraversalForDisplay(root->left, maxHeap);
            maxHeap.insert(root->data);
            inOrderTraversalForDisplay(root->right, maxHeap);
        }
    }
    void Khubsurti(string Name)
    {
        fflush(stdin);
        cout << "              Welcome to ONLINE MARKETING PLACE  \n ";
        cout << "             +============================+         \n\n";
        cout << "                     $  " << Name << "  $ \n\n";
        // if(Name.compare("HOME PAGE") && Name.compare("LOGIN PAGE") && Name.compare("SIGN UP PAGE"))
        if (currentUser)
        {
            cout << " ________________________________________________________\n";
            cout << "   NAME :  " << currentUser->getName() << "            AMOUNT :  " << currentUser->getAccount().getBalance();
            cout << "\n ________________________________________________________\n\n";
        }
        if (Name.compare("LOGIN PAGE") && Name.compare("SIGN UP PAGE"))
        {
            cout << " || Please select the Option that you would like to do. || \n\n";
        }
    }
    string checkgmail(const string email)
    {
        string gmail;
        gmail = email;
        int x = 0;
        do
        {
            x = 0;
            regex pattern("(\\w+)((\\.(\\w+))|(_(\\w+)))?@((yahoo)|(hotmail)|(gmail))\\.((com)|((co)\\.(\\w+)))");
            // If the email matches the pattern and is from Gmail, Yahoo, or Hotmail
            if (regex_match(gmail, pattern))
            {
                for (const auto &entry : user)
                {
                    const User &U = entry.second;
                    if (U.checkGmail(gmail))
                    {
                        cout << "\n\t\t   EMAIL ID ALREADY EXISTS" << endl;
                        x = 1;
                        break;
                    }
                }
                if (x == 0)
                {
                    return gmail;
                }
            }

            else
            {
                cout << "\n\t\t   INCORRECT EMAIL FORMAT" << endl;
                x = 1;
            }

            if (x == 1)
            {
                cout << "\t\t   PLEASE ENTER AGAIN" << endl;
                cout << "\nENTER YOUR GMAIL ID  = ";
                cin >> gmail;
            }
        } while (1);
    }
    string checkuservalidity(string gmail)
    {
        do
        {
            for (const auto &entry : user)
            {
                const User &U = entry.second;
                if (U.checkGmail(gmail))
                {
                    return gmail;
                }
            }
            cout << "\t\t   EMAIL ID DOESN'T EXIST " << endl;
            cout << "\t\t   PLEASE ENTER AGAIN" << endl;
            cout << "\nENTER YOUR GMAIL ID  = ";
            cin >> gmail;
        } while (1);
    }
    string checkpassword(string password, string username)
    {
        int x = 1;
        while (x)
        {
            bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
            if (x != 1)
            {
                cout << "\n\t\t   CAN'T CONSIDER WEEK PASSWORD." << endl;
                sleep(1);
                cout << "ENTER YOUR PASSWORD AGAIN = ";
                cin >> password;
            }
            int password_len = password.length();

            // Check if password is the same as the username
            if (password.find(username) != string::npos)
            {
                cout << "\n\t\t   PASWORD SHOULD NOT CONTAIN USERNAME." << endl;
                sleep(1);
                x++;
                continue;
            }

            // Check if password is too common
            vector<string> common_passwords = {"password", "123456", "12345678", "1234", "qwerty", "abc123", "123123", "admin", "letmein", "monkey", "shadow", "sunshine", "12345", "password1", "trustno1"};
            int num_common_passwords = common_passwords.size();
            bool is_common = false;
            for (int i = 0; i < num_common_passwords; i++)
            {
                if (password == common_passwords[i])
                {
                    cout << "\n\t\t   PASSWORD IS TOO COMMON." << endl;
                    sleep(1);
                    is_common = true;
                    x++;
                }
            }
            if (is_common)
            {
                continue;
            }
            // Check if password contains uppercase, lowercase, digit, and special character
            for (int i = 0; i < password_len; i++)
            {
                char c = password[i];
                if (isupper(c))
                {
                    has_upper = true;
                }
                else if (islower(c))
                {
                    has_lower = true;
                }
                else if (isdigit(c))
                {
                    has_digit = true;
                }
                else if (!isalnum(c))
                {
                    has_special = true;
                }
            }

            if (!(has_upper && has_lower && has_digit && has_special))
            {
                fflush(stdin);
                cout << "\n\t\t   PASWORD SHOULD CONTAIN ATLEAST. \n\n\t\t   [1] ONE UPPERCASE LETTER. \n\t\t   [2] ONE LOWERCASE LETTER.\n\t\t   [3] ONE DIGIT.  \n\t\t   [4] ONE SPECIAL CHARACTER." << endl;
                sleep(1);
                x++;
                continue;
            }

            // Check password length
            if (password_len < 8 || password_len > 15)
            {
                cout << "\n\t\t   PASSWORD LENGTH SHOULD BE BETWEEN 8 TO 15 CHARACTERS." << endl;
                x++;
                sleep(1);
                continue;
            }
            // Password meets all requirements, return true
            x = 0;
            cout << "\n\t\t   PASWORD IS STRONG AND VALID." << endl;
            sleep(1);
            return password;
        }
        return "";
    }
    string checkaccountnum(const string acc_num)
    {
        string account_number = acc_num;
        int x = 0;
        do
        {
            x = 0;
            regex pattern("^\\d{4}-\\d{4}-\\d{4}-\\d{4}$");
            // If the account number matches the pattern [0000-0000-0000-0000]
            if (regex_match(account_number, pattern))
            {
                for (const auto &entry : user)
                {
                    const User &U = entry.second;
                    if (U.checkaccn(account_number))
                    {
                        cout << "\n\t\t   ACCOUNT NUMBER ALREADY EXISTS" << endl;
                        x = 1;
                        break;
                    }
                }
                if (x == 0)
                {
                    return account_number;
                }
            }
            else
            {
                cout << "\n\t\t   INCORRECT ACCOUNT NUMBER FORMAT" << endl;
                x = 1;
            }

            if (x == 1)
            {
                cout << "\t\t   PLEASE ENTER AGAIN" << endl;
                cout << "\nENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
                cin >> account_number;
            }

        } while (1);
    }
    string checkaccount_num(const string acc_num)
    {
        string account_number = acc_num;
        int x = 0;
        do
        {
            x = 0;
            regex pattern("^\\d{4}-\\d{4}-\\d{4}-\\d{4}$");
            // If the account number matches the pattern [0000-0000-0000-0000]
            if (regex_match(account_number, pattern))
            {
                return account_number;
            }
            else
            {
                cout << "\n\t\t   INCORRECT ACCOUNT NUMBER FORMAT" << endl;
                cout << "\t\t   PLEASE ENTER AGAIN" << endl;
                cout << "\nENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
                cin >> account_number;
            }
        } while (1);
    }
    double checkamount(double amount)
    {
        do
        {
            if (amount <= 100000)
            {
                return amount;
            }
            cout << "\t\t   YOUR REQUESTED AMOUNT IS TOO MUCH..." << endl;
            cout << "\t\t   PLEASE ENTER AGAIN" << endl;
            cout << "\nENTER YOUR AMOUNT AGAIN  = ";
            cin >> amount;
        } while (1);
    }
    // Helper function to find a product by ID in the AVL tree
    Node *findProductById(int id)
    {
        for (int i = 0; i < 5; ++i)
        {
            Node *foundProduct = categoryAVL[i].searchById(id); // Assuming you have a searchById function in AVL class
            if (foundProduct)
            {
                return foundProduct;
            }
        }

        return nullptr;
    }
    void buyProduct(Product *p, const string &acc, int q)
    {
        // Check if the provided account number matches the current user's account number
        if (currentUser->getAccount().getAccountNumber() == acc)
        {
            if (p->buy(currentUser, q))
            {
                cout << "Thanks for buying " << p->getName() << endl;
                sleep(1); // Assuming the seller is accessible from the product
                p->getSeller()->sellProduct(p->getID(), q);
            }
            else
            {
                cout << "Try next time" << endl;
                sleep(1);
            }
        }
        else
        {
            cout << "Invalid account number. Purchase failed." << endl;
        }
    }

    void addProductToAVL()
    {
        // Get product information from the user
        string name, description, category, brand;
        double price;
        int stock;

        // Name input with length check
        do
        {
            cout << "Enter product name (minimum 3 characters): ";
            cin.ignore();
            getline(cin, name);
        } while (name.length() < 3);

        // Description input with length check
        do
        {
            cout << "Enter product description (minimum 11 characters): ";
            getline(cin, description);
        } while (description.length() < 11);

        // Category input using a switch statement
        int categoryOption;
        do
        {
            cout << "Available product categories:\n";
            cout << "1. Electronics\n2. Clothing\n3. Books\n4. Home Appliances\n5. Sports Equipment\n";
            cout << "Select product category (1-5): ";
            cin >> categoryOption;

            switch (categoryOption)
            {
            case 1:
                category = "Electronics";
                break;
            case 2:
                category = "Clothing";
                break;
            case 3:
                category = "Books";
                break;
            case 4:
                category = "HomeAppliances";
                break;
            case 5:
                category = "SportsEquipment";
                break;
            default:
                cout << "Invalid category option. Please select again.\n";
            }
        } while (categoryOption < 1 || categoryOption > 5);

        // Price input with non-negative check
        do
        {
            cout << "Enter product price (non-negative): ";
            cin >> price;
        } while (price < 0);

        // Stock input with positive check
        do
        {
            cout << "Enter product stock (positive): ";
            cin >> stock;
        } while (stock <= 0);

        // Brand input with length check
        do
        {
            cout << "Enter product brand (minimum 2 characters): ";
            cin.ignore();
            getline(cin, brand);
        } while (brand.length() < 2);

        // Create a Product object with the entered information
        Product newProduct(name, description, category, price, stock, brand, 0, {}, currentUser, 0.0);

        // Attempt to add the product to the user's map
        if (currentUser->addProductToUserMap(newProduct.getID(), newProduct.getStock()))
        {
            // User's map was updated successfully, now add the product to the AVL
            categoryAVL[newProduct.getCategoryIndex()].insert(newProduct);
            cout << "\nProduct added successfully!\n";
        }
        else
        {
            // Product addition failed, display a message
            cout << "\nProduct addition failed. Product with the same ID already exists.\n";
        }
    }

public:
    OnlineMarketplace()
    {
        unordered_map<int, int> userProductsMap;
        unordered_map<int, int> boughtProductsMap;
        unordered_map<int, int> soldProductsMap;
        readUsersFromFile("Users.txt");
        readProductsFromFile("products.txt");
    }
    void readProductsFromFile(const string &filename)
    {
        ifstream infile(filename, ios::in);
        if (infile.is_open())
        {
            int id, stock, ratingcount, numReviews;
            double rating;
            string name, description, category, brand, sellerGmail;
            double price;
            stringstream s;
            string temp;
            while (!infile.eof())
            {
                cout << "Attributes read from product file: " << endl;
                getline(infile, temp);
                stringstream(temp) >> id; // Ignore newline character
                getline(infile, name);
                getline(infile, description);
                getline(infile, category);
                getline(infile, temp);
                stringstream(temp) >> price;
                getline(infile, temp);
                stringstream(temp) >> stock; // Ignore newline character
                getline(infile, brand);
                getline(infile, sellerGmail);
                getline(infile, temp);
                stringstream(temp) >> rating;
                getline(infile, temp);
                stringstream(temp) >> ratingcount;
                getline(infile, temp);
                stringstream(temp) >> numReviews; // Ignore newline character
                                                  // Read and store reviews
                vector<string> reviews;
                for (int i = 0; i < numReviews; ++i)
                {
                    string review;
                    getline(infile, review);
                    reviews.push_back(review);
                }

                int categoryIndex = getCategoryIndex(category);
                // Assuming addProduct function is defined elsewhere
                addProduct(Product(id, name, description, category, price, stock, brand, ratingcount, reviews, getUserByEmail(sellerGmail), rating));
            }

            infile.close();
            cout << "Products read from file: " << filename << endl;
        }
        else
        {
            cout << "Error: Unable to open file: " << filename << endl;
        }
    }

    User *getUserByEmail(const string &email)
    {
        auto it = user.find(email);
        if (it != user.end())
        {
            return &(it->second);
        }
        return nullptr; // Return nullptr if user with the given email is not found
    }
    void writeUsersToFile()
    {
        string filename = "Users.txt";
        ofstream file(filename, ios::out);
        for (const auto &u : user)
        {
            u.second.writeToFile(file); // Assuming your user data is stored in a map named 'users'
        }
        cout << "written ho gya";
        file.close();
    }
    void readUsersFromFile(const string &filename)
    {
        ifstream inFile(filename, ios::in);
        if (inFile.is_open())
        {
            while (!inFile.eof())
            {
                User newUser;
                newUser.readFromFile(inFile);
                addUser(newUser); // Assuming you have a function to add a user to your 'user' map
            }
            inFile.close();
            cout << "Read operation completed.\n";
        }
        else
        {
            cerr << "Error: Unable to open file for reading: " << filename << "\n";
        }
    }

    ~OnlineMarketplace()
    {
        writeUsersToFile();
        saveProductsToFile();
    }
    void saveProductsToFile()
    {
        string filename = "Products.txt";
        writeProductsToFile(filename);
    }

    void traverseAndWriteProductsToFile(Node *root, ofstream &file)
    {
        if (root)
        {
            traverseAndWriteProductsToFile(root->left, file);

            // Write product information to the file
            Product product = root->data;
            file << product.getID() << endl;
            file << product.getName() << endl;
            file << product.getDescription() << endl;
            file << product.getCategory() << endl;
            file << product.getPrice() << endl;
            file << product.getStock() << endl;
            file << product.getBrand() << endl;
            file << product.getSeller()->getGmail() << endl;
            file << product.getCustomerRatings() << endl;
            // Add additional properties to the file
            file << product.getRatingCount() << endl;

            const vector<string> &reviews = product.getReviews();
            file << reviews.size() << endl; // Write the number of reviews
            for (const string &review : reviews)
            {
                file << review << endl; // Write each review
            }

            traverseAndWriteProductsToFile(root->right, file);
        }
    }

    void writeProductsToFile(const string &filename)
    {
        ofstream file(filename, ios::out);
        if (file.is_open())
        {
            // Loop through each AVL tree in the array
            for (int i = 0; i < 5; ++i)
            {
                traverseAndWriteProductsToFile(categoryAVL[i].getRoot(), file);
            }
            file.close();
            cout << "Products written to file: " << filename << endl;
        }
        else
        {
            cout << "Error: Unable to open file: " << filename << endl;
        }
    }

    void display()
    {
        MaxHeap maxHeap;
        // Iterate through each category AVL tree
        for (int i = 0; i < 5; ++i)
        {
            auto categoryTree = categoryAVL[i].getRoot();
            // Use an in-order traversal to insert products into the max heap
            inOrderTraversalForDisplay(categoryTree, maxHeap);
        }

        maxHeap.display();
    }

    int MarketingStart()
    {
        int op = 1;
        bool flag = false;
        while (1)
        {
            system("cls");
            Khubsurti("HOME PAGE");

            if (currentUser)
            {
                cout << "\t      [5]  PROFILE ";
            }
            else
            {
                cout << "\t\t      [1]  LOGIN ";
                cout << "\n\t\t      [2]  SIGN UP \n";
            }
            cout << "\t\t      [3]  SEARCH \n";
            cout << "\t\t      [0]  EXIT\n\n";
            display();
            cout << "\t\t      [4]  BUY PRODUCT\n";
            if (flag)
                cout << "\n\tPlease Choose Correctly\n\n";
            cout << "Enter your choice here : ";
            cin >> op;
            if (op == 0)
                break;
            else if (op == 1 && currentUser == NULL)
            {
                flag = false;
                login();
            }
            else if (op == 2 && currentUser == NULL)
            {
                flag = false;

                signUp();
            }
            else if (op == 3)
            {
                flag = false;
                search();
            }
            else if (op == 4)
            {
                flag = false;
                productDetail();
            }
            else if (op == 5 && currentUser != NULL)
            {
                flag = false;
                profile();
            }
            else
            {
                flag = true;
            }
        }
        return 0;
    }
    int login()
    {
        string gmail, password;
        while (true)
        {
            system("cls");
            Khubsurti("LOGIN PAGE");
            cout << "\t\t FOR EXIT PRESS [0] \n\n";
            cout << "\nEnter YOUR GMAIL : ";
            cin >> gmail;
            if (gmail[0] == '0')
                return 0;

            for (auto &c : gmail)
            {
                c = tolower(c);
            }

            auto userIt = user.find(gmail);
            if (userIt != user.end())
            {
                cout << "\nEnter YOUR PASSWORD : ";
                password = getPassword();
                password = hashPassword(password); // Hash the entered password

                if (userIt->second.checkPassword(password))
                {
                    cout << "\n\t\t LOGIN SUCCESSFUL\n";
                    sleep(1);
                    cout << "\n\t\t WELCOME MR. " << userIt->second.getName();
                    sleep(1);
                    currentUser = &(userIt->second);
                    return 0;
                }
                else
                {
                    cout << "\n\t\tPLEASE ENTER CORRECT PASSWORD\n";
                    sleep(1);
                }
            }
            else
            {
                cout << "\n\t\tPLEASE ENTER CORRECT GMAIL FOR LOGIN \n";
                sleep(1);
            }
        }
        return 0;
    }

    int signUp()
    {
        string name;
        string gmail;
        string password;
        string account_num;
        double balance;
        unordered_map<int, int> userProductsMap;
        unordered_map<int, int> boughtProductsMap;
        unordered_map<int, int> soldProductsMap;

        system("cls");
        Khubsurti("SIGN UP PAGE");
        printf("\t\t FOR EXIT PRESS [0] \n\n");
        cout << "ENTER YOUR NAME = ";
        getline(cin, name);
        if (name[0] == '0')
            return 0;

        cout << "ENTER YOUR GMAIL ID = ";
        cin >> gmail;
        if (gmail == "0")
            return 0;

        for (auto &c : gmail)
        {
            c = tolower(c);
        }
        gmail = checkgmail(gmail);

        cout << "ENTER YOUR PASSWORD = ";
        cin >> password;
        password = checkpassword(password, name);
        password = hashPassword(password);
        cout << "ENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
        cin >> account_num;
        if (account_num == "0")
            return 0;
        account_num = checkaccountnum(account_num);

        cout << "ENTER YOUR BALANCE = ";
        cin >> balance;
        balance = checkamount(balance);

        user[gmail] = User(name, gmail, password, Account(account_num, balance), userProductsMap, boughtProductsMap, soldProductsMap);

        cout << "\n\t\t SIGNED UP SUCCESSFULLY\n";
        sleep(1);
        return 0;
    }

    void productDetail()
    {
        int id;
        cout << "\tENTER PRODUCT ID FOR MOR DETAILS : ";
        cin >> id;
        if (id == 0)
            return;
        Node *currPro = findProductById(id);

        if (currPro)
        {
            int op = 1;
            bool flag = false;

            while (1)
            {
                system("cls");
                Khubsurti("BUYER PAGE");
                cout << "\t\t      [1]  BUY \n";
                cout << "\t\t      [2] SET RATING \n";
                cout << "\t\t      [3] ADD REVIEW \n";
                cout << "\t\t      [0]  EXIT \n";
                currPro->data.fullDisplay();

                if (flag)
                    cout << "\n\tPlease Choose Correctly\n\n";
                cout << "Enter your choice here : ";
                scanf("%d", &op);
                if (op == 0)
                    break;
                else if (op == 1)
                {
                    flag = false;
                    if (currentUser)
                    {
                        string acc;
                        cout << "\nENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
                        cin >> acc;
                        if (acc == "0")
                            break;
                        acc = checkaccount_num(acc);
                        int q;
                        cout << "\nHOW MANY YOU WAT TO BUY = ";
                        cin >> q;
                        while (q < 0)
                        {
                            cout << "\nQUANTITY HAVE TO BE MORE THAN ZERO  = ";
                            cout << "\nPLEASE ENTER AGAIN = ";
                            cin >> q;
                        }

                        buyProduct(&currPro->data, acc, q);
                        break;
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else if (op == 2)
                {
                    if (currentUser)
                    {
                        flag = false;
                        setProductRating(&currPro->data);
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else if (op == 3)
                {
                    if (currentUser)
                    {
                        flag = false;
                        addProductReview(&currPro->data);
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else
                {
                    flag = true;
                }
            }
        }
        else
        {
            cout << "Product with ID " << id << " not found." << endl;
        }
    }
    void setProductRating(Product *currPro)
    {
        double rating;
        cout << "Enter the new rating for the product: ";
        cin >> rating;
        currPro->setCustomerRatings(rating);
        cout << "Rating set successfully." << endl;
        sleep(1);
    }

    void addProductReview(Product *currPro)
    {
        string review;
        cout << "Enter your review for the product: ";
        cin.ignore(); // Ignore any previous newline character in the buffer
        getline(cin, review);
        currPro->addReview(review);
        cout << "Review added successfully." << endl;
        sleep(1);
    }
    void productDetailforSearch(MaxHeap &maxheap)
    {
        int id;
        cout << "\tENTER PRODUCT ID FOR MOR DETAILS : ";
        cin >> id;
        if (id == 0)
            return;
        Product *Pro = maxheap.findProductById(id);

        if (Pro)
        {
            int op = 1;
            bool flag = false;

            while (1)
            {
                system("cls");
                Khubsurti("BUYER PAGE");
                cout << "\t\t      [1]  BUY \n";
                cout << "\t\t      [0]  EXIT \n";
                Pro->fullDisplay();

                if (flag)
                    cout << "\n\tPlease Choose Correctly\n\n";
                cout << "Enter your choice here : ";
                scanf("%d", &op);
                if (op == 0)
                    break;
                else if (op == 1)
                {
                    flag = false;
                    if (currentUser)
                    {
                        string acc;
                        cout << "\nENTER YOUR ACCOUNT NUMBER [0000-0000-0000-0000] = ";
                        cin >> acc;
                        if (acc == "0")
                            break;
                        acc = checkaccount_num(acc);
                        int q;
                        cout << "\nHOW MANY YOU WAT TO BUY = ";
                        cin >> q;
                        while (q < 0)
                        {
                            cout << "\nQUANTITY HAVE TO BE MORE THAN ZERO  = ";
                            cout << "\nPLEASE ENTER AGAIN = ";
                            cin >> q;
                        }

                        buyProduct(Pro, acc, q);
                        break;
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else if (op == 2)
                {
                    if (currentUser)
                    {
                        flag = false;
                        setProductRating(Pro);
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else if (op == 3)
                {
                    if (currentUser)
                    {
                        flag = false;
                        addProductReview(Pro);
                    }
                    else
                    {
                        if (!SigninFirst())
                        {
                            return;
                        }
                    }
                }
                else
                {
                    flag = true;
                }
            }
        }
        else
        {
            cout << "Product with ID " << id << " not found." << endl;
            sleep(1);
        }
    }
    bool SigninFirst()
    {
        int op = 1;
        bool flag = false;
        while (1)
        {
            system("cls");
            Khubsurti("SIGN IN PAGE");
            cout << "\t   PLEASE SIGNIN FIRST TO BUY THE PRODUCT \n";
            cout << "\t\t      [1]  LOGIN \n";
            cout << "\t\t      [2]  SIGN UP \n";
            cout << "\t\t      [0]  EXIT\n\n";
            if (flag)
                cout << "\n\tPlease Choose Correctly\n\n";
            cout << "Enter your choice here : ";
            cin >> op;
            if (op == 0)
                return false;
            else if (op == 1)
            {
                flag = false;
                login();
                if (currentUser)
                {
                    return true;
                }
                return false;
            }
            else if (op == 2)
            {
                flag = false;
                signUp();
                login();
                if (currentUser)
                {
                    return true;
                }
                else
                    return false;
            }
            else
            {
                flag = true;
            }
        }
    }
    void search()
    {
        int op = 1;
        bool flag = false;
        while (1)
        {
            system("cls");
            Khubsurti("SEARCH PAGE");

            cout << "\t\t      [1]  SEARCH BY CATEGORY \n";
            cout << "\t\t      [2]  SEARCH BY NAME \n";
            cout << "\t\t      [0]  EXIT\n\n";
            if (flag)
                cout << "\n\tPlease Choose Correctly\n\n";
            cout << "Enter your choice here : ";
            cin >> op;
            if (op == 0)
                break;
            else if (op == 1)
            {
                flag = false;
                searchByCategory();
            }
            else if (op == 2)
            {
                flag = false;
                searchByName();
            }
            else
            {
                flag = true;
            }
        }
        return;
    }
    searchByCategory()
    {
        int op;
        bool flag = false;

        while (1)
        {
            system("cls");
            Khubsurti("SEARCH BY CATEGORY PAGE");

            // Display category options
            cout << "\t\t      [1]  Electronics \n";
            cout << "\t\t      [2]  Clothing \n";
            cout << "\t\t      [3]  Books \n";
            cout << "\t\t      [4]  Home Appliances \n";
            cout << "\t\t      [5]  Sports Equipment \n";
            cout << "\t\t      [0]  EXIT\n\n";

            if (flag)
                cout << "\n\tPlease Choose Correctly\n\n";

            cout << "Enter your choice here : ";
            cin >> op;

            if (op == 0)
                break;
            else if (op >= 1 && op <= 5)
            {
                flag = false;

                // Get the root of the AVL tree corresponding to the selected category
                auto categoryTree = categoryAVL[op - 1].getRoot();

                // Perform in-order traversal for display
                MaxHeap maxHeap;
                inOrderTraversalForDisplay(categoryTree, maxHeap);

                // Display the products in the selected category
                maxHeap.display();
                productDetailforSearch(maxHeap);
            }
            else
            {
                flag = true;
            }
        }
    }
    void searchByName()
    {
        string searchName;
        bool flag = false;

        while (1)
        {
            system("cls");
            Khubsurti("SEARCH BY NAME PAGE");

            cout << "\tEnter the name to search (Enter 0 to exit): ";
            //  cin.ignore();  // Ignore the newline character from previous input
            getline(cin, searchName);

            if (searchName == "0")
                break;

            // Convert the search name to lowercase for case-insensitive comparison
            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

            MaxHeap searchResults;

            // Iterate through each category AVL tree
            for (int i = 0; i < 5; ++i)
            {
                auto categoryTree = categoryAVL[i].getRoot();
                searchByNameInCategory(categoryTree, searchName, searchResults);
            }

            if (!searchResults.isEmpty())
            {
                cout << "Products with the name '" << searchName << "':" << endl;
                searchResults.display();
                productDetailforSearch(searchResults);
            }
            else
            {
                cout << "No products found with the name: " << searchName << endl;
                sleep(2);
            }
        }
    }

    void searchByNameInCategory(Node *root, const string &searchName, MaxHeap &searchResults)
    {
        if (root)
        {
            searchByNameInCategory(root->left, searchName, searchResults);

            // Convert the product name to lowercase for case-insensitive comparison
            string productNameLower = root->data.getName();
            transform(productNameLower.begin(), productNameLower.end(), productNameLower.begin(), ::tolower);

            // Check if the product name contains the search string
            if (productNameLower.find(searchName) != string::npos)
            {
                searchResults.insert(root->data);
            }

            searchByNameInCategory(root->right, searchName, searchResults);
        }
    }
    int profile()
    {
        int ch = 0;
        while (1)
        {
            system("cls");
            fflush(stdin);
            Khubsurti("USER PROFILE");
            cout << "\t\t      [1] MY  ACCOUNT \n";
            cout << "\t\t      [2] My PRODUCT\n";
            cout << "\t\t      [3] SOLD PRODUCT\n";
            cout << "\t\t      [4] PURCHASED PRODUCT\n";
            cout << "\t\t      [5] ADD PRODUCT\n";
            cout << "\t\t      [0] EXIT\n\n";
            if (ch > 4 || ch < 0)
                cout << "\n\tPlease Choose Correctly\n\n";
            fflush(stdin);
            cout << "Enter your choice here : ";
            scanf("%d", &ch);
            if (ch == 0)
                break;
            else if (ch == 1)
                UserAccount();
            else if (ch == 2)
                showUserProducts();
            else if (ch == 3)
                showSoldProducts();
            else if (ch == 4)
                showBoughtProducts();
            else if (ch == 5)
                addProductToAVL();
            else
                continue;
        }

        return 0;
    }
    int UserAccount()
    {
        int ch = 0;
        while (1)
        {
            system("cls");
            fflush(stdin);
            Khubsurti("ACCOUNT MENU");
            cout << "\t\t      [1] DEPOSITE \n";
            cout << "\t\t      [2] WITHDRAWL\n";
            cout << "\t\t      [0] EXIT\n\n";
            if (ch > 2 || ch < 0)
                cout << "\n\tPlease Choose Correctly\n\n";
            fflush(stdin);
            cout << "Enter your choice here : ";
            scanf("%d", &ch);
            if (ch == 0)
                break;
            if (ch == 1)
            {
                string acc;
                double amount;
                cout << "Enter Your Account Number : ";
                cin >> acc;
                acc = checkaccount_num(acc);
                cout << "Enter Amount You want to Deposite : ";
                cin >> amount;
                amount = checkamount(amount);
                currentUser->deposite(acc, amount);
            }
            if (ch == 2)
            {
                string acc;
                double amount;
                cout << "Enter Your Account Number : ";
                cin >> acc;
                acc = checkaccount_num(acc);
                cout << "Enter Amount You want to Withdrawl : ";
                cin >> amount;
                amount = checkamount(amount);
                currentUser->withdrawl(acc, amount);
            }
        }

        return 0;
    }
    void showSoldProducts()
    {
        const string &userEmail = currentUser->getGmail();
        auto it = user.find(userEmail);

        if (it != user.end())
        {
            // User found, display sold products
            it->second.displaySoldProducts();
        }
        else
        {
            // User not found
            cout << "User with email " << userEmail << " not found.\n";
        }
    }
    void showBoughtProducts()
    {
        const string &userEmail = currentUser->getGmail();
        auto it = user.find(userEmail);

        if (it != user.end())
        {
            // User found, display bought products
            it->second.displayboughtProducts();
        }
        else
        {
            // User not found
            cout << "User with email " << userEmail << " not found.\n";
        }
    }
    void showUserProducts()
    {
        const string &userEmail = currentUser->getGmail();
        auto it = user.find(userEmail);

        if (it != user.end())
        {
            // User found, display user products
            it->second.displayUserProducts();
        }
        else
        {
            // User not found
            cout << "User with email " << userEmail << " not found.\n";
        }
    }
};

int main()
{
    OnlineMarketplace marketplace;
    marketplace.MarketingStart();
}
