//
// Created by Maria on 06/07/2026.
//

#include "Service.h"
#include <sstream>

Service::Service(Repository &repo):repo{repo} {
}

std::vector<Chef> Service::getChefs() const {
    return repo.getChefs();
}

std::vector<Recipe> Service::getRecipes() const {
    return repo.getRecipes();
}

std::vector<Recipe> Service::getRecipesSorted() const {
    //std::vector<Recipe> result;
    auto recipes=repo.getRecipes();
    std::sort(recipes.begin(),recipes.end(),[](const Recipe& r1,const Recipe& r2) {
        return r1.getCuisine()<r2.getCuisine();
    });
    return recipes;
}

std::vector<Recipe> Service::getSpecialisedRecipes(const std::string &specialisation) const {
    std::vector<Recipe> result;
    auto recipes=repo.getRecipes();
    for (const auto& r:recipes) {
        if (r.getCuisine()==specialisation)
            result.push_back(r);
    }
    return result;
}


void Service::add(const std::string &name, const std::string &speciality, int time, const std::string &ingredients) {
    if (name.empty())
        throw std::runtime_error("empty name");

    auto recipes = repo.getRecipes();
    for (const auto& r : recipes) {
        if (r.getName() == name)
            throw std::runtime_error("already exists a recipe with this name");
    }

    std::vector<std::string> ingredientsVector;
    std::stringstream ss(ingredients);
    std::string ingredient;
    while (std::getline(ss, ingredient, ',')) {
        ingredientsVector.push_back(ingredient);
    }
    Recipe newRecipe{name, speciality, time, ingredientsVector};
    repo.add(newRecipe);
    notify();
}

std::vector<Recipe> Service::getRecipesInCuisine(const Chef &chef) const {
    std::vector<Recipe> result;
    auto recipes=repo.getRecipes();
    for (const auto& r:recipes) {
        if (r.getCuisine()==chef.getSpeciality())
            result.push_back(r);
    }
    return result;
}

 std::vector<Recipe> Service::filter(const std::string &text) {
    auto recipes=repo.getRecipes();
    std::vector<Recipe> result;
    for (const auto& r:recipes) {
        auto ingredientsString=r.getIngredientsAsString();
        if (ingredientsString==text)
            result.push_back(r);
    }
    return result;
}
