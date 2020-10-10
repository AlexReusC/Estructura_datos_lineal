#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Registro{

	private:

    int mesNum;
    int sumaHorario;
    string mes;
    string dia;
    string horaMinSeg;
    string ip;
    string state;
    int cifraUnoIP;
    int cifraDosIP;
    int cifraTresIP;
    int cifraCuatroIP;

  public:

		Registro(){

		}

    Registro(string mes, string dia, string horario, string ip, string state){

      int indice = 0;

      this -> mes = mes;
      this -> dia = dia;
      this -> ip = ip;
      this -> state = state;

      mesNum = monthToNumb(mes);
      sumaHorario = getHorario(horario, dia);
      horaMinSeg = horario;

      cifraUnoIP = convierteIP(ip, indice);
      cifraDosIP = convierteIP(ip, indice);
      cifraTresIP = convierteIP(ip, indice);
      cifraCuatroIP = convierteIP(ip, indice);

    }

  	int monthToNumb(string mes){

    	int month = (mes == "Jan") ? 1:
      (mes == "Feb") ? 2: (mes == "Mar") ? 3:
      (mes == "Apr") ? 4: (mes == "May") ? 5:
      (mes == "Jun") ? 6: (mes == "Jul") ? 7:
			(mes == "Aug") ? 8: (mes == "Sep") ? 9:
			(mes == "Oct") ? 10:(mes == "Nov") ? 11:
      (mes == "Dec") ? 12: 0;

      return month;

    }

    int getHorario(string horario, string dia){

    	int dias = stoi(dia);
    	int horas = stoi(horario.substr(0,2));
			int minutos = stoi(horario.substr(3,4));
			int segundos = stoi(horario.substr(6,7));

    	return segundos + (minutos * 60) + (horas * 3600) + (dias * 86400);

    }

    int convierteIP(string ip, int &j){

      int numero = 0;

      for(int i = j; i < ip.size(); i++){

        if(ip[i] != '.' && ip[i] != ':'){

          int tmp = ip[i] - 48;
          numero = (numero == 0) ? numero + tmp : (numero * 10) + tmp;


        }
        else{

          j = i + 1;
          return numero;

        }

      }

      return numero;

    }

    string print(int i){

      if(i == 1){
        return to_string(mesNum) + " " + to_string(sumaHorario) + " " + ip + " " + state;
      }
      else{
        return mes + " " + dia + " " + horaMinSeg + " " + ip + " " + state;
      }

    }

    int getMesNum(){
    	return mesNum;
    }

    int getSumaHorario(){
    	return sumaHorario;
    }

    int getDiaNum(){
    	return stoi(dia);
    }

		int getCifraUnoIP(){
			return cifraUnoIP;
		}

		int getCifraDosIP(){
			return cifraDosIP;
		}

		int getCifraTresIP(){
			return cifraTresIP;
		}

		int getCifraCuatroIP(){
			return cifraCuatroIP;
		}

		string getState(){
			return state;
		}

		string getIP(){

			string shortIP;
			int i = 0;
			while (ip[i] != ':') {
				shortIP += ip[i];
				i++;
			}

			return shortIP;
		}
		string getAllIP(){
			return ip;
		}
};
