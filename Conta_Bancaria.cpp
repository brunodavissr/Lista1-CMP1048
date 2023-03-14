#include <bits/stdc++.h>

using namespace std;

class Conta_Bancaria {
    private:
    float saldo;
    string titular;
    int numero;
    vector<string> historico;
    
    public:
    Conta_Bancaria(float saldo, string titular, int numero) {
        this->saldo = saldo;
        this->titular = titular;
        this->numero = numero;
    }
    
    void depositar(float deposito) {
        saldo+=deposito;
        historico.push_back("Deposito de " + to_string(deposito) + " reais");
    }
    
    void sacar(float saque) {
        saldo-=saque;
        historico.push_back("Saque de " + to_string(saque) + " reais");
    }
    
    void transferir(float transferencia) {
        saldo-=transferencia;
        historico.push_back("Transferencia de " + to_string(transferencia) + " reais");
    }
    
    float consultar_saldo() {
        return saldo;
    }
    
    vector<string> consultar_historico() {
        return historico;
    }
};
