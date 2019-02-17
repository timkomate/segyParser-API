//
// Created by Mate Timko 2018.02.16
//

#ifndef SEGY_BINARYHEADER_H
#define SEGY_BINARYHEADER_H

//#include <iostream>

struct BinaryHeader{
    int jobID; //Job identification number.
    int lineNumber; //Line number. For 3-D poststack data, this will typically contain the in-line number.
    int reelNumber; //Reel number.
    short unsigned int tracesPerEnsemble; //Number of data traces per ensemble.
    short int aTracesPerEnsemble; //Number of auxiliary traces per ensemble.
    short unsigned int sampleInterval; //Sample interval in microseconds.
    short unsigned int sampleIntervalOriginalFieldRec; //Sample interval in microseconds of original field recording.
    short unsigned int samplesPerTrace; //Number of samples per data trace.
    short unsigned int samplesPerTraceOriginalFieldRec; //Number of samples per data trace for original field recording.
    unsigned short int dataSampleFormat; //Data sample format code.
    short int ensembleFold; //The expected number of data traces per trace ensemble
    short int traceSortingCode; //Trace sorting code (i.e. type of ensemble)
    short int verticalSumCode; //Vertical sum code:
    short int sweepFreqStart; //Sweep frequency at start (Hz).
    short int sweepFreqEnd; //Sweep frequency at end (Hz).
    short int sweepLength; //Sweep length (ms).
    short int sweepType; //Sweep type code: 
    short int sweepTraceNum; //Trace number of sweep channel.
    short int sweepTraceTaperStart; //Sweep trace taper length in milliseconds at start if tapered
    short int sweepTraceTaperEnd; //Sweep trace taper length in milliseconds at end
    short int taperType; //Taper type
    short int correlatedDataTraces; //Correlated data traces
    short int binaryGainRec; //Binary gain recovered:
    short int ampRecMethod; //Amplitude recovery method
    short int measurementSys; //Measurement system
    short int impulseSigPol; //Impulse signal polarity
    short int vibPolCode; //Vibratory polarity code
    char unassigned1 [240]; //Unassigned1
    short int revisionNumber; //SEG Y Format Revision Number
    short int fixedTraceFlag; //Fixed length trace flag.
    short int extendedTextFileHeaderNum; //Number of 3200-byte, Extended Textual File Header records following the Binary Header.
    char unassigned2 [94]; //Unassigned
};


#endif // SEGY_BINARYHEADER_H