#include <stdexcept>
#include "SmartArray.h"

SmartArray::SmartArray(size_t size)
{
	m_elements = new int[size];
	m_size = size;
}

SmartArray::~SmartArray()
{
	delete[] m_elements;
}

void SmartArray::addElement(int value)
{
	// � �������� ������ ��� ���������� ������� ������ ������������, ������ ��������� �������������
	// ������ ��� ��������
	if (m_head >= m_size)
	{
		throw std::out_of_range("������� ���������� �������� � ����������� ������� �������");
	}

	m_elements[m_head++] = value;
}


int SmartArray::getElement(size_t index)
{
	// �������, ��� ���� ������ ����������� ��������
	if (index >= m_head)
	{
		throw std::out_of_range("������ �������� ������� ��� ����������� ���������");
	}

	return m_elements[index];
}

size_t SmartArray::getLength()
{
	return m_head;
}