//////////////////////////////////////////////////////////////////////////////
// inout.h
// заголовочний файл – оголошення функцій введення та виводу масиву

#pragma once

#include <string>
#include "student.h"

using namespace std;

// введення цілого числа з діапазону [lo; hi] – з контролем помилок користувача
int InputInt(const string prompt, const int lo, const int hi);
// введення непорожнього літерного рядка – з контролем помилок користувача
string InputString(const string prompt);

void Create(Student *p, const int N);
void Print(Student *p, const int N);
void PrintIndexSorted(Student *p, int *I, const int N);
