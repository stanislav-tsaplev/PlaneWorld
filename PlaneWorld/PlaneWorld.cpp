#include <iostream>
#include <locale>
#include <math.h>

using namespace std;


// ������� ��������� � �������: 107, 154, 161, 183, 210, 223, 230, 258, 272, 278, 284, 290, 324, 370


// ����� �� ���������
struct Point
{
    ///////////////////
    // ���� (fields) //
    ///////////////////

    int x;
    int y;

    //////////////////
    // ������������ //
    //////////////////

    // ����������� �� ���������
    Point()
    {
        this->x = 0;
        this->y = 0;
    };

    // ����������� � �����������
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    // �������������� ����� 
    // ������������� ����� 
    // � ������������

    //Point()
    //    : x(0), y(0)
    //{
    //}

    //Point(int x, int y)
    //    : x(x), y(y)
    //{
    //}

    //////////////////////
    // ������ (methods) //
    //////////////////////

    // ��������� ���������� �� ����� �� ������ �����
    double distance_to(Point other)
    {
        int dx = other.x - this->x;
        int dy = other.y - this->y;

        return sqrt(dx * dx + dy * dy);
    }
};

// ������� �� ���������
struct LineSegment
{
    ///////////////////
    // ���� (fields) //
    ///////////////////

    Point p1;
    Point p2;

    //////////////////
    // ������������ //
    //////////////////

    // ����������� �� ���������
    LineSegment()
        : p1(Point()), p2(Point())
    {
    };

    // ����������� � �����������
    LineSegment(Point p1, Point p2)
        : p1(p1), p2(p2)
    {
    };

    //////////////////////
    // ������ (methods) //
    //////////////////////

    // ��������� ����� �������
    double length()
    {
        return p1.distance_to(p2);
    };

    // ���������, ��������� �� ����� �� ������� 
    // (�������� �� ������� �����)
    bool contains(Point p)
    {
        // TODO: �������� ���
    };
};

// ������ �� ���������
struct Line
{
    ///////////////////
    // ���� (fields) //
    ///////////////////

    // ������ �� ��������� �������� ����������:
    // Ax + By + C = 0

    double A;
    double B;
    double C;

    //////////////////
    // ������������ //
    //////////////////

    // ����������� �� ���������
    Line()
        : A(0), B(1), C(0)  // ��� Ox
    {
    };

    // ����������� � �����������
    Line(Point p1, Point p2)
    {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;

        this->A = dy;
        this->B = -dx;
        this->C = p1.y * dx - p1.x * dy;
    };

    //////////////////////
    // ������ (methods) //
    //////////////////////

    // ���������, ��������� �� ����� �� ������ 
    // (�������� �� ������ �����)
    bool contains(Point p)
    {
        // TODO: �������� ���
    };

    // ���������, ��������� �� ������� �� ������ 
    // (�������� �� ������ �������)
    bool contains(LineSegment ls)
    {
        // TODO: �������� ���
    };

    // ���������, ��������� �� ������ � ������ ������
    bool is_coincide_to(Line other)
    {
        return this->A * other.B == other.A * this->B && 
                this->B * other.C == other.B * this->C;
    }

    // ���������, ����������� �� ������ ������ ������
    // (����������� ������ ����� ������� �������������)
    bool is_parallel_to(Line other)
    {
        // ������ �����������, ���� ��������� A / B � ��� ����������
        return this->A * other.B == other.A * this->B;
    };

    // ���������, ������������ �� ������ � ������ ������
    // (����������� ������ ����� ������� ���������������)
    bool intersects_with(Line other)
    {
        // TODO: �������� ���
    };
};

// ������� �� ���������
struct BrokenLine
{
    ///////////////////
    // ���� (fields) //
    ///////////////////

    int segments_count;
    LineSegment* segments;

    //////////////////
    // ������������ //
    //////////////////

    // ����������� �� ���������
    BrokenLine()
        : segments(NULL), segments_count(0)
    {
    };

    // ����������� � �����������
    BrokenLine(Point points[])
    {
        // TODO: �������� ���

        // ��������: ������� ������� ����� ��������� �����������,
        // ����� ��� ���� ������� ����� ������������ ���� � �� �� ������
    }

    //////////////////////
    // ������ (methods) //
    //////////////////////

    // ��������� ����� �������
    double length()
    {
        // TODO: �������� ���
    };

