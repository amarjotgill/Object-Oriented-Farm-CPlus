//Title: Tree.cpp
//Author: Amarjot Gill
//Date: 4/12/2012
//Description: Tree class child of Agitem
#include "Tree.h"
const int TWO = 2;
const string TREE = "Tree";
Tree::Tree():AgItem(){
    m_age = 0;
    cout <<"Tree Added" << endl;
}

Tree::~Tree(){
    for (int i = 0; i < int(m_fruit.size()); i++){
        delete m_fruit[i];
    }
}

void Tree::Tick(bool time){
    if (m_age <= SEASONS_TO_HARVEST){
        m_age++;
    }if(m_age == SEASONS_TO_HARVEST){
        SetIsHarvestable(true);
        // if the mod seasons is 0 then it is time for a new fruit
    }if(m_age % SEASONS_TO_FRUIT == 0){
        Fruit *newFruit = new Fruit;
        m_fruit.push_back(newFruit);
        SetIsHarvestable(true);
    }
}

int Tree::Harvest(){
    if (GetIsHarvestable()){ 
        // deletes the fruit if it is there
        int size = m_fruit.size();
        for (int i = 0; i < int(m_fruit.size()); i++){
            delete m_fruit[i];
        }
        m_fruit.clear();
        SetIsHarvestable(false);
        // returns a 2 if the trees time to harvest
        if(m_age == SEASONS_TO_HARVEST){
            return TWO;
            // else returns 1 which is the size
        }else{
            return size;
        }
    }else{
        return 0;
    }
    
}

string Tree::GetType(){
    return TREE;
}

ostream &Tree::operator << (ostream &os){
    // if tree has a fruit or not
    if (int(m_fruit.size()) == 0){
        // once its over 12 the age will always be mature
        if(m_age > SEASONS_TO_FRUIT){
             os << TREE << CONCAT << TREE_SIZE[3] << CONCAT << "Non Harvestable" << CONCAT <<"Not Fruiting" << CONCAT << "Fruit Count : 0";
        }else{
             os << TREE << CONCAT << TREE_SIZE[m_age / SEASONS_TO_SIZE] << CONCAT << "Non Harvestable" << CONCAT <<"Not Fruiting" << CONCAT << "Fruit Count : 0";
        }
    }else{
        if(m_age > SEASONS_TO_FRUIT){
            os << TREE << CONCAT << TREE_SIZE[3] << CONCAT << "Non Harvestable" << CONCAT <<"Fruiting" << CONCAT << "Fruit Count : " << m_fruit.size();
        }else{
              os << TREE << CONCAT << TREE_SIZE[m_age / SEASONS_TO_SIZE] << CONCAT << "Non Harvestable" << CONCAT <<"Fruiting" << CONCAT << "Fruit Count : " << m_fruit.size();
        }
         
    }
    return os;
}


