#include <iostream>

using namespace std;


class Arr{
private:
	int* elem;
	int sz;

public:
	Arr(int s) : elem(new int[s]), sz(s)
	{}

	int& operator[](int i)
	{
		return elem[i];
	}
	
	int size(){
		return sz;
	}
	~Arr();
	void randI();

};

Arr::~Arr(){
	delete[] elem;
}

void Arr::randI()
{
	for (auto i = 0; i < sz; i++)
	{
		elem[i] = rand() % 100;
	}
}

int main()
{

	cout << "Criando minha Arr!" << endl;
	cout << "Sem ponteiro: " << endl;
	Arr minhaArr = Arr(10);
	minhaArr.randI();
		for (auto i = 0; i < minhaArr.size(); i++)
	{
		cout << "minhaArray[" << i << "] = " << minhaArr[i] << endl;
	}


	cout << "Criando ponteiro para Arr!" << endl;
	cout << "Digite o tamanho da Arr: ";
	int tamanho;
	cin >> tamanho;
	Arr* ptrminhaArr = new Arr(tamanho);
	ptrminhaArr->randI();

	for (auto i = 0; i < ptrminhaArr->size(); i++)
	{
		cout << "(*ptrminhaArray)[" << i << "] = " << (*ptrminhaArr)[i] << endl;
	}

	delete ptrminhaArr;
	ptrminhaArr = NULL;

	return 0;

}