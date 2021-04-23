//Title: AgItem.cpp
//Author: Amarjot Gill
//Date: 4/12/2021
//Description: Parent class (Agricultural Items - animals, vegetables, and trees)

#include "AgItem.h"
AgItem::AgItem(){
    m_size = 0;
    m_worth = BASE_WORTH;
    m_isHarvestable = false;
}
AgItem::AgItem(int size, int worth, bool harvest){
    m_size = size;
    m_worth = worth;
    m_isHarvestable = harvest;
}

AgItem::~AgItem(){
    // for tree subclass
}

int AgItem::GetSize(){
    return m_size;
}

int AgItem::GetWorth(){
    return m_worth;
}

bool AgItem::GetIsHarvestable(){
    return m_isHarvestable;
}

void AgItem::SetSize(int size){
    if (size < 0){
        m_size = 0;
    }else{
        m_size = size;
    }
    
}

void AgItem::SetIsHarvestable(bool canHarvest){
    m_isHarvestable = canHarvest;
}
