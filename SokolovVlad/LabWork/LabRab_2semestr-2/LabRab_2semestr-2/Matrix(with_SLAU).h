#pragma once

#include"Vector.h"

double danger_posability = 0.00001; //�������� �� ������� ���������� �������� (����������� ����������)
							  


template<class T>class Matrix : public Vector<Vector<T>>
{
public:

	Vector<T> b;
	Vector<T> x;
	bool manyXs;

	void set() // ������������ ������ �������� �������
	{
		for (int i = 0; i < this->size; i++)
		{
			if(i==2) cout << "        > ������� �������� ��������� �� " << i + 1 << "-�� ������ \n";
			else cout << "        > ������� �������� ��������� �� " << i + 1 << "-�� ������ \n";
			for (int j = 0; j < this->size; j++)
			{
				cin >> this->array[i].array[j];
			}
		}
		
	}


	Matrix(int n) :Vector<Vector<T>>(n) // ������ ������� �������
	{
		this->change_size(n);
		for (int i = 0; i < n; i++)
		{
			this->array[i].change_size(n);
		}

		set();

		b.change_size(n);
		x.change_size(n);
		for (int i = 0; i < this->size; i++)
		{
			x.array[i] = 0;
		}
		b.set();

		cout << "\n\n\n\n ������� ���������. ��� ��������� ������ ������� �� ����� �������...\n";
		int c;

		c = _getch();
		system("CLS");
	}


	Matrix(int n,Matrix<T>& M) :Vector<Vector<T>>(n) // ������ ������� ��� ���������, ����������
	{
		this->change_size(n);
		for (int i = 0; i < n; i++)
		{
			this->array[i].change_size(n);
		}

		for (int i = 0; i < this->size; i++)
			for (int j = 0; j < this->size; j++)
				this->array[i].array[j] = M.array[i].array[j];

		b.change_size(n);
		x.change_size(n);
		for (int i = 0; i < this->size; i++)
		{
			x.array[i] = 0;
		}



	}


		ostream& operator<<(ostream& out) // ����� ����
		{
			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					if (j != 0)
						cout << " + " << this->array[i].array[j] << "*[x" << j<<"] ";
					else
						cout <<i+1<< ">      " << this->array[i].array[j] << "*[x" << j << "] ";
				}
				cout << " = " << b[i] <<"\n";
			}
			out << "\n\n\n\n        > Ÿ �������:\n\n";
			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					if (j != 0)
						cout << "   " << this->array[i].array[j] ;
					else
						cout << "     ( " << this->array[i].array[j] ;
				}
				cout << " | " << b[i] << "  )\n";
			}
			cout << "\n\n___________________________________________\n";
			return out;
		}





		string Whole_Check(Vector<T>& B, Matrix<T> &M) // �������� ������ (X) �� ������� ������� ������� �����������               ������: 5.5/2 != 2.5  ���� ������ ����������� � ������������ �  6.875 %
		{
			string answerCorrect = "���� ��� �����";
			

			Vector<T> Check;
			double ZoneOfBadPosability = 0;
			Check.change_size(this->size);
			bool check_sign = true;
			for (int i = 0; i < this->size; i++)
			{
				Check.array[i] = 0;
				for (int j = 0; j < this->size; j++)
				{
					Check.array[i] += M.array[i].array[j] * x.array[j];
				}
				if (Check.array[i] > B.array[i] && Check.array[i] != 0)
				{
					ZoneOfBadPosability = ((Check.array[i] - B.array[i])/(Check.array[i]))*100.0;
				}
				else if (Check.array[i] < B.array[i] && B.array[i] != 0)
				{
					ZoneOfBadPosability = ((B.array[i] - Check.array[i])/(B.array[i]))*100.0 ;
				}
				
				if (ZoneOfBadPosability >= danger_posability)
				{
					check_sign = false;
					
					break;
				}
			}
			answerCorrect = "[�� ���������] � ������������ ������ ";
			if (check_sign) answerCorrect = "[���������] � ������������ ������ ";
			return answerCorrect;
			
		}


		void Method_Gaussa() // ����� ������
		{
			Vector<T> B;
			Matrix<T> M(this->size,(*this));

			B.change_size(this->size);
			B = b;
			for (int i = 0; i < this->size; i++)
			{
				if (this->array[i].array[i] == 0)
				{
					Vector<T> tmp;
					T B;
					tmp.change_size(this->size);
					for (int j = i + 1; j < this->size; j++)
					{
						if (this->array[j].array[i] != 0)
						{
							B = b.array[j];
							b.array[j] = b.array[i];
							b.array[i] = B;

							tmp = this->array[j];
							this->array[j] = this->array[i];
							this->array[i] = tmp;
							break;
						}
					}
				}
				if (this->array[i].array[i] != 0)
				{
					Vector<T> tmp;
					tmp.change_size(this->size);
					for (int j = 0; j < i; j++)
					{
						if (this->array[j].array[i] != 0)
						{
							tmp = this->array[i];
							tmp *= this->array[j].array[i] / this->array[i].array[i];
							b.array[j] -= b.array[i] * this->array[j].array[i] / this->array[i].array[i];
							this->array[j] -= tmp;
						}
					}
					for (int j = i + 1; j < this->size; j++)
					{
						if (this->array[j].array[i] != 0)
						{
							tmp = this->array[i];
							tmp *= this->array[j].array[i] / this->array[i].array[i];
							b.array[j] -= b.array[i] * this->array[j].array[i] / this->array[i].array[i];
							this->array[j] -= tmp;
						}
					}
				}
			}
			int k;
			for (int i = this->size - 1; i >= 0; i--)
			{
				k = 0;
				for (int j = 0; j < this->size; j++)
				{
					if (this->array[i].array[j] != 0) k++;
				}
				if (k == 0 && b.array[i] != 0)
				{
					this->array[i] << cout << " | " << b.array[i];
					throw MyException(2);
				}
				x.array[i] = b.array[i];
				for (int j = this->size - 1; j >= 0; j--)
				{
					if (j != i)
					{
						x.array[i] -= this->array[i].array[j] * x.array[j];
					}
				}
				if (this->array[i].array[i] != 0)
					x.array[i] /= this->array[i].array[i];
			}
			string correct = Whole_Check(B, M);
			
			cout << "\n\n        > ���������� ����:\n\n";
			*this << cout << "\n\n  <><--| ���������� ������:  X = ";
			x << cout << "\n\n___________________________________________\n\n    ���� ���� ������ " << correct << danger_posability << "% \n\n";
		}




};


