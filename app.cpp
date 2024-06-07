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
    unsigned long long idTutor;
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
	long id; //observar que talvez esse id choque com a fun??o de id nos metodos de impressao de todos os dados
	unsigned long long cpf;
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

struct Agenda{
	int numConsulta;
	char tutor[50];
	char animal[50];
	char data[11]; //formato 10/10/1010
	char hora[6]; //fromato 15:00
	char veterinario[50];	
};

struct Laboratorio {
    int id_exame;
    char nome_animal[50];
    unsigned long long cpf_tutor;
    char data[11];
    char medico[30];
    char situacao[10];
    float hemacias;
    float globular;
    float hemoglobina;
    float vgm;
    float chgm;
    long plaquetas;
    float proteina;
    long leucometria;
    float bastonetes;
    float segmentos;
    float linfocitos;
    float eosinofilos;
    float basofilos;
    float monocitos;
    float mielocitos;
    float metamielocitos;
    char obs[500];
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

Tutor tutor3Mock = {
	3,
	12345678900,
	"Ale",
	819957175,
};

Animal animalMock = {
	1,
	"Raquel",
	123456789,
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

struct Agenda consultas[100];
struct Animal novoAnimal[100] = {animalMock, animal2Mock, animal3Mock};
struct Tutor tutoresCadastrados[100] = {tutorMock, tutor2Mock, tutor3Mock};
struct Laboratorio novoExame[100];

int numConsulta = 0;
int id = 3;
int idAnimal = 3;
int id_exame = 0;

int agenda();
bool verificaragendamento(const char* data, const char* hora, const char* veterinario);
void agendarconsulta();
void ordenarConsultas();
void agendadiaria();
void mostrarConsultas();
int menuTutor();
void cadastrarTutores();
void imprimirTutores();
void buscarTutores();
int menuAnimal();
void cadastrarAnimais();
void imprimirAnimais();
void buscarAnimais();
int menuLaboratorio();
void cadastrarexame();

int menu(){
	int opcao;
	
	printf("\nMENU PRINCIPAL:");
	printf("\n[1] - AGENDA");
	printf("\n[2] - PROPRIETARIO");
	printf("\n[3] - ANIMAIS");
	printf("\n[4] - LABORATORIO");
	printf("\n[5] - SAIR");
	
	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao) {
		case 1:
			agenda();
			break;
		case 2:
			menuTutor();
			break;
		case 3:
			menuAnimal();
			break;
		case 4:
			menuLaboratorio();
			break;
		case 5:
			printf("ENCERRANDO PROGRAMA!!!");
			break;
		default:
			printf("OPCAO INVALIDA\n");
			menu();
	}
	
	return opcao;
}

int agenda(){
	
int opcao;
	
	printf("\nMENU AGENDA:");
	printf("\n[1] - AGENDAR CONSULTA");
	printf("\n[2] - AGENDA DIARIA");
	printf("\n[3] - CONSULTAS AGENDADAS");
	printf("\n[4] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao) {
		case 1:
			agendarconsulta();
			break;
		case 2:
			agendadiaria();
			break;
		case 3:
			mostrarConsultas();
			break;
		case 4:
			menu();
			break;
		default:
			printf("OPCAO INVALIDA\n");
			agenda();
	}
	
	return opcao;	
}
bool verificaragendamento(const char* data, const char* hora, const char* veterinario) {
    for (int r = 0; r < numConsulta; r++) {
        if (strcmp(consultas[r].data, data) == 0 && 
            strcmp(consultas[r].hora, hora) == 0 && 
            strcmp(consultas[r].veterinario, veterinario) == 0) {
            printf("\nDATA E HORA ESTÃO OCUPADOS, ESCOLHA OUTRO HORÁRIO OU OUTRA DATA OU OUTRO VETERINÁRIO!\n\n");
            return true;
        }
    }
    return false;
}

void agendarconsulta() {
	
    struct Agenda agendar; 
    
    printf("AGENDAR CONSULTA\n");

    printf("NOME DO PROPRIETARIO: ");
    scanf("%s", &agendar.tutor);

    printf("NOME DO ANIMAL: ");
    scanf("%s", &agendar.animal);
    do{
    	printf("DATA (DD/MM/AAAA): ");
    	scanf("%s", &agendar.data);  

    	printf("HORA (HH:MM): ");
    	scanf("%s", &agendar.hora);  
    
    	printf("VETERINARIO: ");
    	scanf("%s", &agendar.veterinario);
    
    } while(verificaragendamento(agendar.data, agendar.hora, agendar.veterinario));
	
    
    agendar.numConsulta = numConsulta + 1;

	
    consultas[numConsulta] = agendar;
    numConsulta++;

    printf("\nCONSULTA AGENDADA!\n");
    agenda(); 
}

void ordenarConsultas() { 
    struct Agenda temp; // Declaração da variável temp
    
    for (int i = 0; i < numConsulta - 1; i++) {
        for (int j = 0; j < numConsulta - i - 1; j++) {
            // Compara as datas
            if (strcmp(consultas[j].data, consultas[j + 1].data) > 0 ||
                (strcmp(consultas[j].data, consultas[j + 1].data) == 0 &&
                 strcmp(consultas[j].hora, consultas[j + 1].hora) > 0)) {
                temp = consultas[j]; // Não é necessário redeclarar temp
                consultas[j] = consultas[j + 1];
                consultas[j + 1] = temp;
            }
        }
    }
}
	

void agendadiaria(){
	
	if (numConsulta==0){
    	printf("NAO TEM CONSULTA AGENDADA PARA ESSA DATA!\n");
	}
	
	ordenarConsultas();
	
	char data[10];
	printf("DIGITE A DATA: ");
	scanf("%s", &data);
	
	system("cls");
	
    for (int i = 0; i < numConsulta; i++) {
        if (strcmp(consultas[i].data, data) == 0) { 
        	printf("----------------------------------------\n");
    		printf("\tAGENDA PARA A DATA %s\n", data);
    		printf("----------------------------------------\n");
            printf("NOME DO PROPRIETARIO: %s\n", consultas[i].tutor);
            printf("NOME DO ANIMAL: %s\n", consultas[i].animal);
            printf("HORARIO: %s\n", consultas[i].hora);
            printf("VETERINARIO: %s\n", consultas[i].veterinario);
            printf("----------------------------------------\n");
        }
    }

	agenda();
}
void mostrarConsultas(){
	
    if (numConsulta==0){
    	printf("NAO TEM CONSULTA AGENDA!\n");
	}
	
	ordenarConsultas();
	
    int y;
    for (int y = 0; y < numConsulta; y++) {
    	printf("\tCONSULTAS AGENDADAS:\n");
    	printf("\n-----------------------------\n");
    	printf("PROPRIETARIO: %s\n", consultas[y].tutor);
    	printf("ANIMAL: %s\n", consultas[y].animal);
    	printf("DATA: %s\n", consultas[y].data);
    	printf("HORA: %s\n", consultas[y].hora);
    	printf("VETERINARIO: %s\n", consultas[y].veterinario);
    	printf("\n-----------------------------\n");
    }
    agenda();
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
	
	system("cls");
	
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
    scanf("%llu", &tutor.cpf);
    
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
    
	unsigned long long buscarTutor;
	
    printf("\nBUSCAR PROPRIETARIO CADASTRADO\n");
    printf("\nDIGITE O CPF DO PROPRIETARIO: ");
 	scanf("%llu", &buscarTutor);
 	
	int x;
	int possui_tutor = 0;
    for (x = 0; x < id; x++) {
 		if(tutoresCadastrados[x].cpf == buscarTutor) {
 			possui_tutor = 1;
    		printf("\nNOME DO PROPRIETARIO: %s", tutoresCadastrados[x].nome); 
    		printf("TELEFONE: %d", tutoresCadastrados[x].telefone); 
			printf("\nSEXO: %s", tutoresCadastrados[x].sexo); 
    		printf("\nNASCIMENTO: %s", tutoresCadastrados[x].nascimento); 
    		printf("\nCPF: %llu", tutoresCadastrados[x].id);
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

    		int possui_animais = 0;
        	for(int y = 0; y < idAnimal; y++) {        		
	        	if(novoAnimal[y].idTutor == tutoresCadastrados[x].cpf){
	        		possui_animais = 1;
	        		printf("ANIMAIS DO TUTOR: %s", novoAnimal[y].nome);
	        		printf("\n-----------------------------\n");
				}
			}

    		if(possui_animais == 0) {
    			printf("\nNAO POSSUI ANIMAIS CADASTRADO");
    		}
    		
		} 
		
    }if(possui_tutor == 0){
		printf("\nPROPRIETARIO NAO ENCONTRADO / NAO POSSUI CADASTRO!\n"); 
	}
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
    		printf("\nCPF: %llu", tutoresCadastrados[i].cpf);
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
    			printf("\nNAO POSSUI ANIMAIS CADASTRADO");
    		}
		}
    }
    menuTutor();
}
	
	
int menuAnimal(){

	int opcao;
	
	printf("\nMENU ANIMAL:");
	printf("\n[1] - CADASTRAR ANIMAL");
	printf("\n[2] - BUSCAR ANIMAL");
	printf("\n[3] - ANIMAIS CADASTRADO");
	printf("\n[4] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("cls");
	
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
	scanf("%llu", &animal.idTutor); 
    
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
    
    printf("CASTRADO: ");
    scanf("%s", &animal.castrado);
    
    printf("IDADE: ");
    scanf("%d", &animal.idade); 
    
    printf("PESO(0.30 KG): ");
    scanf("%f", &animal.peso); 
    
    printf("RESTRICOES: "); //tirar essa opção
    scanf("%s", &animal.restricoes);
    
    animal.id = idAnimal + 1;
    idAnimal++;
    
    
    novoAnimal[idAnimal - 1] = animal;
    
    printf("\nPACIENTE CADASTRADO!\n");
    menuAnimal();
}

void imprimirAnimais() {
    int i;
    printf("\nANIMAIS CADASTRADO:\n");
    
    for (i = 0; i < idAnimal; i++) {
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
    for (y = 0; y < idAnimal; y++) {
 		if(strcmp (novoAnimal[y].nome, buscaranimal)== 0){
    		printf("\nNOME DO ANIMAL: %s", novoAnimal[y].nome);
    		printf("\nNOME DO TUTOR: %s", novoAnimal[y].nomeTutor);
			printf("\nESPECIE: %s", novoAnimal[y].especie);
			printf("\nRACA: %s", novoAnimal[y].raca);
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

int menuLaboratorio(){


	int opcao;
	
	printf("\nMENU LABORATORIO:");
	printf("\n[1] - CADASTRAR EXAME");
	printf("\n[2] - RESULTADO DE EXAME");
	printf("\n[3] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao) {
		case 1:
			cadastrarexame();
			break;
		case 2:
			
			break;
		case 3:
			menu();
			
		default:
			printf("OPCAO INVALIDA\n");
			menuLaboratorio();
	}
	
	return opcao;
}

void cadastrarexame(){
	struct Laboratorio exame;
	
	printf("\tCADASTRO DE EXAME\n\n");
	
	printf("NOME DO ANIMAL: ");
	scanf("%s", exame.nome_animal);
	
	printf("CPF DO TUTOR: ");
	scanf("%llu", exame.cpf_tutor);
	
	printf("DATA: ");
	scanf("%s", exame.data);
	
	printf("SITUAÇÃO: ");
	scanf("%s", exame.situacao);
	
	printf("HEMÁCIAS(x10/mm6): ");
	scanf("%f", exame.hemacias);
	
	printf("VOLUME GLOBULAR(%): ");
	scanf("%f", exame.globular);
	
	printf("PLAQUETAS(MILHARES/MM³): ");
	scanf("%lu", exame.plaquetas);
	
	printf("PROTEÍNA PLASMÁTICA TOTAL (G/DL): ");
	scanf("%f", exame.proteina);
	
	printf("LEUCOMETRIA: ");
	scanf("%lu", exame.leucometria);
	
	printf("BASTONETES: ");
	scanf("%f", exame.bastonetes);
	
	printf("SEGMENTADOS: ");
	scanf("%f", exame.segmentos);
	
	printf("LINFOCITOS: ");
	scanf("%f", exame.linfocitos);

	printf("EOSINOFILOS: ");
	scanf("%f", exame.eosinofilos);
	
	printf("BASOFILOS: ");
	scanf("%f", exame.basofilos);

	printf("MONOCITOS: ");
	scanf("%f", exame.monocitos);
	
	printf("MIELOCITOS: ");
	scanf("%f", exame.mielocitos);
	
	printf("METAMIELÓCITOS: ");
	scanf("%f", exame.metamielocitos);
	
	printf("CADASTRO CONCLUÍDO!");

	exame.id_exame = id_exame + 1;
    id_exame++;
    
    
    novoExame[id_exame - 1] = exame;
    
    menuLaboratorio();
}

void resultadoExame(){
	/*printf("====================================================================\n");
    printf("|              CLÍNICA VETERINÁRIA CARNEVET                         |\n");
    printf("|                 AV. CARNE LEITAO, Nª001                   |\n");
    printf("|                    (81) 1112-0000                                     |\n");
    printf("====================================================================\n");
    printf("| ANIMAL: %s                               ESPÉCIE: %s                                  |\n");
    printf("| SEXO: %s                                 RAÇA: %s                                     |\n");
    printf("| MÉD. VET.: %s                            DATA: %s                                     |\n");
    printf("| TUTOR: %s                                SITUAÇÃO: %s                                 |\n");
    printf("====================================================================\n");
    printf("|                           HEMATIMETRIA           |   VALORES DE REFERÊNCIA |\n");
    printf("| Hemácias (x10/mm6)                   4,83        |     6,0 a 7,0           |\n");
    printf("| Volume Globular (%)                 32           |     40 a 47             |\n");
    printf("| Hemoglobina (g/dL)                  10,67        |     14 a 17             |\n");
    printf("| VGM (fl)                            66,25        |     65 a 78             |\n");
    printf("| CHGM (%)                            33,33        |     30 a 35             |\n");
    printf("| Plaquetas (milhares / mm³)         156000        |     200000 a 500000     |\n");
    printf("| Proteína Plasmática Total (g/dL)     7,2         |     5,0 a 7,0           |\n");
    printf("====================================================================\n");
    printf("| LEUCOMETRIA                 5198          |     8000 a 16000     |\n");
    printf("====================================================================\n");
    printf("|       Relativo (%)     |    Absoluto     |    Relativo (%)     |     Absoluto       |\n");
    printf("| Bastonetes      %f%    |       0         |     0 a 1           |     0 a 160        |\n");
    printf("| Segmentados     %f%    |     3742        |     55 a 70         |  3760 a 11040      |\n");
    printf("| Linfócitos      %f%    |      572        |     20 a 40         |  2240 a 7200       |\n");
    printf("| Eosinófilos     %f%    |      416        |     1 a 6           |     80 a 800       |\n");
    printf("| Basófilos       %f%    |       0         |     RAROS           |     RAROS          |\n");
    printf("| Monócitos       %f%    |      468        |     2 a 8           |  160 a 1600        |\n");
    printf("| Mielócitos      %f%    |       0         |     0               |     0              |\n");
    printf("| Metamielócitos  %f%    |       0         |     0               |     0              |\n");
    printf("====================================================================\n");
    printf("OBS: ANEMIA NORMOCITICA HIPOCROMICA, TROMBOCITOPENIA, HIPERPROTEINEMIA, LEUCOPENIA,\n");
    printf("NEUTROPENIA, LINFOCITOPENIA, EOSINOFILIA RELATIVA, MONOCITOSE RELATIVA.\n");
    printf("====================================================================\n");*/
}
typedef struct {
    char nomedoproduto[50];
    char grupo[30];
    float valor;
    int qtdestoque;
} Produto;

int menuestoque(){


	int opcao;
	
	printf("\nMENU ESTOQUE:");
	printf("\n[1] - CADASTRAR PRODUTO");
	printf("\n[2] - LISTA PRODUTOS");
	printf("\n[3] - VOLTAR");

	printf("\nDIGITE A OPCAO: ");
	scanf("%d", &opcao);
	
	system("cls");
	
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
			menuestoque();
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
	system("cls");
	printf("\n\t BEM VINDO AO SISTEMA DE  GERENCIAMENTO");
    printf("\n\t****  TECHVET  *****");
    menu();
	return 0;
}

//
