default: test analysis

testAlg4:
	g++ test.cpp alg4.cpp -o alg4.o

analysisAlg4:
	g++ analysis.cpp alg4.cpp -o alg4.o

plot:
	cd timingfiles; gnuplot alg4plot.gp; gnuplot alg4plotlog.gp; gnuplot algCompare.gp
pdf: plot cleanDev
	pdflatex maxSubarray.tex
	pdflatex maxSubarray.tex

analysis: analysisAlg4
	mv alg4.o analysis

test: testAlg4
	mv alg4.o test

cleanDev:
	rm maxSubarray.aux -f
	rm maxSubarray.log -f
	rm maxSubarray.tex\~ -f
	rm maxSubarray.tex.backup -f
	rm maxSubarray.ps -f
	rm maxSubarray.dvi -f

clean: cleanDev
	rm *.o -f
	rm analysis/*.o -f
	rm test/*.o -f
	rm timingfiles/*.png

