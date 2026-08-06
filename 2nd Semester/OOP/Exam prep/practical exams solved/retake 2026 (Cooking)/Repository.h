//
// Created by Maria on 06/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_REPOSITORY_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_REPOSITORY_H
#include <string>

#include "domain/Chef.h"
#include "domain/Recipe.h"
#include <vector>
#include <string>

class Repository {
private:
    std::string chefsFile;
    std::string recipesFile;
    std::vector<Chef> chefs;
    std::vector<Recipe> recipes;
public:
    Repository(const std::string& chefsFile,const std::string& recipesFile);
    std::vector<Chef> getChefs() const;
    std::vector<Recipe> getRecipes() const;
    void loadChefs();
    void loadRecipes();
    void save();
    void add(const Recipe& recipe);
};



#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_REPOSITORY_H
