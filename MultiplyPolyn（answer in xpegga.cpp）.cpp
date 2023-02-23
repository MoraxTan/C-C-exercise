#include<stdio.h>  
#include<string.h>  
int a[100000],b[100000],c[100000];  

int main() {    
    int i,j,m=0,n=0,t=0,x=0;
    int q,w=0;
	int max=0,maxa=0,maxb=0;
	int flag=1;     
    
    memset(a,0,sizeof(a));  
    memset(b,0,sizeof(b));  
    memset(c,0,sizeof(c));  
    
    scanf("%d",&t);
   
    while(t>0) {
    	t--;
    	scanf("%d",&x);
    	q=x;
    	for(int y=0;y<(x*2);y++) {

    		scanf("%d",&a[y]);
		}
		
		scanf("%d",&x);
		w=x;
    	for(int y=0;y<(x*2);y++) {

    		scanf("%d",&b[y]);
		}
		
		maxa=a[1]; //maxa is the highest pow of a
		maxb=b[1]; //same too
		printf("%d\n",a[1]);
		printf("%d\n",b[1]);
    	max=maxa+maxb;  
    	printf("%d",max);
    	
    	for(int o=0;o<(q*2);o++){
    		for(int p=0;p<(w*2);p++){
    			c[]
			}
		}
    	printf("D");
    	if(flag)  
        	printf("0");  
    	printf("\n");  
	}
	return 0;  
}  

