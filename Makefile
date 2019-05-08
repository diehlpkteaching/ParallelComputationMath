


syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=xelatex -pdf syllabus.tex 

clean:
	latexmk -CA
