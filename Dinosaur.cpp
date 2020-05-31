//
// Created by Velina on 28/03/2020.
//

#include "Dinosaur.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>


const char* const Dinosaur::gender[2] = { "Female", "Male" };
const char* const Dinosaur::_era[3] = { "Triassic" , "Cretaceous", "Jurassic" };

Dinosaur::Dinosaur(const char * dinosaurName, Gender dinosaurGender, Era era, const char * typeOfDinosaur)
        : dinosaurName(nullptr), typeOfDinosaur(nullptr){
    setDinosaurName(dinosaurName);
    setDinosaurGender(dinosaurGender);
    setEra(era);
    setTypeOfDinosaur(typeOfDinosaur);
}

Dinosaur::Dinosaur(const Dinosaur & other) {
    setDinosaurName(other.dinosaurName);
    setDinosaurGender(other.dinosaurGender);
    setEra(other.era);
    setTypeOfDinosaur(other.typeOfDinosaur);
}

 Dinosaur& Dinosaur::operator=(const Dinosaur& other) {
    if(this!=&other){
        delete [] this->dinosaurName;
        this->dinosaurName = nullptr;
        delete [] this->typeOfDinosaur;
        this->typeOfDinosaur = nullptr;

        setDinosaurName(other.dinosaurName);
        setDinosaurGender(other.dinosaurGender);
        setEra(other.era);
        setTypeOfDinosaur(other.typeOfDinosaur);
    }
    return *this;
}

Dinosaur::~Dinosaur() {
    delete [] this->dinosaurName;
    this->dinosaurName = nullptr;
    delete [] this->typeOfDinosaur;
    this->typeOfDinosaur = nullptr;
}

void Dinosaur::setDinosaurName(const char * newDinosaurName) {
    if(!newDinosaurName)
        throw "ERROR!";
    delete[] this->dinosaurName;
    this->dinosaurName = nullptr;

    this->dinosaurName = new char[strlen(newDinosaurName)+1];
    strcpy(this->dinosaurName,newDinosaurName);
}

void Dinosaur::setDinosaurGender(Gender newDinosaurGender) {
    this->dinosaurGender = newDinosaurGender;
}

void Dinosaur::setEra(Era newEra) {
    this->era = newEra;
}

void Dinosaur::setTypeOfDinosaur(const char * newTypeOfDinosaur) {
    if(!newTypeOfDinosaur) {
        throw "ERROR!";
    }
    delete[] this->typeOfDinosaur;
    this->typeOfDinosaur = nullptr;

    this->typeOfDinosaur = new char[strlen(newTypeOfDinosaur) + 1];
    strcpy(this->typeOfDinosaur,newTypeOfDinosaur);
}

const char * Dinosaur::getDinosaurName() const {
    return this->dinosaurName;
}

Gender Dinosaur::getDinosaurGender() const {
    return this->dinosaurGender;
}

Era Dinosaur::getEra() const {
    return this->era;
}

const char* Dinosaur::getTypeOfDinosaur() const {
    return this->typeOfDinosaur;
}

void Dinosaur::print() const {
    std::cout<<"Name of dinosaur: "<<dinosaurName<<std::endl;
    std::cout<<"Gender: "<<gender[static_cast<int>(this->dinosaurGender)]<<std::endl;
    std::cout<<"Era: "<<_era[static_cast<int>(this->era)]<<std::endl;
    std::cout<<"Type of dinosaur: "<<typeOfDinosaur<<std::endl;
}

void Dinosaur::storeInBinaryFile() {
    // We make a file where we are going to store the information about dinosaurs.
    std::ofstream outputFile("InformationAboutDinosaurs", std::ios::out | std::ios::ate | std::ios::app | std::ios::binary);
    // Check if the file is open;
    if(!outputFile.is_open()){
        //If it's not open we print the message and exiting the program;
        std::cout<<"The file can not be opened!"<<std::endl;
        exit(1);
    }

    // write the name of dinosaur into the file;
    int lengthOfNameOfTheDinosaur = strlen(this->getDinosaurName());
    outputFile.write(reinterpret_cast<const char*>(&lengthOfNameOfTheDinosaur), sizeof(int));
    outputFile.write(reinterpret_cast<const char*>(this->getDinosaurName()),lengthOfNameOfTheDinosaur * sizeof(char));

    // write the gender of dinosaur into the file;
    int _gender = this->getDinosaurGender();
    outputFile.write(reinterpret_cast<const char*>(&_gender), sizeof(int));

    // write the era of dinosaur into the file;
    int _era = this->getEra();
    outputFile.write(reinterpret_cast<const char*>(&_era), sizeof(int));

    // write the type of dinosaur into the file;
    int lengthOfTypeOfDinosaur = strlen(this->getTypeOfDinosaur());
    outputFile.write(reinterpret_cast<const char*>(&lengthOfTypeOfDinosaur), sizeof(int));
    outputFile.write(reinterpret_cast<const char*>(this->getTypeOfDinosaur()), lengthOfTypeOfDinosaur * sizeof(char));

    //closing the file;
    outputFile.close();
}

