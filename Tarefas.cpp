#include <iostream>

using namespace std;

class Tarefa {
	private:
		string titulo, descricao, data_finalizacao;
		bool status;
	public:
		Tarefa(string titulo, string descricao, string data_finalizacao, bool status) {
			this->titulo = titulo;
			this->descricao = descricao;
			this->data_finalizacao = data_finalizacao;
			this->status = status;
		}
		
		void set_titulo(string titulo) {this->titulo = titulo;}
		string get_titulo() {return titulo;}
		
		void set_descricao(string descricao) {this->descricao = descricao;}
		string get_descricao() {return descricao;}
		
		void set_data(string data_finalizacao) {this->data_finalizacao = data_finalizacao;}
		string get_data() {return data_finalizacao;}
		
		void set_status(bool status) {this->status = status;}
		bool get_status() {return status;}
		
		bool verificar_se_tarefa_esta_no_prazo(string data_hoje) {//nesta função, assumirei que as datas foram dadas na forma dia, mes ano, no formato:"xx/xx/xxxx"
			int dia_hoje, mes_hoje, ano_hoje;
			int dia_finalizacao, mes_finalizacao, ano_finalizacao;
			
			dia_hoje = (data_hoje[0] - 48)*10 + (data_hoje[1] - 48);
			mes_hoje = (data_hoje[3] - 48)*10 + (data_hoje[4] - 48);
			ano_hoje = (data_hoje[6] - 48)*1000 + (data_hoje[7] - 48)*100 + (data_hoje[8] - 48)*10 + (data_hoje[9] - 48);
			
			dia_finalizacao = (data_finalizacao[0] - 48)*10 + (data_finalizacao[1] - 48);
			mes_finalizacao = (data_finalizacao[3] - 48)*10 + (data_finalizacao[4] - 48);
			ano_finalizacao = (data_finalizacao[6] - 48)*1000 + (data_finalizacao[7] - 48)*100 + (data_finalizacao[8] - 48)*10 + (data_finalizacao[9] - 48);
			
			if(ano_hoje <= ano_finalizacao) {
				if(ano_hoje < ano_finalizacao)
					return true;
				if(mes_hoje <= mes_finalizacao) {
					if(mes_hoje < mes_finalizacao)
						return true;
					if(dia_hoje <= dia_finalizacao)
						return true;
					return false;
				}
				return false;
			}
			return false;
		}
};
