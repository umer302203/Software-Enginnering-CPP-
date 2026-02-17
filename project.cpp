#include <iostream>
      #include <string>
      using namespace std;

     
      // Person (Abstract Base Class)
      
      class Person {
      protected:
          string id;
          string name;
          string email;

      public:
          Person(string id="", string name="", string email="") 
              : id(id), name(name), email(email) {}

          virtual void displayRole() const = 0;

          void printBasicInfo() const {
              cout << "ID: " << id << endl;
              cout << "Name: " << name << endl;
              cout << "Email: " << email << endl;
          }

          string getId() const { return id; }
          string getName() const { return name; }
      };

      // Forward declarations
      class Course;
      class Enrollment;

     
      // Student Class
     
      class Student : public Person {
      private:
          string program;
          int semester;
          string regNo;
          Enrollment* enrollments[20]; // fixed size
          int enrollmentCount;
          static int totalStudents;

      public:
          Student(string id="", string name="", string email="", string program="", int semester=1, string regNo="")
              : Person(id,name,email), program(program), semester(semester), regNo(regNo), enrollmentCount(0) {
              totalStudents++;
          }

          void displayRole() const override {
              cout << "[Role] Student" << endl;
          }

          void addEnrollment(Enrollment* e) {
              if(enrollmentCount < 20) {
                  enrollments[enrollmentCount++] = e;
              }
          }

          double calculateGPA() const;

          void studentReport() const;

          void printDetails() const {
              printBasicInfo();
              cout << "Program: " << program << endl;
              cout << "Semester: " << semester << endl;
              cout << "Reg#: " << regNo << endl;
          }

          string getRegNo() const { return regNo; }

          static int getTotalStudents() { return totalStudents; }
      };
      int Student::totalStudents = 0;

      
      // Teacher Class
     
      class Teacher : public Person {
      private:
          string designation;
          string department;
          static int totalTeachers;

      public:
          Teacher(string id="", string name="", string email="", string designation="", string department="")
              : Person(id,name,email), designation(designation), department(department) {
              totalTeachers++;
          }

          void displayRole() const override {
              cout << "[Role] Teacher" << endl;
          }

          void printDetails() const {
              printBasicInfo();
              cout << "Designation: " << designation << endl;
              cout << "Department: " << department << endl;
          }

          static int getTotalTeachers() { return totalTeachers; }
      };
      int Teacher::totalTeachers = 0;

    
      // Course Class
     
      class Course {
      private:
          string code;
          string title;
          int creditHours;
          Teacher* teacher;
          static int totalCourses;

      public:
          Course(string code="", string title="", int ch=3)
              : code(code), title(title), creditHours(ch), teacher(NULL) {
              totalCourses++;
          }

          void assignTeacher(Teacher* t) { teacher = t; }

          void printCourseInfo() const {
              cout << "Course Code: " << code << endl;
              cout << "Title: " << title << endl;
              cout << "Credit Hours: " << creditHours << endl;
              if(teacher) cout << "Teacher: " << teacher->getName() << endl;
          }

          string getCode() const { return code; }
          int getCreditHours() const { return creditHours; }

          static int getTotalCourses() { return totalCourses; }
      };
      int Course::totalCourses = 0;

     
      // Enrollment Class
     
      class Enrollment {
      private:
          Student* student;
          Course* course;
          double marks;
          string grade;

      public:
          Enrollment(Student* s=NULL, Course* c=NULL, double m=0)
              : student(s), course(c), marks(m) {
              updateGrade();
          }

          void updateGrade() {
              if(marks >= 85) grade="A";
              else if(marks >= 70) grade="B";
              else if(marks >= 55) grade="C";
              else if(marks >= 40) grade="D";
              else grade="F";
          }

          double gradePoints() const {
              if(grade=="A") return 4.0;
              if(grade=="B") return 3.0;
              if(grade=="C") return 2.0;
              if(grade=="D") return 1.0;
              return 0.0;
          }

          void printEnrollmentInfo() const {
              cout << "Student: " << student->getName() << endl;
              cout << "Course: " << course->getCode() << endl;
              cout << "Marks: " << marks << endl;
              cout << "Grade: " << grade << endl;
          }

          Course* getCourse() const { return course; }
      };

     
      // GPA + Report
     
      double Student::calculateGPA() const {
          double totalPoints=0; int totalCredits=0;
          for(int i=0;i<enrollmentCount;i++) {
              totalPoints += enrollments[i]->gradePoints() * enrollments[i]->getCourse()->getCreditHours();
              totalCredits += enrollments[i]->getCourse()->getCreditHours();
          }
          return totalCredits ? totalPoints/totalCredits : 0.0;
      }

      void Student::studentReport() const {
          cout << "=== Student Report ===" << endl;
          printDetails();
          for(int i=0;i<enrollmentCount;i++) {
              enrollments[i]->printEnrollmentInfo();
          }
          cout << "GPA: " << calculateGPA() << endl;
      }

     
      // Main Menu
      
      int main() {
          Student* students[50]; int studentCount=0;
          Teacher* teachers[20]; int teacherCount=0;
          Course* courses[30]; int courseCount=0;
          Enrollment* enrollments[100]; int enrollmentCount=0;

          int choice;
          do {
              cout << "\nSmart Campus Portal\n";
              cout << "1. Add Student\n2. Add Teacher\n3. Add Course\n4. Assign Teacher\n5. Enroll Student\n6. Show Students\n7. Show Courses\n8. Show Enrollments\n9. Student Report\n0. Exit\nChoice: ";
              cin >> choice;

              if(choice==1) {
                  string id,name,email,program,reg; int sem;
                  cout << "Enter ID Name Email Program Semester Reg#: ";
                  cin >> id >> name >> email >> program >> sem >> reg;
                  students[studentCount++] = new Student(id,name,email,program,sem,reg);
              }
              else if(choice==2) {
                  string id,name,email,desig,dept;
                  cout << "Enter ID Name Email Designation Department: ";
                  cin >> id >> name >> email >> desig >> dept;
                  teachers[teacherCount++] = new Teacher(id,name,email,desig,dept);
              }
              else if(choice==3) {
                  string code,title; int ch;
                  cout << "Enter Code Title CreditHours: ";
                  cin >> code >> title >> ch;
                  courses[courseCount++] = new Course(code,title,ch);
              }
              else if(choice==4) {
                  string code,tid;
                  cout << "Enter CourseCode TeacherID: ";
                  cin >> code >> tid;
                  Course* c=NULL; Teacher* t=NULL;
                  for(int i=0;i<courseCount;i++) if(courses[i]->getCode()==code) c=courses[i];
                  for(int j=0;j<teacherCount;j++) if(teachers[j]->getId()==tid) t=teachers[j];
                  if(c && t) c->assignTeacher(t);
              }
              else if(choice==5) {
                  string reg,code; double marks;
                  cout << "Enter StudentReg CourseCode Marks: ";
                  cin >> reg >> code >> marks;
                  Student* s=NULL; Course* c=NULL;
                  for(int i=0;i<studentCount;i++) if(students[i]->getRegNo()==reg) s=students[i];
                  for(int j=0;j<courseCount;j++) if(courses[j]->getCode()==code) c=courses[j];
                  if(s && c) {
                      Enrollment* e=new Enrollment(s,c,marks);
                      enrollments[enrollmentCount++]=e;
                      s->addEnrollment(e);
                  }
              }
              else if(choice==6) {
                  for(int i=0;i<studentCount;i++) students[i]->printDetails();
              }
              else if(choice==7) {
                  for(int i=0;i<courseCount;i++) courses[i]->printCourseInfo();
              }
              else if(choice==8) {
                  for(int i=0;i<enrollmentCount;i++) enrollments[i]->printEnrollmentInfo();
              }
                      else if(choice==9) {
                          string reg;
                          cout << "Enter StudentReg: ";
                          cin >> reg;
                          for(int i=0;i<studentCount;i++) {
                              if(students[i]->getRegNo()==reg) students[i]->studentReport();
                          }
                      }
                  } while(choice!=0);
              }
