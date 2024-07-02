#include "Pyramid.h"
#include <cmath>
const std::string Pyramid::GetName()
{
	return name;
}

const double Pyramid::GetVolume()
{
	double alpha = 3.1415926535 / sideNum; //���� �/� ��������� � ��������
	double Rad = a / (2 * sin(alpha)); //����� ������� ��������� ����������
	double S = sideNum * pow(Rad, 2) /( 2 * sin(2 * alpha)); //������� ���������
	return S * h / 3 ;
}

const int Pyramid::GetSideNum()
{
	return sideNum;
}

const double Pyramid::GetH()
{
	return h;
}

const double Pyramid::GetSide()
{
	return a;
}