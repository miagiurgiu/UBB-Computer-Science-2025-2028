//
// Created by Maria on 06/07/2026.
//

#include "Repository.h"
#include <fstream>
#include <sstream>
#include <string>

Repository::Repository(const std::string &chefsFile, const std::string &recipesFile):chefsFile{chefsFile}, recipesFile{recipesFile}{
    loadChefs();
    loadRecipes();
}

std::vector<Chef> Repository::getChefs() const {
    return chefs;
}

std::vector<Recipe> Repository::getRecipes() const {
    return recipes;
}

void Repository::loadChefs() {
    std::ifstream fin(chefsFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name,speciality;
        std::getline(ss,name,',');
        std::getline(ss,speciality);
        chefs.emplace_back(name,speciality);
    }
    fin.close();
}


void Repository::loadRecipes() {
    std::ifstream fin(recipesFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open file");

    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string name, cuisine, timeString, ingredientsString;

        std::getline(ss, name, ';');
        std::getline(ss, cuisine, ';');
        std::getline(ss, timeString, ';');
        std::getline(ss, ingredientsString);

        int time = 0;
        if (!timeString.empty()) {
            time = std::stoi(timeString);
        }

        std::vector<std::string> ingredients;
        std::stringstream sss(ingredientsString);
        std::string singleIngredient;

        while (std::getline(sss, singleIngredient, ',')) {
            if (!singleIngredient.empty()) {
                ingredients.push_back(singleIngredient);
            }
        }

        recipes.emplace_back(name, cuisine, time, ingredients);
    }
    fin.close();
}


void Repository::save() {
    std::ofstream fout(recipesFile);
    std::sort(recipes.begin(),recipes.end(),[](const Recipe& r1,const Recipe& r2) {
        if (r1.getCuisine()!=r2.getCuisine())
            return r1.getCuisine()<r2.getCuisine();
        return r1.getTime()<r2.getTime();
    });
    for (const auto& r : recipes) {
        fout <<r.getName() << ";"
             <<r.getCuisine() << ";"
             <<r.getTime() << ";";
        auto ingredients=r.getIngredients();
        for (int i=0; i<ingredients.size();i++) {
            fout<<ingredients[i];
            if (i!= ingredients.size()-1) {
                fout << ",";
            }
        }
        fout << "\n";
    }
    fout.close();
}

void Repository::add(const Recipe &recipe) {
    recipes.push_back(recipe);
    save();
}
