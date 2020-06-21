all:
	#g++ -c ./lib/<sample_cpp>

	g++ -c ./lib/database.cpp 
	#create main file after all object files are made.
	g++ -g -Wall ./main.cpp *.o -o main -lsqlite3 


clean:
	rm main *.o