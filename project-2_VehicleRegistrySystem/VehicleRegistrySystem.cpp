#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// -------------------------- class Vehical ----------------------------------------//

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
        this->vehicleID;
        this->manufacturer;
        this->model;
        this->year;
        totalVehicles++;
    }
    Vehicle(int vid,string manuf,string model,int year){
        this->vehicleID=vid;
        this->manufacturer=manuf;
        this->model=model;
        this->year=year;
    }

    ~Vehicle()
    {
        cout << "remove object ";
    }

    void inputVehicle(int vid,string manuf,string model,int year)
    {   
        this->vehicleID=vid;
        this->manufacturer=manuf;
        this->model=model;
        this->year=year;
        
    }

    void displayVehical()
    {
    }
};

// -------------------------- class Car ---------------------------------------------//

class Car : public Vehicle
{
public:
    string fuelType;
    Car(int vid,string manuf,string model,int year,string fuelt):Vehicle(vid,manuf,model,year){
        this->fuelType=fuelt;
    }
    
};

//  class ElectricCar -------------------------------------//

class ElectricCar : public Car
{
public:
    string batteryCapacity;
    ElectricCar(int vid,string manuf,string model,int year,string fuelt,string battryc):Car(vid,manuf,model,year,fuelt){
        this->batteryCapacity=battryc;
    }
};

// -------------------------- class Aircraft ---------------------------------------//

class Aircraft : public Vehicle
{
public:
    int flightRange;
    Aircraft(int vid,string manuf,string model,int year,int flightr):Vehicle(vid,manuf,model,year){
        this->flightRange=flightr;
    }
};

// -------------------------- class FlyingCar -------------------------------------//

class FlyingCar : public Car, public Aircraft
{
    FlyingCar(int vid,string manuf,string model,int year,string fuelt,int flightr):Car(vid,manuf,model,year,fuelt),Aircraft(vid,manuf,model,year,flightr){

    }
};

// -------------------------- class SportCar --------------------------------------//

class SportsCar : public ElectricCar
{
public:
    int topSpeed;
    SportsCar(int vid,string manuf,string model,int year,string fuelt,string battryc,int tops):ElectricCar( vid, manuf, model, year, fuelt,battryc){

    }

};

// -------------------------- class Sedan ----------------------------------------//

class Sedan : public Car
{
public:
    Sedan(int vid,string manuf,string model,int year,string fuelt):Car(vid,manuf,model,year,fuelt){

    }
};

// -------------------------- class SUV    ---------------------------------------//

class SUV : public Car
{
public:
    SUV(int vid,string manuf,string model,int year,string fuelt):Car(vid,manuf,model,year,fuelt){

    }
};

// -------------------------  VehicleRegistry Class -------------------------------//

class VehicleRegistry
{
public:
    Vehicle Vehival[100];

    void addingvehicles()
    {
        this->Vehival[Vehicle::totalVehicles].
    }

    void displayingvehicles()
    {
    }

    void searchingvehicles()
    {

    }
};

int Vehicle::totalVehicles = 0;

int main()
{
     VehicleRegistry v;
    while (1)
    {
        int choice;
        int vid, year;
        string manuf, model, fuelt, battryc;

        cout << endl;
        cout << "---------vehicle menu--------" << endl;
        cout << "1.Add a vehicle  " << endl;
        cout << "2.View all vehicles  " << endl;
        cout << "3.Search by Id" << endl;
        cout << "4.Exit " << endl;

        cout << "\n"
             << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int choices;
            
            cout << "\n" << "------select vehicle type-----" << endl;
            cout << "1.ElectricCar" << endl;
            cout << "2.FlayingCar" << endl;
            cout << "3.SportCar" << endl;
            cout << "4.SedanCar" << endl;
            cout << "5.SuvCar" << endl;
            cout << "\n"
                 << " Enter vehicle type :";
            cin >> choices;


            switch(choices)
            {
            case 1:
                cout << "Enter Vehicle id :";
                cin >> vid;
                cout << "Enter Vehicle manufacturer:";
                cin >> manuf;
                cout << "Enter Vehicle model :";
                cin >> model;
                cout << "Enter Vehicle year :";
                cin >> year;
                cout << "Enter Fueltype : ";
                cin >> fuelt;
                cout << "Enter Battrycapacity : ";
                cin >> battryc;

                
                v.addingvehicles(vid,manuf,model,year,fuelt,battryc);
                break;
            
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            
            default:
                cout << "invalid type";
                break;
            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice ";
            break;
        }
    }

    return 0;
}