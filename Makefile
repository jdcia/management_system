all:
	#g++ -c ./lib/<sample_cpp>

	#create main file after all object files are made.
	g++ -g -Wall ./cpp_files/main.cpp *.o -o main

clean:
	rm main *.o