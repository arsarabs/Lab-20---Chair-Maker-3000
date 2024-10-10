#include <iostream>
#include <iomanip>

using namespace std;

//Constants
const int SIZE = 3;
const int MIN = 10000;
const int MAX = 99999;

class Chair {
private:
    int legs;
    double* prices;
public:
    // Default Constructor: Intializes chair with random legs and random prices between $100 - $999
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) + 3;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }
    Chair(int l, const int p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }
    //Clean up dynamic memory (avoid memory leaks)
    ~Chair() {
        delete[] prices;
    }

    // setters (with validation) and getters
    void setLegs(int l) {
        if (l >= 3 && l <= 4) {
            legs = l;
        }
        else {
            cout << "INVALID" << endl;
        }
    }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; 
        prices[1] = p2; 
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    cout << fixed << setprecision(2);

    //chair with default constructor
    Chair* chairPtr = new Chair;
    chairPtr->print();
    delete chairPtr;

    //chair with parameterized constructor
    double prices[SIZE] = { 277.34, 932.84, 142.92 };
    Chair* newChair = new Chair(3, prices);
    newChair->print();
    delete newChair;

    


    //creating dynamic array of chair objects
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }
    delete[] collection;
   
    return 0;
}