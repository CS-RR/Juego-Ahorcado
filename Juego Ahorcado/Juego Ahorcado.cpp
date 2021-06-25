// Juego Ahorcado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MaxIntentos = 5; // El maximos de intentos debe ser constante para no alargar el juego y menor siempre a las cantidad de letras de las palabras.
int RellenoLetra(char, string, string&);//Nuestra funcion 

int main()
{

	char letra;
	int intentosFallidos = 0;
	string palabra1;//son como varios char 
	string Palabras[] = { "fresa","mora","mango","uva","melon","papaya","anon","guayaba","pera","manzana" };

	srand(time(0));      //Se crea una semilla para usar el random.
	int n = rand() % 10; //Escoger una palabra al azar.
	palabra1 = Palabras[n]; //Inicia la palabra escogida al azar.


	string desconocido(palabra1.size(), '_'); //Inicializamos nuestra palabra secreta en caracteres.


	cout << "\n\tJUEGO DEL AHORCADO" << endl;
	cout << "\nTIENES: " << MaxIntentos << " INTENTOS PARA  ADIVINAR LA PALABRA." << endl;
	cout << "\a" << endl;//Sonido del sistema.

	while (intentosFallidos < MaxIntentos) //Bucl, mientras no se supere los intentos permitidos o se adivine la palabra se repite.
	{
		system("color 0C");
		cout << "\tCategoria Frutas" << endl;
		cout << "\nTu Palabra es: " << desconocido; //Mostramos nuestra palabra secreta.
		cout << "\n\nDame una letra: "; //Pedimos al usuario darnos una primera letra.
		cin >> letra; //Leemos la letra, el carácter.

		if (RellenoLetra(letra, palabra1, desconocido) == 0)
		{
			system("cls");
			intentosFallidos++;
			cout << "\n\t-----JUEGO DEL AHORCADO-----" << endl;
			cout << endl << "Esa letra no esta aqui !" << endl;
			cout << "Aun tienes " << MaxIntentos - intentosFallidos << " intentos restantes" << endl;
		}
		else
		{
			system("cls");
			cout << "\n\t-----JUEGO DEL AHORCADO-----" << endl;
			cout << endl << "Encontraste una letra!" << endl;
		}
		if (palabra1 == desconocido) //Si la palabra es igual a la random o desconocida se termina el juego.
		{
			system("cls");
			system("color 2");
			cout << "\n\t-----JUEGO DEL AHORCADO-----" << endl;
			cout << "\n\tEn hora buena has adivinado la palabra:" << endl;
			cout << "\n\t----->  " << palabra1 << " <-----" << endl;
			cout << "\t          \\0/ " << endl;
			cout << "\t           |" << endl;
			cout << "\t           | " << endl;
			cout << "\t          / \\" << endl;
			break;
		}

	}
	if (intentosFallidos == MaxIntentos)//Si se pierden todos los intentos se pierde.
	{
		system("cls");
		system("color 3");
		cout << "\n\tJUEGO DEL AHORCADO" << endl;
		cout << "------" << endl;
		cout << "|    0 " << endl;
		cout << "|   /|\\" << endl;
		cout << "|    | " << endl;
		cout << "|   / \\" << endl;
		cout << "|_________\tHAS PERDIDO TU PALABRA ERA: " << palabra1 << endl;
		cout << "\n" << endl;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*Toma un caracter para adivinar la palabra secreta,
y lo pone en la palabra incompleta para adivinar.
Si encuentra un carácter igual lo muestra o devuelve.
adicional, si la palabra es adivinada devuelve un cero.*/
int RellenoLetra(char adivinar, string palabrasecreta, string& adivinarpalabra)
{
	int i;
	int comparar = 0;
	int len = palabrasecreta.size();
	for (i = 0; i < len; i++)
	{

		if (adivinar == adivinarpalabra[i])	// ¿conincide la letra con alguna anterior?
			return 0;

		if (adivinar == palabrasecreta[i])// ¿la letra que se supone esta en la palabra secreta?
		{
			adivinarpalabra[i] = adivinar;
			comparar++;
		}
	}
	return comparar;
}