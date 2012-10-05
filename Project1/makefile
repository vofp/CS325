default: alg1 alg2 pdf release

alg1:
	g++ test.cpp alg1.cpp -o alg1.o

alg2:
	g++ test.cpp alg2.cpp -o alg2.o

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

release: cleanDev
	mkdir release
	mv *.o *.pdf release

cleanDev:
	rm maxSubarray.aux -f
	rm maxSubarray.log -f
	rm maxSubarray.tex\~ -f
	rm maxSubarray.tex.backup -f
	rm maxSubarray.ps
	rm maxSubarray.dvi

clean: cleanDev
	rm *.o -f
	rm maxSubarray.pdf -f

cleanAll: clean
	rm -rf release