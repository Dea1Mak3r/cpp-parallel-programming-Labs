#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");
    cout << "================ Начало рассчёта... ================\n\n\n";

    auto startTime = std::chrono::steady_clock::now();

    if (argc < 3) {
        cout << "Для запуска файла из командной строки необходимо ввести имя файла, после чего через пробел  указать 2 числа - начало и конец рассчёта.\n";
        return 1;
    }

    long long start = stoll(argv[1]);
    long long end = stoll(argv[2]);
    vector<long long> resultVector;

    long long itertionStart = start;

    itertionStart = itertionStart - (itertionStart % 80) + 1;

    for (long long i = itertionStart; i <= end; i += 80)
    {
        double potentialDigit = round(pow(i, 0.25));
        if (pow(potentialDigit, 4) == i)
        {
            int root1 = (int)potentialDigit;
            int count = 0;
            for (int a = 3; a <= pow(potentialDigit, 0.5); a = a + 2)
            {
                if (root1 % a == 0)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                resultVector.push_back(i);
                cout << i << endl;
            }

        }
    }

    ofstream fout;
    fout.open("Результат вычислений.txt");

    for (auto k : resultVector)
        fout << k << endl;

    fout.close();

    auto endTime = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    cout << "\n\nВремя выполнения: " << elapsedTime.count() << " секунд.\n";
    
    
    return 0;
}

/*void main()
{
    long long a = 16983563041;
    cout << "a = " << a << endl;
    double b = round(pow(a, 0.25));
    cout << "b = " << b << endl;
    if (pow(b, 4) == a)
    {
        cout << "true\n";
        int r = (int)b;
        int counter = 0;
        for (int k = 3; k <= pow(b, 0.5); k += 2)
        {
            cout << "k = " << k << "\t" << "r = " << r << endl;
            if (r % k == 0)
            {
                cout << r << endl;
            }
        }
    }
    cout << "a = " << a << "\t" << "b = " << b << "\tc = " << c;
}*/