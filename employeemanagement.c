#include<stdio.h>
#include<string.h>

struct employee{
	int ID;
	char name[20];
	int salary;
}e1,temp;

int main()
{
	FILE *fp,*fp2,*fp3,*fp4,*fp5;
	int i,ch=0,max,j,id,sal;
	char ch2,N[20];
   do
   {
	
	printf("choose one of the following operations:\n");
	printf("1.write in the existing file\n");
	printf("2.read the file\n");
	printf("3.find the maximum salary among all the employees\n");
	printf("4.edit the employee details\n");
	printf("5.delete employee data\n");
	printf("6.sort in d-order\n");
	printf("6.exit the program\n");
	printf("choose an option:\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:{
	           fp=fopen("employee.txt","a");
	           	printf("enter details of the employees:");
	            
		         printf("ID:");
		         scanf("%d",&e1.ID);
		         printf("Name:");
		         scanf("%s",e1.name);
		         printf("Salary:");
		         scanf("%d",&e1.salary);
		         fwrite (&e1, sizeof(struct employee), 1, fp); 
	
	            if(fp==NULL)
	            {
		         printf("error\n");
	            }
	            else
	            {
		         printf("completed\n");
	            }
	            fclose(fp);}
	            break;
	     case 2: {
	              fp=fopen("employee.txt","r");
	              while(fread(&e1, sizeof(struct employee), 1, fp)==1)
	              {
				   
	               printf ("id = %d,name = %s,salary=%d\n",e1.ID,e1.name, e1.salary);
			    
                  }
                 
                 fclose(fp);
                 break;
                }
         case 3: {
         	      i=0;
	             fp=fopen("employee.txt","r");
	             while(fread(&e1, sizeof(struct employee), 1, fp)==1)
	             {
	             	
	             	if(i==0)
	             	{
	             	 
	             	 max=e1.salary;
	                }
	                else{
	                	if(e1.salary>max)
	                	max=e1.salary;
				        }i++;
				 }
				
				 fclose(fp);
				 fp2=fopen("employee.txt","r");
				 printf("details:\n");
				 while(fread(&e1, sizeof(struct employee), 1, fp2)==1)
	             {
				  if(e1.salary==max)		 		
				  printf ("id = %d,name =%s,salary=%d\n",e1.ID,e1.name, e1.salary);
				 }
			
				 fclose(fp2);
				 break;

			    }
	    case 4:{
	    	printf("enter the ID of the employee whose details are to be edited");
	    	scanf("%d",&id);
	    	fp3=fopen("employee.txt","r");
	    	while(fread(&e1, sizeof(struct employee), 1, fp3)==1)
	    	{
	    		
	    		if(id==e1.ID)
	    		{
	    			
	    			printf("enter new name:");
	    			scanf("%s",N);
	    			printf("enter new salary:");
	    			scanf("%d",sal);
	    			strcpy(e1.name,N);
	    			e1.salary=sal;
                    printf("details are successfully edited");
                    fwrite(&e1, sizeof(struct employee), 1, fp3);
				}
			}
			fclose(fp3);
	    	
			break;
		}
		case 5:{
			printf("enter the id of the employee whose data is to be deleted");
			scanf("%d",&id);
			fp5=fopen("employee.txt","r");
			fp4=fopen("employee2.txt","w");
			while(fread(&e1, sizeof(struct employee), 1, fp5)==1)
			{
				if(e1.ID!=id)
				{
					fwrite(&e1, sizeof(struct employee), 1, fp4);
				}
			   }
			fclose(fp5);
			fclose(fp4);
			printf("%d",fclose(fp4));
			//rename("employee2.txt","employee.txt");		
			break;
		}      
/*case 6:{
	    	
	    	fp=fopen("employee.dat","r");
	    	fp2=fopen("employee2.dat","w");
			 while(!feof(fp))
			 {
			 	fread(&e1,sizeof(struct employee),1,fp);
			 	
			 }
			  
			   
	    	fclose(fp);
			break;
		}*/
	    case 6:{
	    	//exit(1);
			break;
		}
	
	    
	default:printf("invalid option");      
	}
			fflush(stdin);
			printf("want to continue?(y/n)\f");
			scanf("%c",&ch2);
      }while(ch2=='Y'||ch2=='y');	
	
}

