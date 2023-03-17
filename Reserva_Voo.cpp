#include <bits/stdc++.h>

using namespace std;

typedef struct Voo {
	string origem;
	string destino;
	vector<bool> disponibilidade_assentos;
};

class Reserva_Voo {
	private:
		map<int,Voo> Voos;
	public:
		Reserva_Voo (int numero_voo, string origem, string destino, int capacidade) {
			Voo aux;
			aux.origem = origem;
			aux.destino = destino;
			aux.disponibilidade_assentos.resize(capacidade, false);
			Voos[numero_voo] = aux;
		}
		
		bool voo_existe(int numero_voo) {
			map<int,Voo>::iterator it;
			it = Voos.find(numero_voo);
			if(it != Voos.end())
				return true;
			else
				return false;
		}
		
		bool assento_eh_valido (int numero_voo, int numero_assento) {
			return Voos[numero_voo].disponibilidade_assentos.size() > numero_assento && Voos[numero_voo].disponibilidade_assentos[numero_assento] == false;
		}
		
		bool remover_voo (int numero_voo) {
			if(voo_existe(numero_voo)) {
				Voos.erase(numero_voo);
				return true;
			}
			else
				return false;
		}
		
		bool reservar_assento (int numero_voo, int numero_assento) {
			if(voo_existe(numero_voo)) {
				if(assento_eh_valido(numero_voo,numero_assento)) {
					Voos[numero_voo].disponibilidade_assentos[numero_assento] = true;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
};
