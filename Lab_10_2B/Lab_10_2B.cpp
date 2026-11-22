#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>               

#include "student.h"
#include "inout.h"
#include "sort.h"
#include "search.h"

using namespace std;

int main()
{                           
    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251); 
    int N = InputInt("Введіть кількість студентів N: ", 1, 100);

    Student *p = new Student[N];

    bool created = false;     // чи введено дані
    bool sorted = false;      // чи виконано фізичне впорядкування

    string prizv;
    int kurs;
    Spec spec;
    int found;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - бінарний пошук студента за прізвищем," << endl;
        cout << "        курсом та спеціальністю" << endl;
        cout << " [5] - індексне впорядкування та вивід даних"
             << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        if ( cin.fail() )         // контроль помилок: введено не число
        {
            cin.clear();
            menuItem = -1;
        }
        cin.ignore(1000, '\n');   // очищуємо буфер клавіатури
        cout << endl << endl << endl;

        if ( menuItem >= 2 && menuItem <= 5 && !created )
        {
            cout << "Спочатку слід ввести дані (пункт меню [1])" << endl;
            continue;
        }

        switch ( menuItem )
        {
        case 1:
            Create(p, N);
            created = true;
            sorted = false;
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            sorted = true;
            break;
        case 4:
            if ( !sorted )        // бінарний пошук – лише у впорядкованому масиві
            {
                cout << "Спочатку слід виконати фізичне впорядкування "
                        "(пункт меню [3])" << endl;
                break;
            }
            cout << "Введіть ключі пошуку:" << endl;
            prizv = InputString("     прізвище: ");
            kurs = InputInt("     курс: ", 1, 6);
            cout << "     спеціальність (0 - Інформатика, 1 - Комп'ютерні науки," << endl
                 << "       2 - Математика та економіка, 3 - Трудове навчання," << endl
                 << "       4 - Фізика та інформатика)" << endl;
            spec = (Spec)InputInt("     спеціальність: ", 0, 4);
            cout << endl;
            if ( (found = BinSearch(p, N, prizv, kurs, spec)) != -1 )
                cout << "Знайдено студента в позиції " << found+1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 5:
            PrintIndexSorted(p, IndexSort(p, N), N);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                    "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while ( menuItem != 0 );

    delete[] p;
    return 0;
}
