//
// Created by Velina on 28/03/2020.
//

#ifndef JURASSICPARK_DINOSAUR_H
#define JURASSICPARK_DINOSAUR_H

#include <iostream>
#include <cstring>

enum Gender {Female , Male};
enum Era {Triassic , Cretaceous, Jurassic};
enum Order {Carnivorous, Herbivorous, Aqueous, Flying};
enum Food {Grass, Meat, Fish};

///This class **constructs a dinosaur**.
///
///It is a base class for Carnivorous, Herbivorous, Aqueous and Flying.
///
/// The variables(data members of the class) which are declared in Dinosaur are:
///
/// Data members:
///
/// @arg char* **dinosaurName** - this is the name of dinosaur.
/// @arg Gender **genderOfDinosaur** - this is the gender of dinosaur. It's *enum variable* : **Male** or **Female**.
/// @arg static const char* gender - this is static variable for gender. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the gender.
/// @arg Era **era** - era of dinosaurs. It's *enum variable* : **Triassic** , **Cretaceous** or **Jurassic**
/// @arg static const char*  _era - this is static variable for era. We use this static variable to index through the variable enum.
/// Enum gives us the indexes, and the variable returns the era.
/// @arg char* **typeOfDinosaur** - the type of dinosaur.
class Dinosaur {
public:

    ///This is the **default** constructor.
    ///
    ///Default constructor is the constructor which does not take any argument. It has no parameters.
    ///
    ///@arg **dinosaurName** - The default name of dinosaur is *nullptr*;
    ///@arg **dinosaurGender** - The default gender of dinosaur is *Female*;
    ///@arg **era** - The default era is *Triassic*;
    ///@arg **typeOfDinosaur** - The default type of dinosaur is *nullptr*;
    Dinosaur() = default;


    ///This is the constructor with parameters.
    ///
    ///It has 4 parameters, which are making a dinosaur:
    ///
    ///@param dinosaurName -> this is the name that you want to set to dinosaur;
    ///@param dinosaurGender -> this is the gender that your dinosaur is going to be(or he is going to decide when he grow up);
    ///@param era -> this is era of dinosaur;
    ///@param typeOfDinosaur -> this is the type that your dinosaur is going to be;
    ///@see Dinosaur() Dinosaur(const Dinosaur&)
    Dinosaur(const char*,Gender, Era,const char*);


    ///This is copy constructor.
    ///
    ///With this constructor we make copies of the dinosaurs.
    Dinosaur(const Dinosaur&);


    /// This is copy assignment operator.
    ///@note And assignment operator is called when an already initialized object is assigned a new value from another existing object.
    Dinosaur& operator=(const Dinosaur&);


    ///This is the **destructor**.
    ///
    /// When a class contains a pointer to memory allocated in class(as we have here for **dinosaurName** and **typeOfDinosaur**).
    ~Dinosaur();



    ///This is accessor for the *dinosaurName*.
    ///
    ///@returns const char* array filled with name of the dinosaur;
    /// @attention The accessor has **const** at the beginning of a function because the name of dinosaur that we return - doesn't change.
    /// @attention The function has **const** at the end because we don't change the current Dinosaur object.
    const char* getDinosaurName() const;


    ///This is accessor for the *dinosaurGender*.
    ///
    ///@returns Gender, which is enum variable: It can be : **Male** or **Female**;
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    Gender getDinosaurGender() const;


    ///This is accessor for the *era*.
    ///
    ///@returns Era, which is enum variable: It can be : **Triassic** , **Cretaceous** or **Jurassic**;
    ///@attention The accessor has **const** at the end of a function because the object that we return - doesn't change.
    Era getEra() const;



    ///This is accessor for the *typeOfDinosaur*.
    ///
    ///@returns const char* array filled with type of dinosaur;
    /// @attention The accessor has **const** at the beginning of a function because the type of dinosaur that we return - doesn't change.
    /// @attention The function has **const** at the end because we don't change the current Dinosaur object.
    const char* getTypeOfDinosaur() const;




    ///This is a mutator for the **dinosaurName**.
    ///
    ///That function allow us to **change** the name of dinosaur.
    ///
    ///In the body of a function:
    ///
    ///@arg If we set empty name -> throw exception;
    ///
    ///@arg If we change the name of dinosaur with correct one:
    ///
    ///     First we delete what we have in "dinosaurName" and then we allocate memory for the newDinosaurName + 1 (for '\0')
    ///     and we copy what we have in newDinosaurName in dinosaurName;
    ///
    ///@param newDinosaurName -> This is the new name of the dinosaur, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setDinosaurName(const char*);


    ///This is a mutator for the **dinosaurGender**.
    ///
    ///That function allow us to **change** the gender of our dinosaur.
    ///
    ///@param newDinosaurGender -> This is the new gender of dinosaur, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setDinosaurGender(Gender);


    ///This is a mutator for the **era**.
    ///
    ///That function allow us to **change** the era of our dinosaur.
    ///
    ///@param newEra -> This is the new era of dinosaur, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setEra(Era);


    ///This is a mutator for the **typeOfDinosaur**.
    ///
    ///That function allow us to **change** the type of dinosaur.
    ///
    ///In the body of a function:
    ///
    ///@arg If we set empty type of dinosaur -> throw exception;
    ///
    ///@arg If we change the type of dinosaur with correct one:
    ///
    ///     First we delete what we have in "typeOfDinosaur" and then we allocate memory for the newTypeOfDinosaur + 1 (for '\0')
    ///     and we copy what we have in newTypeOfDinosaur in typeOfDinosaur;
    ///
    ///@param newTypeOfDinosaur -> This is the new type of the dinosaur, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setTypeOfDinosaur(const char*);

    ///This function prints all the information about our dinosaur.
    ///
    ///@attention The print function has **const** at the end of a function because we just print the information, we don't change it.
    virtual void print() const;

    /// We store our information of dinosaurs in binary file "InformationAboutDinosaurs.bin".
    void storeInBinaryFile();

private:
    char* dinosaurName{nullptr};
    Gender dinosaurGender{Female};
    static const char* const gender[];
    Era era{Triassic};
    static const char* const _era[];
    char* typeOfDinosaur{nullptr};
};



#endif //JURASSICPARK_DINOSAUR_H
