#include <iostream>
#include <locale>
#include <math.h>

using namespace std;


// ЗАДАНИЯ размещены в строках: 107, 154, 161, 183, 210, 223, 230, 258, 272, 278, 284, 290, 324, 370


// точка на плоскости
struct Point
{
    ///////////////////
    // поля (fields) //
    ///////////////////

    int x;
    int y;

    //////////////////
    // конструкторы //
    //////////////////

    // конструктор по умолчанию
    Point()
    {
        this->x = 0;
        this->y = 0;
    };

    // конструктор с параметрами
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    // альтернативная форма 
    // инициализации полей 
    // в конструкторе

    //Point()
    //    : x(0), y(0)
    //{
    //}

    //Point(int x, int y)
    //    : x(x), y(y)
    //{
    //}

    //////////////////////
    // методы (methods) //
    //////////////////////

    // вычисляет расстояние от точки до другой точки
    double distance_to(Point other)
    {
        int dx = other.x - this->x;
        int dy = other.y - this->y;

        return sqrt(dx * dx + dy * dy);
    }
};

// отрезок на плоскости
struct LineSegment
{
    ///////////////////
    // поля (fields) //
    ///////////////////

    Point p1;
    Point p2;

    //////////////////
    // конструкторы //
    //////////////////

    // конструктор по умолчанию
    LineSegment()
        : p1(Point()), p2(Point())
    {
    };

    // конструктор с параметрами
    LineSegment(Point p1, Point p2)
        : p1(p1), p2(p2)
    {
    };

    //////////////////////
    // методы (methods) //
    //////////////////////

    // вычисляет длину отрезка
    double length()
    {
        return p1.distance_to(p2);
    };

    // проверяет, находится ли точка на отрезке 
    // (содержит ли отрезок точку)
    bool contains(Point p)
    {
        // TODO: написать код
    };
};

// прямая на плоскости
struct Line
{
    ///////////////////
    // поля (fields) //
    ///////////////////

    // прямая на плоскости задается уравнением:
    // Ax + By + C = 0

    double A;
    double B;
    double C;

    //////////////////
    // конструкторы //
    //////////////////

    // конструктор по умолчанию
    Line()
        : A(0), B(1), C(0)  // ось Ox
    {
    };

    // конструктор с параметрами
    Line(Point p1, Point p2)
    {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;

        this->A = dy;
        this->B = -dx;
        this->C = p1.y * dx - p1.x * dy;
    };

    //////////////////////
    // методы (methods) //
    //////////////////////

    // проверяет, находится ли точка на прямой 
    // (содержит ли прямая точку)
    bool contains(Point p)
    {
        // TODO: написать код
    };

    // проверяет, находится ли отрезок на прямой 
    // (содержит ли прямая отрезок)
    bool contains(LineSegment ls)
    {
        // TODO: написать код
    };

    // проверяет, совпадает ли прямая с другой прямой
    bool is_coincide_to(Line other)
    {
        return this->A * other.B == other.A * this->B && 
                this->B * other.C == other.B * this->C;
    }

    // проверяет, параллельна ли прямая другой прямой
    // (совпадающие прямые будем считать параллельными)
    bool is_parallel_to(Line other)
    {
        // прямые параллельны, если отношение A / B у них одинаковое
        return this->A * other.B == other.A * this->B;
    };

    // проверяет, пересекается ли прямая с другой прямой
    // (совпадающие прямые будем считать пересекающимися)
    bool intersects_with(Line other)
    {
        // TODO: написать код
    };
};

// ломаная на плоскости
struct BrokenLine
{
    ///////////////////
    // поля (fields) //
    ///////////////////

    int segments_count;
    LineSegment* segments;

    //////////////////
    // конструкторы //
    //////////////////

    // конструктор по умолчанию
    BrokenLine()
        : segments(NULL), segments_count(0)
    {
    };

