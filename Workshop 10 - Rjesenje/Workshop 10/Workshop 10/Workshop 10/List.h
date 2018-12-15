#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class List {

	T1* _elementi1;
	T2* _elementi2;
	const int _max;
	int _trenutno;

public:
	List(const int max = 5) :_max(max), _trenutno(0),_elementi1(new T1[_max]),_elementi2(new T2[_max]){}

	List(const List& list) :_max(list._max), _trenutno(list._trenutno), _elementi1(new T1[list._max]), _elementi2(new T2[list._max]) {
	if(_trenutno>0)
		for (int i = 0; i < _trenutno; i++)
		{
			_elementi1[i] = list._elementi1[i];
			_elementi2[i] = list._elementi2[i];
		}
	}
	List(List&& l) :_max(l._max), _trenutno(l._trenutno) {
		_elementi1 = l._elementi1;
		l._elementi1 = nullptr;
		_elementi2 = l._elementi2;
		l._elementi2 = nullptr;
	}
	~List() {
		delete[] _elementi1;
		delete[] _elementi2;
		_elementi1 = nullptr;
		_elementi2 = nullptr;
	}
	
	List& operator()(T1 t1, T2 t2) {
		if (_trenutno >= _max) {
			cout << "Lista puna..\n";
			return *this;
		}
		_elementi1[_trenutno] = t1;
		_elementi2[_trenutno++] = t2;
		return *this;
	}
	List& operator-=(int index) {
		if (index<0 || index>_trenutno - 1 || _trenutno <= 0)
			return *this;
		for (int i = index; i < _trenutno - 1; i++) {
			_elementi1[i] = _elementi1[i + 1];
			_elementi2[i] = _elementi2[i + 1];
		}
		_trenutno--;
		return *this;
	}

	T1* operator[](int index) {
		if (index<0 || index>_trenutno - 1 || _trenutno <= 0)
			return nullptr;
		return &_elementi1[index];
	}
	T2* operator()(int index) {
		if (index<0 || index>_trenutno - 1 || _trenutno <= 0)
			return nullptr;
		return &_elementi2[index];
	}

	int GetTrenutno()const { return _trenutno; }
	int getMax()const { return _max; }
	friend ostream& operator<< <>(ostream&, const List&);
};
template<class T1, class T2>
ostream& operator<< <>(ostream& cout, const List<T1, T2>& list) {
	if (list._trenutno <= 0)
		return cout;
	for (int i = 0; i < list._trenutno; i++) {
		cout << list._elementi1[i] << "\t" << list._elementi2[i] << endl;
	}

	return cout;
}