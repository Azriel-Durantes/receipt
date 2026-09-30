#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    string customerName;
    string itemName;
    int quantity;
    double unitPrice;
    int score1, score2;

    // ---------------- Input ----------------
    cout << "Enter Customer Full Name : ";
    getline(cin, customerName);

    cout << "Enter Item Name          : ";
    getline(cin, itemName);

    cout << "Enter Item Quantity      : ";
    cin >> quantity;

    cout << "Enter Item Unit Price ($): ";
    cin >> unitPrice;

    

    // ---------------- Calculations ----------------
    // explicit cast on quantity before multiplying, so the intent is clear
    double subtotal = static_cast<double>(quantity) * unitPrice;

    // tax as an arithmetic expression, parentheses make precedence explicit
    double taxRate = 7.5 / 100.0;
    double tax     = subtotal * taxRate;
    double total   = subtotal + tax;

    // score1 + score2 would truncate under integer division;
    // static_cast forces true (double) division
    double average = static_cast<double>(score1 + score2) / 2;

    // ---------------- Layout ----------------
    const int colItem     = 25;
    const int colQty      = 10;
    const int colPrice    = 15;
    const int colTotal    = 15;
    const int tableWidth  = colItem + colQty + colPrice + colTotal;

    cout << fixed << setprecision(2);

    cout << endl;
    cout << string(tableWidth, '=') << endl;
    string title = "CUSTOMER SALES RECEIPT";
    int pad = (tableWidth - static_cast<int>(title.length())) / 2;
    cout << string(pad, ' ') << title << endl;
    cout << string(tableWidth, '=') << endl;

    cout << "Customer: " << customerName << endl;
    cout << string(tableWidth, '-') << endl;

    cout << left  << setw(colItem)  << "Item"
         << right << setw(colQty)   << "Qty"
         << right << setw(colPrice) << "Price"
         << right << setw(colTotal) << "Total" << endl;

    cout << left  << setw(colItem)  << itemName
         << right << setw(colQty)   << quantity
         << right << setw(colPrice) << unitPrice
         << right << setw(colTotal) << subtotal << endl;

    cout << string(tableWidth, '-') << endl;

    cout << left << setw(tableWidth - 10) << "Subtotal:"
         << right << "$" << setw(9) << subtotal << endl;

    cout << left << setw(tableWidth - 10) << "Tax (7.5%):"
         << right << "$" << setw(9) << tax << endl;

    cout << left << setw(tableWidth - 10) << "Total Amount Due:"
         << right << "$" << setw(9) << total << endl;

    cout << string(tableWidth, '-') << endl;

    return 0;
}