    // конструктор с параметрами
    BrokenLine(Point points[])
    {
        // TODO: написать код

        // ВНИМАНИЕ: отрезки ломаной нужно создавать динамически,
        // иначе для всех ломаных будет использована одна и та же память
    }

    //////////////////////
    // методы (methods) //
    //////////////////////

    // вычисляет длину ломаной
    double length()
    {
        // TODO: написать код
    };

    // проверяет, находится ли точка на ломаной 
    // (содержит ли ломаная точку)
    bool contains(Point p)
    {
        // TODO: написать код
    };
};

// треугольник на плоскости
struct Triangle
{
    ///////////////////
    // поля (fields) //
    ///////////////////

    LineSegment* AB;
    LineSegment* BC;
    LineSegment* CA;

    //////////////////
    // конструкторы //
    //////////////////

    // конструктор по умолчанию
    Triangle()
        : AB(NULL), BC(NULL), CA(NULL)
    {
    };

    // конструктор с параметрами
    Triangle(Point A, Point B, Point C)
    {
        // TODO: написать код

        // ВНИМАНИЕ: стороны треугольника нужно создавать динамически,
        // потому что мы объявили поля как указатели (так правильнее)
    }

    //////////////////////
    // методы (methods) //
    //////////////////////

    // проверяет, вырожден ли треугольник
    // (то есть, лежат ли его вершины на одной прямой)
    bool is_degenerate()
    {
        // TODO: написать код
    }

    // проверяет, является ли треугольник прямоугольным
    bool is_right_triangle()
    {
        // TODO: написать код
    }

    // вычисляет периметр треугольника
    double perimeter()
    {
        // TODO: написать код
    };

    // вычисляет площадь треугольника
    double area()
    {
        // TODO: написать код

        // площадь тругольника по формуле Герона равна 
        // корню из произведения разностей 
        // полупериметра треугольника (p) 
        // и каждой из его сторон (a, b, c)
    };
};


int main()
{
    setlocale(LC_CTYPE, "Russian");

    // FYI: выражение вида case ? value_true : value_false -- 
    // так называемый тернарный оператор; его значение равно 
    // подвыражению value_true, если условие case истинно,
    // или подвыражению value_false, если оно ложно


    bool test_result;

    LineSegment segment11(Point(1, 1), Point(5, 5));

    test_result = segment11.contains(Point(3, 3));
    cout << "Тест 1.1: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = !segment11.contains(Point(2, 3));
    cout << "Тест 1.2: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = !segment11.contains(Point(8, 8));
    cout << "Тест 1.3: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;


    // TODO: придумать и записать по образцу выше
    // тестовые случаи для методов 
    // contains(Point) и contains(LineSegment) класса Line


    Line line31(Point(1, 10), Point(10, 15));
    Line line32(Point(20, 35), Point(2, 25));
    Line line33(Point(1, 1), Point(1, 10));
    Line line34(Point(2, 20), Point(2, 2));

    test_result = line31.is_parallel_to(line31);
    cout << "Тест 3.1.1: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = line31.is_parallel_to(line32);
    cout << "Тест 3.1.2: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = !line31.is_parallel_to(line33);
    cout << "Тест 3.1.3: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = line33.is_parallel_to(line34);
    cout << "Тест 3.1.4: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;


    test_result = line31.is_coincide_to(line31);
    cout << "Тест 3.2.1: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = !line31.is_coincide_to(line32);
    cout << "Тест 3.2.2: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = line33.is_coincide_to(line34);
    cout << "Тест 3.2.3: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;


    test_result = line31.intersects_with(line31);
    cout << "Тест 3.3.1: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = !line31.intersects_with(line32);
    cout << "Тест 3.3.2: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = line33.intersects_with(line32);
    cout << "Тест 3.3.3: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;

    test_result = line33.intersects_with(line34);
    cout << "Тест 3.3.4: " << (test_result ? "ОК" : "ПРОВАЛЕН") << endl;


    // TODO: придумать и записать по образцу выше
    // тестовые случаи для методов 
    // is_degenerate() и is_right_triangle() класса Triangle

}


