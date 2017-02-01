#include <iostream>

#define MAX_GRADES 100

class Student {
private:
  std::string name;
  int id;
  float* grades;
  int n_grades;
public:
  Student();
  Student(std::string name, int id);
  Student(const Student& other);
  ~Student();
  void operator=(const Student& other);
  // void operator=(const std::string other);
  void add_grade(float grade);
  void print_student();
};

Student::Student() : id(0), n_grades(0) {
  this->grades = new float[MAX_GRADES];
}

Student::Student(std::string name, int id) : name(name), id(id), n_grades(0) {
  this->grades = new float[MAX_GRADES];
}

Student::Student(const Student& other) {
  this->name = other.name;
  this->id = other.id;
  this->n_grades = other.n_grades;

  this->grades = new float[MAX_GRADES];
  for (int i = 0; i < other.n_grades; i++) {
    this->grades[i] = other.grades[i];
  }
}

void Student::operator=(const Student& other) {
  this->name = other.name;
  this->id = other.id;
  this->n_grades = other.n_grades;

  this->grades = new float[MAX_GRADES];
  for (int i = 0; i < other.n_grades; i++) {
    this->grades[i] = other.grades[i];
  }
}

Student::~Student() {
  std::cout << "== In the destructor." << std::endl;
  delete[] this->grades;
}

void Student::add_grade(float grade) {
  if (this->n_grades < MAX_GRADES) {
    this->grades[this->n_grades++] = grade;
  }
}

void Student::print_student() {
  std::cout << this->name << " (" << this->id << "):" << std::endl;
  std::cout << "  grades address: " << this->grades << std::endl;
  for (int i = 0; i < this->n_grades; i++) {
    std::cout << "  " << this->grades[i] << std::endl;
  }
  std::cout << std::endl;
}


int main(int argc, char** argv) {
  Student s1("Luke Skywalker", 933123456);
  s1.add_grade(4.0);
  s1.add_grade(3.75);
  s1.print_student();

  // Student* s3 = new Student("Darth Vader", 933654321);
  // s3->add_grade(1.0);
  // s3->print_student();
  // delete s3;

  // Student* students = new Student[2];
  // delete[] students;
  //
  // Student** students_dyn = new Student*[3];
  // for (int i = 0; i < 3; i++) {
  //   students_dyn[i] = new Student;
  // }

  // Student s2 = s1;
  Student s2;
  // s2 = "some string";
  s2 = s1;
  s2.add_grade(3.5);
  s2.print_student();

  // for (int i = 0; i < 3; i++) {
  //   delete students_dyn[i];
  // }
  // delete[] students_dyn;

}
