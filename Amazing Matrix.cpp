#include<stdio.h>
#include<stdlib.h>
void Symmetry(int m,int a[7][7]) {//judging Symmetric Asymmetric or not
	int i,j,c,b,d;
	c=0;
	d=0;
	b=0;
	d=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=a[j][i])
			{
				c=1;
				break;
			}
		}
	}
	if( c == 0 ) 
		printf("Symmetric Asymmetric ");
	
}

void AntiSymmetric(int m,int a[7][7]) {//judging AntiSymmetric or not
	int i,j,c,b,d;
	c=0;
	d=0;
	b=0;
	d=1;

	if(c == 0) 
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j] = a[i+1][j+1])
				{
					c++;
				}
			}
		}
	if( c >= m ) 
		printf("Asymmetric ");

}

void MagicMatrix(int m,int a[7][7]) { //judging magicMatrix or not
	int old[m*m];
  	for(int i = 1;i<=m*m;i++){
  		old[i]=i;
    }
  	
  	int num = m*m;
  	for(int k=1;k<=m*m;k++){
    	for(int i = 0;i<m;i++){
          	for(int j=0;j<m;j++){
        		if(old[k]==a[i][j]){
            		num--;
            		old[k]=0;
            	}
            }
        }
    }
  	int totalnum1[m],totalnum2[m];
  	for(int i=0;i<m;i++){
    	totalnum1[i]=0;
    	totalnum2[i]=0;
    }
  	for(int i=0;i<m;i++){
    	for(int j=0;j<m;j++){
        	totalnum1[i]=totalnum1[i]+a[i][j];
        }
    }
  	for(int j=0;j<m;j++){
    	for(int i=0;i<m;i++){
        	totalnum2[i]=totalnum2[i]+a[i][j];
        }
    }
  	int total2=0;
  	for(int i=0;i<m;i++) {
    	if(totalnum1[i]==totalnum1[i+1] && totalnum2[i]==totalnum2[i+1]){
        	total2++;
        }
    }
	if(num==0 && total2==m-1){
    printf("MAGIC SQUARE");
    }
}

int main() {
	int a[7][7];
	int m; // columns == rows
	//so is square matrix
	
	scanf("%d",&m);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	
	Symmetry(m,a);
	AntiSymmetric(m,a);
	MagicMatrix(m,a);
	
}

