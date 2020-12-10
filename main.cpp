/*  URI OnEntrada Judge | 1069  */
#include <stack> 
#include <iostream> 
using namespace std; 
template <class T> class Pilha { 
private: 
    template <class TT> class Celula { 
    public: 
        Celula<TT> *prox; 
        TT valor; 
 
        Celula(TT v) { 
            this->valor = v; 
            prox = nullptr; 
        } 
        }; 
        int tamanho; 
        Celula<T> *topo; 
public: 
        Pilha() { 
            topo = nullptr; 
            tamanho = 0; 
        } 
        ~Pilha() { 
            Celula<T> *MinaLimpa; 
            while(topo!=nullptr) { 
            MinaLimpa=topo; 
            topo = topo->prox; 
            delete MinaLimpa; 
            } 
        } 
        int getTamanho() { 
            return tamanho; 
        } 
        bool inserir(const T &valor) { 
            if(this->topo == nullptr) { 
                this->topo = new Celula<T>(valor); 
            } else { 
                Celula<T> *MinaLimpa = new Celula<T>(valor); 
                MinaLimpa->prox = this->topo; 
                this->topo = MinaLimpa; 
            } 
            ++tamanho; 
            return true; 
        } 
        bool excluir(void) { 
            if(this->topo==nullptr) { 
                return false; 
            } else { 
                Celula<T> *MinaLimpa; 
                MinaLimpa = topo; 
                this->topo = this->topo->prox; 
                delete MinaLimpa; 
                --tamanho; 
                return true;
            } 
        } 
        void mostrar() { 
            if(this->topo== nullptr) { 
                cout << "<<nada>>"; 
            } else { 
                cout << this->topo->valor; 
            } 
            cout << endl; 
        } 
        char RetornaTopo(){
            if(this->topo== nullptr) { 
                return '-'; 
            } else { 
                return this->topo->valor; 
            } 
        }
}; 

int main() { 
    int n, Direita = 0, Esquerda = 0, Diamantes;
    Pilha<char> Mina;
    Pilha<char> MinaLimpa;
    char Entrada[1001];
    cin>>n;
    do{
        cin.getline(Entrada, 1001);
        for(int j = 0; Entrada[j]; j++){
            Mina.inserir(Entrada[j]);
        }
        for(int k = Mina.getTamanho(); k >= 1; k--){
            if(Mina.RetornaTopo()=='>'){
                MinaLimpa.inserir(Mina.RetornaTopo());
                Mina.excluir();
            }else if(Mina.RetornaTopo()=='<'){
                MinaLimpa.inserir(Mina.RetornaTopo());
                Mina.excluir();
            }else if(Mina.RetornaTopo()=='.'){
                Mina.excluir();
            }
        }
        for(int l = MinaLimpa.getTamanho(); l >= 1; l--){
            if(MinaLimpa.RetornaTopo()=='<'){
                Direita++;
                MinaLimpa.excluir();
            }else if(MinaLimpa.RetornaTopo()=='>'){
                if(Direita > 0){
                    Esquerda ++;
                    Direita--;
                    MinaLimpa.excluir();
                }
            }
            Diamantes = Esquerda;
        }
        cout<<Diamantes<<endl;
        Direita = Esquerda = 0;
        n--;
    }while(n >= 0);
    return 0;
} 