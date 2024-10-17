#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

// Функция F(x,y)
double f(double x, double y)
{
    return 8-x*x*x-y*y*y;
}

// Функция вычисление объёма
double V(int N)
{
   
    double x = 0, y = 0;
   
    double n = 0; // число точек, попавших в область D

    double xmin = 0;//границы области D
    double xmax = 3;
    double ymin = -sqrt(3.);
    double ymax = sqrt(3.);
   
    double S = 0, H = 0, V = 0;  // площадь, объём и высота

    double r1 = (double)rand() * 1 / RAND_MAX;
    double r2 = (double)rand() * 1 / RAND_MAX;
    for (long int i = 0; i < N; i++)
    {
        r1 = (double)rand() * 1 / RAND_MAX;
        r2 = (double)rand() * 1 / RAND_MAX;
        x = xmin + r1 * (xmax - xmin);
        y = ymin + r2 * (ymax - ymin);
        if ((2*x*x+y*y)<=1&&x>=0&&y>=0)
        {
            n++;
            H = H + (f(x, y));
        }


    }

    // средняя высота
    H = H / n;
    // Вычисление площади
    S = (xmax - xmin) * (ymax - ymin) * (n / N);
    // объём
    V = H * S;
    return V;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int N = 0;
    cout << "Введите количество точек ";
    cin >> N;
    cout << "Объём фигуры = " << setprecision(6)<<V(N) << endl;
}
