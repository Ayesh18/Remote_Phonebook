/********************************************************************************************
**     FILENAME      :      func.h
**
**    DESCRIPTION    :      This file contains functions used for unit testing.
*****************************************************************************************/
char link[200] = "/home/kali/Desktop/cunit/db/";
#define SUCCESS 1
#define FAILURE 0
int removecontact(char * input, char * filename)
{
	  char nm[200]="";
	  strcpy(nm,input);
	  FILE * fp1,* fp2;
      char path1[1024]="";
      char path2[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path1,link);
      strcpy(path2,link);     
      strcat(path1,filename);
      //strcat(path2,"temp");
      strcat(path2,filename);
      strcat(path2,"_temp");
      strcat(path1,".txt");
      strcat(path2,".txt");
      fp1=fopen(path1,"r");
      fp2=fopen(path2,"w");
      if (fp1 == NULL || fp2 == NULL)
	  {
		return 0;
	  }
	  int flag=0;
	  bool keep_reading = true;
	  do 
	  { 
	  	char buffer[1024]="";
		fgets(buffer, 1024, fp1);
		char temp[1024]="";
		strcpy(temp,buffer);
		//char comp[1024]="";
		char * tok = "";
		tok=strtok(temp,",");
		//strcpy(comp,temp);
		if (feof(fp1)) 
		keep_reading = false;
		else if (strcmp(tok, nm)!= 0)
		  fputs(buffer, fp2);
		else
		{
			flag=1;
		}
	  } while (keep_reading);
	  fclose(fp1);
	  fclose(fp2);
	  //char p[1024]="";
	  //strcpy(p,path1);
	  remove(path1);
	  rename(path2,path1);
	  if(flag==0)
	  return FAILURE;
	  return SUCCESS;
}


int ToChgrp(char * type,char *filename)
{
        char grp[200]="";
        strcpy(grp,filename);	
        FILE *fp;
    	char * line="";
    	int size = 1024,flag=0;
    	line = (char *)malloc(size);
    	char path1[1024]="";
        strcpy(path1,link);    
        strcat(path1,"authentication.txt");
    	fp=fopen(path1,"r");
    	if(fp!=NULL)
    	{                                                                               
         	while(fgets(line,size,fp))
         	{
         		char t[1024]="";
         		strcpy(t,line);
         		t[strlen(t)-1]='\0';
         		char *tok="";
         		tok=strtok(t,":");
         		if(strcmp(tok,type)==0)
         		{
		     		tok=strtok(NULL,":");
		     		tok=strtok(NULL,":");
		     		while(tok!=NULL)
		     		{
		     			if(strcmp(tok,grp)==0)
		     			{
		     				flag=1;
		     				break;
		     			}
		     			tok=strtok(NULL,":");
		     		}
		     		break;
		     	}
         	}
    	}
    	fclose(fp);
    	free(line);
    	if(flag==0)
    	return FAILURE;
    	return SUCCESS;
}
