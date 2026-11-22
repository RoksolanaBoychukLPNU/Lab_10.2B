#include <iostream>
#include <iomanip>
#include <string>

#include "inout.h"

using namespace std;

int InputInt(const string prompt, const int lo, const int hi)
{
    int value;
    while ( true )
    {
        cout << prompt; cin >> value;
        if ( cin.fail() || value < lo || value > hi )
        {                          // введено не число або число поза межами
            cin.clear();           // скидаємо стан помилки потоку
            cin.ignore(1000, '\n'); // очищуємо буфер клавіатури
            cout << "     Помилка! Слід ввести ціле число від "
                 << lo << " до " << hi << endl;
        }
        else
        {
            cin.ignore(1000, '\n'); // очищуємо буфер клавіатури
            return value;
        }
    }
}

string InputString(const string prompt)
{
    string s;
    do {
        cout << prompt; getline(cin, s);
        if ( s.empty() )
            cout << "     Помилка! Рядок не може бути порожнім" << endl;
    } while ( s.empty() );
    return s;
}

void Create(Student *p, const int N)
{
    for (int i=0; i<N; i++)
    {
        cout << "Студент № " << i+1 << ":" << endl;

        p[i].prizv = InputString("     прізвище: ");
        p[i].kurs = InputInt("     курс: ", 1, 6);
        cout << "     спеціальність (0 - Інформатика, 1 - Комп'ютерні науки," << endl
             << "       2 - Математика та економіка, 3 - Трудове навчання," << endl
             << "       4 - Фізика та інформатика)" << endl;
        p[i].spec = (Spec)InputInt("     спеціальність: ", 0, 4);
        p[i].fizyka = InputInt("     оцінка з фізики: ", 1, 5);
        p[i].matematyka = InputInt("     оцінка з математики: ", 1, 5);
        switch ( p[i].spec )
        {
        case KOMP_NAUKY:
            p[i].programuvannya = InputInt("     оцінка з програмування : ", 1, 5);
            break;
        case INFORMATYKA:
            p[i].chys_metody = InputInt("     оцінка з чисельних методів : ", 1, 5);
            break;
        case MATEM_EKONOM:
        case TRUD_NAVCH:
        case FIZ_INF:
            p[i].pedagogika = InputInt("     оцінка з педагогіки : ", 1, 5);
            break;
        }
        cout << endl;
    }
}

void Print(Student *p, const int N)
{
    cout << "============================================================================"
         << endl;
    cout << "|  № |   Прізвище  | Курс | Спеціальність | Фіз | Мат | Прог | Ч.м. | Пед. |"
         << endl;
    cout << "----------------------------------------------------------------------------"
         << endl;

    for (int i=0; i<N; i++)
    {
        cout << "| " << setw(2) << right << i+1 << " ";
        cout << "| " << setw(12) << left << p[i].prizv
             << "| " << setw(4) << right << p[i].kurs << " "
             << "| " << setw(14) << left << specStr[ p[i].spec ]
             << "| " << setw(3) << right << p[i].fizyka << " "
             << "| " << setw(3) << right << p[i].matematyka << " ";
        switch ( p[i].spec )
        {
        case KOMP_NAUKY:
            cout << "| " << setw(4) << right << p[i].programuvannya << " "
                 << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << " " << " |" << endl;
            break;
        case INFORMATYKA:
            cout << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << right << p[i].chys_metody << " "
                 << "| " << setw(4) << " " << " |" << endl;
            break;
        case MATEM_EKONOM:
        case TRUD_NAVCH:
        case FIZ_INF:
            cout << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << right << p[i].pedagogika << " |" << endl;
            break;
        }
    }
    cout << "============================================================================"
         << endl;
    cout << endl;
}

void PrintIndexSorted(Student *p, int *I, const int N)
{ // аналогічно функції Print(), але замість звертання p[i]...
  // використовуємо доступ за допомогою індексного масиву І: p[I[i]]...
    cout << "============================================================================"
         << endl;
    cout << "|  № |   Прізвище  | Курс | Спеціальність | Фіз | Мат | Прог | Ч.м. | Пед. |"
         << endl;
    cout << "----------------------------------------------------------------------------"
         << endl;

    for (int i=0; i<N; i++)
    {
        cout << "| " << setw(2) << right << i+1 << " ";
        cout << "| " << setw(12) << left << p[I[i]].prizv
             << "| " << setw(4) << right << p[I[i]].kurs << " "
             << "| " << setw(14) << left << specStr[ p[I[i]].spec ]
             << "| " << setw(3) << right << p[I[i]].fizyka << " "
             << "| " << setw(3) << right << p[I[i]].matematyka << " ";
        switch ( p[I[i]].spec )
        {
        case KOMP_NAUKY:
            cout << "| " << setw(4) << right << p[I[i]].programuvannya << " "
                 << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << " " << " |" << endl;
            break;
        case INFORMATYKA:
            cout << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << right << p[I[i]].chys_metody << " "
                 << "| " << setw(4) << " " << " |" << endl;
            break;
        case MATEM_EKONOM:
        case TRUD_NAVCH:
        case FIZ_INF:
            cout << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << " " << " "
                 << "| " << setw(4) << right << p[I[i]].pedagogika << " |" << endl;
            break;
        }
    }
    cout << "============================================================================"
         << endl;
    cout << endl;
}
