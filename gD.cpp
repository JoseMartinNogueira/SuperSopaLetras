#include "Tools.cpp"

int main(int argc, char *argv[]) {
    if(argc == 1) {
        cout << endl;
        cout << "Uso: >./" << argv[0] << " nombreDiccionario numeroElemetos min max [nombreTablero porcentaje]" << endl;
        cout << "\t- nombreDiccionario 'para indicar el nombre del fichero a generar'" << endl;
        cout << "\t- numeroElementos 'para indicar cuantos numeros se tienen que generar" << endl;
        cout << "\t- min 'los numeros del diccionario seran mayor o igual a este valor" << endl;
        cout << "\t- max 'los numeros del diccionario seran menores o igual a este valor" << endl;
        cout << "\t- nombreTablero 'nombre tablero para generar el diccionario" << endl;
        cout << "\t- porcentaje 'porcentaje aproximado de elementos que perteneceran al tablero" << endl;
        cout << endl;
    }
    else if (argc == 5) {
        Tools T;
        T.generarD(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), 0);
    }
    else if (argc == 7) {
        Tools T;
        input in;
        T.leerTablero(argv[5], in);
        T.generarDT(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), 20, in.T);
    }
    else {
        cout << endl;
        cout << "!!! MAL USO !!!" << endl;
        cout << "Uso: >./" << argv[0] << " nombreDiccionario numeroElemetos min max [nombreTablero porcentaje]" << endl;
        cout << "\t- nombreDiccionario 'para indicar el nombre del fichero a generar'" << endl;
        cout << "\t- numeroElementos 'para indicar cuantos numeros se tienen que generar" << endl;
        cout << "\t- min 'los numeros del diccionario seran mayor o igual a este valor" << endl;
        cout << "\t- max 'los numeros del diccionario seran menores o igual a este valor" << endl;
        cout << "\t- nombreTablero 'nombre tablero para generar el diccionario" << endl;
        cout << "\t- porcentaje 'porcentaje aproximado de elementos que perteneceran al tablero" << endl;
        cout << endl;
    }
}
