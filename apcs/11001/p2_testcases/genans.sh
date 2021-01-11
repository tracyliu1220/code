#! /bin/bash

gen="$1"
sol="$2"

g++ $gen -o gen
g++ $sol -o sol

for i in $(seq -f "%02g" 0 3)
do
	echo $i
	./gen 1 testcases/$i
	./sol < testcases/$i.in > testcases/$i.ans
	sleep 2
done
for i in $(seq -f "%02g" 4 9)
do
	echo $i
	./gen 2 testcases/$i
	./sol < testcases/$i.in > testcases/$i.ans
	sleep 2
done
for i in $(seq -f "%02g" 10 19)
do
	echo $i
	./gen 3 testcases/$i
	./sol < testcases/$i.in > testcases/$i.ans
	sleep 2
done
rm gen
rm sol
