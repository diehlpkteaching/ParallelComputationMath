
all: syllabus.pdf index.md

syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=xelatex -pdf syllabus.tex && cp syllabus.pdf ../webpage

index.md: webpage/index.md
	cd webpage && pandoc -s index.markdown --toc -c pandoc.css -o index.html



clean:
	latexmk -CA
