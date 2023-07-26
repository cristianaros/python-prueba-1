#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool searchStack(Node* top, int element) {
    Node* current = top;
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* invertirPila(Node* top) {
    if (top == nullptr) {
        return nullptr;
    }

    Node* temporal = invertirPila(top->next);

    if (temporal == nullptr) {
        return top;
    }

    top->next->next = top;
    top->next = nullptr;

    return temporal;
}

void mostrarPilaInvertida(Node* top) {
    if (top == nullptr) {
        return;
    }
    mostrarPilaInvertida(top->next);
    cout << top->data << " ";
}

Node* combinarPilas(Node* pila1, Node* pila2) {
    if (pila1 == nullptr) {
        return pila2;
    }
    if (pila2 == nullptr) {
        return pila1;
    }

    if (pila1->data < pila2->data) {
        pila1->next = combinarPilas(pila1->next, pila2);
        return pila1;
    } else {
        pila2->next = combinarPilas(pila1, pila2->next);
        return pila2;
    }
}

Node* interseccionPilas(Node* pila1, Node* pila2) {
    Node* interseccion = nullptr;
    Node* current1 = pila1;
    Node* current2 = pila2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data == current2->data) {
            if (interseccion == nullptr) {
                interseccion = new Node{current1->data, nullptr};
            } else {
                interseccion = new Node{current1->data, interseccion};
            }
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->data < current2->data) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }

    return invertirPila(interseccion);
}

int main() {
    // crea la pila original
    Node* top = new Node{1, new Node{2, new Node{3, nullptr}}};

    // muestra la pila original
    cout << "searchStack(top, 2): " << searchStack(top, 2) << endl;
    cout << "searchStack(top, 4): " << searchStack(top, 4) << endl;

    // muestra la pila original y la invertida
    cout << "Pila original: ";
    mostrarPilaInvertida(top);
    cout << endl;
    Node* pilaInvertida = invertirPila(top);
    cout << "Pila invertida: ";
    mostrarPilaInvertida(pilaInvertida);
    cout << endl;

    // muestra la combinacion de dos pilas
    Node* pila1 = new Node{1, new Node{3, new Node{5, nullptr}}};
    Node* pila2 = new Node{2, new Node{4, new Node{6, nullptr}}};
    cout << "Pila 1: ";
    mostrarPilaInvertida(pila1);
    cout << endl;
    cout << "Pila 2: ";
    mostrarPilaInvertida(pila2);
    cout << endl;
    Node* pilaCombinada = combinarPilas(pila1, pila2);
    cout << "Pila combinada: ";
    mostrarPilaInvertida(pilaCombinada);
    cout << endl;

    // muestra la interseccion de dos pilas
    Node* pila3 = new Node{1, new Node{2, new Node{3, nullptr}}};
    Node* pila4 = new Node{2, new Node{3, new Node{4, nullptr}}};
    cout << "Pila 3: ";
    mostrarPilaInvertida(pila3);
    cout << endl;
    cout << "Pila 4: ";
    mostrarPilaInvertida(pila4);
    cout << endl;
    Node* interseccion = interseccionPilas(pila3, pila4);
    if (interseccion != nullptr) {
        cout << "Primer elemento en comun: " << interseccion->data << endl;
    } else {
        cout << "No hay elementos en comun" << endl;
    }

    return 0;
}
