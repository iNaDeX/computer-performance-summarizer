# Performance Statistics Summarizer. 

Program that summarizes the statistics from multiple samples collected using the <a href="https://github.com/iNaDeX/computer-performance-collector/">statistics collector</a>.

build: g++ -std=c++11 -o summarize main.cpp

run: ./summarize < samples.txt > summedUp.txt
