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

void busquedaIP(struct Node *h, struct Node * &p, string ip){

  struct Node *tmp = h;

  while(tmp != NULL){

    if(tmp -> data.getIP() == ip){
      p = tmp;
      break;
    }

    tmp = tmp -> next;

  }

}

bool compareStrings(string s1, string s2){

  char *ptc_1 = (char*)&s1[0];
  char *ptc_2 = (char*)&s2[0];
  bool flag = true;

  while(*ptc_1 && *ptc_2){

    if(*ptc_1 > *ptc_2){
      flag = false;
      break;
    }
    else if(*ptc_1 < *ptc_2){
      break;
    }

    ptc_1++;
    ptc_2++;

  }

  return flag;

}

bool compare(Registro &r1, Registro &r2){

  // return (r1.getCifraUnoIP() < r2.getCifraUnoIP()) ? true : (r1.getCifraUnoIP() == r2.getCifraUnoIP()) ?
  // (r1.getCifraDosIP() < r2.getCifraDosIP()) ? true : (r1.getCifraDosIP() == r2.getCifraDosIP()) ?
  // (r1.getCifraTresIP() < r2.getCifraTresIP()) ? true : (r1.getCifraTresIP() == r2.getCifraTresIP()) ?
  // (r1.getCifraCuatroIP() < r2.getCifraCuatroIP()) ? true : false : false : false : false;

  if(r1.getCifraUnoIP() < r2.getCifraUnoIP()){
    return true;
  }
  else if(r1.getCifraUnoIP() == r2.getCifraUnoIP()){

    if(r1.getCifraDosIP() < r2.getCifraDosIP()){
      return true;
    }
    else if(r1.getCifraDosIP() == r2.getCifraDosIP()){

      if (r1.getCifraTresIP() < r2.getCifraTresIP()){
        return true;
      }
      else if(r1.getCifraTresIP() == r2.getCifraTresIP()){

        if(r1.getCifraCuatroIP() < r2.getCifraCuatroIP()){
          return true;
        }
        else if(r1.getCifraCuatroIP() == r2.getCifraCuatroIP()){ // Si las IPs son iguales

          if (r1.getMesNum() < r2.getMesNum()){
            return true;
          }
          else if(r1.getMesNum() == r2.getMesNum()){

            if(r1.getDiaNum() < r2.getDiaNum()){
              return true;
            }
            else if(r1.getDiaNum() == r2.getDiaNum()){

              if(r1.getSumaHorario() < r2.getSumaHorario()){
                return true;
              }
              else if(r1.getSumaHorario() == r2.getSumaHorario()){

                if(compareStrings(r1.getState(), r2.getState())){
                  return true;
                }
                else{
                  return false;
                }

              }
              else{
                return false;
              }

            }
            else{
              return false;
            }

          }
          else{
            return false;
          }

        }
        else{
          return false;
        }

      }
      else{
        return false;
      }

    }
    else {
      return false;
    }

  }
  else {
    return false;
  }

}

int main(){

  struct Node *h = NULL;
  struct Node *t = NULL;
  struct Node *tmpI = NULL; // Apuntador a nodo inicial para la búsqueda de la IP
  struct Node *tmpF = NULL; // Apuntador a nodo final para la búsqueda de la IP

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

        if(compare(entrada, h -> data)){

          struct Node *tmp = new Node;

          (tmp -> prev) = NULL;
          (tmp -> data) = entrada;
          (tmp -> next) = h;
          (h -> prev) = tmp;
          h = tmp;

        }

        else if(compare(t -> data, entrada)){

          struct Node *tmp = new Node;

          (tmp -> prev) = t;
          (tmp -> data) = entrada;
          (tmp -> next) = NULL;
          (t -> next) = tmp;
          t = tmp;

        }

        else if(compare(h -> data, entrada)){

          struct Node *tmp = h;

          while(tmp != NULL && compare(tmp -> data, entrada)){
            tmp = (tmp -> next);
          }

          if(tmp == NULL){ // Si llegó al último nodo de la lista

            if(compare(tmp -> data, entrada)){

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = t;
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = NULL;
              (t -> next) = tmp_2;
              t = tmp_2;

            }
            else{ // Cuando el nodo (entrada) es menor al último nodo

              struct Node *tmp_2 = new Node;

              (tmp_2 -> prev) = (tmp -> prev);
              (tmp_2 -> data) = entrada;
              (tmp_2 -> next) = tmp;
              ((tmp -> prev) -> next) = tmp_2;
              (tmp -> prev) = tmp_2;

            }

          }
          else{ // La entrada (nuevo nodo) es menor al tmp (un dato que ya estaba en la lista)

            struct Node *tmp_2 = new Node;

            (tmp_2 -> prev) = (tmp -> prev);
            (tmp_2 -> data) = entrada;
            (tmp_2 -> next) = tmp;
            ((tmp -> prev) -> next) = tmp_2;
            (tmp -> prev) = tmp_2;

          }

        }

        else if(compare(entrada, t -> data)){

          struct Node *tmp = t;

          while(tmp != NULL && compare(entrada, tmp -> data)){
            tmp = (tmp -> prev);
          }

          if(tmp == NULL){

            if (compare(entrada, tmp -> data)) {

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


  Registro masIP;
  string strIPinicio, strIPfinal;

  cin >> strIPinicio;
  cin >> strIPfinal;

  busquedaIP(h, tmpI, strIPinicio);
  busquedaIP(h, tmpF, strIPfinal);

  if(compare(tmpF -> data, tmpI -> data)){

    while(tmpI != NULL && tmpF != NULL){

      cout << tmpI -> data.print(0) << endl;

      if(tmpI == tmpF){
        break;
      }

      tmpI = tmpI -> prev;

    }

  }
  else{

    while(tmpF != NULL && tmpI != NULL){

      cout << tmpF -> data.print(0) << endl;

      if(tmpF == tmpI){
        break;
      }

      tmpF = tmpF -> prev;

    }

  }

  imprimeListaHead(h);

  return 0;

}
