#include <bits/stdc++.h>

using namespace std;

class Repositorio {
	private:
		map<string,pair<string,int> > arquivos;
	public:
		void adicionar(string nome, string extensao, int tamanho) {
			arquivos[nome] = make_pair(extensao,tamanho);
		}
		void remover(string nome) {
			map<string,pair<string,int> >::iterator it;
			it = arquivos.find(nome);
			arquivos.erase(it);
		}
		void pesquisar(string nome) {
			cout << arquivos[nome].second;
		}
};
