// sp8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

using namespace std;

typedef struct {
    float area, perimetr;
    char color[25]; /* Общие компоненты: площадь и периметр */
    int type; /* Метка активного компонента */
    union { /* Переменный компонент */
        float r; /* радиус окружности */
        float a[2]; /* две стороны прямоугольника */
        float b[3]; /* три стороны треугольника */
    } geomfig; /* Имя объединения - переменного компонента */
} fig;
fig f; /* Определение переменной f типа fig */
typedef enum { circle, rect, triangle } fclass;
//fig rectangle; /* Определение переменной f типа fig */
//fig triangle; /* Определение переменной f типа fig */
//fig circle; /* Определение переменной f типа fig */

int main()
{
    setlocale(LC_ALL, "rus");

    int R;
    cout << "R=";
    cin >> R;

    std::cout << std::endl;
    float cPerimetr = 0, cArea = 0.0;
    cArea = 3.14 * pow(R, 2);
    cPerimetr = 2 * 3.14 * R;
    cout << "Sc=" << cArea << "\nPc=" << cPerimetr<<endl;

    std::cout << std::endl;
    int A,B;
    cout << "A=";
    cin >> A;
    cout << "B=";
    cin >> B;

    float rPerimetr = 0, rArea = 0;
    rPerimetr = 2*(A+B);
    rArea = A*B;
    cout << "Sr=" << rArea << "\nPr=" << rPerimetr << endl;

    std::cout << std::endl;
    int X, Y, Z;
    cout << "X=";
    cin >> X;
    cout << "Y=";
    cin >> Y;
    cout << "Z=";
    cin >> Z;

    float tPerimetr = 0, tArea = 0,P2;
    tPerimetr = Z + X + Y;
    P2 = tPerimetr / 2;
    tArea = sqrt(P2*(P2-Z)*(P2-X)*(P2-Y));
    cout << "St=" << tArea << "\nPt=" << tPerimetr << endl;

    f.type = triangle;
    f.area = tArea;   f.geomfig.b[0] = Z; f.geomfig.b[1] = X; f.geomfig.b[2] = Y;
    f.perimetr = tPerimetr;
    f.type = rect;
    f.area = rArea; f.geomfig.a[0] = A;f.geomfig.a[1]=B;
    f.perimetr = rPerimetr;
    f.type = circle;
    f.area = cArea; f.geomfig.r=R;
    f.perimetr = cPerimetr;

    list<float> Areas{ tArea,cArea,rArea };
    Areas.sort();
    //Areas.reverse();
    std::cout << std::endl;
    for (float n : Areas)
        std::cout << n << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
