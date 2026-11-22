#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_10_2B/student.h"
#include "../Lab_10_2B/sort.h"
#include "../Lab_10_2B/search.h"

#include "../Lab_10_2B/student.cpp"
#include "../Lab_10_2B/sort.cpp"
#include "../Lab_10_2B/search.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102B
{
    // формування тестового масиву з 5 студентів групи РІ-13
    void Fill(Student *p)
    {
        p[0].prizv = "Бойко";        p[0].kurs = 2; p[0].spec = KOMP_NAUKY;
        p[0].programuvannya = 5;
        p[1].prizv = "Бойчук";       p[1].kurs = 1; p[1].spec = INFORMATYKA;
        p[1].chys_metody = 4;
        p[2].prizv = "Грех";         p[2].kurs = 2; p[2].spec = KOMP_NAUKY;
        p[2].programuvannya = 3;
        p[3].prizv = "Гримак";       p[3].kurs = 1; p[3].spec = INFORMATYKA;
        p[3].chys_metody = 5;
        p[4].prizv = "Грушка";       p[4].kurs = 1; p[4].spec = KOMP_NAUKY;
        p[4].programuvannya = 4;
    }

    TEST_CLASS(UnitTest102B)
    {
    public:

        TEST_METHOD(TestSort)
        {
            Student p[5];
            Fill(p);
            Sort(p, 5);  // курс, спеціальність, прізвище за спаданням
            Assert::IsTrue(p[0].prizv == "Гримак");
            Assert::IsTrue(p[1].prizv == "Бойчук");
            Assert::IsTrue(p[2].prizv == "Грушка");
            Assert::IsTrue(p[3].prizv == "Грех");
            Assert::IsTrue(p[4].prizv == "Бойко");
            // поле об'єднання переміщується разом зі структурою
            Assert::AreEqual(5, p[0].chys_metody);     // Гримак
            Assert::AreEqual(3, p[3].programuvannya);  // Грех
        }

        TEST_METHOD(TestIndexSort)
        {
            Student p[5];
            Fill(p);
            int *I = IndexSort(p, 5);  // курс, спеціальність, прізвище за зростанням
            Assert::AreEqual(1, I[0]);   // Бойчук
            Assert::AreEqual(3, I[1]);   // Гримак
            Assert::AreEqual(4, I[2]);   // Грушка
            Assert::AreEqual(0, I[3]);   // Бойко
            Assert::AreEqual(2, I[4]);   // Грех
            Assert::IsTrue(p[1].prizv == "Бойчук"); // масив не змінився
            delete[] I;
        }

        TEST_METHOD(TestBinSearch)
        {
            Student p[5];
            Fill(p);
            Sort(p, 5);
            Assert::AreEqual(1,  BinSearch(p, 5, "Бойчук",    1, INFORMATYKA));
            Assert::AreEqual(4,  BinSearch(p, 5, "Бойко",     2, KOMP_NAUKY));
            Assert::AreEqual(-1, BinSearch(p, 5, "Грех",      2, INFORMATYKA));
            Assert::AreEqual(-1, BinSearch(p, 5, "Грушка",    3, KOMP_NAUKY));
        }
    };
}
