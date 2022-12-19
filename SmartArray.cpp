#include <stdexcept>
#include "SmartArray.h"

SmartArray::SmartArray(size_t size)
{
	m_elements = new int[size];
	m_size = size;
}

SmartArray::SmartArray(const SmartArray& src)
{
	copyFrom(src);
}

SmartArray& SmartArray::operator =(const SmartArray& src)
{
	// ��� ������������ � ������������ ������ �� ������ ��������, �� � ������� ������ ������
	cleanup();
	copyFrom(src);
	return *this;
}

SmartArray::~SmartArray()
{
	cleanup();
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

void SmartArray::copyFrom(const SmartArray& src)
{
	m_elements = new int[src.m_size];
	for (auto i = 0; i < src.m_head; ++i)
	{
		m_elements[i] = src.m_elements[i];
	}

	m_head = src.m_head;
	m_size = src.m_size;
}

void SmartArray::cleanup()
{
	delete[] m_elements;
}