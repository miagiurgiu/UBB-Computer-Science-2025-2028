//
// Created by Maria on 06/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_SERVICE_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_SERVICE_H
#include "domain/Subject.h"
#include "repo/Repository.h"


class Service:public Subject {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Chef> getChefs() const;
    std::vector<Recipe> getRecipes() const;
    std::vector<Recipe> getRecipesSorted() const;
    std::vector<Recipe> getSpecialisedRecipes(const std::string& specialisation) const;
    void add(const std::string& name,const std::string& speciality,int time,const std::string& ingredients);
    std::vector<Recipe> getRecipesInCuisine(const Chef& chef) const;
    std::vector<Recipe> filter(const std::string& text);
};



#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_SERVICE_H
