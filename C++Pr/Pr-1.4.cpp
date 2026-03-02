#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    double speed;

public:

    Vehicle(string m, double s) {
        model = m;
        speed = s;
    }

    string getModel() {
        return model;
    }

    double getSpeed() {
        return speed;
    }

    virtual void displayDetails() {
        cout << "Vehicle Model: " << model << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(string m, double s, int doors)
        : Vehicle(m, s) {
        numberOfDoors = doors;
    }

    void displayDetails() override {
        cout << "\n--- Car Details ---\n";
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/h" << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasGear;

public:
    Bike(string m, double s, bool gear)
        : Vehicle(m, s) {
        hasGear = gear;
    }

    void displayDetails() override {
        cout << "\n--- Bike Details ---\n";
        cout << "Model: " << getModel() << endl;
        cout << "Speed: " << getSpeed() << " km/h" << endl;
        cout << "Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

int main() {

    Vehicle* vehicles[2];

    vehicles[0] = new Car("Honda City", 120, 4);
    vehicles[1] = new Bike("Yamaha R15", 90, true);

    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();  
    }

    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}

//output
//--- Car Details ---
//Model: Honda City
//Speed: 120 km/h
//Number of Doors: 4
//
//--- Bike Details ---
//Model: Yamaha R15
//Speed: 90 km/h
//Has Gear: Yes