//Title: Farm.cpp
//Author: Amarjot Gill
//Date: 4/12/2021
//Description: Main class, simualtes farm and deals with user menu and everthing
#include "Farm.h"
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int ZERO = 0;
const string ANIMAL = "Chicken";
const string VEG = "Vegetable";
const string TREE = "Tree";

Farm::Farm(){
    m_food = SIX;
    m_season = ONE;
    m_money = ZERO;
}

Farm::~Farm(){
    for (int i = 0; i < int(m_farm.size()); i++){
        delete m_farm[i];
    }
}

void Farm::StartSimulation(){
    cout << "Welcome to Stardew Valley Simulator" << endl;
    int userChoice;
    int addItems;
    int seasonSim;
    do{
       userChoice = Menu();
       if (userChoice == ONE){
           addItems = ChooseItem();
           AddItem(addItems, ONE);
       }if(userChoice == TWO){
           AddItem(ONE,TWO);
       }if(userChoice == THREE){
           // error checking so no negative seasons and 0 is entered
           do{
                cout << "How many seasons to simulate?" << endl;
                cin >> seasonSim;
           } while (seasonSim <= ZERO);
           Tick(seasonSim);
       }if(userChoice == FOUR){
           Status();
       }
       
    } while (userChoice != FIVE);
    cout << "Thank you for simulating Stardew Valley!" << endl;
}

int Farm::Menu(){
    int currentOption;
    do{
        cout << "1. Add item to Farm" << endl;
        cout << "2. Add Two of Each Item to Farm" << endl;
        cout << "3. Simulate Time" << endl;
        cout << "4. Farm Status" << endl;
        cout << "5. Quit" << endl;

        cin >> currentOption;
        
    } while (currentOption <= ZERO || currentOption > FIVE);

    return currentOption;
    
}

int Farm::ChooseItem(){
    int farmItem;
    do{
        cout << "Which agricultrual item are you interesed in?" << endl;
        cout << "1. Animal" << endl;
        cout << "2. Vegetable" << endl;
        cout << "3. Tree" << endl;
        cin >> farmItem;
        
    } while (farmItem <= ZERO || farmItem > THREE);

    return farmItem;
    
}

void Farm::AddItem(int type, int quantity){
    if (quantity == ONE){
        if (type == ONE){
        AgItem *newAnimal = new Animal;
        m_farm.push_back(newAnimal);

    }   else if (type == TWO){
            AgItem *newVegetable = new Vegetable;
            m_farm.push_back(newVegetable);
    }   else if (type == THREE){
            AgItem *newTree = new Tree;
            m_farm.push_back(newTree);
        }

    }else{
        // if quantity is more than 1 so option number 2 is selected this will run
        for (int i = 0; i < quantity; i++){
            AgItem *newAnimal = new Animal;
            AgItem *newVegetable = new Vegetable;
            AgItem *newTree = new Tree;
            
            m_farm.push_back(newAnimal);
            m_farm.push_back(newVegetable);
            m_farm.push_back(newTree);
        }
    }
}

void Farm::Status(){
    cout << "**** Farm Status ****" << endl;
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season " << m_season << endl;
    cout << "Agricultural Items: " << endl;
    if (int(m_farm.size()) == 0){
       cout << "None" << endl;
    }else{
        for (int i = 0; i < int(m_farm.size()); i++){
            (*m_farm.at(i)) << cout << endl; 
        }
    }
}

void Farm::Tick(int amount){
    string isAnimal;
    int harvestTime;
    
    // double for loop for amount of seasons and for each object in m_farm second loop starts from end so when erasing index's are not messed up
    for (int i = 0; i < amount; i++){
       cout << "SEASON: " << m_season << endl;
       for (int j = int(m_farm.size() - 1); j >= 0; --j){
               // gets the return for each
               harvestTime = m_farm[j] -> Harvest();
               // if its 0 that means not time to harvest yet
               isAnimal = m_farm[j] -> GetType();
               if (harvestTime == ZERO){
                    // if more than 0 food then enough food to feed animals
                    if (m_food > ZERO){
                   if (isAnimal == ANIMAL){
                       m_food--;
                   }m_farm.at(j) -> Tick(true);
               }else{
                   // will run if food is less than 0
                   m_farm.at(j) -> Tick(false);
               }
               }else{
                   // if the object being harvested is a chicken it will add money and reduce food by 1
                   if(isAnimal == ANIMAL){
                       m_money += harvestTime;
                       if(m_food > ZERO){
                            m_food--;
                       }
                       // delete allocated memory and remove from vector
                       delete m_farm[j];
                       m_farm.erase(m_farm.begin()+j);
                       // does same as Animal but increases food by 1 instead
                   }else if(isAnimal == VEG){
                       m_food++;
                       delete m_farm[j];
                       m_farm.erase(m_farm.begin()+j);
                       
                   }else if(isAnimal == TREE){
                       if(harvestTime == ONE){
                           // tick because this means fruit is harvested not that
                           m_farm.at(j) -> Tick(true);
                            m_food += harvestTime;
                       }else if(harvestTime == TWO){
                            delete m_farm[j];
                            m_farm.erase(m_farm.begin()+j);
                       }
                      
                   }
               }
       }
       Status();
       // updates season
       m_season++;
    }
    
}