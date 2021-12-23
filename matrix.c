#include <pthread.h>
#include <stdio.h>
/*Hàm tính toán trả về số nguyên tố thứ n, n là là giá trị được trỏ bởi
*arg. */
struct char_print_parms

{
int m,n,p;
            
             

};
void* compute_prime (void* arg)
{
 struct char_print_parms* ph = (struct char_print_parms*) arg;

            int a[10][10],b[10][10],result[10][10];

        int i,j,k;
            
            int n=ph->n;
            int m=ph->m;
            int p=ph->p;
    printf("\nEnter first matrix:\n");
        

        for(i=0;i<m;++i)
        {
            for(j=0;j<p;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        
        printf("\nEnter second matrix:\n");
        
        
        for(i=0;i<p;++i)
        {
            for(j=0;j<n;++j)
            {
            
                scanf("%d",&b[i][j]);
                
            }
        }
           for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                 result[i][j]=0;
                for(k=0;k<p;++k)
                    result[i][j]=result[i][j]+(a[i][k]*b[k][j]);
                        
                         printf("%d ",result[i][j]);
                       
            }
            
            printf("\n");
        }
        return NULL;
}
int main ()
{
 pthread_t  thread1_id; 

            struct char_print_parms  p1; 
           int m,n,p;
            

    printf("Enter rows and columns of first matrix:");
    scanf("%d%d",&m,&p);
    
    
    printf("Enter rows and columns of second matrix:");
    scanf("%d%d",&p,&n);
    
    
   
        
        p1.m=m;
        p1.n=n;
        p1.p=p;
        
            pthread_create(&thread1_id, NULL, &compute_prime , &p1);


            pthread_join(thread1_id, NULL);


 return 0;
}
