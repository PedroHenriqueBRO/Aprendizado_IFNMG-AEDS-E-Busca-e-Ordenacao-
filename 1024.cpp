#include<iostream>
#include<vector>
using namespace std;
string toright(string aux){
       for(unsigned j=0;j<aux.length();j++){
        if(isalpha(aux[j])){ 
            
            aux[j]=aux[j]+3;}
       }
    
return aux;
}
string swap(string aux){
    
   int cont=0;
        
        for(unsigned j=aux.length();j>aux.length()/2;j--){
            char c=aux[cont];
            aux[cont]=aux[j-1];
            aux[j-1]=c;
            
            
            cont++;
        }
        
    
    return aux;
}
string midtoright(string aux){

    
        for(unsigned j=aux.length()/2;j<aux.length();j++){
            aux[j]=aux[j]-1;
        }
   
    return aux;

}
int main(){
int countN;
cout<<"Digite a quantidade de strings para serem criptografadas"<<endl;
cin>>countN;
vector<string>vectorstring;
cin.ignore();
for(int i=0;i<countN;i++){
    string aux;
    getline(cin,aux);
    aux=toright(aux);
    aux=swap(aux);
    aux=midtoright(aux);
    vectorstring.push_back(aux);

}
for(unsigned i=0;i<vectorstring.size();i++){
    cout<<vectorstring[i]<<endl;
}
    return 0;

}