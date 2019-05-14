
all: syllabus.pdf index.md timetable.pdf lectures

syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=xelatex -pdf syllabus.tex && cp syllabus.pdf ../webpage

index.md: webpage/index.md
	cd webpage && pandoc -s index.md --toc -c pandoc.css -o index.html


timetable.pdf: timetable/timetable.tex
	cd timetable && latexmk -pdflatex=xelatex -pdf timetable.tex && cp timetable.pdf ../webpage

lectures=$(ls *.tex)

lectures: ${lectures}
	find -maxdepth 1 -name "*.tex" -exec latexmk -pdflatex=xelatex -pdf "{}" ";"
	find -maxdepth 1 -name "*.pdf" -exec cp "{}" webpage ";"



clean:
	latexmk -CA
