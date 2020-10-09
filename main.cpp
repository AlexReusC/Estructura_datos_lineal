// Creado el 06/10/2020
//
// Autores:
// Ezequiel Lozano Guerrero - A01734172
// Alejandro Castro Reus - A01731065
// Daniel Esteban Maldonado Espitia - A01657967
//
// TC1031.2
// Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

#include <iostream>
#include <fstream>
#include <string>
#include "Registro.h"
#include "Node.h"
#include "insertaNodo.h"
#include "imprimeListaHead.h"
#include "imprimeListaTile.h"

using namespace std;


int main(){

  struct Node *h = NULL;
  struct Node *t = NULL;

  int busqDiaInicio, busqMesInicio, busqDiaFinal, busqMesFinal;
  string line, mes, dia, horario, ip, state, linea;

  ifstream leerFile("bitacora.txt");

  while(!leerFile.eof()){

		while(leerFile >> mes >> dia >> horario >> ip){

			if(leerFile.peek() == ' '){
				leerFile.get();
			}

			getline(leerFile, state);
    	Registro entrada(mes, dia, horario, ip, state);

      if(h != NULL){

        if(entrada.getCifraUnoIP() < (h -> data.getCifraUnoIP())){

          struct Node *tmp = new Node;

          (tmp -> prev) = NULL;
          (tmp -> data) = entrada;
          (tmp -> next) = h;
          (h -> prev) = tmp;
          h = tmp;

        }
        else
        if(entrada.getCifraUnoIP() > (t -> data.getCifraUnoIP())){

          struct Node *tmp = new Node;

          (tmp -> prev) = t;
          (tmp -> data) = entrada;
          (tmp -> next) = NULL;
          (t -> next) = tmp;
          t = tmp;

        }
        else
        if(entrada.getCifraUnoIP() > (h -> data.getCifraUnoIP())){

          struct Node *tmp = h;

          while(tmp != NULL && entrada.getCifraUnoIP() > (tmp -> data.getCifraUnoIP())){
            tmp = (tmp -> next);
          }

          if(tmp == NULL){

            if(entrada.getCifraUnoIP() > (tmp -> data.getCifraUnoIP())){

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = t;
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = NULL;
              (t -> next) = tmp_2;
              t = tmp_2;

            }
            else{ // Cuando el nodo (entrada) es mayor al h (primer nodo)

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = (tmp -> prev);
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = tmp;
              ((tmp -> prev) -> next) = tmp_2;
              (tmp -> prev) = tmp_2;

            }

          }
          else{ // tmp es mayor que el nuevo nodo (entrada)

            struct Node *tmp_2 = new Node;

            (tmp_2 -> prev) = (tmp -> prev);
            (tmp_2 -> data) = entrada;
            (tmp_2 -> next) = tmp;
            ((tmp -> prev) -> next) = tmp_2;
            (tmp -> prev) = tmp_2;

          }

        }
        else
        if(entrada.getCifraUnoIP() < (t -> data.getCifraUnoIP())){

          struct Node *tmp = t;

          while(tmp != NULL && entrada.getCifraUnoIP() < (tmp -> data.getCifraUnoIP())){
            tmp = (tmp -> prev);
          }

          if(tmp == NULL){

            if(entrada.getCifraUnoIP() < (tmp -> data.getCifraUnoIP())){

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = NULL;
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = h;
              (h -> prev) = tmp;
              h = tmp;

            }
            else{ // Cuando el nodo (entrada) es mayor al h (primer nodo)

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = tmp;
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = (tmp -> next);
              ((tmp -> next) -> prev) = tmp_2;
              (tmp -> next) = tmp_2;

            }

          }
          else{ // tmp es menor que el nuevo nodo (entrada)

            struct Node *tmp_2 = new Node;

            (tmp_2 -> prev) = tmp;
            (tmp_2 -> data) = entrada;
            (tmp_2 -> next) = (tmp -> next);
            ((tmp -> next) -> prev) = tmp_2;
            (tmp -> next) = tmp_2;

          }

        }

      }
      else{
        insertaNodo(h, t, entrada);
      }

		}

  }

  imprimeListaHead(h);

  // ofstream sortedData;
  // sortedData.open("sortedData.txt");

  // for(int i = 0; i < entradas.size(); i++){
    // 	sortedData << entradas[i].print(0) << endl;
    // }
    //
    // sortedData.close();


  return 0;

}
