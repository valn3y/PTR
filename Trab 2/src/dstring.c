/*
 * ADT Dynamic Strings
 * An ADT responsible to operate strings dynamically
 * Authors: Josias Cavalcante, Valney Junior 
 * Last edit: May, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include "dstring.h"

// ADT structure
struct dstring {
	char * dstr;
	size_t size;
};

// Dynamic string constructor/initializator
dstring dstring_new(const char * cstr){
	dstring s = calloc(1, sizeof(struct dstring));
	// Tratando um erro:
	if(s == NULL) return NULL;

	size_t len = strlen(cstr);
	s->size = len;
	s->dstr = calloc(len+1, sizeof(char));
	// Tratando um erro:
	if(s->dstr == NULL) return NULL;
	strcpy(s->dstr, cstr);

	return s;
	//char * meubuffer
};

// Set allocated memory free
void dstring_free(dstring s){
	if(s != NULL){
		free(s->dstr);
		free(s);
	}
};

// Get base string (char*)
char* dstring_base(dstring s){
	return s->dstr;
};

// Get dynamic string size
size_t dstring_len(dstring s){
	if(s==NULL) return 0;
	return s->size;
};

// Concatenate two dynamic strings
dstring dstring_concat(const dstring s1, const dstring s2){
	dstring s = calloc(1, sizeof(struct dstring));
	if(s == NULL) return NULL;

	s->size = s1->size + s2->size;
	s->dstr = calloc(s->size + 1, sizeof(char));

	if(s->dstr == NULL) return NULL;

	strcat(s->dstr, s1->dstr);
	strcat(s->dstr, s2->dstr);

	return s;
}

// Concatenate mutiples dynamic strings
dstring dstring_multiconcat(const dstring s1, ...){
	dstring ds1 = s1;
	dstring s = NULL;
	va_list va;
	va_start(va, s1);
	dstring ds2 = va_arg(va, dstring);
	if(ds2 == NULL){
		va_end(va);
		return ds1;
	}

	s = calloc(1, sizeof(struct dstring));
	if(s == NULL) return NULL;
	s->dstr = NULL;
	
	while(ds2 != NULL){
		s->size = ds1->size + ds2->size;
		s->dstr = realloc(s->dstr, (s->size + 1) * sizeof(char) );

		if(s->dstr == NULL) return NULL;

		strcpy(s->dstr, ds1->dstr);
		strcat(s->dstr, ds2->dstr);
		ds1 = s;
		ds2 = va_arg(va, dstring);

	}

	va_end(va);
	return s;
}

// Create a dynamic string from an integer
dstring dstring_newInt(int i){
	dstring s = calloc(1, sizeof(struct dstring));
	// Tratando um erro:
	if(s == NULL) return NULL;

	// Start conversion int -> char*
	char* res;
    if (i >= 0) res = malloc(floor(log10(i)) + 2);
    else res = malloc(floor(log10(i)) + 3);

	// Tratando um erro:
	if(res == NULL) return NULL;
	sprintf(res, "%d", i);

	size_t len = strlen(res);
	s->size = len;
	s->dstr = calloc(len+1, sizeof(char));
	// Tratando um erro:
	if(s->dstr == NULL) return NULL;
	strcpy(s->dstr, res);

	free(res);

	return s;
}

// Create a dynamic string from a float
dstring dstring_newFloat(float f, int lf){
	if(lf < 0) return NULL;
	if(lf == 0) return dstring_newInt((int) f);
	
	int inteira = f;
	int decimal = (int) ((f-inteira) * pow(10,lf));

	dstring final = dstring_multiconcat(
		dstring_newInt(inteira), 
		dstring_new("."),
		dstring_newInt(decimal),
		NULL
	);

	return final;
}

// Create a dynamic string from a double
dstring dstring_newDouble(double d, int ld){
	if(ld < 0) return NULL;
	if(ld == 0) return dstring_newInt((int) d);
	
	int inteira = d;
	int decimal = (int) ((d-inteira) * pow(10,ld));

	dstring final = dstring_multiconcat(
		dstring_newInt(inteira), 
		dstring_new("."),
		dstring_newInt(decimal),
		NULL
	);

	return final;
}
