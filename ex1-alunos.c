#include <stdio.h>
#include <malloc.h>


struct aluno {
     long nusp;
     char nome[50];
     double nota1;
     double nota2;
};

FILE *fp = NULL;

struct aluno *le_reg();

int main()
{
    int i=0,b, c=0, flag=0;
    int tam;
    long n=1;
    struct aluno *a;
    char newnome[49];
    
    a = le_reg();
   
    struct aluno v[50];
    
    while(a != NULL)
    {
        v[i++] = *a;
      
        a = le_reg();
    }
    tam = i;
    
    for(i=0;i<tam;i++)
    {
        printf("%ld\n", v[i].nusp);
        printf("%s", v[i].nome);
        printf("%.2f\n",v[i].nota1);
        printf("%.2f\n\n",v[i].nota2);
    }
    
  while (n != -1)
  {
    printf(">>Forneca o num usp do aluno a modificar ou deletar o registro o registro:\n (-1 para sair) \n>> ");
    scanf("%ld", &n);
    if(n == -1)
    	break;
    	
   	flag = 0;
    for(i=0;i<tam;i++)
    {
    
        if(n == v[i].nusp)
        {
            printf("\n\n>>Digite a acao que deseja fazer:\n");
			printf("1- Deletar o regitro\n2- Modificar a(s) nota(s)\n3- Modificar o nome do aluno\n4- Modificar o num USP\n");
			printf(">> ");
            scanf("%d",&b);
            
            switch (b)
            {
                case 1: v[i].nusp=-1;  //exclusao logica
                		printf("\n>>FEITO!\n");
                        break;
                        
                case 2: printf("\n>>Digite a acao para modificar as notas:\n1- Somente a nota 1\n2- Somente a nota 2\n3- As duas notas\n");
						scanf("%d",&c); //acao quanto as notas do aluno
                		if(c==1)
                		{
                			printf("\n>>Digite a nova nota 1 do aluno: ");
                			scanf("%lf", &v[i].nota1);
                			printf("\n>>FEITO!\n");
                		}
                		else if(c==2)
						{
							printf("\n>>Digite a nova nota 2 do aluno: ");
							scanf("%lf", &v[i].nota2);
							printf("\n>>FEITO!\n");
						}
                		else if(c==3)
                		{
							printf(">>Digite as novas notas do aluno: \n");
                        	scanf("%lf %lf", &v[i].nota1, &v[i].nota2);
                        	printf("\n>>FEITO!\n");
                        }
                        break;
                        
                case 3: fflush(stdin); //fflush para não dar problema no gets
						printf("\n>>Digite o novo nome do aluno:\n"); //modificação do nome do aluno
                		gets(v[i].nome);
                		printf("\n>>FEITO!\n");
                		break;
                		
                case 4: printf("\n>>Digite o novo Num USP do aluno:\n");//modificar o numero usp
                		scanf("%ld", &v[i].nusp);
                		printf("\n>>FEITO!\n");
                		break;  		
            }   
        }
    	else if((n != v[i].nusp) && (n!=-1))//flag caso o numero USP seja nvalido
    			{
    				flag++;
    			}
    	if(flag == tam)
    		printf("\n\n>> ERRO! Registro nao enontrado! <<\n\n"); // mensagem quando num usp for invalido
    }
  }    
   system("cls");
   printf(">> Listagem Final:\n\n");
   for(i=0;i<tam;i++)//for para listar o registro final
   {
   		if(v[i].nusp != -1)//usando a exclusao logica
   		{
   			printf(">Num USP= %ld\n", v[i].nusp);
       		printf(">Nome   = %s", v[i].nome);
        	printf(">Nota 1 = %.2f\n",v[i].nota1);
        	printf(">Nota 2 = %.2f\n\n",v[i].nota2);
   		}
   	}
   	system("PAUSE");
   	system("cls");
   	
   	free(a);  //liberação de memoria
   	printf(">> Memoria Liberada\n>> Fim do programa!\n");
	system("PAUSE");
}







struct aluno *le_reg()
{
    long k;
    struct aluno *a1;

    if ( fp == NULL )
    {
        fp = fopen("notas.txt", "r");
        if ( fp != NULL )
           printf("Arquivo aberto com sucesso\n");
    }
    if ( fp == NULL)
    {
        printf("Erro ao ler registro\n");
        return NULL;
    }
    fscanf(fp, "%ld", &k );
    if ( k == 0 ) return NULL;

    a1 = (struct aluno *) malloc(sizeof(struct aluno));
    a1->nusp = k;   //(*a1).nunsp
    fgets(a1->nome, 49, fp);
    fscanf(fp, "%lf", & (a1->nota1) );
    fscanf(fp, "%lf", & (a1->nota2) );
    return a1;
}

