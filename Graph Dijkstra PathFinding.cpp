#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;

#define size 6

#define SHOW(mat,s1,s2)         \
for(int i = 0; i < s1; i++){    \
  for(int j = 0; j < s2; j++){  \
    cout << setw(2) << mat[i][j] << " ";   \
  }                             \
  cout << endl;                 \
} 

int main() {
    //int** array = new int*[size]; for (int i = 0; i < size; i++) array[i] = new int[size];
    int array[size][size] = {
      { 0, 7, 9, 0, 0,14 },
      { 7, 0,10,15, 0, 0 },
      { 9,10, 0,11, 0, 2 },
      { 0,15,11, 0, 6, 0 },
      { 0, 0, 0, 6, 0, 9 },
      {14, 0, 2, 0, 9, 0 }
    };

    int distance[size] = {};
    int ways[size] = {};

    int start = 0;
    int end = 4;

    SHOW(array, size, size);
    cout << endl;

    for (int i = 0; i < 6; i++) {
        if (i == start) distance[i] = 0;
        else distance[i] = -1;
        ways[i] = -1;
    }

    stack<int> Que;
    Que.push(start);
    while (!Que.empty()) {
        int Old = Que.top();
        Que.pop();
        for (int New = 0; New < size; New++) {
            if (array[Old][New] != 0 && (array[Old][New] + distance[Old] < distance[New] || distance[New] == -1)) {
                distance[New] = array[Old][New] + distance[Old];
                ways[New] = Old;
                Que.push(New);
            }

        }
    }

    /*
    for (int i = 0; i < size; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << ways[i] << " ";
    }
    cout << endl;
    //*/

    Que.push(end);
    while (end != start) {
        Que.push(ways[end]);
        end = ways[end];
    }
    while (!Que.empty()) {
        cout << Que.top() + 1 << " ";
        Que.pop();
    }

}