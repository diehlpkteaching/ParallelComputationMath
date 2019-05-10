
all: syllabus.pdf index.md

syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=xelatex -pdf syllabus.tex && cp syllabus.pdf ../webpage

index.md: webpage/index.md
	cd webpage && pandoc -s index.md --toc -c pandoc.css -o index.html


timetable.pdf: timetable/timtable.tex
	cd timetable && latexmk -pdflatex=xelatex -pdf timetable.tex && cp timetable.pdf ../webpage

clean:
	latexmk -CA
