//Title: Animal.cpp
//Author: Amarjot Gill
//Date: 4/12/2021
//Description: Animal code for the Animal Class
#include "Animal.h"
const string ANIMAL_NAME = "Chicken";
const string ANIMAL = "Animal";

Animal::Animal():AgItem(){
    m_name = ANIMAL_NAME;
    m_IsHungry = true;
    cout << "New Animal Created" << endl;
}

void Animal::Tick(bool enoughFood){
    int size = GetSize();
    if(enoughFood){
        // animal not hungry updates size
        if (size < ANIMAL_MAX_SIZE){
            m_IsHungry = false;
            size++;
            SetSize(size);
        }if(size == ANIMAL_MAX_SIZE){
            SetIsHarvestable(true);
        }
    }if(!enoughFood){
        // if animal is hungry and not enough food this would be 2nd season so its not harvestable
        if (m_IsHungry){
            SetIsHarvestable(true);
        }else if (!m_IsHungry){
            m_IsHungry = true;
        }
    }
}

string Animal::GetType(){
    return m_name;
}

ostream &Animal::operator<<(ostream &output){
    // if the animal is hungry it is not fed
    if (m_IsHungry){
        output << ANIMAL << CONCAT << GetType() << CONCAT <<"Non Harvestable" << CONCAT << ANIMAL_SIZE[GetSize()] << CONCAT << "Not Fed";
    }else{
         output << ANIMAL << CONCAT << GetType() << CONCAT<< "Non Harvestable" << CONCAT << ANIMAL_SIZE[GetSize()] << CONCAT << "Fed";
    }
    return output;
}

int Animal::Harvest(){
    int size = GetSize();
    int worth = GetWorth();
    if (GetIsHarvestable()){
        cout << "The Animal was harvested" << endl;
        return size * worth;
    }else{
        return 0;
    }
}