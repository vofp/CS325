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
	gnuplot alg1plot.gp
	gnuplot alg2plot.gp
	gnuplot alg3plot.gp

dvi: plot 
#   run latex twice to get references correct
	latex maxSubarray.tex
#   you can also have a bibtex line here
#   bibtex $(TARGET).tex
	latex maxSubarray.tex

ps: dvi
	dvips -R -Poutline -t letter maxSubarray.dvi -o maxSubarray.ps

pdf: ps
	ps2pdf maxSubarray.ps

analysis: analysisAlg1 analysisAlg2 analysisAlg3
	mkdir analysis
	mv alg1.o alg2.o alg3.o analysis

test: testAlg1 testAlg2 testAlg3
	mkdir test
	mv alg1.o alg2.o alg3.o test
	cp mstest.txt francis_test.txt kevin_test.txt soo_hyun_test.txt test

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

cleanAll: clean
	rm maxSubarray.pdf -f
