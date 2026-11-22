//////////////////////////////////////////////////////////////////////////////
// search.h
// заголовочний файл – оголошення функції бінарного пошуку

#pragma once

#include <string>
#include "student.h"

using namespace std;

// бінарний пошук у фізично впорядкованому (функцією Sort) масиві
int BinSearch(Student *p, const int N, const string prizv,
              const int kurs, const Spec spec);
