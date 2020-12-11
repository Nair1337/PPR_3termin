/****
	Przyklad pliku RPCGEN
	Odczytanie z serwera biezacego czasu.
****/

/***********************************************************************
	Wywolanie procedury odleglej dopuszcza maksymalnie jeden
	argument wywolania i jeden zwracany wynik.
	Oba musza byc podane w formie wskaznikow

	Dlatego nalezy definiowac odpowiednie struktury
***********************************************************************/
struct print_data {
	char buffer[1024];
	int size;
}; 

/* definicja programu i jego wersji */
program TEST {
	version VERSION {
			/* definicja procedury nr 1 */
			int PROCEDURE( print_data ) = 1;	
	} = 1;			/* nr wersji */	
} = 0x21000000;		/* nr programu */	
	
