#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


void login(){
 int pwd = 1234;
 int senha;
 char mail[] = "doutordacarne";
 char email[14];
 
 printf("\n\t****  TECHVET  *****");
 
 printf("\n\t <-> LOGIN DE ACESSO: ");
 fgets(email,14,stdin);
 printf ("\n\t <-> SENHA DE ACESSO: ");
 scanf("%d", &senha);
 
 if (strcmp (mail, email)== 0 && pwd == senha){
        printf("\n\tAcesso permitido");
    }else{
        printf("\n\tAcesso negado, email ou senha incorreta.");
    }
}

struct Animal {
	int id;
    char nome[50];
    long idTutor;
    char nomeTutor[50];
    char especie[30];
    char raca[30];
    char pelo[10];
    char cor[10];
    char sexo[2];
    int idade;
    char castrado[3];
    float peso;
    char restricoes[200];
    
}; 

struct Tutor {
	long id;//observar que talvez esse id choque com a fun��o de id nos metodos de impressao de todos os dados
	unsigned long cpf;
    char nome[50];
    int telefone;
    char sexo[2];
    char nascimento[10];
    char rg[15];
    char cep[9];
    char endereco[100];
    int numero;
    char bairro[15];
    char complemento[30];
    char cidade[20];
    char estado[20];
    char email[50];
};

Tutor tutorMock = {
	1,
	123456789,
	"Cleiton",
	819957175,
};

Tutor tutor2Mock = {
	2,
	122456789,
	"Abiel",
	819957175,
};

Animal animalMock = {
	1,
	"Raquel",
	123456789
};

Animal animal2Mock = {
	1,
	"Toto",
	122456789
};

Animal animal3Mock = {
	1,
	"Poli",
	122456789
};

struct Animal novoAnimal[100] = {animalMock, animal2Mock, animal3Mock};
struct Tutor tutoresCadastrados[100] = {tutorMock, tutor2Mock};
int id = 2;
int idAnimal = 3;

int menuTutor();
void cadastrarTutores();
void imprimirTutores();
void buscarTutores();
int menuAnimal();
void cadastrarAnimais();
void imprimirAnimais();
void buscarAnimais();

