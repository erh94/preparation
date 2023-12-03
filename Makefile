# MY_VAR=$(shell python -c 'import sys; print(int(sys.version_info >= (2,5)))')
BASE=$(shell basename ${INPUT} '.cpp')
compile:
	g++ -s ${INPUT} -o ${BASE}.out 2>&1 | tee compile.log

run:
	./${BASE}.out

clean:
	rm -rf *.out
	rm -rf *.log
# hemu
# 7-11-2021