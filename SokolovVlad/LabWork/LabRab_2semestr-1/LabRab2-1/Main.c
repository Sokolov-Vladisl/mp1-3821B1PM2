#include"Functions.h"
#include <windows.h>

















void main()
{

	setlocale(LC_ALL, "Rus");


	double betterX, x;

	double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078;
	int constanta, x1, i = 1;

//----------------------------------------------------------------------------------------
	/* ����������� ������ */	double errorFactSin, errorFactCos, errorFactExp, errorFactLn;		 double recursiveErrorFactSin, recursiveErrorFactCos, recursiveErrorFactExp, recursiveErrorFactLn;
	/* ���������� ������ */		double errorAbsSin, errorAbsCos, errorAbsExp, errorAbsLn;			 double recursiveErrorAbsSin, recursiveErrorAbsCos, recursiveErrorAbsExp, recursiveErrorAbsLn;
//----------------------------------------------------------------------------------------

	printf("\n\n [��������!!!] ��-�� �������� ������ ������ ������������� ������� � <������������� �����> ");
	printf("\n\n      ������� x = ");
	scanf_s("%lf", &x);

	betterX = x;
	while (x - 2 * PI > 0)
	{                       
		x -= 2 * PI;
	}

	system("cls");

	double PredElLn = betterX, PredElSin = x, PredElCos = 1, PredElExp = 1, expx = 1, cosx = 1, sinx = x, lnx = betterX;
//----------------------------------------------------------


	double recursiveSin = recursive_sin(x, x, 0);

	double recursiveCos = recursive_cos(1.0, x, 0);

	double recursiveExp = recursive_exp(1.0, betterX, 0);

	double recursiveLn = recursive_ln(betterX, betterX, 1);


//----------------------------------------------------------


	for(i=1;i < 101010;i++)                     // 01101010 01101111 01101011 01100101         ������ ����!!!
	{
		if (i % 2 == 0) x1 = 1;
		else x1 = -1;

		PredElLn = next_element_lnx(PredElLn, betterX, i);
		PredElSin = next_element_sin(PredElSin, x, i);
		PredElCos = next_element_cos(PredElCos, x, i);
		PredElExp = next_element_exp(PredElExp, betterX, i);

		lnx = lnx + x1 * PredElLn;
		sinx = sinx + x1 * PredElSin;
		cosx = cosx + x1 * PredElCos;
		expx = expx + PredElExp;

	}




//--------------------- ����� ������ --------------------------------------------------------------------- ����� ������ -------------------------------------------

	errorFactSin = ((sin(betterX) - sinx) / sin(betterX)) * 100;			recursiveErrorFactSin = ((sin(betterX) - recursiveSin) / sin(betterX)) * 100;
	errorAbsSin = sinx - sin(betterX);										recursiveErrorAbsSin = recursiveSin - sin(betterX);

	errorFactCos = ((cos(betterX) - cosx) / cos(betterX)) * 100;			recursiveErrorFactCos = ((cos(betterX) - recursiveCos) / cos(betterX)) * 100;
	errorAbsCos = cosx - cos(betterX);										recursiveErrorAbsCos = recursiveCos - cos(betterX);

	errorFactExp = ((exp(betterX) - expx) / exp(betterX)) * 100;			recursiveErrorFactExp = ((exp(betterX) - recursiveExp) / exp(betterX)) * 100;
	errorAbsExp = expx - exp(betterX);										recursiveErrorAbsExp = recursiveExp - exp(betterX);

	errorFactLn = ((log(betterX + 1) - lnx) / log(betterX + 1)) * 100;		recursiveErrorFactLn = ((log(betterX + 1) - recursiveLn) / log(betterX + 1)) * 100;
	errorAbsLn = lnx - log(betterX + 1);									recursiveErrorAbsLn = recursiveLn - log(betterX + 1);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------



//	printf("                                                                                                ");





	printf("\n ��� x = %lf\n\n----------- [ ����� ������������ ] -------------------------", betterX);
	printf("\n");
	printf("\n");
	printf(" ������������ sinx = %lf         ��������� sinx = %lf \n", sinx, sin(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", errorFactSin, errorAbsSin);
	printf("\n");
	printf(" ������������ cosx = %lf          ��������� cosx = %lf \n", cosx, cos(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", errorFactCos, errorAbsCos);
	printf("\n");
	printf(" ������������ expx = %lf          ��������� expx = %lf \n", expx, exp(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", errorFactExp, errorAbsExp);
	printf("\n");
	printf(" ������������ ln(1+x)= %lf          ��������� ln(1+x)= %lf \n", lnx, log(betterX + 1));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", errorFactLn, errorAbsLn);
	printf("\n");

	
	
	printf("\n----------- [ ����� �������� ] -------------------------");
	printf("\n");
	printf("\n");
	printf(" ������������ sinx = %lf         ��������� sinx = %lf \n", recursiveSin, sin(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", recursiveErrorFactSin, recursiveErrorAbsSin);
	printf("\n");
	printf(" ������������ cosx = %lf         ��������� cosx = %lf\n", recursiveCos, cos(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", recursiveErrorFactCos, recursiveErrorAbsCos);
	printf("\n");
	printf(" ������������ expx = %lf         ��������� expx = %lf\n", recursiveExp, exp(betterX));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", recursiveErrorFactExp, recursiveErrorAbsExp);
	printf("\n");
	printf(" ������������ ln(1+x)= %lf         ��������� ln(1+x)= %lf \n", recursiveLn, log(betterX + 1));
	printf(" ( ����������� ������ = %lf          ���������� ������ = %.16lf )\n", recursiveErrorFactLn, recursiveErrorAbsLn);

	if (recursiveLn == 0.0) { printf("\n\n\n\n\n������ � ����������� ��������� ( ln(1+x) )  ----->   �������: x < -1  ���  x > 1 "); }
	printf("\n\n\n\n\n\n\n\n\n\n");
}