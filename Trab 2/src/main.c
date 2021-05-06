/*
 * Testing ADT Dynamic Strings
 * Authors: Josias Cavalcante, Valney Junior 
 * Last edit: May, 2021
*/

#include "dstring.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
	// Create a dynamic string made by a multiple concatenation of dynamic strings.
	//dstring sint = dstring_newInt(54321);

	dstring sres = dstring_multiconcat( 
		N$("Greetings, "), 
		N$("Mr. "), 
		N$("Foo! "), 
		Nf$(4.56789f, 4), 
		Ni$(13),
		N$(" "), 
		Nd$(123.4567890, 5), 
		NULL 
	);

	if(sres != NULL) {
		printf("Mensagem: %s\n", $(sres));
		printf("Tamanho: %lu\n", L$(sres));
		dstring_free(sres);
	}



}


