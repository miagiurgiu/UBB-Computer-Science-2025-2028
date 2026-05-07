//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_ABSTRACT_REPO_H
#define HOSPITAL_ABSTRACT_REPO_H
#include "../domain/department.h"
#include <vector>

// PURE ABSTRACT CLASS - has only virtual functions
class AbstractRepo {
private:
public:
    virtual void addDepartment(Department* department) = 0;
    virtual std::vector<Department*> getAll() const = 0;
    virtual ~AbstractRepo() = default;
};

#endif //HOSPITAL_ABSTRACT_REPO_H
