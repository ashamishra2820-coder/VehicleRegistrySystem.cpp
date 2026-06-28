#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle(int id,string man,string mod,int y)
    {
        vehicleID=id;
        manufacturer=man;
        model=mod;
        year=y;
        totalVehicles++;
    }

    virtual ~Vehicle(){}

    void setID(int id)
    {
        vehicleID=id;
    }

    void setManufacturer(string man)
    {
        manufacturer=man;
    }

    void setModel(string mod)
    {
        model=mod;
    }

    void setYear(int y)
    {
        year=y;
    }

    int getID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    virtual void display()
    {
        cout<<"Vehicle ID : "<<vehicleID<<endl;
        cout<<"Manufacturer : "<<manufacturer<<endl;
        cout<<"Model : "<<model<<endl;
        cout<<"Year : "<<year<<endl;
    }
};

int Vehicle::totalVehicles=0;


// Single Inheritance

class Car:public Vehicle
{
protected:
    string fuel;

public:

    Car(int id,string man,string mod,int y,string f)
    :Vehicle(id,man,mod,y)
    {
        fuel=f;
    }

    void display()
    {
        Vehicle::display();
        cout<<"Fuel Type : "<<fuel<<endl;
    }
};


// Multilevel Inheritance

class ElectricCar:public Car
{
private:
    int battery;

public:

    ElectricCar(int id,string man,string mod,int y,string f,int b)
    :Car(id,man,mod,y,f)
    {
        battery=b;
    }

    void display()
    {
        Car::display();
        cout<<"Battery : "<<battery<<" kWh"<<endl;
    }
};


// Another Base Class

class Aircraft:public Vehicle
{
private:
    int range;

public:

    Aircraft(int id,string man,string mod,int y,int r)
    :Vehicle(id,man,mod,y)
    {
        range=r;
    }

    void display()
    {
        Vehicle::display();
        cout<<"Range : "<<range<<" km"<<endl;
    }
};


// Multiple Inheritance

class FlyingCar:public Car,public Aircraft
{
public:

    FlyingCar(int id,string man,string mod,int y,string f,int r)
    :Car(id,man,mod,y,f),
    Aircraft(id,man,mod,y,r)
    {

    }

    void display()
    {
        cout<<"Flying Car"<<endl;
        Car::display();
    }
};


// Hierarchical Inheritance

class SUV:public Car
{
public:

    SUV(int id,string man,string mod,int y,string f)
    :Car(id,man,mod,y,f)
    {

    }

    void display()
    {
        cout<<"SUV Details"<<endl;
        Car::display();
    }
};


class Sedan:public Car
{
public:

    Sedan(int id,string man,string mod,int y,string f)
    :Car(id,man,mod,y,f)
    {

    }

    void display()
    {
        cout<<"Sedan Details"<<endl;
        Car::display();
    }
};



// Registry Class

class VehicleRegistry
{
private:

    Vehicle* list[50];
    int count;

public:

    VehicleRegistry()
    {
        count=0;
    }


    void addVehicle(Vehicle* v)
    {
        list[count]=v;
        count++;

        cout<<"Vehicle Added Successfully"<<endl;
    }


    void showVehicles()
    {
        if(count==0)
        {
            cout<<"No Vehicle Available"<<endl;
        }

        for(int i=0;i<count;i++)
        {
            cout<<"\n-----------------\n";
            list[i]->display();
        }
    }


    void searchVehicle(int id)
    {
        for(int i=0;i<count;i++)
        {
            if(list[i]->getID()==id)
            {
                cout<<"Vehicle Found"<<endl;
                list[i]->display();
                return;
            }
        }

        cout<<"Vehicle Not Found"<<endl;
    }
};



int main()
{
    VehicleRegistry registry;

    int choice;


    do
    {
        cout<<"\n===== Vehicle Registry System ====="<<endl;
        cout<<"1. Add Vehicle"<<endl;
        cout<<"2. Display Vehicle"<<endl;
        cout<<"3. Search Vehicle"<<endl;
        cout<<"4. Total Vehicle"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter Choice : ";
        cin>>choice;


        if(choice==1)
        {
            int type,id,year,battery,range;
            string man,model,fuel;


            cout<<"1.Car"<<endl;
            cout<<"2.Electric Car"<<endl;
            cout<<"3.Aircraft"<<endl;
            cout<<"4.SUV"<<endl;

            cout<<"Enter Type : ";
            cin>>type;


            cout<<"ID : ";
            cin>>id;

            cout<<"Manufacturer : ";
            cin>>man;

            cout<<"Model : ";
            cin>>model;

            cout<<"Year : ";
            cin>>year;


            if(type==1)
            {
                cout<<"Fuel : ";
                cin>>fuel;

                registry.addVehicle(new Car(id,man,model,year,fuel));
            }


            else if(type==2)
            {
                cout<<"Fuel : ";
                cin>>fuel;

                cout<<"Battery : ";
                cin>>battery;

                registry.addVehicle(new ElectricCar(id,man,model,year,fuel,battery));
            }


            else if(type==3)
            {
                cout<<"Range : ";
                cin>>range;

                registry.addVehicle(new Aircraft(id,man,model,year,range));
            }


            else if(type==4)
            {
                cout<<"Fuel : ";
                cin>>fuel;

                registry.addVehicle(new SUV(id,man,model,year,fuel));
            }
        }


        else if(choice==2)
        {
            registry.showVehicles();
        }


        else if(choice==3)
        {
            int id;

            cout<<"Enter ID : ";
            cin>>id;

            registry.searchVehicle(id);
        }


        else if(choice==4)
        {
            cout<<"Total Vehicles : "
            <<Vehicle::totalVehicles<<endl;
        }


    }while(choice!=5);


    return 1;
}