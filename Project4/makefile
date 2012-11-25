default: code

tex:
	pdflatex tsp.tex
	pdflatex tsp.tex

code:
	g++ main.cpp input.cpp output.cpp types.cpp alg1.cpp optimize.cpp common.cpp -o tsp.o

clean:
	rm -rf tsp.o
	rm -rf tsp.aux tsp.log tsp.pdf

