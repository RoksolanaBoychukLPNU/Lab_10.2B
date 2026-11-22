//////////////////////////////////////////////////////////////////////////////
// search.cpp
// файл реалізації – функція бінарного пошуку

#include "search.h"

int BinSearch(Student *p, const int N, const string prizv,
              const int kurs, const Spec spec)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
    int L=0, R=N-1, m;
    do {
        m = (L+R)/2;
        if ( p[m].prizv == prizv && p[m].kurs == kurs && p[m].spec == spec )
            return m;
        if (( p[m].kurs < kurs )
            ||
            ( p[m].kurs == kurs &&
              p[m].spec < spec )
            ||
            ( p[m].kurs == kurs &&
              p[m].spec == spec &&
              p[m].prizv > prizv ))     // прізвище – за спаданням
        {
            L = m+1;
        }
        else
        {
            R = m-1;
        }
    } while ( L <= R );
    return -1;
}
