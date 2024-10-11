// Lab 12 - Anthony Sarabia
// COMSC-210 | Lab 20 | Anthony Sarabia
// IDE used: Visual Studio

#include <iostream>
#include <iomanip>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Constants
const int SIZE = 3;      // Size of the prices array
const int MIN = 10000;   // Minimum price in cents ($100.00)
const int MAX = 99999;   // Maximum price in cents ($999.99)

/**
 * Chair() initializes a Chair object with random legs and prices.
 * Arguments: None
 * Returns: A Chair object with randomly assigned legs and prices.
 */
class Chair {
private:
    int legs;           // Number of legs on the chair
    double* prices;     // Dynamic array to store price history

public:
    // Default Constructor: Initializes chair with random legs and random prices between $100.00 - $999.99
    Chair() {
        prices = new double[SIZE]; // Allocate memory for prices
        legs = (rand() % 2) + 3;   // Randomly assign 3 or 4 legs

        // Assign random prices between $100.00 and $999.99
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }

    /**
     * Chair(int, const int[]) initializes a Chair with specified legs and prices.
     * Arguments:
     *   - int l: Number of legs
     *   - const int p[SIZE]: Array of prices in cents
     * Returns: A Chair object with specified legs and prices.
     */
    Chair(int l, const int p[SIZE]) {
        prices = new double[SIZE]; // Allocate memory for prices
        legs = l;                  // Set number of legs

        // Assign provided prices (assuming prices are in cents)
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i]; // Consider converting cents to dollars if needed
    }

    // Destructor: Cleans up dynamic memory to prevent memory leaks
    ~Chair() {
        delete[] prices;
    }

    /**
     * setLegs(int) sets the number of legs for the chair with validation.
     * Arguments:
     *   - int l: Number of legs to set
     * Returns: void
     */
    void setLegs(int l) {
        if (l >= 3 && l <= 4) {
            legs = l;
        }
        else {
            cout << "INVALID" << endl;
        }
    }

    /**
     * getLegs() retrieves the number of legs on the chair.
     * Arguments: None
     * Returns: int representing the number of legs.
     */
    int getLegs() {
        return legs;
    }

    /**
     * setPrices(double, double, double) sets the price history of the chair.
     * Arguments:
     *   - double p1: First price
     *   - double p2: Second price
     *   - double p3: Third price
     * Returns: void
     */
    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    /**
     * getAveragePrices() calculates the average price of the chair.
     * Arguments: None
     * Returns: double representing the average price.
     */
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    /**
     * print() displays the chair's data, including legs and price history.
     * Arguments: None
     * Returns: void
     */
    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << "$" << fixed << setprecision(2) << prices[i] << " ";
        cout << endl << "Historical avg price: $" << fixed << setprecision(2) << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    // Seed the random number generator for randomness
    srand(static_cast<unsigned>(time(0)));
    cout << fixed << setprecision(2);

    // Creating a Chair object using the default constructor
    Chair* chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;

    // Creating a Chair object using the parameterized constructor
    int prices[SIZE] = { 27734, 93284, 14292 }; // Prices in cents
    Chair* newChair = new Chair(3, prices);
    newChair->print();
    delete newChair;

    // Creating a dynamic array of Chair objects using default constructors
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }
    // Clean up to avoid memory leaks
    delete[] collection;

    return 0;
}
