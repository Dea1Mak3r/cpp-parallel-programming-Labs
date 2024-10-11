#include<iostream>
#include<chrono>
#include<thread>
#include<functional>
#include<vector>

using namespace std;

/*void someWork(int a, int b)
{
	this_thread::sleep_for(chrono::seconds(3));
	cout << "===========\tCALCULATING...\t===========\n";
	this_thread::sleep_for(chrono::seconds(3));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "===========\tCALCULATING COMPLETE!\t===========\n";
}

void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Привет!";
	
	thread th(someWork, 3, 7);

	for (int i = 0; i < 30; i++)
	{
		cout << "Итерация главного цикла: " << i << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	th.join();
}*/

void Foo(int a)
{
	if (a > 10 && a < 40)
	{
		cout << "Foo: " << a << endl;
	}
}

void Bar(int a)
{
	if (a % 2 == 0)
	{
		cout << "Bar: " << a << endl;
	}
}

void Iterate(vector<int>& v, vector<function<void(int)>> vf)
{
	for (auto i : v)
	{
		for (auto j : vf)
		{
			j(i);
		}
	}
}

void main1()
{
	vector<int> vc = { 1, 5, 10, 16, 17, 33, 25, 26, 19, 34, 39, 56, 68 };

	vector<function<void(int)>> vecFunc;
	vecFunc.emplace_back(Foo);
	vecFunc.emplace_back(Bar);

	Iterate(vc, vecFunc);

}