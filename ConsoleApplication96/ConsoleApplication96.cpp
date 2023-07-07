#include <iostream>
#include <thread>
#include<vector>
using namespace std;
int* n{};
void pr1() {
    cout << "вычисл процесс 1 начал работу " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
        int k = 0;
    for (int i{}; i < 10; ++i) {
        if (k <= n[i]) {
            k = n[i];
        }
        cout << "вычисл процесс 1 работает " << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "вычисл процсс 1 закончил работу " << endl;
    cout << "макс число = " << k<<endl;
}
void pr2() {
    cout << "вычисл процесс 2 начал работу " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    int a = 10;
    for (int i{}; i < 10; ++i) {
        if (a > n[i]) {
            a = n[i];
        }
        cout << "вычисл процесс 2 работает " << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << "вычисл процесс 2 закончил работу " << endl;
    cout << "мин число = " << a<<endl;
}
int main(){
    setlocale(LC_ALL, "RUS");
    const int size = 10;
    n = new int[size] {1,2,3,4,5,6,7,8,9,10};

    thread t1(pr1);
    thread t2(pr2);
    t1.join();
    t2.join();


    return 0;
}