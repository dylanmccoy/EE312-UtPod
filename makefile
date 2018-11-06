UtPodDriver: UtPodDriver.o UtPod.o song.o
	g++ -o UtPodDriver UtPodDriver.o UtPod.o song.o
UtPodDriver.o: UtPodDriver.cpp UtPod.h song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c song.cpp
