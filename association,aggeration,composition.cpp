#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* =======================
   1. ASSOCIATION
   =======================*/

class Student {
    string name;
public:
    Student(string n) : name(n) {}

    string getName() const {
        return name;
    }
};

class Teacher {
    string name;
public:
    Teacher(string n) : name(n) {}

    void guideStudent(const Student& s) {
        cout << "Teacher " << name << " is guiding student " 
             << s.getName() << endl;
    }
};

/* =======================
   2. AGGREGATION
   =======================*/

class Course {
    string courseName;
public:
    Course(string name) : courseName(name) {}

    string getCourseName() const {
        return courseName;
    }
};

class Department {
    string deptName;
    vector<Course*> courses;   // aggregation (independent objects)

public:
    Department(string name) : deptName(name) {}

    void addCourse(Course* c) {
        courses.push_back(c);
    }

    void showCourses() const {
        cout << "Department: " << deptName << endl;
       // for (auto c : courses) {
           // cout << "- " << c->getCourseName() << endl;
        }
    
};

/* =======================
   3. COMPOSITION
   =======================*/

class Room {
    int roomNo;
public:
    Room(int no) : roomNo(no) {}

    void showRoom() const {
        cout << "Room No: " << roomNo << endl;
    }
};

class UniversityBuilding {
    vector<Room> rooms;   // composition (dependent objects)

public:
    UniversityBuilding() {
        rooms.push_back(Room(101));
        rooms.push_back(Room(102));
        rooms.push_back(Room(103));
    }

    void showRooms() const {
        cout << "University Building Rooms:" << endl;
        for (const auto& r : rooms) {
            r.showRoom();
        }
    }
};

/* =======================
   MAIN FUNCTION
   =======================*/

int main() {

    // ----- Association -----
    Teacher t1("Ali");
    Student s1("Ayesha");
    t1.guideStudent(s1);

    cout << endl;

    // ----- Aggregation -----
    Course c1("OOP");
    Course c2("Database Systems");

    Department d1("Computer Science");
    d1.addCourse(&c1);
    d1.addCourse(&c2);
    d1.showCourses();

    cout << endl;

    // ----- Composition -----
    UniversityBuilding ub;
    ub.showRooms();

    return 0;
}


