//
// Created by Velina on 28/04/2020.
//

#include "Flying.h"


const char* const Flying::food[3] = { "Grass" , "Meat", "Fish" };
const char* const Flying::_order[4] = { "Carnivorous" , "Herbivorous", "Aqueous", "Flying"};

Flying::Flying(const char * dinosaurName, Gender dinosaurGender, Era era, const char * typeOfDinosaur, Food foodThatFlyingDinosaurEats, Order order)
        : Dinosaur(dinosaurName,dinosaurGender,era,typeOfDinosaur){
    setFoodThatFlyingDinosaurEats(foodThatFlyingDinosaurEats);
    setOrder(order);
}

void Flying::setFoodThatFlyingDinosaurEats(Food newFoodThatFlyingDinosaurEats) {
    this->foodThatFlyingDinosaurEats = newFoodThatFlyingDinosaurEats;
}

void Flying::setOrder(Order newOrder) {
    this->order = newOrder;
}

Food Flying::getFoodThatFlyingDinosaurEats() const {
    return this->foodThatFlyingDinosaurEats;
}

Order Flying::getOrder() const {
    return this->order;
}

void Flying::print() const {
    Dinosaur::print();
    std::cout<<"Food: "<<food[static_cast<int>(this->foodThatFlyingDinosaurEats)]<<std::endl;
    std::cout<<"Order: "<<_order[static_cast<int>(this->order)]<<std::endl;
}