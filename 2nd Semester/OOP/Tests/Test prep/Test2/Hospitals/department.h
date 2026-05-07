//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_DEPARTMENT_H
#define HOSPITAL_DEPARTMENT_H
#include <string>

// ABSTRACT CLASS (has virtual and non-virtual functions)
class Department {
private:
protected: // no need for getters - subclasses can access them directly
    std::string hospitalName;
    int numberOfDoctors;
public:
    Department(const std::string& hospitalName, int numberOfDoctors);
    virtual bool isEfficient()=0;
    virtual std::string toString();

    // getters - useful only if these fields were private
    std::string getHospitalName() const;
    int getNumberOfDoctors() const;

    // setters - useful only when the values change after the object is created

    virtual ~Department() = default;
};


#endif //HOSPITAL_DEPARTMENT_H
