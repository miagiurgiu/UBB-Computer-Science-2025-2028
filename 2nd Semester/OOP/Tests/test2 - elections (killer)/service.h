//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_SERVICE_H
#define T2_MIAGIURGIU_1_SERVICE_H
#include <vector>
#include "../domain/county.h"


class Service {
private:
    std::vector<County*> counties;

public:
    Service();
    void add(County* c);
    std::vector<County*> getAll();
    void writeToFile(const std::string& filename, std::vector<County*> counties);
    int getVotes() const;
    ~Service()=default;

};



#endif //T2_MIAGIURGIU_1_SERVICE_H
