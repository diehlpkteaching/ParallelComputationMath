


syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=xelatex -pdf syllabus.tex 

index.md: webpage/index.md
	cd webpage && pandoc -s index.md --toc -o index.html



clean:
	latexmk -CA
