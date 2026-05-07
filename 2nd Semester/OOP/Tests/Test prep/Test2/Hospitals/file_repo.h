//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_FILE_REPO_H
#define HOSPITAL_FILE_REPO_H
#include "../repo/abstract_repo.h"

class FileRepo:public AbstractRepo {
private:
    std::vector<Department*> departments;
    std::string filename;
    //std::vector<Department*> readFromFile() const;
    //void writeToFile(const std::vector<Department*> &departments) const;
public:
    FileRepo();
    void addDepartment(Department* department) override;
    std::vector<Department*> getAll() const override;
    ~FileRepo() override;
};



#endif //HOSPITAL_FILE_REPO_H
