#include <iostream>
#include <stack>

using namespace std;

void ordenarPila(stack<int>& pila) {
    stack<int> pilaAux1;
    stack<int> pilaAux2;

    while (!pila.empty()) {
        int temp = pila.top();
        pila.pop();

        // Mover de pilaAux1 a pilaAux2
        while (!pilaAux1.empty() && pilaAux1.top() > temp) {
            pilaAux2.push(pilaAux1.top());
            pilaAux1.pop();
        }


        pilaAux1.push(temp);

        // Mover de vuelta de pilaAux2 a pilaAux1
        while (!pilaAux2.empty()) {
            pilaAux1.push(pilaAux2.top());
            pilaAux2.pop();
        }
    }



    // invertimos el orden porque el profe dijo que queria el elemento mas chico en el fondo del stack
    while (!pilaAux1.empty()) {
        pilaAux2.push(pilaAux1.top());
        pilaAux1.pop();
    }

    while (!pilaAux2.empty()) {
        pila.push(pilaAux2.top());
        pilaAux2.pop();
    }
}

int main() {
    stack<int> pila;
    pila.push(12);
    pila.push(4);
    pila.push(2);
    pila.push(3);
    pila.push(7);
    pila.push(1);

    ordenarPila(pila);


    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }


    return 0;
}