int menu(){
	int opcao;
	
	printf("\nMENU PRINCIPAL:");
	printf("\n[1] - AGENDA");
	printf("\n[2] - PROPRIETARIO");
	printf("\n[3] - ANIMAIS");
	printf("\n[4] - LABORATORIO");
	printf("\n[5] - FINANCEIRO");
	printf("\n[6] - SAIR");
	
	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("clear");
	
	switch(opcao) {
		case 1:
			//agenda();
			break;
		case 2:
			menuTutor();
			break;
		case 3:
			menuAnimal();
			break;
		case 4:
			//laboratorio();
			break;
		case 5:
			break;
		case 6:
			printf("ENCERRANDO PROGRAMA!!!");
			break;
		default:
			printf("OPCAO INVALIDA\n");
			menu();
	}
	
	return opcao;
}
int menuTutor(){
	int opcao;
	
	printf("\nMENU PROPRIETARIO:");
	printf("\n[1] - CADASTRAR PROPRIETARIO");
	printf("\n[2] - BUSCAR PROPRIETARIO");
	printf("\n[3] - PROPRIETARIO CADASTRADOS");
	printf("\n[4] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("clear");
	
	switch(opcao) {
		case 1:
			cadastrarTutores();
			break;
		case 2:
			buscarTutores();
			break;
		case 3:
			imprimirTutores();
			break;
		case 4:
			menu();
			break;
		default:
			printf("OPCAO INVALIDA\n");
			menuTutor();
	}
	
	return opcao;
}

void cadastrarTutores(){
	struct Tutor tutor;
    
    printf("CADASTRO DE PROPRIETARIO:\n");
    
    getchar();
    printf("NOME DO PROPRIETARIO: ");
    fgets(tutor.nome, sizeof(tutor.nome), stdin);
    
    printf("TELEFONE: ");
    scanf("%d", &tutor.telefone); 
	
	printf("SEXO: ");
	scanf("%s", &tutor.sexo); 
    
    printf("NASCIMENTO: ");
    scanf("%s", &tutor.nascimento); 
    
    printf("CPF: ");
    scanf("%ld", &tutor.cpf);
    
    printf("RG: ");
    scanf("%s", &tutor.rg);
    
    printf("CEP: ");
    scanf("%s", &tutor.cep);
    
    getchar();
    
    printf("ENDERECO: ");
    fgets(tutor.endereco, sizeof(tutor.endereco), stdin);
    
    printf("NUMERO: ");
    scanf("%d", &tutor.numero);
    
    getchar();
    
    printf("BAIRRO: ");
    fgets(tutor.bairro, sizeof(tutor.bairro), stdin); 
    
    printf("COMPLEMENTO: ");
    fgets(tutor.complemento, sizeof(tutor.complemento), stdin);
    
    printf("CIDADE: ");
    fgets(tutor.cidade, sizeof(tutor.cidade), stdin);
    
    printf("ESTADO: ");
    fgets(tutor.estado, sizeof(tutor.estado), stdin);
    
    printf("EMAIL: ");
    scanf("%s", &tutor.email);
    
    tutor.id = id + 1;
    id++;

   	tutoresCadastrados[id - 1] = tutor;
    
    
    printf("\nPROPRIETARIO CADASTRADO!\n");
    menuTutor();
	
}

void buscarTutores(){
    
	long buscarTutor;
	
    printf("\nBUSCAR PROPRIETARIO CADASTRADO\n");
    printf("\nDIGITE O CPF DO PROPRIETARIO: ");
 	scanf("%ld", &buscarTutor);
	
	int x;
    int num_elements = sizeof(tutoresCadastrados) / sizeof(tutoresCadastrados[0]); //erro aqui no codigo nao esta convertendo 
    for (x = 0; x < num_elements; x++) {
 		if(tutoresCadastrados[x].id == buscarTutor) {
    		printf("\nNOME DO PROPRIETARIO: %s", tutoresCadastrados[x].nome); 
    		printf("TELEFONE: %d", tutoresCadastrados[x].telefone); 
			printf("\nSEXO: %s", tutoresCadastrados[x].sexo); 
    		printf("\nNASCIMENTO: %s", tutoresCadastrados[x].nascimento); 
    		printf("\nCPF: %ld", tutoresCadastrados[x].id);
			printf("\nRG: %s", tutoresCadastrados[x].rg);
            printf("\nCEP: %s", tutoresCadastrados[x].cep);
    		printf("\nENDERECO: %s", tutoresCadastrados[x].endereco);
    		printf("NUMERO: %d", tutoresCadastrados[x].numero);
    		printf("BAIRRO: %s", tutoresCadastrados[x].bairro); 
    		printf("COMPLEMENTO: %s", tutoresCadastrados[x].complemento); 
			printf("CIDADE: %s", tutoresCadastrados[x].cidade);
			printf("ESTADO: %s", tutoresCadastrados[x].estado);
    		printf("EMAIL: %s", tutoresCadastrados[x].email);
        	printf("\n-----------------------------\n");
        	
        	if(novoAnimal[x].idTutor == tutoresCadastrados[x].id){
        		printf("ANIMAIS DO TUTOR: %s", novoAnimal[x].nome);
        		printf("\n-----------------------------\n");
        		break;
			}else{
				printf("NAO POSSUI ANIMAIS CADASTRADO");
			}
		}
    }
    printf("\nPROPRIETARIO NAO ENCONTRADO!");
    printf("\n-----------------------------\n");
    printf("%ld", buscarTutor);
    menuTutor();
    
}


void imprimirTutores() {
    int i;
    printf("\nPROPRIETARIOS CADASTRADOS:\n");
    
    for (i = 0; i < id; i++) {
    	if(tutoresCadastrados[i].id != 0) {
    
    		printf("\nNOME DO PROPRIETARIO: %s", tutoresCadastrados[i].nome); 
    		printf("TELEFONE: %d", tutoresCadastrados[i].telefone); 
			printf("\nSEXO: %s", tutoresCadastrados[i].sexo); 
    		printf("\nNASCIMENTO: %s", tutoresCadastrados[i].nascimento); 
    		printf("\nCPF: %ld", tutoresCadastrados[i].cpf);
			printf("\nRG: %s", tutoresCadastrados[i].rg);
            printf("\nCEP: %s", tutoresCadastrados[i].cep);
    		printf("\nENDERECO: %s", tutoresCadastrados[i].endereco);
    		printf("\nNUMERO: %d", tutoresCadastrados[i].numero);
    		printf("\nBAIRRO: %s", tutoresCadastrados[i].bairro); 
    		printf("\nCOMPLEMENTO: %s", tutoresCadastrados[i].complemento); 
			printf("CIDADE: %s", tutoresCadastrados[i].cidade);
			printf("ESTADO: %s", tutoresCadastrados[i].estado);
    		printf("EMAIL: %s", tutoresCadastrados[i].email);
        	printf("\n-----------------------------\n");

    		int possui_animais = 0;
        	for(int y = 0; y < idAnimal; y++) {        		
	        	if(novoAnimal[y].idTutor == tutoresCadastrados[i].cpf){
	        		possui_animais = 1;
	        		printf("ANIMAIS DO TUTOR: %s", novoAnimal[y].nome);
	        		printf("\n-----------------------------\n");
				}
			}

    		if(possui_animais == 0) {
    			printf("\nN�O POSSUI ANIMAIS CADASTRADO");
    		}
		}
    }
    menuTutor();
}
	
	
int menuAnimal(){

	printf("id: %d", idAnimal);
	printf("\nTutor: %ld",novoAnimal[idAnimal].idTutor);
	int opcao;
	
	printf("\nMENU ANIMAL:");
	printf("\n[1] - CADASTRAR ANIMAL");
	printf("\n[2] - BUSCAR ANIMAL");
	printf("\n[3] - ANIMAIS CADASTRADO");
	printf("\n[4] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("clear");
	
	switch(opcao) {
		case 1:
			cadastrarAnimais();
			break;
		case 2:
			buscarAnimais();
			break;
		case 3:
			imprimirAnimais();
			break;
		case 4:
			menu();
		default:
			printf("OPCAO INVALIDA\n");
			menuAnimal();
	}
	
	return opcao;
}	


void cadastrarAnimais() {
	
    struct Animal animal;
    
    printf("CADASTRO DE ANIMAIS:\n");
    
    printf("NOME DO ANIMAL: ");
    scanf("%s", &animal.nome); 
    
    printf("NOME DO TUTOR: ");
    scanf("%s", &animal.nomeTutor); 
	
	printf("CPF DO TUTOR: ");
	scanf("%ld", &animal.idTutor); 
    
    printf("ESPECIE: ");
    scanf("%s", &animal.especie); 
    
    printf("RACA: ");
    scanf("%s", &animal.raca);
    
    printf("PELO: ");
    scanf("%s", &animal.pelo);
    
    printf("COR: ");
    scanf("%s", &animal.cor);
    
    printf("SEXO: ");
    scanf("%s", &animal.sexo);
    
    printf("CADASTRADO: ");
    scanf("%s", &animal.castrado);
    
    printf("IDADE: ");
    scanf("%d", &animal.idade); 
    
    printf("PESO(0.30 KG): ");
    scanf("%f", &animal.peso); 
    
    printf("RESTRICOES: ");
    scanf("%s", &animal.restricoes);
    
    animal.id = idAnimal + 1;
    idAnimal++;
    
    //int num_elements = sizeof(novoAnimal) / sizeof(novoAnimal[0]);
    novoAnimal[idAnimal - 1] = animal;
    
    printf("\nPACIENTE CADASTRADO!\n");
    menuAnimal();
}

void imprimirAnimais() {
    int i;
    int num_elements = sizeof(novoAnimal) / sizeof(novoAnimal[0]);
    printf("\nANIMAIS CADASTRADO:\n");
    
    for (i = 0; i < num_elements; i++) {
    	if(novoAnimal[i].id != 0) {
    		printf("\nNOME DO ANIMAL: %s", novoAnimal[i].nome);
    		printf("\nNOME DO TUTOR: %s", novoAnimal[i].nomeTutor);
			printf("\nESPECIE: %s", novoAnimal[i].especie);
			printf("\nRACA: %s", novoAnimal[i].raca);
			printf("\nPELO: %s", novoAnimal[i].pelo);
			printf("\nCOR: %s", novoAnimal[i].cor);
			printf("\nSEXO: %s", novoAnimal[i].sexo);
			printf("\nCASTRADO: %s", novoAnimal[i].castrado);
			printf("\nIDADE: %d", novoAnimal[i].idade);
			printf("\nPESO: %f  KG", novoAnimal[i].peso);
			printf("\nRESTRICOES: %s", novoAnimal[i].restricoes);
        	printf("\n-----------------------------\n");
		}
    }
    menuAnimal();
}

void buscarAnimais() {
	
	char buscaranimal[50];
	
    printf("\nBUSCAR ANIMAIS CADASTRADO\n");
    printf("\nDIGITE O NOME DO ANIMAL: ");
 	scanf("%s", &buscaranimal);
 	
 	
 	int y;
 	int num_elements = sizeof(novoAnimal) / sizeof(novoAnimal[0]);
    for (y = 0; y < num_elements; y++) {
 		if(strcmp (novoAnimal[y].nome, buscaranimal)== 0){
    		printf("\nNOME DO ANIMAL: %s", novoAnimal[y].nome);
    		printf("\nNOME DO TUTOR: %s", novoAnimal[y].nomeTutor);
			printf("\nESPECIE: %s", novoAnimal[y].especie);
			printf("\nRA�A: %s", novoAnimal[y].raca);
			printf("\nPELO: %s", novoAnimal[y].pelo);
			printf("\nCOR: %s", novoAnimal[y].cor);
			printf("\nSEXO: %s", novoAnimal[y].sexo);
			printf("\nCASTRADO: %s", novoAnimal[y].castrado);
			printf("\nIDADE: %d", novoAnimal[y].idade); //troca a idade por data de nascimento para o sistema converter automaticamente a idade do animal
			printf("\nPESO: %f  KG", novoAnimal[y].peso);
			printf("\nRESTRICOES: %s", novoAnimal[y].restricoes); // essa parte pode ser tirada
        	printf("\n-----------------------------\n");
		    menuAnimal();
			return;
			}
		}
    
    printf("\nANIMAL NAO ENCONTRADO!");
    printf("\n-----------------------------\n");
    menuAnimal();
}
int laboratorio(){


	int opcao;
	
	printf("\nMENU LABORATORIO:");
	printf("\n[1] - CADASTRAR EXAME");
	printf("\n[2] - RESULTADO DE EXAME");
	printf("\n[3] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("clear");
	
	switch(opcao) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			menu();
			
		default:
			printf("OPCAO INVALIDA\n");
			menuAnimal();
	}
	
	return opcao;
}

typedef struct {
    char nomedoproduto[50];
    char grupo[30];
    float valor;
    int qtdestoque;
} Produto;

int estoque(){


	int opcao;
	
	printf("\nMENU ESTOQUE:");
	printf("\n[1] - CADASTRAR PRODUTO");
	printf("\n[2] - LISTA PRODUTOS");
	printf("\n[3] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("clear");
	
	switch(opcao) {
		case 1:
			//cadastraproduto();
			break;
		case 2:
			
			break;
		case 3:
			menu();
			
		default:
			printf("OPCAO INVALIDA\n");
			menuAnimal();
	}
	
	return opcao;
}	


void cadastroproduto(){
       
	Produto novoproduto;
    
    printf("CADASTRO DE ANIMAIS:\n");
    
    printf("\nNOME DO PRODUTO: ");
    scanf("%s", &novoproduto.nomedoproduto);  
    
    printf("\nGRUPO: ");
    scanf("%s", &novoproduto.grupo); 
    
    printf("\nVALOR: ");
    scanf("%f", &novoproduto.valor); 
    
    printf("\nQtd. ESTOQUE: ");
    scanf("%d", &novoproduto.qtdestoque); 
    
    
    printf("\nPRODUTO CADASTRADO!\n");
}

int main(int argc, char *argv[]) {
	login();
	system("clear");
	printf("\n\t BEM VINDO AO SISTEMA DE  GERENCIAMENTO");
    printf("\n\t****  TECHVET  *****");
    menu();
	return 0;
}

//