    // ���������, ��������� �� ����� �� ������� 
    // (�������� �� ������� �����)
    bool contains(Point p)
    {
        // TODO: �������� ���
    };
};

// ����������� �� ���������
struct Triangle
{
    ///////////////////
    // ���� (fields) //
    ///////////////////

    LineSegment* AB;
    LineSegment* BC;
    LineSegment* CA;

    //////////////////
    // ������������ //
    //////////////////

    // ����������� �� ���������
    Triangle()
        : AB(NULL), BC(NULL), CA(NULL)
    {
    };

    // ����������� � �����������
    Triangle(Point A, Point B, Point C)
    {
        // TODO: �������� ���

        // ��������: ������� ������������ ����� ��������� �����������,
        // ������ ��� �� �������� ���� ��� ��������� (��� ����������)
    }

    //////////////////////
    // ������ (methods) //
    //////////////////////

    // ���������, �������� �� �����������
    // (�� ����, ����� �� ��� ������� �� ����� ������)
    bool is_degenerate()
    {
        // TODO: �������� ���
    }

    // ���������, �������� �� ����������� �������������
    bool is_right_triangle()
    {
        // TODO: �������� ���
    }

    // ��������� �������� ������������
    double perimeter()
    {
        // TODO: �������� ���
    };

    // ��������� ������� ������������
    double area()
    {
        // TODO: �������� ���

        // ������� ����������� �� ������� ������ ����� 
        // ����� �� ������������ ��������� 
        // ������������� ������������ (p) 
        // � ������ �� ��� ������ (a, b, c)
    };
};


int main()
{
    setlocale(LC_CTYPE, "Russian");

    // FYI: ��������� ���� case ? value_true : value_false -- 
    // ��� ���������� ��������� ��������; ��� �������� ����� 
    // ������������ value_true, ���� ������� case �������,
    // ��� ������������ value_false, ���� ��� �����


    bool test_result;

    LineSegment segment11(Point(1, 1), Point(5, 5));

    test_result = segment11.contains(Point(3, 3));
    cout << "���� 1.1: " << (test_result ? "��" : "��������") << endl;

    test_result = !segment11.contains(Point(2, 3));
    cout << "���� 1.2: " << (test_result ? "��" : "��������") << endl;

    test_result = !segment11.contains(Point(8, 8));
    cout << "���� 1.3: " << (test_result ? "��" : "��������") << endl;


    // TODO: ��������� � �������� �� ������� ����
    // �������� ������ ��� ������� 
    // contains(Point) � contains(LineSegment) ������ Line


    Line line31(Point(1, 10), Point(10, 15));
    Line line32(Point(20, 35), Point(2, 25));
    Line line33(Point(1, 1), Point(1, 10));
    Line line34(Point(2, 20), Point(2, 2));

    test_result = line31.is_parallel_to(line31);
    cout << "���� 3.1.1: " << (test_result ? "��" : "��������") << endl;

    test_result = line31.is_parallel_to(line32);
    cout << "���� 3.1.2: " << (test_result ? "��" : "��������") << endl;

    test_result = !line31.is_parallel_to(line33);
    cout << "���� 3.1.3: " << (test_result ? "��" : "��������") << endl;

    test_result = line33.is_parallel_to(line34);
    cout << "���� 3.1.4: " << (test_result ? "��" : "��������") << endl;


    test_result = line31.is_coincide_to(line31);
    cout << "���� 3.2.1: " << (test_result ? "��" : "��������") << endl;

    test_result = !line31.is_coincide_to(line32);
    cout << "���� 3.2.2: " << (test_result ? "��" : "��������") << endl;

    test_result = line33.is_coincide_to(line34);
    cout << "���� 3.2.3: " << (test_result ? "��" : "��������") << endl;


    test_result = line31.intersects_with(line31);
    cout << "���� 3.3.1: " << (test_result ? "��" : "��������") << endl;

    test_result = !line31.intersects_with(line32);
    cout << "���� 3.3.2: " << (test_result ? "��" : "��������") << endl;

    test_result = line33.intersects_with(line32);
    cout << "���� 3.3.3: " << (test_result ? "��" : "��������") << endl;

    test_result = line33.intersects_with(line34);
    cout << "���� 3.3.4: " << (test_result ? "��" : "��������") << endl;


    // TODO: ��������� � �������� �� ������� ����
    // �������� ������ ��� ������� 
    // is_degenerate() � is_right_triangle() ������ Triangle

}


