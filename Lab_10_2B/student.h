//////////////////////////////////////////////////////////////////////////////
// student.h
// заголовочний файл – оголошення типів: перелік спеціальностей та структура з об'єднанням

#pragma once

#include <string>

using namespace std;

// спеціальності перелічені в алфавітному порядку їх назв
enum Spec { INFORMATYKA, KOMP_NAUKY, MATEM_EKONOM, TRUD_NAVCH, FIZ_INF };

extern string specStr[];       // назви спеціальностей – для виводу

struct Student
{
    string prizv;              // прізвище
    int    kurs;               // курс
    Spec   spec;               // спеціальність
    int    fizyka;             // оцінка з фізики
    int    matematyka;         // оцінка з математики
    union                      // третя оцінка – залежно від спеціальності:
    {
        int programuvannya;    // "Комп'ютерні науки"
        int chys_metody;       // "Інформатика"
        int pedagogika;        // всі інші спеціальності
    };
};
