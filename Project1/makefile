default: test analysis

testAlg1:
	g++ test.cpp alg1.cpp -o alg1.o

testAlg2:
	g++ test.cpp alg2.cpp -o alg2.o

analysisAlg1:
	g++ analysis.cpp alg1.cpp -o alg1.o

analysisAlg2:
	g++ analysis.cpp alg2.cpp -o alg2.o

dvi: maxSubarray.tex 
	#gnuplot graph1
#   run latex twice to get references correct
	latex maxSubarray.tex
#   you can also have a bibtex line here
#   bibtex $(TARGET).tex
	latex maxSubarray.tex

ps: dvi
	dvips -R -Poutline -t letter maxSubarray.dvi -o maxSubarray.ps

pdf: ps
	ps2pdf maxSubarray.ps

analysis: analysisAlg1 analysisAlg2 
	mkdir analysis
	mv alg1.o alg2.o analysis

test: testAlg1 testAlg2
	mkdir test
	mv alg1.o alg2.o test


cleanDev:
	rm maxSubarray.aux -f
	rm maxSubarray.log -f
	rm maxSubarray.tex\~ -f
	rm maxSubarray.tex.backup -f
	rm maxSubarray.ps -f
	rm maxSubarray.dvi -f

clean: cleanDev
	rm *.o -f
	rm maxSubarray.pdf -f

cleanAll: clean
	rm -rf test
	rm -rf analysis
