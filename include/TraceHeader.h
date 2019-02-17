#ifndef SEGY_TRACEHEADER_H
#define SEGY_TRACEHEADER_H

//#include <iostream>

struct TraceHeader{
    int traceSeqNum; //Trace sequence number within line
    int traceSeqNumInSEGY; //Trace sequence number within SEG Y file
    int fieldRecordNum; //Original field record number
    int traceNum; //Trace number within the original field record
    int sourcePointNum; //Energy source point number
    int ensembleNum; //Ensemble number
    int traceNumInEnsemble; //Trace number within the ensemble
    short int traceCode; //Trace identification code:
    short int verticallySumTraces; //Number of vertically summed traces yielding this trace.
    short int horizontallySumTraces; //Number of horizontally summed traces yielding this trace.
    short int dataUse; //Data use:
    int distanceFromCentre; //Distance from center of the source point to the center of the receiver group
    int receiverGroupElev; //Receiver group elevation
    int sourceElev; //Surface elevation at source
    int sourceDepth; //Source depth below surface (a positive number)
    int datumElevationGroup; //Datum elevation at receiver group.
    int datumElevationSource; //Datum elevation at source.
    int waterDepthSource; //Water depth at source.
    int waterDepthGroup; //Water depth at group;
    short int elevScalar; //Scalar to be applied to all elevations and depths specified in Trace Header
    short int coordScalar; //Scalar to be applied to all coordinates specified in Trace Header
    int sourceCoordX; //Source coordinate - X.
    int sourceCoordY; //Source coordinate - Y.
    int groupCoordX; //Group coordinate - X.
    int groupCoordY; //Group coordinate - Y.
    short int coordUnits; //Coordinate units
    short int weatheringVel; //Weathering velocity
    short int subWeatheringVel; //SubWeathering velocity.
    short int upholeTimeSource; //Uphole time at source in milliseconds.
    short int upholeTimeGroup; //Uphole time at group in milliseconds.
    short int sourceStaticCorr; //Source static correction in milliseconds.
    short int groupStaticCorr; //Group static correction in milliseconds.
    short int staticApplied; //Total static applied in milliseconds.
    short int lagTimeA; //Lag time A — Time in milliseconds between end of 240-byte trace identification header and time break.
    short int lagTimeB; //Lag Time B — Time in milliseconds between time break and the initiation time of the energy source.
    short int delayRecTime; /*Time in milliseconds between
    initiation time of energy source and the time when recording
    of data samples begins.*/
    short int muteTimeStart; //Mute time - Start time in milliseconds.
    short int muteTimeEnd; //Mute time — End time in milliseconds.
    short int samplePerTrace; //Number of samples in this trace
    short int sampleInterval; //Sample interval in microseconds
    short int gainType; //Gain type of field instruments
    short int instrumentGain; //Instrument gain constant (dB)
    short int instrumentInitGain; //Instrument early or initial gain
    short int isCorrelated; //Correlated 1-yes 2-no
    short int sweepFreqStart; //Sweep frequency at start (Hz)
    short int sweepFreqEnd; //Sweep frequency at end (Hz)
    short int sweepLen; //Sweep length in milliseconds
    short int sweepType; //Sweep type
    short int taperLenStart; //Sweep trace taper length at start in milliseconds.
    short int taperLenEnd; //Sweep trace taper length at end in milliseconds.
    short int taperType; //Taper type
    short int aliasFilterFreq; //Alias filter frequency (Hz), if used.
    short int aliasFilterSlope; //Alias filter slope (dB/octave).
    short int notchFilterFreq; //Notch filter frequency (Hz), if used.
    short int notchFilterSlope; //Notch filter slope (dB/octave).
    short int lowCutFreq; //Low-cut frequency (Hz), if used.
    short int highCutFreq; //High-cut frequency (Hz), if used.
    short int lowCutSlope; //Low-cut slope (dB/octave)
    short int highCutSlope; //High-cut slope (dB/octave)
    short int year; //Year data recorded
    short int dayOfYear; //Day of year (Julian day for GMT and UTC time basis).
    short int hour; //Hour of day (24 hour clock).
    short int minute; // Minute of hour
    short int second; //Second of minute.
    short int timeBasisCode; //Time basis code:
    short int traceWFactor; //Trace weighting factor
    short int geophoneGroupNum; //Geophone group number of roll switch position one.
    short int geophoneGroupNumOF; //Geophone group number of trace number one within original field record.
    short int geophoneGroupNumLT; //Geophone group number of last trace within original field record.
    short int gapSize; //Gap size (total number of groups dropped).
    short int overTravel; //Over travel associated with taper at beginning or end of line:
    int ensembleCoordX; //X coordinate of ensemble (CDP) position of this trace
    int ensembleCoordY; //Y coordinate of ensemble (CDP) position of this trace
    int inlineNumber; //For 3-D poststack data, this field should be used for the in-line number.
    int crosslineNumber; //For 3-D poststack data, this field should be used for the cross-line number.
    int shotpointNumber; //Shotpoint number — This is probably only applicable to 2-D poststack data.
    short int shotpointNumberScalar; //Scalar to be applied to the shotpoint number
    short int traceValueMeasurementUnit; //Trace value measurement unit:
    int transductionConstant; //Transduction Constant
    short int transductionUnit; //Transduction Unit
    short int traceIdentifier; //Device/Trace Identifier The unit number or id number of the device
    short int timeScalar; //Scalar to be applied to times specified
    short int sourceTypeOrientation; //Source Type/Orientation
    char sourceEnergyDir[6]; //Source Energy Direction with respect to the source orientation???
    char sourceMeasurement[6]; //Source Measurement
    short int sourceMeasurementUnit; //Source Measurement Unit
    char unassigned[8];
};


#endif // SEGY_TRACEHEADER_H