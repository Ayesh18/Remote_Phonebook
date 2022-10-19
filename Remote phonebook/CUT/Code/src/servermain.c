//program to define the server main function
/**********************************************************************************
	FILENAME: servermain.c
	DESCRIPTION:This file is used to define the server main function.
	DATE            NAME              REASON
	------------------------------------------------------------------
    14/10/2022      Username          
 
 * ********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int main()
{	
   	load();		        		//calling the function loadDAta of server
	ToCreateSocket();			//calling the function createSocket() of the server to create the socket
	ToBindSocket();				//calling the function bindSocket to bind the socket
	ToListen(); 				//calling the function Tolisten of the server 
	ToAcceptConnections() ;		//calling the acceptConnection of the server 
	return EXIT_SUCCESS;
}
