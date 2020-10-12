#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

double fun(double x)
{
	return x*x*sin(x);
}

double funsin(double x)
{
	return fun(x)*sin(5*x);
}

int main()
{
    double P[10], q[20],XX[20][10];
    int N[20][10];

    double a,b,Xmin,Fmin,R;
    setlocale(LC_ALL, "russian");
    a=9; b=12;
    for (int j=0; j < 20; j++)
    {
        q[j]=(j+1)*0.005;
    }
    for (int i=0; i < 10; i++)
    {
        P[i]=0.9+i*0.01;
    }

    for (int i=0; i < 20; i++)
    {
        for (int j=0; j < 10; j++)
        {
            N[i][j]=(int)(log(1-P[j])/log(1-q[i])+1);
        }

    }
    //������ �������
    printf("q\p\t|");
    for (int i=0; i < 10; i++) printf("%3.2f\t|",P[i]);
    printf("\n");
    printf("----------------------------------------------------------------------------------------\n");
    for (int j=0; j < 20; j++)
    {
        printf("%4.3f\t|",q[j]);
        for (int i=0; i < 10; i++) printf("%d\t|",N[j][i]);
        printf("\n");
    }
    printf("\n\n");

    srand(time(NULL));//��� ���� ��� ������ ������� ���� ������ ��������� �����
    //���� ����� ������ ���������� ������������������, ������ ������� ��� ������
    printf("q\p\t|");
    for (int i=0; i < 10; i++) printf("%3.2f    |",P[i]);
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for (int j=0; j < 20; j++)
    {
        printf("%4.3f\t|",q[j]);
        for (int i=0; i < 10; i++)
        {
            R = (double)(rand()%10000)/10000; // ��������� ����� �� 0 �� 1
            R = a + (b-a)*R; //��������� ����� �� a �� b;
            Xmin = R; Fmin=fun(R);
            XX[j][i]=Xmin;
            for (int k=1; k < N[j][i]; k++)
            {
                R = (double)(rand()%10000)/10000; // ��������� ����� �� 0 �� 1
                R = a + (b-a)*R; //��������� ����� �� a �� b;
                if (fun(R)<Fmin)
                {
                    Xmin = R; Fmin=fun(R);
                    XX[j][i]=Xmin;
                }
            }
            printf("%6.4f |",Xmin);
        }
        printf("\n");
    }
    printf("\n\n");

        printf("q \p\t|");
    for (int i=0; i < 10; i++) printf("%3.2f    |",P[i]);
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for (int j=0; j < 20; j++)
    {
        printf("%4.3f\t|",q[j]);
        for (int i=0; i < 10; i++)
        {
            R = (double)(rand()%10000)/10000; // ��������� ����� �� 0 �� 1
            R = a + (b-a)*R; //��������� ����� �� a �� b;
            Xmin = R; Fmin=funsin(R);
            for (int k=1; k < N[j][i]; k++)
            {
                R = (double)(rand()%10000)/10000; // ��������� ����� �� 0 �� 1
                R = a + (b-a)*R; //��������� ����� �� a �� b;
                if (fun(R)<Fmin)
                {
                    Xmin = R; Fmin=funsin(R);
                }
            }
            printf("%7.4f |",Xmin);
        }
        printf("\n");
    }
    printf("\n\n");

    //���������� ������� N �� �����������
    ofstream out("N.txt");
    ofstream out1("X.txt");

    for (int j=0; j < 20; j++)
    {
        for (int i=0; i < 10; i++)
        {
            out << N[j][i] <<endl;
            out1 << abs(XX[j][i]-11.1727) <<endl;
        }
    }
    out.close();
    out1.close();
    return 0;
}
