
all: syllabus.pdf index.md timetable.pdf lectures list.pdf

syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=lualatex -pdf syllabus.tex && cp syllabus.pdf ../webpage

index.md: webpage/index.md
	cd webpage && pandoc -s index.md --toc -c pandoc.css -o index.html

list.pdf: references/list.tex
	cd references && latexmk -pdflatex=lualatex -pdf list.tex && cp list.pdf ../webpage

timetable.pdf: timetable/timetable.tex
	cd timetable && latexmk -pdflatex=lualatex -pdf timetable.tex && cp timetable.pdf ../webpage

lectures=$(ls *.tex)

lectures: ${lectures}
	find -maxdepth 1 -name "*.tex" -exec latexmk -pdflatex=lualatex -shell-escape -pdf "{}" ";"
	find -maxdepth 1 -name "*.gnuplot" -exec gnuplot "{}" ";"
	find -maxdepth 1 -name "*.tex" -exec latexmk -pdflatex=lualatex -shell-escape -pdf "{}" ";"
	find -maxdepth 1 -name "*.pdf" -exec cp "{}" webpage ";"



clean:
	latexmk -CA
