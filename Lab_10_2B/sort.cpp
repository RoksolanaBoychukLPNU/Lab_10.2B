//////////////////////////////////////////////////////////////////////////////
// sort.cpp
// файл реалізації – функції фізичного та індексного впорядкування

#include "sort.h"

void Sort(Student *p, const int N)
{
    Student tmp;
    for (int i0=0; i0<N-1; i0++)        // метод "бульбашки"
    for (int i1=0; i1<N-i0-1; i1++)
        if (( p[i1].kurs > p[i1+1].kurs )
            ||
            ( p[i1].kurs == p[i1+1].kurs &&
              p[i1].spec > p[i1+1].spec )
            ||
            ( p[i1].kurs == p[i1+1].kurs &&
              p[i1].spec == p[i1+1].spec &&
              p[i1].prizv < p[i1+1].prizv ))    // прізвище – за спаданням
        {
            tmp = p[i1];
            p[i1] = p[i1+1];
            p[i1+1] = tmp;
        }
}

int *IndexSort(Student *p, const int N)
{ // використовуємо метод вставки для формування індексного масиву
  //
  //   int i, j, value;
  //   for (i = 1; i < length; i++) {
  //       value = a[i];
  //       for (j = i - 1; j >= 0 && a[j] > value; j--) {
  //           a[j + 1] = a[j];
  //       }
  //       a[j + 1] = value;
  //   }
    int *I = new int[N];    // створили індексний масив
    for (int i=0; i<N; i++)
        I[i]=i;             // заповнили його початковими даними

    int i, j, value;        // починаємо сортувати масив індексів
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
             j >= 0 && (( p[I[j]].kurs > p[value].kurs ) ||
                        ( p[I[j]].kurs == p[value].kurs &&
                          p[I[j]].spec > p[value].spec ) ||
                        ( p[I[j]].kurs == p[value].kurs &&
                          p[I[j]].spec == p[value].spec &&
                          p[I[j]].prizv > p[value].prizv ));
             j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}
