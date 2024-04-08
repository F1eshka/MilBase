#include <iostream>
using namespace std;

class Base {
public:
    static int people_on_base;
    static int vehicles_on_base;
    static double petrol_on_base;
    static double goods_on_base;
};

int Base::people_on_base = 1000;
int Base::vehicles_on_base = 50;
double Base::petrol_on_base = 100000;
double Base::goods_on_base = 100;

class Vehicle {
protected:
    Base b;
    double petrol_amount;
    double tank_volume;
    bool leave;
public:
    Vehicle() {
        SetPetrolAmount(55);
        SetTankVolume(80);
    };

    Vehicle(double petrol_amount, double tank_volume) {
        SetPetrolAmount(petrol_amount);
        SetTankVolume(tank_volume);
    }

    void SetTankVolume(double tank_volume) {
        this->tank_volume = tank_volume;
    }

    void SetPetrolAmount(double petrol_amount) {
        this->petrol_amount = petrol_amount;
    }

    double GetTankVolume() const {
        return tank_volume;
    }

    double GetPetrolAmount() const {
        return petrol_amount;
    }

    void Arrive() {
        cout << "New person arrive\n";
        b.vehicles_on_base++;
        b.people_on_base += 1;
    }

    bool Leave() {
        if (petrol_amount < tank_volume) {
            double gasoline_shortage = tank_volume - petrol_amount;
            if (b.petrol_on_base >= gasoline_shortage) {
                b.petrol_on_base -= gasoline_shortage;
                petrol_amount += gasoline_shortage;
                b.people_on_base -= 1;
                b.vehicles_on_base--;
                cout << "Person is leave\n";
                return true;
            }
            else {
                cout << "Insufficient gasoline at the base. No movement possible. Find fuel!!!\n";
                return false;
            }
        }
        else {
            b.vehicles_on_base--;
            cout << "Good trip!\n";
            return true;
        }
    }
};

class Bus : public Vehicle {
private:
    int people;
    int max_people;
    double petrol;
    double max_petrol;
public:
    Bus() {
        SetPeople(6);
        SetMaxPeople(12);
        SetPetrol(60);
        SetMaxPetrol(80);
    }

    Bus(int people, int max_people, double petrol, double max_petrol) {
        SetPeople(people);
        SetMaxPeople(max_people);
        SetPetrol(petrol);
        SetMaxPetrol(max_petrol);
    }

    void SetMaxPetrol(double max_petrol) {
        this->max_petrol = max_petrol;
    }

    double GetMaxPetrol() {
        return max_petrol;
    }

    void SetPetrol(double petrol) {
        this->petrol = petrol;
    }

    double GetPetrol() const {
        return petrol;
    }

    void SetMaxPeople(int max_people) {
        this->max_people = max_people;
    }

    void SetPeople(int people) {
        this->people = people;
    }

    int GetPeopleCount() const {
        return people;
    }

    int GetMaxPeople() const {
        return max_people;
    }

    void Arrive() {
        cout << "New people on base. Hiiii!\n";
        b.vehicles_on_base++;
        b.people_on_base += people;
    }

    bool Leave() {
        if (petrol < max_petrol) {
            double gasoline_shortage = max_petrol - petrol;
            if (b.petrol_on_base >= gasoline_shortage) {
                b.petrol_on_base -= gasoline_shortage;
                petrol += gasoline_shortage;
                b.people_on_base -= people;
                b.vehicles_on_base--;
                cout << "People are living base(((\n";
                return true;
            }

            else {
                cout << "Insufficient gasoline at the base. No movement possible. Find fuel!!!\n";
                return false;
            }
        }

        if (people < max_people) {
            int absence_people = max_people - people;
            if (b.people_on_base >= absence_people) {
                b.people_on_base -= absence_people;
                people += absence_people;
            }
        }

        else {
            cout << "Byyye!!!\n";
            b.vehicles_on_base--;
            return true;
        }
    }
};

class Truck : public Vehicle {
private:
    double load;
    double max_load;
    double petrol;
    double max_petrol;
public:

    Truck() {
        SetCurrentLoad(4);
        SetMaxLoad(5);
        SetPetrol(100);
        SetCurrentLoad(120);
    }

    Truck(double load, double max_load, double petrol, double max_petrol) {
        SetCurrentLoad(load);
        SetMaxLoad(max_load);
        SetPetrol(petrol);
        SetCurrentLoad(max_petrol);
    }

    void SetMaxPetrol(double max_petrol) {
        this->max_petrol = max_petrol;
    }

    double GetMaxPetrol() const {
        return max_petrol;
    }

    void SetPetrol(double petrol) {
        this->petrol = petrol;
    }

    double GetPetrol() const {
        return petrol;
    }

    void SetMaxLoad(double max_load) {
        this->max_load = max_load;
    }

    void SetCurrentLoad(double load) {
        this->load = load;
    }

    double GetCurrentLoad() const {
        return load;
    }

    double GetMaxLoad() const {
        return max_load;
    }

    void Arrive() {
        cout << "Hello and welcome on our base :))\n";
        b.vehicles_on_base++;
        b.people_on_base += 1;
    }

    bool Leave() {
        if (petrol < max_petrol) {
            double gasoline_shortage = max_petrol - petrol;
            if (b.petrol_on_base >= gasoline_shortage) {
                b.petrol_on_base -= gasoline_shortage;
                petrol += gasoline_shortage;
                b.people_on_base -= 1;
                b.vehicles_on_base--;
                cout << "See you soon!\n";
                return true;
            }

            else {
                cout << "Insufficient gasoline at the base. No movement possible. Find fuel!!!\n";
                return false;
            }
        }

        if (load < max_load) {
            int no_cargo = max_load - load;
            if (b.goods_on_base >= no_cargo) {
                b.goods_on_base -= no_cargo;
                load += no_cargo;
            }
        }

        else {
            cout << "Byeeee!\n";
            b.vehicles_on_base--;
            return true;
        }
    }
};

int main()
{
    Base base;
    Vehicle vehicle;
    Truck truck;
    Bus bus;
    vehicle.Arrive();
    bus.Arrive();
    truck.Leave();
    cout << base.people_on_base << "\n";
    cout << base.vehicles_on_base << "\n";
    cout << base.petrol_on_base << "\n";
    cout << base.goods_on_base << "\n";
}