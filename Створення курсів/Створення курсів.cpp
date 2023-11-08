#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Модель для сутності "Курс"
class Course {
public:
    Course(const string& name, const string& description)
        : name(name), description(description) {}

    string getName() const { return name; }
    string getDescription() const { return description; }

    void setName(const string& newName) { name = newName; }
    void setDescription(const string& newDescription) { description = newDescription; }

private:
    string name;
    string description;
};

// Модель для сутності "Студент"
class Student {
public:
    Student(const string& firstName, const string& lastName)
        : firstName(firstName), lastName(lastName) {}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    void setFirstName(const string& newFirstName) { firstName = newFirstName; }
    void setLastName(const string& newLastName) { lastName = newLastName; }

private:
    string firstName;
    string lastName;
};

// Сервіс для управління курсами
class CourseService {
public:
    void createCourse(const string& name, const string& description) {
        courses.push_back(Course(name, description));
    }

    void editCourse(int index, const string& name, const string& description) {
        if (index >= 0 && index < courses.size()) {
            courses[index].setName(name);
            courses[index].setDescription(description);
        }
    }

    void deleteCourse(int index) {
        if (index >= 0 && index < courses.size()) {
            courses.erase(courses.begin() + index);
        }
    }

    void listCourses() {
        cout << "Список курсів:\n";
        for (int i = 0; i < courses.size(); i++) {
            cout << i + 1 << ". " << courses[i].getName() << " - " << courses[i].getDescription() << "\n";
        }
    }

private:
    vector<Course> courses;
};

// Сервіс для управління студентами
class StudentService {
public:
    void createStudent(const string& firstName, const string& lastName) {
        students.push_back(Student(firstName, lastName));
    }

    void editStudent(int index, const string& firstName, const string& lastName) {
        if (index >= 0 && index < students.size()) {
            students[index].setFirstName(firstName);
            students[index].setLastName(lastName);
        }
    }

    void deleteStudent(int index) {
        if (index >= 0 && index < students.size()) {
            students.erase(students.begin() + index);
        }
    }

    void listStudents() {
        cout << "Список студентів:\n";
        for (int i = 0; i < students.size(); i++) {
            cout << i + 1 << ". " << students[i].getFirstName() << " " << students[i].getLastName() << "\n";
        }
    }

private:
    vector<Student> students;
};

int main() {
    CourseService courseService;
    StudentService studentService;

    int choice;
    while (true) {
        cout << "Оберіть дію:\n";
        cout << "1. Створити курс\n";
        cout << "2. Редагувати курс\n";
        cout << "3. Видалити курс\n";
        cout << "4. Список курсів\n";
        cout << "5. Створити студента\n";
        cout << "6. Редагувати студента\n";
        cout << "7. Видалити студента\n";
        cout << "8. Список студентів\n";
        cout << "0. Вийти\n";

        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            string name, description;
            cout << "Назва курсу: ";
            cin >> name;
            cout << "Опис курсу: ";
            cin >> description;
            courseService.createCourse(name, description);
            break;
        }
        case 2: {
            int index;
            string name, description;
            courseService.listCourses();
            cout << "Виберіть курс для редагування (за номером): ";
            cin >> index;
            cout << "Нова назва курсу: ";
            cin >> name;
            cout << "Новий опис курсу: ";
            cin >> description;
            courseService.editCourse(index - 1, name, description);
            break;
        }
        case 3: {
            int index;
            courseService.listCourses();
            cout << "Виберіть курс для видалення (за номером): ";
            cin >> index;
            courseService.deleteCourse(index - 1);
            break;
        }
        case 4:
            courseService.listCourses();
            break;
        case 5: {
            string firstName, lastName;
            cout << "Ім'я студента: ";
            cin >> firstName;
            cout << "Прізвище студента: ";
            cin >> lastName;
            studentService.createStudent(firstName, lastName);
            break;
        }
        case 6: {
            int index;
            string firstName, lastName;
            studentService.listStudents();
            cout << "Виберіть студента для редагування (за номером): ";
            cin >> index;
            cout << "Нове ім'я студента: ";
            cin >> firstName;
            cout << "Нове прізвище студента: ";
            cin >> lastName;
            studentService.editStudent(index - 1, firstName, lastName);
            break;
        }
        case 7: {
            int index;
            studentService.listStudents();
            cout << "Виберіть студента для видалення (за номером): ";
            cin >> index;
            studentService.deleteStudent(index - 1);
            break;
        }
        case 8:
            studentService.listStudents();
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }

    return 0;
}
