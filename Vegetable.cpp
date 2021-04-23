//Title: Vegetable.cpp
//Author: Amarjot Gill
//Date: 3/19/2021
//Description: Vegetable class child class of Agitem
#include "Vegetable.h"
const string VEGBASE = "Vegetable";

Vegetable::Vegetable():AgItem(){
    cout << "New Vegetable added to the farm" << endl;
}

int Vegetable::Harvest(){
    if (GetIsHarvestable()){
        cout << "The Vegetable was harvested" << endl;
        return GetSize();
    }else{
        return 0;
    }  
}

void Vegetable::Tick(bool timer){
    int size = GetSize();
    // update the size
    if (size < MAX_VEG_SIZE){
        size++;
        SetSize(size);
    }if(size == MAX_VEG_SIZE){
        SetIsHarvestable(true);
    } 
}

string Vegetable::GetType(){
    return VEGBASE;
}

ostream &Vegetable::operator << (ostream &os){
    // once it becomes harvestable it is instanlty harvested so it will not display harvestable
    os << GetType() << CONCAT << "Non Harvestable" << CONCAT << Veg_Size[GetSize()];
    return os;
}

