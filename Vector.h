#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <fstream> 
#include <iostream>

class Vector {
	double *mas = nullptr;
	size_t n = 0;// int n = 0;
	
public:
	Vector();
	Vector(size_t n);
	Vector(double* mas, size_t n);
	Vector(const Vector & vector);
	Vector(Vector && vector);
	~Vector();

	double operator[](size_t index);

	Vector& operator=(const Vector& vector2);
	Vector& operator=(Vector&& vector2);

	friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
	friend std::istream& operator>>(std::istream& is, Vector& vector);

	// дружественная функция, определенная вне класса, для перегрузки математических операторов
	friend Vector operator+(const Vector& vector1, const Vector& vector2);
	//friend Vector operator*(const Vector& vector1, const Vector& vector2);
};

// 1. Конструктор без параметров, задает "пустой" объект
Vector::Vector() {
	this->n = 0;
	this->mas = nullptr;
}

// 2. Конструктор - выделяем память без инициализации
Vector::Vector(size_t n) {
	this->n = n;
	this->mas = new double[n];
}

// 3. Конструктор на входе массив, задающий вектор
Vector::Vector(double *mas, size_t n) {
	this->n = n;
	this->mas = new double[n];
	for (size_t i = 0; i < this->n; ++i) {
		this->mas[i] = mas[i];
	}
}

// 4. Конструктор копирования
Vector::Vector(const Vector & vector) {
	n = vector.n;
	mas = new double[n];
	for (size_t i = 0; i < this->n; ++i) {
		mas[i] = vector.mas[i];
	}
}

// 5. Конструктор перемещения
Vector::Vector(Vector&& vector) {  // Параметр - правосторонняя ссылка

	std::swap(this->mas, vector.mas);
	std::swap(this->n, vector.n);
}

// 6. Деструктор ~
Vector::~Vector() {
	if (mas != nullptr) {
		delete[] mas;
	}
}

// Перегрузки операций (описание функций)

// 1. [] (обращение к элементу вектора по индексу)
 double Vector::operator[](size_t index){
	return mas[index];
}

 // 2. = (присваивание с копированием)
 Vector& Vector::operator=(const Vector& vector2) {
	 if (this != &vector2) {
		 n = vector2.n;
		 if (mas != nullptr) { // Освобождаем память старого вектора
			 delete[] mas;  // Выделяем память для нового вектора
		 }
		 mas = new double[n];
		 for (size_t i = 0; i < this->n; ++i) {
			 this->mas[i] = vector2.mas[i];
		 }
	 }
	 return *this;
 }

 // 3. = (присваивание с перемещением)
Vector& Vector::operator=(Vector&& vector2) {
	 if (this != &vector2) {
		 std::swap(this->mas, vector2.mas);
		 std::swap(this->n, vector2.n);
	 }
	 return *this;
 }
 
 // 4. вставки (<<) объекта в поток cout  или в файл (объект класса ostream)
 std::ostream& operator<<(std::ostream& os, const Vector& vector) {
	 os << "[ ";
	 for (size_t i = 0; i < vector.n; ++i) {
		 os << vector.mas[i] << " ";
	 }
	 os << "]";
	 return os;
 }

 // 5. операцию извлечения (>>) объекта из потока cin или из файла (объект класса istream)
 std::istream& operator>>(std::istream& is, Vector& vector) {
	 for (size_t i = 0; i < vector.n; ++i) {
		 is >> vector.mas[i];
	 }
	 return is;
 }
 
 // + сложение векторов одинаковой размерности (сумма соответствующих элементов двух векторов)
 Vector operator+(const Vector& vector1, const Vector& vector2) {
	 if (vector1.n == vector2.n) {
		 Vector V(vector1.n); // Создаем новый объект заданного размера
		 for (size_t i = 0; i < vector1.n; ++i) {
			 V.mas[i] = vector1.mas[i] + vector2.mas[i];
		 }
		 return V;
	 }
	 else {
		 std::cerr << "Lenght doesn't match";
	 }
 }


#endif

