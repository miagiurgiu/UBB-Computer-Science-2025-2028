//
// Created by Maria on 07/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_RECIPE_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_RECIPE_H
#include <string>
#include <vector>

class Recipe {
private:
    std::string name;
    std::string cuisine;
    int time;
    std::vector<std::string> ingredients;
public:
    Recipe(const std::string& name,const std::string& cuisine,int time,const std::vector<std::string>& ingredients);
    std::string getName() const;
    std::string getCuisine() const;
    int getTime() const;
    std::vector<std::string> getIngredients() const;
    std::string toString() const;
    std::string getIngredientsAsString() const;
};



#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_RECIPE_H
