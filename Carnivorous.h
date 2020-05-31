//
// Created by Velina on 30/03/2020.
//

#ifndef JURASSICPARK_CARNIVOROUS_H
#define JURASSICPARK_CARNIVOROUS_H

#include "Dinosaur.h"

/// This class **constructs a carnivorous dinosaur**.
///
/// This is the class that inherits from Dinosaur class. It called derived class.
///
/// The variables(data members of the class, which ARE NOT in Dinosaur) are:
///
/// @arg Food **foodThatCarnivorousDinosaurEats** - this is the food that dinosaur eats. It's *enum variable* : **Grass**,**Meat** or **Fish**.
/// @arg static const char* food - this is static variable for food. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the food that dinosaur eats.
/// @arg Order **order** - the order of dinosaur. It's *enum variable* : **Order::Carnivorous**, **Order::Herbivorous**, **Order::Aqueous** or **Order::Flying**.
/// @arg static const char* _order - this is static variable for order. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the order of dinosaur.
class Carnivorous : public Dinosaur{
public:

    ///This is the **default** constructor and **constructor with parameters** in one place.
    ///
    /// The default values of data members that the Carnivorous inherits from Dinosaur are:
    ///
    /// @arg **dinosaurName** - The default name of dinosaur is *nullptr*;
    /// @arg **dinosaurGender** - The default gender of dinosaur is *Female*;
    /// @arg **era** - The default era is *Triassic*;
    /// @arg **typeOfDinosaur** - The default type of dinosaur is *nullptr*;
    ///
    /// @param dinosaurName -> this is the name that you want to set to dinosaur;
    /// @param dinosaurGender -> this is the gender that your dinosaur is going to be(or he is going to decide when he grow up);
    /// @param era -> this is era of dinosaur;
    /// @param typeOfDinosaur -> this is the type that your dinosaur is going to be;
    /// @attention We do not use the data members of the class in the constructor because on behalf of
    /// the class we know what the dinosaur eats and what order it has.
    Carnivorous(const char* = nullptr,Gender = Female, Era = Triassic,const char* = nullptr);


    ///This is accessor for the *foodThatCarnivorousDinosaurEats*.
    ///
    ///@returns Food, which is enum variable: It can be : **Grass**, **Meat** or **Fish**(but in that case is only **Meat**).
    ///@attention The accessor has **const** at the end of a function because the current Carnivorous object that we return - doesn't change.
    Food getFoodOfCarnivorousDinosaur() const;


    ///This is accessor for the *order*.
    ///
    /// @returns Order, which is enum variable: It can be : **Order::Carnivorous**, **Order::Herbivorous**,
    /// **Order::Aqueous** or **Order::Flying**(but in that case is **Order::Carnivorous**);
    ///@attention The accessor has **const** at the end of a function because the current Carnivorous object that we return - doesn't change.
    Order getOrder() const;

    virtual void print() const;
private:
    Food foodThatCarnivorousDinosaurEats;
    Order order;
    static const char* const food[];
    static const char* const _order[];

};


#endif //JURASSICPARK_CARNIVOROUS_H
