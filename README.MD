build: g++ -std=c++11 -o summarize main.cpp

run: ./summarize < samples.txt > summedUp.txt