#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Struct composta por variáveis relacionadas ao ITEM

struct ITEM
  {
    char DESCRICAO[15];
    double QUANTIDADE;
    char UNI_MEDIDA[3];
    double VALOR_UNI;
    double VALORTOTAL;
  };


// Struct composta por variáveis relacionadas a categoria de compra
//Há também um vetor da struct item limitando a quantidade de itens em 10 para cada categoria
struct CATEGORIA
  {
    char NOME_CAT[25];
    int NUMEROITENS;
    double VALORTOTAL;

    struct ITEM item[10];
  };


 int main(void) {

   // Está declarado um vetor da struct CATEGORIA chamado cad_categoria
  

   struct CATEGORIA cad_categoria[10];
   double P_DESCONTO, VALORMINIMO, VALORTOTAL, VALORAPAGAR, VALORDAPARCELA;
   char TIPO_PAGTO;
   int TOTAL_ITENS;
   int PARCELAS;
   int N_CAT; 
   


    // Permite usar acentos
    setlocale(LC_ALL, "");

    //Primeiro loop: responsável por coletar nome da categoria e seu respectivo número de itens, bem como somar o número total de itens (todas as categorias) e valor total a ser pago (sem desconto)
    //Segundo loop: está contido dentro do primeiro loop e é responsável pela entrada de informações do item

    scanf ("%d", &N_CAT);

    for (int i = 0; i < N_CAT; i = i + 1 )
    
    {

      scanf ("%s %d\n", cad_categoria[i].NOME_CAT, &cad_categoria[i].NUMEROITENS);

      for (int j = 0; j < cad_categoria[i].NUMEROITENS; j = j + 1)
      
      {

      
        scanf ("%s %lf %s R$ %lf", cad_categoria[i].item[j].DESCRICAO, &cad_categoria[i].item[j].QUANTIDADE, cad_categoria[i].item[j].UNI_MEDIDA, &cad_categoria[i].item[j].VALOR_UNI);

        cad_categoria[i].item[j].VALORTOTAL = cad_categoria[i].item[j].VALOR_UNI * cad_categoria[i].item[j].QUANTIDADE;

        cad_categoria[i].VALORTOTAL = cad_categoria[i].VALORTOTAL + cad_categoria[i].item[j].VALORTOTAL; 


      }

  

    VALORTOTAL = cad_categoria[i].VALORTOTAL + VALORTOTAL;

    TOTAL_ITENS = cad_categoria[i].NUMEROITENS + TOTAL_ITENS;
        


    }

      scanf ("%lf %c R$ %lf", &P_DESCONTO, &TIPO_PAGTO, &VALORMINIMO); 

     VALORAPAGAR = VALORTOTAL - (VALORTOTAL * P_DESCONTO/100);

     //Condição de pagamento
     // Caso parcelado, o cliente poderá escolher o número de parcelas.
     // O pagamento à vista terá um o valor mínimo igual a 0

    if (TIPO_PAGTO == 'A' && VALORMINIMO == 0)
    
    {


        printf ("\nKauê Muniz Silva\n");
        printf ("munizkaueee@gmail.com\n");

      

    for (int i = 0; i < N_CAT; i = i + 1)
    
    {

        

      printf ("\n%s\n", cad_categoria[i].NOME_CAT);

      for (int j = 0; j < cad_categoria[i].NUMEROITENS; j = j + 1)
      {

       

         printf ("*%s : R$ %.2lf (%.2lf %s)\n", cad_categoria[i].item[j].DESCRICAO, cad_categoria[i].item[j].VALORTOTAL, cad_categoria[i].item[j].QUANTIDADE, cad_categoria[i].item[j].UNI_MEDIDA );

        

      

     }

      printf ("**TOTAL %s : R$ %0.2lf\n",cad_categoria[i].NOME_CAT, cad_categoria[i].VALORTOTAL);

    }

      printf ("\nTOTAL DE ITENS: %d\n", TOTAL_ITENS);

      printf ("\nVALOR TOTAL: R$ %0.2lf\n", VALORTOTAL);    

      printf ("\nDESCONTO: %0.2lf%%\n", P_DESCONTO);  

      printf ("\nVALOR DO DESCONTO: R$ %0.2lf\n", VALORTOTAL * (P_DESCONTO/100));

      printf ("\nVALOR A PAGAR: R$ %0.2lf\n", VALORAPAGAR);




    }  else if (TIPO_PAGTO == 'P' && VALORMINIMO != 0)
    
    {

      scanf ("%d", &PARCELAS);
      VALORDAPARCELA = VALORAPAGAR / PARCELAS;


      printf ("\nKauê Muniz Silva\n");
      printf ("munizkaueee@gmail.com\n");

      

      for (int i = 0; i < N_CAT; i = i + 1)
    
      {

        

        printf ("\n%s\n", cad_categoria[i].NOME_CAT);

        for (int j = 0; j < cad_categoria[i].NUMEROITENS; j = j + 1)
        {

       

          printf ("*%s : R$ %.2lf (%.2lf %s)\n", cad_categoria[i].item[j].DESCRICAO, cad_categoria[i].item[j].VALORTOTAL, cad_categoria[i].item[j].QUANTIDADE, cad_categoria[i].item[j].UNI_MEDIDA );

        

      

        }

       printf ("**TOTAL %s : R$ %0.2lf\n",cad_categoria[i].NOME_CAT, cad_categoria[i].VALORTOTAL);

    }

      printf ("\nTOTAL DE ITENS: %d\n", TOTAL_ITENS);

      printf ("\nVALOR TOTAL: R$ %0.2lf\n", VALORTOTAL);    

      printf ("\nDESCONTO: %0.2lf%%\n", P_DESCONTO);  

      printf ("\nVALOR DO DESCONTO: R$ %0.2lf\n", VALORTOTAL * (P_DESCONTO/100));

      printf ("\nVALOR A PAGAR: R$ %0.2lf\n", VALORAPAGAR);      

      printf ("\nPARCELAS:%d\n", PARCELAS);
        
      printf ("\nVALOR DA PARCELA: R$ %0.2lf\n", VALORDAPARCELA);







    }
    
}