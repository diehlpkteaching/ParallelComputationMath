
all: syllabus.pdf index.md timetable.pdf lectures list.pdf

syllabus.pdf: syllabus/syllabus.tex
	cd syllabus && latexmk -pdflatex=lualatex -pdf syllabus.tex && cp syllabus.pdf ../webpage

index.md: webpage/index.md
	cd webpage && pandoc -s index.md --toc -c pandoc.css -o index.html

list.pdf: references/list.tex
	cd references && latexmk -pdflatex=lualatex -pdf list.tex && cp list.pdf ../webpage

timetable.pdf: timetable/timetable.tex timetable/content.csv
	cd timetable && latexmk -pdflatex=lualatex -pdf timetable.tex && cp timetable.pdf ../webpage

lectures=$(ls *.tex)

lectures: ${lectures}
		git submodule update --init --remote ParallelComputationMathExamples/
		@for f in $(shell ls *.tex); do name=$$(basename $${f} .tex); latexmk -pdflatex="lualatex --shell-escape %O %S" --jobname=$${name}-slides -pdf $${f};  done
		@for f in $(shell ls *.tex); do name=$$(basename $${f} .tex); latexmk -pdflatex="lualatex -shell-escape --synctex=1 %O '\def\classoption{12.pt,handout}\input{%S}'" --jobname=$${name}-handout -pdf $${f};  done
		find -maxdepth 1 -name "*.pdf" -exec cp "{}" webpage ";"

clean:
	rm *.bbl *.nav *.snm *.vrb *.out *.aux *.log *.toc *.blg
	latexmk -pdf -CA
