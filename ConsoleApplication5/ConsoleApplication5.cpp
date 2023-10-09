#include <iostream>
using namespace std;

/// <summary>
/// Класс, представляющий дату и время.
/// </summary>
class DateTime
{
    int day;
    int month;
    int year;

public:
    /// <summary>
    /// Устанавливает день.
    /// </summary>
    /// <param name="day">День</param>
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// Возвращает день.
    /// </summary>
    /// <returns>День</returns>
    int GetDay() const
    {
        return day;
    }

    /// <summary>
    /// Устанавливает месяц.
    /// </summary>
    /// <param name="month">Месяц</param>
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// Возвращает месяц.
    /// </summary>
    /// <returns>Месяц</returns>
    int GetMonth() const
    {
        return month;
    }

    /// <summary>
    /// Устанавливает год.
    /// </summary>
    void SetYear(int year)
    {
        this->year = year;
    }

    /// <summary>
    /// Возвращает год.
    /// </summary>
    /// <returns>Год</returns>
    int GetYear() const
    {
        return year;
    }

    /// <summary>
    /// Конструктор по умолчанию, устанавливает дату 23.03.2005.
    /// </summary>
    DateTime() : DateTime(23, 3, 2005) {}

    /// <summary>
    /// Конструктор с параметрами дня и месяца, устанавливает год 2004.
    /// </summary>
    /// <param name="day">День</param>
    /// <param name="month">Месяц</param>
    DateTime(int day, int month) : DateTime(day, month, 2004) {}

    /// <summary>
    /// Конструктор с параметрами дня, месяца и года.
    /// </summary>
    /// <param name="day">День</param>
    /// <param name="month">Месяц</param>
    /// <param name="year">Год</param>
    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    /// <summary>
    /// Выводит дату в консоль.
    /// </summary>
    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

//////////////////////////////////////////////////////

/// <summary>
/// Класс, представляющий студента.
/// </summary>
class Student
{
    string name;
    string surname;
    DateTime birthday;
    DateTime study_start; // 01.09.2022

    // TO DO: 

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    // TO DO: practice and exams

public:
    /// <summary>
    /// Конструктор по умолчанию, создает студента с пустыми данными.
    /// </summary>
    Student()
    {
        SetName("");
        SetSurname("");
        SetBirthday({ 9, 10, 2000 });
        SetStudyStart({ 1, 9, 2022 });
    }

    // TO DO: constructors overloading !!!

    // TO DO: make copy c-tor

    /// <summary>
    /// Деструктор класса Student.
    /// </summary>
    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
    }

    /// <summary>
    /// Устанавливает имя студента.
    /// </summary>
    /// <param name="name">Имя студента</param>
    void SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// Возвращает имя студента.
    /// </summary>
    /// <returns>Имя студента</returns>
    string GetName() const
    {
        return name;
    }

private:
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:
    /// <summary>
    /// Возвращает дату рождения студента.
    /// </summary>
    /// <returns>Дата рождения</returns>
    DateTime GetBirthday() const
    {
        return birthday;
    }

    /// <summary>
    /// Устанавливает дату начала учебы студента.
    /// </summary>
    /// <param name="study_start">Дата начала учебы</param>
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    /// <summary>
    /// Возвращает дату начала учебы студента.
    /// </summary>
    /// <returns>Дата начала учебы</returns>
    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary>
    /// Устанавливает фамилию студента.
    /// </summary>
    /// <param name="surname">Фамилия студента</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// Возвращает фамилию студента.
    /// </summary>
    /// <returns>Фамилия студента</returns>
    string GetSurname() const
    {
        return surname;
    }

    /// <summary>
    /// Добавляет оценку за домашнее задание студенту.
    /// </summary>
    /// <param name="rate">Оценка (от 1 до 12)</param>
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }

    /// <summary>
    /// Выводит оценки за домашние задания в консоль.
    /// </summary>
    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// Получает оценку за домашнее задание по индексу.
    /// </summary>
    /// <param name="index">Индекс оценки</param>
    /// <returns>Оценка</returns>
    int GetHometaskRateByIndex(unsigned int index)
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }

    /// <summary>
    /// Возвращает количество оценок за домашние задания.
    /// </summary>
    /// <returns>Количество оценок</returns>
    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    // TO DO: show what can happen if return pointer to array
    /* int* GetHometaskRates() const
    {
        int* copy = new int[hometask_rates_count];
        for (int i = 0; i < hometask_rates_count; i++)
        {
            copy[i] = hometask_rates[i];
        }
        return copy;
    }*/

    // TO DO: a lot of work here...
};

int main()
{
    Student s;
    s.AddHometaskRate(10);
    s.AddHometaskRate(12);
    s.AddHometaskRate(5);
    s.AddHometaskRate(2);
    s.PrintHometaskRates();
    s.AddHometaskRate(7);
    s.AddHometaskRate(7);
    s.AddHometaskRate(8);
    s.AddHometaskRate(8);
    s.PrintHometaskRates();
    cout << s.GetHometasksRatesCount() << "\n"; // 8
}