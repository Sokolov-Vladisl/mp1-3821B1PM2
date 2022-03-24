#include"Functions.h"
#include <windows.h>



void main()
{

	setlocale(LC_ALL, "Rus");


	float badX, x;

	float PI = 3.1415926535897932384626433832795028841971693993751058209749445923078;
	int x1, i = 1;

	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	/* ����������� ������ */	double errorFactSin, errorFactCos, errorFactExp, errorFactLn;		 double recursiveErrorFactSin, recursiveErrorFactCos, recursiveErrorFactExp, recursiveErrorFactLn;				double pairErrorFactSin, pairErrorFactCos, pairErrorFactExp, pairErrorFactLn;
	/* ���������� ������ */		double errorAbsSin, errorAbsCos, errorAbsExp, errorAbsLn;			 double recursiveErrorAbsSin, recursiveErrorAbsCos, recursiveErrorAbsExp, recursiveErrorAbsLn;					double pairErrorAbsSin, pairErrorAbsCos, pairErrorAbsExp, pairErrorAbsLn;
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	printf("\n\n [��������!!!] ��-�� �������� ������ ������ ������������� ������� � <������������� �����> ");
	printf("\n\n      ������� x = ");
	scanf_s("%f", &x);

	badX = x;
	double strangeX = x;
	while (x - 2 * PI > 0)
	{
		x -= 2 * PI;
	}

	system("cls");

	float PredElLn = badX, PredElSin = x, PredElCos = 1, PredElExp = 1, expx = 1, cosx = 1, sinx = x, lnx = badX;



//----------------------------------------------------------

	float Array_for_sin[100];
	float Array_for_cos[100];
	float Array_for_exp[100];
	float Array_for_ln[100];

	float pairSin=0, pairCos=0, pairExp=0, pairLn=0;

	 Array_for_sin[0]= PredElSin;   //������ ������� sin
	 Array_for_cos[0]= PredElCos;   //������ ������� cos
	 Array_for_exp[0]= PredElExp;   //������ ������� exp
	 Array_for_ln[0]= PredElLn;     //������ ������� ln

//----------------------------------------------------------


	 float recursiveSin = recursive_sin(x, x, 0);

	 float recursiveCos = recursive_cos(1.0, x, 0);

	 float recursiveExp = recursive_exp(1.0, badX, 0);

	 float recursiveLn = recursive_ln(badX, badX, 1);


//-----------------------------------------------------------


	for (i = 1; i < 100; i++)                   
	{
		if (i % 2 == 0) x1 = 1;
		else x1 = -1;

		
		PredElSin = next_element_sin(PredElSin, x, i);
		PredElCos = next_element_cos(PredElCos, x, i);
		PredElExp = next_element_exp(PredElExp, badX, i);
		PredElLn = next_element_lnx(PredElLn, badX, i);

		lnx = lnx + x1 * PredElLn;
		sinx = sinx + x1 * PredElSin;
		cosx = cosx + x1 * PredElCos;
		expx = expx + PredElExp;


		/*  �������� �������� � ���������� ������������   */
		Array_for_sin[i] = x1 * PredElSin;
		Array_for_cos[i] = x1 * PredElCos;
		Array_for_exp[i] = PredElExp;
		Array_for_ln[i] = x1 * PredElLn;

	}


//------------------------------------------------------------------------------------------------------------

	for (i = 99; i > 0; i -= 2)                                 // �������� �������� ������������
	{
		pairSin += Array_for_sin[i] + Array_for_sin[i - 1];
		pairCos += Array_for_cos[i] + Array_for_cos[i - 1];
		pairExp += Array_for_exp[i] + Array_for_exp[i - 1];
		pairLn += Array_for_ln[i] + Array_for_ln[i - 1];
	}

	//--------------------- ����� ������ --------------------------------------------------------------------- ����� ������ ----------------------------------------------------------------------- ����� ������ ------------------------------------

	errorFactSin = ((sin(strangeX) - sinx) / sin(strangeX)) * 100;			recursiveErrorFactSin = ((sin(strangeX) - recursiveSin) / sin(strangeX)) * 100;				pairErrorFactSin = ((sin(strangeX) - pairSin) / sin(strangeX)) * 100;
	errorAbsSin = sinx - sin(strangeX);										recursiveErrorAbsSin = recursiveSin - sin(strangeX);											pairErrorAbsSin = pairSin - sin(strangeX);
			
	errorFactCos = ((cos(strangeX) - cosx) / cos(strangeX)) * 100;			recursiveErrorFactCos = ((cos(strangeX) - recursiveCos) / cos(strangeX)) * 100;				pairErrorFactCos = ((cos(strangeX) - pairCos) / cos(strangeX)) * 100;
	errorAbsCos = cosx - cos(strangeX);										recursiveErrorAbsCos = recursiveCos - cos(strangeX);											pairErrorAbsCos = pairCos - cos(strangeX);

	errorFactExp = ((exp(strangeX) - expx) / exp(strangeX)) * 100;			recursiveErrorFactExp = ((exp(strangeX) - recursiveExp) / exp(strangeX)) * 100;				pairErrorFactExp = ((exp(strangeX) - pairExp) / exp(strangeX)) * 100;
	errorAbsExp = expx - exp(strangeX);										recursiveErrorAbsExp = recursiveExp - exp(strangeX);											pairErrorAbsExp = pairExp - exp(strangeX);

	errorFactLn = ((log(strangeX + 1) - lnx) / log(strangeX + 1)) * 100;		recursiveErrorFactLn = ((log(strangeX + 1) - recursiveLn) / log(strangeX + 1)) * 100;			pairErrorFactLn = ((log(strangeX + 1) - pairLn) / log(strangeX + 1)) * 100;
	errorAbsLn = lnx - log(strangeX + 1);									recursiveErrorAbsLn = recursiveLn - log(strangeX + 1);										pairErrorAbsLn = pairLn - log(strangeX + 1);
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	//	printf("                                                                                                ");

	printf("\n ��� x = %f\n\n----------- [ ����� ������� ������������ ] -------------------------", badX);
	printf("\n");
	printf("\n");
	printf(" ������������ sinx = %f         ��������� sinx = %f \n", sinx, sin(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", errorFactSin, errorAbsSin);
	printf("\n");
	printf(" ������������ cosx = %f          ��������� cosx = %f \n", cosx, cos(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", errorFactCos, errorAbsCos);
	printf("\n");
	printf(" ������������ expx = %f          ��������� expx = %f \n", expx, exp(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", errorFactExp, errorAbsExp);
	printf("\n");
	printf(" ������������ ln(1+x)= %f          ��������� ln(1+x)= %f \n", lnx, log(strangeX + 1));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", errorFactLn, errorAbsLn);
	printf("\n");



	printf("\n----------- [ ����� �������� (�������� ������������)] -------------------------");
	printf("\n");
	printf("\n");
	printf(" ������������ sinx = %f         ��������� sinx = %f \n", recursiveSin, sin(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", recursiveErrorFactSin, recursiveErrorAbsSin);
	printf("\n");
	printf(" ������������ cosx = %f         ��������� cosx = %f\n", recursiveCos, cos(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", recursiveErrorFactCos, recursiveErrorAbsCos);
	printf("\n");
	printf(" ������������ expx = %f         ��������� expx = %f\n", recursiveExp, exp(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", recursiveErrorFactExp, recursiveErrorAbsExp);
	printf("\n");
	printf(" ������������ ln(1+x)= %f         ��������� ln(1+x)= %f \n", recursiveLn, log(strangeX + 1));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", recursiveErrorFactLn, recursiveErrorAbsLn);
	printf("\n");



	printf("\n----------- [ ����� ��������� ������������ ] -------------------------");
	printf("\n");
	printf("\n");
	printf(" ������������ sinx = %f         ��������� sinx = %f \n", pairSin, sin(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", pairErrorFactSin, pairErrorAbsSin);
	printf("\n");
	printf(" ������������ cosx = %f         ��������� cosx = %f\n", pairCos, cos(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", pairErrorFactCos, pairErrorAbsCos);
	printf("\n");
	printf(" ������������ expx = %f         ��������� expx = %f\n", pairExp, exp(strangeX));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", pairErrorFactExp, pairErrorAbsExp);
	printf("\n");
	printf(" ������������ ln(1+x)= %f         ��������� ln(1+x)= %f \n", pairLn, log(strangeX + 1));
	printf(" ( ����������� ������ = %f          ���������� ������ = %.8f )\n", pairErrorFactLn, pairErrorAbsLn);
	printf("\n");



	if (recursiveLn == 0.0) { printf("\n\n\n\n\n������ � ����������� ��������� ( ln(1+x) )  ----->   �������: x < -1  ���  x > 1 "); }
	printf("\n\n\n\n\n\n\n\n\n\n");

}