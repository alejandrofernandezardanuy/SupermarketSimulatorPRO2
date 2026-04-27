OPCIONS=-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: Hora.o  Cliente.o ConjClientes.o Caja.o ConjCajas.o Tienda.o program.o
	g++ -o program.exe Hora.o Cliente.o ConjClientes.o Caja.o ConjCajas.o Tienda.o program.o

Hora.o: Hora.hh Hora.cc
	g++ -c Hora.cc $(OPCIONS)

Cliente.o: Cliente.hh Cliente.cc
	g++ -c Cliente.cc $(OPCIONS)	

ConjClientes.o: ConjClientes.hh ConjClientes.cc
	g++ -c ConjClientes.cc $(OPCIONS)	

Caja.o: Caja.hh Caja.cc
	g++ -c Caja.cc $(OPCIONS)
	

ConjCajas.o: ConjCajas.hh ConjCajas.cc
	g++ -c ConjCajas.cc $(OPCIONS)
	

Tienda.o: Tienda.hh Tienda.cc
	g++ -c Tienda.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

tar: Hora.hh Hora.cc Cliente.hh Cliente.cc ConjClientes.hh ConjClientes.cc Caja.hh Caja.cc ConjCajas.hh ConjCajas.cc Tienda.hh Tienda.cc program.cc Makefile
	tar -cvf practica.tar Hora.hh Hora.cc Cliente.hh Cliente.cc ConjClientes.hh ConjClientes.cc Caja.hh Caja.cc ConjCajas.hh ConjCajas.cc Tienda.hh Tienda.cc Makefile program.cc Htmlfinal.zip
clean:
	rm -f *.o *.exe 


