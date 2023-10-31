//Nombre:Adrian Juan Fernando Diaz Tazen
//Carnet:1290-23-4928
//Curso:Algoritmos
//Seccion: B

#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include <chrono>	//delay
#include <thread>
#include <fstream>

#define INTENTOS 3

using namespace std;

bool access(string user, string pwd) {
	vector<string> usuario;
	vector<string> pass;
	bool acs = false;
	usuario.push_back("@dmin");
	pass.push_back("1234");

	for(int i = 0; i<usuario.size(); i++) {
		if(user==usuario[i] && pwd==pass[i]) {
			acs = true;
			break;
		}
	}
	return acs;
}

int main() {
	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	int array[500];
	int arrayA[500];
	string another = "si";
	int i = 1;
	string op;
	string user;
	string pwd;
	ofstream archivo;

	do {
		cout<<("----------------------BIENVENIDO----------------------")<<endl<<endl;
		cout<<("-------------------------MATH+------------------------")<<endl<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"\t\tUsuario: ";
		getline(cin, user);
		cout<<"\t\tContraseña: ";
		getline(cin, pwd);
		if(access(user,pwd) == true) {
			do {
				archivo.open("MathPlus.txt",ios::out);
				archivo<<("-------------------------MATH+------------------------")<<endl<<endl;
				archivo<<"--------------Numeros elevados al cuadrado--------------"<<endl<<endl;
				system("cls");
				cout<<"----------------------Numeros elevados al cuadrado----------------------"<<endl<<endl;
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"\n";
				cout<<"Desea que los numeros sean digitados de forma aleatoria? si/no"<<endl;
				cin>>op;

				if(op == "si" || op == "Si" || op == "SI") {
					for(int i = 0; i<500; i++) {
						cout<< "Numero en la posicion " << i+1 <<" = ";
						array[i] = rand() % 100;
						cout<< array[i] <<" "<<endl;
					}
				} else {
					for(int i = 0; i<500; i++) {
						cout<< "Numero en la posicion " << i+1 <<" = ";
						cin>>array[i];
					}
				}

				cout<<"----------------------Numeros elevados al cuadrado----------------------"<<endl<<endl;
				for(int i = 0; i<500 ; i++) {
					arrayA[i] = array[i] * array[i];
					cout<< "Numero en la posicion " << i+1 <<":"<<array[i]<< " = "<<arrayA[i]<<endl;
					archivo<< "Numero en la posicion " << i+1<<":"<<array[i]<< " = "<<arrayA[i]<<endl;
				}
				getch();
				cout<<"Desea realizar otra operacion?";
				cin>>another;
			} while(another == "si" ||another == "SI" ||another == "Si");
		} else {
			system("cls");
			i++;
			cout<<("----------------------BIENVENIDO----------------------")<<endl<<endl;
			cout<<("-------------------------MATH+------------------------")<<endl<<endl;
			cout<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"\t\tUsuario o contraseña invalida";
			sleep_for(10ns);
			sleep_until(system_clock::now() + 1s);
			system("cls");
			if(i>INTENTOS) {
				for(int j = 15 ; j>=0; j--) {
					cout<<"Maximo de intentos utilizados, por favor ";
					cout<<"espere "<<j<<" segundos.";
					sleep_for(1ns);
					sleep_until(system_clock::now() + 1s);
					system("cls");
				}
				i=1;
			}
		}
	} while(another == "si" ||another == "SI" ||another == "Si");
	system("cls");
	archivo.close();
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\tGracias por utilizar nuestro programa"<<endl;
	cout<<"\t\t            Vuelva pronto";
	getch();
}