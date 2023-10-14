#include <iostream>
#include <string>

using namespace std;
class DateTime {
public:
    DateTime(int day, int month, int year) : day(day), month(month), year(year) {}

    
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

private:
    int day, month, year;
};

class Student {
public:
    Student() : Student("", "", "", DateTime(0, 0, 0), "", "") {}

    Student(const string& lastName, const string& firstName, const string& middleName,
        const DateTime& birthDate, const string& homeAddress, const string& phoneNumber)
        : lastName(lastName), firstName(firstName), middleName(middleName),
        birthDate(birthDate), homeAddress(homeAddress), phoneNumber(phoneNumber),
        practiceMarks(nullptr), homeworkMarks(nullptr), examMarks(nullptr),
        practiceCount(0), homeworkCount(0), examCount(0) {}

    // Геттеры и сеттеры для полей
    const string& getLastName() const { return lastName; }
    const string& getFirstName() const { return firstName; }
    const string& getMiddleName() const { return middleName; }
    const DateTime& getBirthDate() const { return birthDate; }
    const string& getHomeAddress() const { return homeAddress; }
    const string& getPhoneNumber() const { return phoneNumber; }

    void setLastName(const string& lastName) { this->lastName = lastName; }
    void setFirstName(const string& firstName) { this->firstName = firstName; }
    void setMiddleName(const string& middleName) { this->middleName = middleName; }
    void setBirthDate(const DateTime& birthDate) { this->birthDate = birthDate; }
    void setHomeAddress(const string& homeAddress) { this->homeAddress = homeAddress; }
    void setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }

    // Метод для вывода информации о студенте
    void displayStudentInfo() const {
        cout << "Last Name: " << lastName << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Middle Name: " << middleName << endl;
        cout << "Birth Date: " << birthDate.getDay() << "/" << birthDate.getMonth() << "/" << birthDate.getYear() << endl;
        cout << "Home Address: " << homeAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
    }

    // Геттеры для количества оценок
    int getPracticeCount() const { return practiceCount; }
    int getHomeworkCount() const { return homeworkCount; }
    int getExamCount() const { return examCount; }

    // Методы для добавления оценок
    void addPracticeMark(int mark) {
        if (practiceCount == 0) {
            practiceMarks = new int[1];
            practiceMarks[0] = mark;
            practiceCount = 1;
        }
        else {
            int* newPracticeMarks = new int[practiceCount + 1];
            for (int i = 0; i < practiceCount; i++) {
                newPracticeMarks[i] = practiceMarks[i];
            }
            newPracticeMarks[practiceCount] = mark;
            delete[] practiceMarks;
            practiceMarks = newPracticeMarks;
            practiceCount++;
        }
    }

    void addHomeworkMark(int mark) {
        if (homeworkCount == 0) {
            homeworkMarks = new int[1];
            homeworkMarks[0] = mark;
            homeworkCount = 1;
        }
        else {
            int* newHomeworkMarks = new int[homeworkCount + 1];
            for (int i = 0; i < homeworkCount; i++) {
                newHomeworkMarks[i] = homeworkMarks[i];
            }
            newHomeworkMarks[homeworkCount] = mark;
            delete[] homeworkMarks;
            homeworkMarks = newHomeworkMarks;
            homeworkCount++;
        }
    }

    void addExamMark(int mark) {
        if (examCount == 0) {
            examMarks = new int[1];
            examMarks[0] = mark;
            examCount = 1;
        }
        else {
            int* newExamMarks = new int[examCount + 1];
            for (int i = 0; i < examCount; i++) {
                newExamMarks[i] = examMarks[i];
            }
            newExamMarks[examCount] = mark;
            delete[] examMarks;
            examMarks = newExamMarks;
            examCount++;
        }
    }

    // Деструктор для освобождения динамически выделенной памяти
    ~Student() {
        delete[] practiceMarks;
        delete[] homeworkMarks;
        delete[] examMarks;
    }

private:
    string lastName;
    string firstName;
    string middleName;
    DateTime birthDate;
    string homeAddress;
    string phoneNumber;
    int* practiceMarks;
    int* homeworkMarks;
    int* examMarks;
    int practiceCount;
    int homeworkCount;
    int examCount;
};

int main() {
    // Пример использования класса Student
    Student student("Smith", "John", "Doe", DateTime(5, 10, 2000), "123 Main St", "555-123-4567");

    student.addPracticeMark(90);
    student.addPracticeMark(85);

    student.addHomeworkMark(95);
    student.addHomeworkMark(88);
    student.addHomeworkMark(92);

    student.addExamMark(78);

    student.displayStudentInfo();
    cout << "Practice Marks: " << student.getPracticeCount() << " marks" << endl;
    cout << "Homework Marks: " << student.getHomeworkCount() << " marks" << endl;
    cout << "Exam Marks: " << student.getExamCount() << " marks" << endl;

    return 0;
}