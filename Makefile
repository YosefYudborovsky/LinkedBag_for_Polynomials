all:
	g++ TestLinkedPolynomial.cpp Node.cpp LinkedPolynomial.cpp -o TestLinkedPolynomial

clean:
	rm *.o
	rm TestLinkedPolynomial