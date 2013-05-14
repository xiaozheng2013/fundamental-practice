all:
	g++ dnso.cpp -o /tmp/dnso -lfftw3 -lm
	/tmp/dnso
fft:
	g++ fft.cpp -o /tmp/fft -lfftw3
	/tmp/fft
fft2:
	g++ fft2.cpp -o /tmp/fft2 -lfftw3
	/tmp/fft2





