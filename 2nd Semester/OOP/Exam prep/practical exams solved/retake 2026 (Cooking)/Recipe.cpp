//
// Created by Maria on 07/07/2026.
//

#include "Recipe.h"

Recipe::Recipe(const std::string &name, const std::string &cuisine, int time,
    const std::vector<std::string> &ingredients):name{name},cuisine{cuisine},time{time},ingredients{ingredients} {
}

std::string Recipe::getName() const {
    return name;
}

std::string Recipe::getCuisine() const {
    return cuisine;
}

int Recipe::getTime() const {
    return time;
}

std::vector<std::string> Recipe::getIngredients() const {
    return ingredients;
}

/*
std::string Recipe::toString() const {
    std::string text;
    text=name+";"+cuisine+";"+std::to_string(time)+";";
    for (int i=0;i<ingredients.size();i++) {
        text +=ingredients[i];
        if (i<ingredients.size()-1)
            text +=",";
    }
    return text;
    return name+";"+cuisine+";"+std::to_string(time)+";";
}
*/

std::string Recipe::toString() const {
    std::string text = name + ";" + cuisine + ";" + std::to_string(time) + ";";

    for (size_t i = 0; i < ingredients.size(); i++) {
        text += ingredients[i];
        if (i < ingredients.size() - 1) {
            text += ",";
        }
    }
    return text;
}

std::string Recipe::getIngredientsAsString() const {
    std::string text;
    for (size_t i = 0; i < ingredients.size(); i++) {
        text += ingredients[i];
        if (i < ingredients.size() - 1) {
            text += ",";
        }
    }
    return text;
}
