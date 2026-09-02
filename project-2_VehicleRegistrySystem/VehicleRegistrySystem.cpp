#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Vehicle
{
public:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    Vehicle(int vid, string manuf, string modelName, int yr)
    {
        vehicleID = vid;
        manufacturer = manuf;
        model = modelName;
        year = yr;
    }

    virtual ~Vehicle() {}

    virtual void display()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
public:
    string fuelType;

    Car(int vid, string manuf, string modelName, int yr, string fuelt)
        : Vehicle(vid, manuf, modelName, yr)
    {
        fuelType = fuelt;
    }

    void display() override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
public:
    string batteryCapacity;

    ElectricCar(int vid, string manuf, string modelName, int yr, string fuelt, string battryc)
        : Car(vid, manuf, modelName, yr, fuelt)
    {
        batteryCapacity = battryc;
    }

    void display() override
    {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << endl;
    }
};

class Aircraft : public Car
{
public:
    int flightRange;

    Aircraft(int vid, string manuf, string modelName, int yr, string fuelt, int flightr)
        : Car(vid, manuf, modelName, yr, fuelt)
    {
        flightRange = flightr;
    }

    void display() override
    {
        Car::display();
        cout << "Flight Range: " << flightRange << endl;
    }
};

class FlyingCar : public Aircraft
{
public:
    FlyingCar(int vid, string manuf, string modelName, int yr, string fuelt, int flightr)
        : Aircraft(vid, manuf, modelName, yr, fuelt, flightr)
    {
    }

    void display() override
    {
        Aircraft::display();
    }
};

class SportsCar : public ElectricCar
{
public:
    int topSpeed;

    SportsCar(int vid, string manuf, string modelName, int yr, string fuelt, string battryc, int tops)
        : ElectricCar(vid, manuf, modelName, yr, fuelt, battryc)
    {
        topSpeed = tops;
    }

    void display() override
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int vid, string manuf, string modelName, int yr, string fuelt)
        : Car(vid, manuf, modelName, yr, fuelt)
    {
    }

    void display() override
    {
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int vid, string manuf, string modelName, int yr, string fuelt)
        : Car(vid, manuf, modelName, yr, fuelt)
    {
    }

    void display() override
    {
        Car::display();
    }
};

class VehicleRegistry
{
public:
    Vehicle* vehicles[100];
    int count;

    VehicleRegistry()
    {
        count = 0;
        for (int i = 0; i < 100; i++)
            vehicles[i] = nullptr;
    }

    void addingvehicles()
    {
        if (count >= 100)
        {
            cout << "Vehicle limit reached. Cannot add more vehicles." << endl;
            return;
        }

        int choices, vid, year;
        string manuf, model, fuelt, battryc;

        cout << "\n------select vehicle type-----" << endl;
        cout << "1. ElectricCar" << endl;
        cout << "2. FlyingCar" << endl;
        cout << "3. Aircraft" << endl;
        cout << "4. SportsCar" << endl;
        cout << "5. Sedan" << endl;
        cout << "6. SUV" << endl;
        cout << "7. Car" << endl;
        cout << "Enter vehicle type : ";
        cin >> choices;

        cout << "Enter Vehicle id : ";
        cin >> vid;
        cout << "Enter Vehicle manufacturer : ";
        cin >> manuf;
        cout << "Enter Vehicle model : ";
        cin >> model;
        cout << "Enter Vehicle year : ";
        cin >> year;
        cout << "Enter Vehicle fuelType : ";
        cin >> fuelt;

        switch (choices)
        {
        case 1:
            cout << "Enter Vehicle batteryCapacity : ";
            cin >> battryc;
            vehicles[count] = new ElectricCar(vid, manuf, model, year, fuelt, battryc);
            break;

        case 2:
        {
            int flightr;
            cout << "Enter Vehicle flightRange : ";
            cin >> flightr;
            vehicles[count] = new FlyingCar(vid, manuf, model, year, fuelt, flightr);
            break;
        }
        case 3:
        {
            int flightr;
            cout << "Enter Vehicle flightRange : ";
            cin >> flightr;
            vehicles[count] = new Aircraft(vid, manuf, model, year, fuelt, flightr);
            break;
        }
        case 4:
            cout << "Enter Vehicle batteryCapacity : ";
            cin >> battryc;
            cout << "Enter Vehicle topSpeed : ";
            int tops;
            cin >> tops;
            vehicles[count] = new SportsCar(vid, manuf, model, year, fuelt, battryc, tops);
            break;

        case 5:
            vehicles[count] = new Sedan(vid, manuf, model, year, fuelt);
            break;

        case 6:
            vehicles[count] = new SUV(vid, manuf, model, year, fuelt);
            break;

        case 7:
            vehicles[count] = new Car(vid, manuf, model, year, fuelt);
            break;

        default:
            cout << "Invalid type." << endl;
            return;
        }

        Vehicle::totalVehicles = count + 1;
        count++;
        cout << "Vehicle added successfully." << endl;
    }

    void displayingvehicles()
    {
        if (count == 0)
        {
            cout << "No vehicles added yet." << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n---- Vehicle " << i + 1 << " ----" << endl;
            vehicles[i]->display();
        }
    }

    void searchingvehicles()
    {
        if (count == 0)
        {
            cout << "No vehicles added yet." << endl;
            return;
        }

        int searchId;
        cout << "Enter vehicle id to search : ";
        cin >> searchId;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->vehicleID == searchId)
            {
                vehicles[i]->display();
                return;
            }
        }

        cout << "Vehicle not found." << endl;
    }
};

int main()
{
    VehicleRegistry v;

    while (true)
    {
        cout << "\n---------vehicle menu--------" << endl;
        cout << "1. Add a vehicle" << endl;
        cout << "2. View all vehicles" << endl;
        cout << "3. Search by Id" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice : ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            v.addingvehicles();
            break;
        case 2:
            v.displayingvehicles();
            break;
        case 3:
            v.searchingvehicles();
            break;
        case 4:
            exit(0);
        default:
            cout << "invalid choice" << endl;
        }
    }

    return 0;
}