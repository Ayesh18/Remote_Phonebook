/**********************************************************************************
	FILENAME: user.c
	DESCRIPTION:This file is used to define the user funtions.
	DATE            NAME              REASON
	------------------------------------------------------------------
    14/10/2022      Username          
 
 * ********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/ipc.h>
#include <user.h>
#include <stdbool.h>

char DIR[20]="../database/";
char AUTH[50]="../database/authentication.txt";

/****************************************************************************************************
**
** FUNCTION NAME  :  AuthenticatedAddData
** DESCRIPTION    :  This functions is used to function to add data to the database for authenticated users
**
**RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/

int AuthenticatedAddData(char * input1 ,char * input2,char * filename)
{
      FILE * fp;
      char path[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path,DIR);
      if(strcmp(fname,"")==0 || strcmp(fname,"public group")==0)
      {
      	return 0;
      }
      else
      {
      	strcat(path,fname);
      }
      strcat(path,".txt");
      fp=fopen(path,"a");
      if(fp==NULL)
      {
      	return 0;
      }
      else
      {
      	char nm[200]="",pno[200]="";
      	strcpy(nm,input1);
      	strcpy(pno,input2);
      	fputs(nm,fp);
      	fputs(",",fp);
      	fputs(pno,fp);
      	fputs("\n",fp);
      }
      fclose(fp);
      return 1;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  ToAddData
** DESCRIPTION    :  This functions is used to add data to the database for admin,anonymous users
**  RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int ToAddData(char * input1 ,char * input2,char * filename)
{
      FILE * fp;
      char path[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path,DIR);
      if(strcmp(fname,"")==0)
      {
      	strcat(path,"public group");
      }
      else
      {
      	strcat(path,filename);
      }
      strcat(path,".txt");
      fp=fopen(path,"a");
      if(fp==NULL)
      {
      	return 0;
      }
      else
      {
      	char nm[200]="",pno[200]="";
      	strcpy(nm,input1);
      	strcpy(pno,input2);
      	fputs(nm,fp);
      	fputs(",",fp);
      	fputs(pno,fp);
      	fputs("\n",fp);
      }
      fclose(fp);
      return 1;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  ToRemoveContact
** DESCRIPTION    :  This functions is used to aremove contact from the database
** RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int ToRemoveContact(char * input,char * filename)
{
      char nm[200]="";
      strcpy(nm,input);
      FILE * fp1,* fp2;
      char path1[1024]="";
      char path2[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path1,DIR);
      strcpy(path2,DIR);     
      strcat(path1,filename);
      strcat(path2,filename);
      strcat(path2,"_temp");
      strcat(path1,".txt");
      strcat(path2,".txt");
      fp1=fopen(path1,"r");
      fp2=fopen(path2,"w");
      if (fp1 == NULL || fp2 == NULL)
	  {
	  	strcpy(filename,"");
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
		char * tok = "";
		tok=strtok(temp,",");
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
	  remove(path1);
	  rename(path2,path1);
	  if(flag==0)
	  return 0;
	  return 1;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  AdminRemoveContact
** DESCRIPTION    :  This functions is used to remove contact from the database (admin)
**  RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int AdminRemoveContact(char * input,char * filename)
{
      char nm[200]="";
	  strcpy(nm,input);
	  FILE * fp1,* fp2;
      char path1[1024]="";
      char path2[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path1,DIR);
      strcpy(path2,DIR); 
      strcat(path1,filename);
      strcat(path2,filename);
      strcat(path2,"_temp");
      strcat(path1,".txt");
      strcat(path2,".txt");
      fp1=fopen(path1,"r");
      if(fp1==NULL)
      return 2;
      fp2=fopen(path2,"w");
      if (fp2 == NULL)
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
		char * tok = "";
		tok=strtok(temp,",");
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
	  remove(path1);
	  rename(path2,path1);
	  if(flag==0)
	  return 0;
	  return 1;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  ToChgrp
** DESCRIPTION    :  This functions is used to change the group
**
****************************************************************************************************/
void ToChgrp(char * filename,char *type)
{
        char grp[200]="";
        strcpy(grp,filename);
        int flag=0;
        if(strcmp(grp,"public group")==0)
        {
        	flag=1;
        }
        else
        {
		    FILE *fp;
			char * line="";
			int size = 1024;
			line = (char *)malloc(size);
			fp=fopen(AUTH,"r");
			if(fp!=NULL)
			{                                                                                		//checking whether the file is opened
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
    	} 
    	if(flag==0)
    	{
    		strcpy(filename,"no");
    	} 
}



/****************************************************************************************************
**
** FUNCTION NAME  :  ToAddGrp
** DESCRIPTION    :  This functions is used to add group to the directory
** RETURN        : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int ToAddGrp(char * filename)
{
	  FILE * fp;
      char path[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path,DIR);
      strcat(path,fname);
      strcat(path,".txt");
      fp=fopen(path,"w");
      if(fp==NULL)
      {
      	return 0;
      }
      fclose(fp);
      return 1;
}



/****************************************************************************************************
**
** FUNCTION NAME  :  ToRemoveGrp
** DESCRIPTION    :  This functions is used to remove group from the directory
**  RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int ToRemoveGrp(char * filename)
{
	  char path[1024]="";
      char fname[100]="";
      strcpy(fname,filename);
      strcpy(path,DIR);
      strcat(path,fname);
      strcat(path,".txt");
      if (remove(path) == 0)
      return 1;
      return 0;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  Tolistcontact
** DESCRIPTION    :  This functions is used to list contacts matching a pattern
**  RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int Tolistcontact(char * input, char * filename,char * concat)
{
	  char nm[200]="";
	  strcpy(nm,input);
	  FILE * fp1;
      char path1[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path1,DIR);
      if(strcmp(fname,"")==0)
      {
      	strcat(path1,"public group");
      }
      else
      {
      	strcat(path1,filename);
      }
      strcat(path1,".txt");
      fp1=fopen(path1,"r");
      if (fp1 == NULL)
	  {
		return 0;
	  }
	  char concat1[1024]="";
	  bool keep_reading = true;
	  do 
	  { 
	  	char buffer[1024];
		fgets(buffer, 1024, fp1);
		if (feof(fp1)) 
		keep_reading = false;
		else if (strncmp(buffer, nm,strlen(nm))== 0)
		  strcat(concat1,buffer);
	  } while (keep_reading);
	  fclose(fp1);
	  if(strlen(concat1)==0)
	  return 0;
	  strcpy(concat,"Matching contacts:\n");
	  strcat(concat,concat1);
	  return 1;
}


/****************************************************************************************************
**
** FUNCTION NAME  :  Adminlistcontact
** DESCRIPTION    :  This functions is used to list contacts matching a pattern for admin
**  RETURN          : Returns 1 if successful else returns 0
**
****************************************************************************************************/
int Adminlistcontact(char * input, char * filename,char * concat)
{
	  char nm[200]="";
	  strcpy(nm,input);
	  FILE * fp1;
      char path1[1024]="";
      char fname[200]="";
      strcpy(fname,filename);
      strcpy(path1,DIR);
      strcat(path1,filename);
      strcat(path1,".txt");
      fp1=fopen(path1,"r");
      if (fp1 == NULL)
	  {
		return 2;
	  }
	  char concat1[1024]="";
	  bool keep_reading = true;
	  do 
	  { 
	  	char buffer[1024];
		fgets(buffer, 1024, fp1);
		if (feof(fp1)) 
		keep_reading = false;
		else if (strncmp(buffer, nm,strlen(nm))== 0)
		  strcat(concat1,buffer);
	  } while (keep_reading);
	  fclose(fp1);
	  if(strlen(concat1)==0)
	  return 0;
	  strcpy(concat,"Matching contacts:\n");
	  strcat(concat,concat1);
	  return 1;
}



