//
//  main.cpp
//  FT_1
//
//  Created by Эмиль Саубанов on 26.04.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

struct Student{
    int id;
    std::string name;
    int age;
};

class Student_DB{
private:
    std::vector<std::shared_ptr<Student>> students;
    
public:
    void addStudent(int id, const std::string& name, int age){
        students.push_back(std::make_shared<Student>(Student{id, name, age}));
    }
    
    void removeStudent(int id) {
            students.erase(std::remove_if(students.begin(), students.end(), [id](const std::shared_ptr<Student>& student) {
                return student->id == id;
            }), students.end());
    }
    
    std::shared_ptr<Student> getStudent(int id) const {
            auto it = std::find_if(students.begin(), students.end(), [id](const std::shared_ptr<Student>& student) {
                return student->id == id;
            });

            if (it != students.end()) {
                return *it;
            }

            return nullptr;
        }
    
};
