default: test analysis

testAlg1:
	g++ test.cpp alg1.cpp -o alg1.o

testAlg2:
	g++ test.cpp alg2.cpp -o alg2.o

testAlg3:
	g++ test.cpp alg3.cpp -o alg3.o

analysisAlg1:
	g++ analysis.cpp alg1.cpp -o alg1.o

analysisAlg2:
	g++ analysis.cpp alg2.cpp -o alg2.o

analysisAlg3:
	g++ analysis.cpp alg3.cpp -o alg3.o

plot:
	cd timingfiles; gnuplot alg1plot.gp; gnuplot alg2plot.gp; gnuplot alg3plot.gp; gnuplot alg1plotlog.gp; gnuplot alg2plotlog.gp; gnuplot alg3plotlog.gp;
pdf: plot cleanDev
	pdflatex maxSubarray.tex

analysis: analysisAlg1 analysisAlg2 analysisAlg3
	mv alg1.o alg2.o alg3.o analysis

test: testAlg1 testAlg2 testAlg3
	mv alg1.o alg2.o alg3.o test

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

