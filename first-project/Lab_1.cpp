#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <fstream>
#include <chrono>
#include <string>
using namespace std;


/*void main(int argc, char* argv[]) {

    long long charToStart = stoll(argv[1]);
    long long charToEnd = stoll(argv[2]);

    cout << charToStart << "\t" << charToEnd;

    auto begin = std::chrono::steady_clock::now();
    setlocale(LC_ALL, "Rus");

    int vectorStart = pow(charToStart, 0.25);
    int vectorEnd = pow(charToEnd, 0.25);

    int vectorSize = vectorEnd - vectorStart + 1;

    vector<bool> isPrime(vectorSize, false);
    

    int i = vectorStart;
    for (i; i <= vectorEnd; i++)
    {
        int dividers = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                dividers++;
        }
        if (dividers == 2)
        {
            isPrime[i - vectorStart] = true;
        }
    }

    vector<long long> result;

    for (int k = vectorStart; k < vectorEnd; k++)
    {
        if (isPrime[k - vectorStart])
        {
            cout << (long long)pow(k, 4) << endl;
            result.push_back((long long)pow(k, 4));
        }
    }

    cout << "\n\n======================================================================\n\n";

    ofstream fout;
    fout.open("Результаты вычислений.txt");
    if (fout.is_open())
    {
        for (int l = 0; l < result.size(); l++)
        {
            cout << result[l] << endl;
            fout << result[l] << endl;
        }
    }
    else
        cout << "\n\n======================= Не удалось записать данные =======================";

    fout.close();

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "\n\nВремя выполнения: " << elapsed_ms.count() << " ms\n";

    system("pause");
}*/