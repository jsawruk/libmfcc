/*
 * example.c - example of using libMFCC
 * Written 2010 - J. Sawruk
 */

#include <stdio.h>
#include <string.h> // For memset

#include "libmfcc.h"

int main(void)
{
	// Read in sample data from sample.dat
	// sample.dat contains an 8192-point spectrum from a sine wave at 440Hz (A) in double precision
	// Spectrum was computed using FFTW (http://www.fftw.org/)
	// Data was not windowed (rectangular)

	// Holds the spectrum data to be analyzed
	double spectrum[8192];

	// Pointer to the sample data file
	FILE *sampleFile;

	// Index counter - used to keep track of which data point is being read in
	int i = 0;

	// Determine which MFCC coefficient to compute
	unsigned int coeff;

	// Holds the value of the computed coefficient
	double mfcc_result;

	// Initialize the spectrum
	memset(&spectrum, 0, sizeof(spectrum)); 
	
	// Open the sample spectrum data	
	sampleFile = fopen("sample.dat","rb");
	
	// Read in the contents of the sample file
	while(fscanf(sampleFile, "%lf", &spectrum[i]) != EOF) // %lf tells fscanf to read a double
	{
		i++;
	}

	// Close the sample file
	fclose(sampleFile);

	// Compute the first 13 coefficients
	for(coeff = 0; coeff < 13; coeff++)
	{
		mfcc_result = GetCoefficient(spectrum, 44100, 48, 128, coeff);
		printf("%i %f\n", coeff, mfcc_result);
	}
	getchar();
	
	return 0;
}