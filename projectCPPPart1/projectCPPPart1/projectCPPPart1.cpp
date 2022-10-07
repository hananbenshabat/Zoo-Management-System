#include <iostream>
#include "Zoo.h"
#include "Address.h"
#include "Bat.h"
#include "Lion.h"
#include "Ostrich.h"
#include "Crocodile.h"
#include "Parrot.h"
#include <string.h>
using namespace std;

void menu(){
    cout << "\n";
    cout << "choose action from Menu : \n";
    cout << "choose 1 : for add Animal \n";
    cout << "choose 2 : for Remove Animal \n";
    cout << "choose 3 : for add Employee\n";
    cout << "choose 4 : for Remove Employee \n";
    cout << "choose 5 : for add Cage \n";
    cout << "choose 6 : for show all Zoo \n";
    cout << "choose 7 : for show all Animals \n";
    cout << "choose 8 : for show all Employees \n";
    cout << "choose 9 : for feed All Animals \n";
    cout << "choose 0 : for exit \n";
}
void addAnimalMenu() {
    cout << "\n";
    cout << "what animal you want to add : \n";
    cout << "choose 1 : for adding a Lion \n";
    cout << "choose 2 : for adding a Crocodile \n";
    cout << "choose 3 : for adding a Parrot\n";
    cout << "choose 4 : for adding a Ostrich \n";
    cout << "choose 5 : for adding a Bat\n";
    cout << "choose 0 : for exit \n";
}
Lion& getLion() {
    int sn;
    string name;
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;   
    return *(new Lion(sn, name, height, weight));
}
Ostrich& getOstrich(){

    int sn;
    string name;
    float height;
    float weight;
    string color;
    cout << "give int serial Number: \n";
    cin >> sn;
    cout << "give name: \n";
    cin >> name;
    cout << "give the height: \n";
    cin >> height;
    cout << "give the weight: \n";
    cin >> weight;
    cout << "give the color of the ostrich: \n";
    cin >> color;
    return *(new Ostrich(sn, name, height, weight, color));
}
Bat& getBat() {

    int sn;
    string name;
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    return *(new Bat(sn, name, height, weight));
}
Parrot& getParrot() {
    int sn;
    string name;
    float height;
    float weight;
    string color;
    float sizeofBeak;
    int speedOfFlight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    cout << "give the color of the parrot:";
    cin >> color;
    cout << "give the size  of beak of the parrot:";
    cin >> sizeofBeak;
    cout << "give the speed of flight of the parrot:";
    cin >> speedOfFlight;
    return *(new Parrot(sn, name, height, weight, color, sizeofBeak, speedOfFlight));
}
Crocodile& getCroc() {
    int sn;
    string name;
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    return *(new Crocodile(sn, name, height, weight));
}
Employee& getEmployee() {
    int employeNumber;
    string name;
    string role;
    cout << "give  employe Number:";
    cin >> employeNumber;
    cout << "give name:";
    cin >> name;
    cout << "give the role of employee:";
    cin >> role;
    return *(new Employee(employeNumber, name, role));
}
void addCageMenu() {
    
    cout << "choose type of cage that this zoo can add \n";
    cout << "1 for Lion \n";
    cout << "2 for Crocodile \n";
    cout << "3 for Parrot \n";
    cout << "4 for Bat \n";
    cout << "5 for Ostrich \n";
    cout << "0 for exit \n";
}

int main()
{
    Address add("cpp", 1, "world");
    const string nameOfZoo = "Hello World";
    //Zoo zoo(nameOfZoo,add);
    Zoo zoo = *(Zoo::getInstance(nameOfZoo, add));
    int option = 10;
    do {
        
        menu();
        try
        {
            cin >> option;
        }
        catch (const std::exception& )
        {
            cout << "wrong input \n";
           
        }
        switch (option)
        {
        case 1:
            int animalOption;
            
            do {
                addAnimalMenu();
                try
                {
                    cin >> animalOption;       
                }
                catch (const std::exception&)
                {
                    cout << "wrong input \n";

                }
                try
                { 
                    switch (animalOption) 
                    {
                    case 1:
                        zoo.addAnimal(getLion());
                        break;
                    case 2:
                        zoo.addAnimal(getCroc());
                        break;
                    case 3:
                        zoo.addAnimal(getParrot());
                        break;
                    case 4:
                        zoo.addAnimal(getOstrich());
                        break;
                    case 5:
                        zoo.addAnimal(getBat());
                        break;
                    default:
                        cout << "no option :" << option;
                        break;
                    }
                }
                catch (const string msg)
                {
                    cout << msg << endl;
                }
            } while (animalOption != 0);
            break;
        case 2:
            int sn;
            cout << "give int serial Number of an animal to remove :";
            cin >> sn;
            zoo.removeAnimal(sn);
            break;
        case 3:
            zoo.addEmployee(getEmployee());
            break;
        case 4:
            int em;
            cout << "give int employe number of an employee to remove :";
            cin >> em;
            zoo.removeEmployee(em);
            break;

        case 5:
            int cageOption ;

            do
            {
                addCageMenu();
                   try
               {
                   cin >> cageOption;
               }
               catch (const std::exception&)
               {
                   cout << "wrong input \n";

               }
               try 
               {     
                    switch (cageOption) 
                    {
                    case 1:
                    
                        zoo.addCage(LION);
                        break;
                    case 2:
                        zoo.addCage(CROCODILE);
                        break;
                    case 3:
                        zoo.addCage(PARROT);
                        break;
                    case 4:
                        zoo.addCage(BAT);
                        break;
                    case 5:
                        zoo.addCage(OSTRICH);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "there is no option :" << cageOption;

                        break;
                    }
               }
               catch (const string msg)
               {
                   cout << msg << endl;
               }
            } while (cageOption != 0);

            break;
        case 6:
            zoo.show();
            cout << "you chose :" << 6;
            break;
        case 7:
            zoo.showAllAnimals();
            break;
        case 8:
            zoo.showAllEmployees();
            break;
        case 9:
            zoo.feedAllAnimals();
            break;
        case 0:
            break;
        case -1: //test
            zoo.addCage(CROCODILE);
            zoo.addAnimal(*(new Crocodile(1, "Coco", 200, 120)));
            zoo.addCage(BAT);
            zoo.addAnimal(*(new Bat(2, "batbat", 2, 10)));
            zoo.showAllAnimals();
            zoo.addEmployee(*(new Employee(123, "jojo", "cage cleaner")));
            zoo.addEmployee(*(new Employee(201, "lodo", "Lion trainer")));
            zoo.addEmployee(*(new Employee(103, "dodo", "Bat trainer")));
            zoo.showAllEmployees();
            zoo.feedAllAnimals();
            break;
        default:
            cout << "no option :" << option;
            break;
        }

    } while (option != 0);


    return 0;


}


