#include "Tools.cpp"

int main(int argc, char *argv[]) {
    if(argc == 1) {
        cout << endl;
        cout << "Uso: >./" << argv[0] << " nombreTablero N " << endl;
        cout << "\t- nombreTablero 'para indicar el nombre del fichero a generar'" << endl;
        cout << "\t- N 'para indicar las dimensiones del tablero')" << endl;
        cout << endl;
    }
    else if (argc == 3) {
        Tools T;
        T.generarT(argv[1], atoi(argv[2]));
    }
    else {
        cout << endl;
        cout << "!!! MAL USO !!!" << endl;
        cout << "Uso: >./" << argv[0] << " nombreTablero N " << endl;
        cout << "\t- nombreTablero 'para indicar el nombre del fichero a generar'" << endl;
        cout << "\t- N 'para indicar las dimensiones del tablero')" << endl;
        cout << endl;
    }
}
