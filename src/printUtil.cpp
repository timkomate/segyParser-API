#include "../include/Segy.h"
#include <iomanip> 

void Segy::printInfo(){
    int w = 40;
    std::cout << std::left << std::setw(w) << "filename: " << fileName << std::endl;
    std::cout << std::left << std::setw(w) << "filesize: " << fileSize << " B" << std::endl;
    std::cout << std::left << std::setw(w) << "number of traces: " << traceHeaders.size() << std::endl;
    std::cout << std::left << std::setw(w) << "size of a binaryHeader: " << sizeof(binaryHeader) << std::endl;
}

void Segy::printBinaryHeader(){
    int w = 70;
    std::cout << "Binary header:" << std::endl
    << std::left << std::setw(w) << "JobID:" << std::fixed << SwapEnd(binaryHeader.jobID) << std::endl
    << std::left << std::setw(w) << "Line number:" << std::fixed << SwapEnd(binaryHeader.lineNumber) << std::endl
    << std::left << std::setw(w) << "Reel number:" << std::fixed << SwapEnd(binaryHeader.reelNumber) <<  std::endl
    << std::left << std::setw(w) << "Number of data traces per ensemble:" << std::fixed << SwapEnd(binaryHeader.tracesPerEnsemble) << std::endl
    << std::left << std::setw(w) << "Number of auxiliary traces per ensemble:" << std::fixed << SwapEnd(binaryHeader.aTracesPerEnsemble) << std::endl
    << std::left << std::setw(w) << "Sample interval in microseconds:" << std::fixed << SwapEnd(binaryHeader.sampleInterval) << std::endl
    << std::left << std::setw(w) << "Sample interval in microseconds of original field recording:" << std::fixed << SwapEnd(binaryHeader.sampleIntervalOriginalFieldRec) << std::endl
    << std::left << std::setw(w) << "Number of samples per data trace:" << std::fixed << SwapEnd(binaryHeader.samplesPerTrace) << std::endl
    << std::left << std::setw(w) << "Number of samples per data trace for original field recording:" << std::fixed << SwapEnd(binaryHeader.samplesPerTraceOriginalFieldRec) << std::endl
    << std::left << std::setw(w) << "Data sample format code:" << std::fixed << SwapEnd(binaryHeader.dataSampleFormat) << std::endl
    << std::left << std::setw(w) << "The expected number of data traces per trace ensemble:" << std::fixed << SwapEnd(binaryHeader.ensembleFold) << std::endl
    << std::left << std::setw(w) << "Trace sorting code (i.e. type of ensemble):" << std::fixed << SwapEnd(binaryHeader.traceSortingCode) << std::endl
    << std::left << std::setw(w) << "Vertical sum code:" << std::fixed << SwapEnd(binaryHeader.verticalSumCode) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at start (Hz):" << std::fixed << SwapEnd(binaryHeader.sweepFreqStart) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at end (Hz):" << std::fixed << SwapEnd(binaryHeader.sweepFreqEnd) << std::endl
    << std::left << std::setw(w) << "Sweep length (ms):" << std::fixed << SwapEnd(binaryHeader.sweepLength) << std::endl
    << std::left << std::setw(w) << "Sweep type code:" << std::fixed << SwapEnd(binaryHeader.sweepType) << std::endl
    << std::left << std::setw(w) << "Trace number of sweep channel:" << std::fixed << SwapEnd(binaryHeader.sweepTraceNum) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length in milliseconds at start if tapered:" << std::fixed << SwapEnd(binaryHeader.sweepTraceTaperStart) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length in milliseconds at end:" << std::fixed << SwapEnd(binaryHeader.sweepTraceTaperEnd) << std::endl
    << std::left << std::setw(w) << "Taper type:" << std::fixed << SwapEnd(binaryHeader.taperType) << std::endl
    << std::left << std::setw(w) << "Correlated data traces:" << std::fixed << SwapEnd(binaryHeader.correlatedDataTraces) << std::endl
    << std::left << std::setw(w) << "Binary gain recovered:" << std::fixed << SwapEnd(binaryHeader.binaryGainRec) << std::endl
    << std::left << std::setw(w) << "Amplitude recovery method:" << std::fixed << SwapEnd(binaryHeader.ampRecMethod) << std::endl
    << std::left << std::setw(w) << "Measurement system:" << std::fixed << SwapEnd(binaryHeader.measurementSys) << std::endl
    << std::left << std::setw(w) << "Impulse signal polarity:" << std::fixed << SwapEnd(binaryHeader.impulseSigPol) << std::endl
    << std::left << std::setw(w) << "Vibratory polarity code:" << std::fixed << SwapEnd(binaryHeader.impulseSigPol) << std::endl
    << std::left << std::setw(w) << "SEG Y Format Revision Number:" << std::fixed << SwapEnd(binaryHeader.revisionNumber) << std::endl
    << std::left << std::setw(w) << "Fixed length trace flag:" << std::fixed << SwapEnd(binaryHeader.fixedTraceFlag) << std::endl
    << std::left << std::setw(w) << "Extended Textual File Header records following the Binary Header:" << std::fixed << SwapEnd(binaryHeader.extendedTextFileHeaderNum) << std::endl
    << std::endl;
}

void Segy::printTraceHeader(unsigned int i){
    TraceHeader tmpTH = traceHeaders.at(i);
    int w = 70;
    std::cout << "Trace header:" << std::endl
    << std::left << std::setw(w) << "Trace sequence number within line:" << std::fixed << SwapEnd(tmpTH.traceSeqNum) << std::endl
    << std::left << std::setw(w) << "Trace sequence number within SEG Y file:" << std::fixed << SwapEnd(tmpTH.traceSeqNumInSEGY) << std::endl
    << std::left << std::setw(w) << "Original field record number:" << std::fixed << SwapEnd(tmpTH.fieldRecordNum) <<  std::endl
    << std::left << std::setw(w) << "Trace number within the original field record:" << std::fixed << SwapEnd(tmpTH.traceNum) << std::endl
    << std::left << std::setw(w) << "Energy source point number:" << std::fixed << SwapEnd(tmpTH.sourcePointNum) << std::endl
    << std::left << std::setw(w) << "Ensemble number:" << std::fixed << SwapEnd(tmpTH.ensembleNum) << std::endl
    << std::left << std::setw(w) << "Trace number within the ensemble:" << std::fixed << SwapEnd(tmpTH.traceNumInEnsemble) << std::endl
    << std::left << std::setw(w) << "Trace identification code:Eddig OK:" << std::fixed << SwapEnd(tmpTH.traceCode) << std::endl
    << std::left << std::setw(w) << "Number of vertically summed traces yielding this trace:" << std::fixed << SwapEnd(tmpTH.verticallySumTraces) << std::endl
    << std::left << std::setw(w) << "Number of horizontally summed traces yielding this trace:" << std::fixed << SwapEnd(tmpTH.horizontallySumTraces) << std::endl
    << std::left << std::setw(w) << "Data use:" << std::fixed << SwapEnd(tmpTH.dataUse) << std::endl
    << std::left << std::setw(w) << "Distance from center of the source point to the receiver group:" << std::fixed << SwapEnd(tmpTH.distanceFromCentre) << std::endl
    << std::left << std::setw(w) << "Receiver group elevation:" << std::fixed << SwapEnd(tmpTH.receiverGroupElev) << std::endl
    << std::left << std::setw(w) << "Surface elevation at source:" << std::fixed << SwapEnd(tmpTH.sourceElev) << std::endl
    << std::left << std::setw(w) << "Source depth below surface (a positive number):" << std::fixed << SwapEnd(tmpTH.sourceDepth) << std::endl
    << std::left << std::setw(w) << "Datum elevation at receiver group:" << std::fixed << SwapEnd(tmpTH.datumElevationGroup) << std::endl
    << std::left << std::setw(w) << "Datum elevation at source." << std::fixed << SwapEnd(tmpTH.datumElevationSource) << std::endl
    << std::left << std::setw(w) << "Water depth at source:" << std::fixed << SwapEnd(tmpTH.waterDepthSource) << std::endl
    << std::left << std::setw(w) << "Water depth at group:" << std::fixed << SwapEnd(tmpTH.waterDepthGroup) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to all elevations and depths:" << std::fixed << SwapEnd(tmpTH.elevScalar) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to all coordinates:" << std::fixed << SwapEnd(tmpTH.coordScalar) << std::endl
    << std::left << std::setw(w) << "Source coordinate - X:" << std::fixed << SwapEnd(tmpTH.sourceCoordX) << std::endl
    << std::left << std::setw(w) << "Source coordinate - Y:" << std::fixed << SwapEnd(tmpTH.sourceCoordY) << std::endl
    << std::left << std::setw(w) << "Group coordinate - X:" << std::fixed << SwapEnd(tmpTH.groupCoordX) << std::endl
    << std::left << std::setw(w) << "Group coordinate - Y:" << std::fixed << SwapEnd(tmpTH.groupCoordY) << std::endl
    << std::left << std::setw(w) << "Coordinate units:" << std::fixed << SwapEnd(tmpTH.coordUnits) << std::endl
    << std::left << std::setw(w) << "Vibratory polarity code:" << std::fixed << SwapEnd(tmpTH.weatheringVel) << std::endl
    << std::left << std::setw(w) << "SEG Y Format Revision Number:" << std::fixed << SwapEnd(tmpTH.subWeatheringVel) << std::endl
    << std::left << std::setw(w) << "Weathering velocity:" << std::fixed << SwapEnd(tmpTH.upholeTimeSource) << std::endl
    << std::left << std::setw(w) << "SubWeathering velocityEddigOK:" << std::fixed << SwapEnd(tmpTH.upholeTimeGroup) << std::endl
    << std::left << std::setw(w) << "Uphole time at source in milliseconds:" << std::fixed << SwapEnd(tmpTH.upholeTimeSource) << std::endl
    << std::left << std::setw(w) << "Uphole time at group in milliseconds:" << std::fixed << SwapEnd(tmpTH.upholeTimeGroup) << std::endl
    << std::left << std::setw(w) << "Source static correction in milliseconds:" << std::fixed << SwapEnd(tmpTH.sourceStaticCorr) <<  std::endl
    << std::left << std::setw(w) << "Group static correction in milliseconds:" << std::fixed << SwapEnd(tmpTH.groupStaticCorr) << std::endl
    << std::left << std::setw(w) << "Total static applied in milliseconds:" << std::fixed << SwapEnd(tmpTH.staticApplied) << std::endl
    << std::left << std::setw(w) << "Lag time A - Time in milliseconds:" << std::fixed << SwapEnd(tmpTH.lagTimeA) << std::endl
    << std::left << std::setw(w) << "Lag Time B - Time in milliseconds:" << std::fixed << SwapEnd(tmpTH.lagTimeB) << std::endl
    << std::left << std::setw(w) << "Time in milliseconds between initiation time of energy source:" << std::fixed << SwapEnd(tmpTH.delayRecTime) << std::endl
    << std::left << std::setw(w) << "Mute time - Start time in milliseconds.:" << std::fixed << SwapEnd(tmpTH.muteTimeStart) << std::endl
    << std::left << std::setw(w) << "Mute time - End time in milliseconds:" << std::fixed << SwapEnd(tmpTH.muteTimeEnd) << std::endl
    << std::left << std::setw(w) << "Number of samples in this trace:" << std::fixed << SwapEnd(tmpTH.samplePerTrace) << std::endl
    << std::left << std::setw(w) << "Sample interval in microseconds:" << std::fixed << SwapEnd(tmpTH.sampleInterval) << std::endl
    << std::left << std::setw(w) << "Gain type of field instruments:" << std::fixed << SwapEnd(tmpTH.gainType) << std::endl
    << std::left << std::setw(w) << "Instrument gain constant (dB):" << std::fixed << SwapEnd(tmpTH.instrumentGain) << std::endl
    << std::left << std::setw(w) << "Instrument early or initial gain:" << std::fixed << SwapEnd(tmpTH.instrumentInitGain) << std::endl
    << std::left << std::setw(w) << "Correlated 1-yes 2-no:" << std::fixed << SwapEnd(tmpTH.isCorrelated) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at start (Hz):" << std::fixed << SwapEnd(tmpTH.sweepFreqStart) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at end (Hz):" << std::fixed << SwapEnd(tmpTH.sweepFreqEnd) << std::endl
    << std::left << std::setw(w) << "Sweep length in milliseconds:" << std::fixed << SwapEnd(tmpTH.sweepLen) << std::endl
    << std::left << std::setw(w) << "Sweep type:" << std::fixed << SwapEnd(tmpTH.sweepType) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length at start in milliseconds:" << std::fixed << SwapEnd(tmpTH.taperLenStart) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length at end in milliseconds:" << std::fixed << SwapEnd(tmpTH.taperLenEnd) << std::endl
    << std::left << std::setw(w) << "Taper type:" << std::fixed << SwapEnd(tmpTH.taperType) << std::endl
    << std::left << std::setw(w) << "Alias filter frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.aliasFilterFreq) << std::endl
    << std::left << std::setw(w) << "Alias filter slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.aliasFilterSlope) << std::endl
    << std::left << std::setw(w) << "Notch filter frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.notchFilterFreq) << std::endl
    << std::left << std::setw(w) << "Notch filter slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.notchFilterSlope) << std::endl
    << std::left << std::setw(w) << "Low-cut frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.lowCutFreq) << std::endl
    << std::left << std::setw(w) << "High-cut frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.highCutFreq) << std::endl
    << std::left << std::setw(w) << "Low-cut slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.lowCutSlope) << std::endl
    << std::left << std::setw(w) << "High-cut slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.highCutSlope) << std::endl
    << std::left << std::setw(w) << "Year data recorded:" << std::fixed << SwapEnd(tmpTH.year) << std::endl
    << std::left << std::setw(w) << "Day of year (Julian day for GMT and UTC time basis):" << std::fixed << SwapEnd(tmpTH.dayOfYear) << std::endl
    << std::left << std::setw(w) << "Hour of day (24 hour clock):" << std::fixed << SwapEnd(tmpTH.hour) << std::endl
    << std::left << std::setw(w) << "Minute of hour:" << std::fixed << SwapEnd(tmpTH.minute) << std::endl
    << std::left << std::setw(w) << "Second of minute:" << std::fixed << SwapEnd(tmpTH.second) << std::endl
    << std::left << std::setw(w) << "Time basis code:" << std::fixed << SwapEnd(tmpTH.timeBasisCode) << std::endl
    << std::left << std::setw(w) << "Trace weighting factor:" << std::fixed << SwapEnd(tmpTH.traceWFactor) << std::endl
    << std::left << std::setw(w) << "Geophone group number of roll switch position one:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNum) << std::endl
    << std::left << std::setw(w) << "Geophone group number of trace number:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNumOF) << std::endl
    << std::left << std::setw(w) << "Geophone group number of last trace:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNumLT) << std::endl
    << std::left << std::setw(w) << "Gap size (total number of groups dropped):" << std::fixed << SwapEnd(tmpTH.gapSize) <<  std::endl
    << std::left << std::setw(w) << "Over travel associated with taper:" << std::fixed << SwapEnd(tmpTH.overTravel) << std::endl
    << std::left << std::setw(w) << "X coordinate of ensemble (CDP) position of this trace:" << std::fixed << SwapEnd(tmpTH.ensembleCoordX) << std::endl
    << std::left << std::setw(w) << "Y coordinate of ensemble (CDP) position of this trace:" << std::fixed << SwapEnd(tmpTH.ensembleCoordY) << std::endl
    << std::left << std::setw(w) << "For 3-D poststack data used for the in-line number:" << std::fixed << SwapEnd(tmpTH.inlineNumber) << std::endl
    << std::left << std::setw(w) << "For 3-D poststack data used for the cross-line number:" << std::fixed << SwapEnd(tmpTH.crosslineNumber) << std::endl
    << std::left << std::setw(w) << "Shotpoint number:" << std::fixed << SwapEnd(tmpTH.shotpointNumber) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to the shotpoint number:" << std::fixed << SwapEnd(tmpTH.shotpointNumberScalar) << std::endl
    << std::left << std::setw(w) << "Trace value measurement unit:" << std::fixed << SwapEnd(tmpTH.traceValueMeasurementUnit) << std::endl
    << std::left << std::setw(w) << "Transduction Constant:" << std::fixed << SwapEnd(tmpTH.transductionConstant) << std::endl
    << std::left << std::setw(w) << "Transduction Unit:" << std::fixed << SwapEnd(tmpTH.transductionUnit) << std::endl
    << std::left << std::setw(w) << "Device/Trace Identifier:" << std::fixed << SwapEnd(tmpTH.traceIdentifier) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to times specified:" << std::fixed << SwapEnd(tmpTH.timeScalar) << std::endl
    << std::left << std::setw(w) << "Source Type/Orientation:" << std::fixed << SwapEnd(tmpTH.sourceTypeOrientation) << std::endl
    << std::left << std::setw(w) << "Source Measurement Unit:" << std::fixed << SwapEnd(tmpTH.sourceMeasurementUnit) << std::endl
    << std::endl;
}

void Segy::printTraceHeader(){
    TraceHeader tmpTH = traceHeaders.back();
    int w = 70;
    std::cout << "Trace header:" << std::endl
    << std::left << std::setw(w) << "Trace sequence number within line:" << std::fixed << SwapEnd(tmpTH.traceSeqNum) << std::endl
    << std::left << std::setw(w) << "Trace sequence number within SEG Y file:" << std::fixed << SwapEnd(tmpTH.traceSeqNumInSEGY) << std::endl
    << std::left << std::setw(w) << "Original field record number:" << std::fixed << SwapEnd(tmpTH.fieldRecordNum) <<  std::endl
    << std::left << std::setw(w) << "Trace number within the original field record:" << std::fixed << SwapEnd(tmpTH.traceNum) << std::endl
    << std::left << std::setw(w) << "Energy source point number:" << std::fixed << SwapEnd(tmpTH.sourcePointNum) << std::endl
    << std::left << std::setw(w) << "Ensemble number:" << std::fixed << SwapEnd(tmpTH.ensembleNum) << std::endl
    << std::left << std::setw(w) << "Trace number within the ensemble:" << std::fixed << SwapEnd(tmpTH.traceNumInEnsemble) << std::endl
    << std::left << std::setw(w) << "Trace identification code:Eddig OK:" << std::fixed << SwapEnd(tmpTH.traceCode) << std::endl
    << std::left << std::setw(w) << "Number of vertically summed traces yielding this trace:" << std::fixed << SwapEnd(tmpTH.verticallySumTraces) << std::endl
    << std::left << std::setw(w) << "Number of horizontally summed traces yielding this trace:" << std::fixed << SwapEnd(tmpTH.horizontallySumTraces) << std::endl
    << std::left << std::setw(w) << "Data use:" << std::fixed << SwapEnd(tmpTH.dataUse) << std::endl
    << std::left << std::setw(w) << "Distance from center of the source point to the receiver group:" << std::fixed << SwapEnd(tmpTH.distanceFromCentre) << std::endl
    << std::left << std::setw(w) << "Receiver group elevation:" << std::fixed << SwapEnd(tmpTH.receiverGroupElev) << std::endl
    << std::left << std::setw(w) << "Surface elevation at source:" << std::fixed << SwapEnd(tmpTH.sourceElev) << std::endl
    << std::left << std::setw(w) << "Source depth below surface (a positive number):" << std::fixed << SwapEnd(tmpTH.sourceDepth) << std::endl
    << std::left << std::setw(w) << "Datum elevation at receiver group:" << std::fixed << SwapEnd(tmpTH.datumElevationGroup) << std::endl
    << std::left << std::setw(w) << "Datum elevation at source." << std::fixed << SwapEnd(tmpTH.datumElevationSource) << std::endl
    << std::left << std::setw(w) << "Water depth at source:" << std::fixed << SwapEnd(tmpTH.waterDepthSource) << std::endl
    << std::left << std::setw(w) << "Water depth at group:" << std::fixed << SwapEnd(tmpTH.waterDepthGroup) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to all elevations and depths:" << std::fixed << SwapEnd(tmpTH.elevScalar) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to all coordinates:" << std::fixed << SwapEnd(tmpTH.coordScalar) << std::endl
    << std::left << std::setw(w) << "Source coordinate - X:" << std::fixed << SwapEnd(tmpTH.sourceCoordX) << std::endl
    << std::left << std::setw(w) << "Source coordinate - Y:" << std::fixed << SwapEnd(tmpTH.sourceCoordY) << std::endl
    << std::left << std::setw(w) << "Group coordinate - X:" << std::fixed << SwapEnd(tmpTH.groupCoordX) << std::endl
    << std::left << std::setw(w) << "Group coordinate - Y:" << std::fixed << SwapEnd(tmpTH.groupCoordY) << std::endl
    << std::left << std::setw(w) << "Coordinate units:" << std::fixed << SwapEnd(tmpTH.coordUnits) << std::endl
    << std::left << std::setw(w) << "Vibratory polarity code:" << std::fixed << SwapEnd(tmpTH.weatheringVel) << std::endl
    << std::left << std::setw(w) << "SEG Y Format Revision Number:" << std::fixed << SwapEnd(tmpTH.subWeatheringVel) << std::endl
    << std::left << std::setw(w) << "Weathering velocity:" << std::fixed << SwapEnd(tmpTH.upholeTimeSource) << std::endl
    << std::left << std::setw(w) << "SubWeathering velocityEddigOK:" << std::fixed << SwapEnd(tmpTH.upholeTimeGroup) << std::endl
    << std::left << std::setw(w) << "Uphole time at source in milliseconds:" << std::fixed << SwapEnd(tmpTH.upholeTimeSource) << std::endl
    << std::left << std::setw(w) << "Uphole time at group in milliseconds:" << std::fixed << SwapEnd(tmpTH.upholeTimeGroup) << std::endl
    << std::left << std::setw(w) << "Source static correction in milliseconds:" << std::fixed << SwapEnd(tmpTH.sourceStaticCorr) <<  std::endl
    << std::left << std::setw(w) << "Group static correction in milliseconds:" << std::fixed << SwapEnd(tmpTH.groupStaticCorr) << std::endl
    << std::left << std::setw(w) << "Total static applied in milliseconds:" << std::fixed << SwapEnd(tmpTH.staticApplied) << std::endl
    << std::left << std::setw(w) << "Lag time A - Time in milliseconds:" << std::fixed << SwapEnd(tmpTH.lagTimeA) << std::endl
    << std::left << std::setw(w) << "Lag Time B - Time in milliseconds:" << std::fixed << SwapEnd(tmpTH.lagTimeB) << std::endl
    << std::left << std::setw(w) << "Time in milliseconds between initiation time of energy source:" << std::fixed << SwapEnd(tmpTH.delayRecTime) << std::endl
    << std::left << std::setw(w) << "Mute time - Start time in milliseconds.:" << std::fixed << SwapEnd(tmpTH.muteTimeStart) << std::endl
    << std::left << std::setw(w) << "Mute time - End time in milliseconds:" << std::fixed << SwapEnd(tmpTH.muteTimeEnd) << std::endl
    << std::left << std::setw(w) << "Number of samples in this trace:" << std::fixed << SwapEnd(tmpTH.samplePerTrace) << std::endl
    << std::left << std::setw(w) << "Sample interval in microseconds:" << std::fixed << SwapEnd(tmpTH.sampleInterval) << std::endl
    << std::left << std::setw(w) << "Gain type of field instruments:" << std::fixed << SwapEnd(tmpTH.gainType) << std::endl
    << std::left << std::setw(w) << "Instrument gain constant (dB):" << std::fixed << SwapEnd(tmpTH.instrumentGain) << std::endl
    << std::left << std::setw(w) << "Instrument early or initial gain:" << std::fixed << SwapEnd(tmpTH.instrumentInitGain) << std::endl
    << std::left << std::setw(w) << "Correlated 1-yes 2-no:" << std::fixed << SwapEnd(tmpTH.isCorrelated) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at start (Hz):" << std::fixed << SwapEnd(tmpTH.sweepFreqStart) << std::endl
    << std::left << std::setw(w) << "Sweep frequency at end (Hz):" << std::fixed << SwapEnd(tmpTH.sweepFreqEnd) << std::endl
    << std::left << std::setw(w) << "Sweep length in milliseconds:" << std::fixed << SwapEnd(tmpTH.sweepLen) << std::endl
    << std::left << std::setw(w) << "Sweep type:" << std::fixed << SwapEnd(tmpTH.sweepType) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length at start in milliseconds:" << std::fixed << SwapEnd(tmpTH.taperLenStart) << std::endl
    << std::left << std::setw(w) << "Sweep trace taper length at end in milliseconds:" << std::fixed << SwapEnd(tmpTH.taperLenEnd) << std::endl
    << std::left << std::setw(w) << "Taper type:" << std::fixed << SwapEnd(tmpTH.taperType) << std::endl
    << std::left << std::setw(w) << "Alias filter frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.aliasFilterFreq) << std::endl
    << std::left << std::setw(w) << "Alias filter slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.aliasFilterSlope) << std::endl
    << std::left << std::setw(w) << "Notch filter frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.notchFilterFreq) << std::endl
    << std::left << std::setw(w) << "Notch filter slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.notchFilterSlope) << std::endl
    << std::left << std::setw(w) << "Low-cut frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.lowCutFreq) << std::endl
    << std::left << std::setw(w) << "High-cut frequency (Hz), if used:" << std::fixed << SwapEnd(tmpTH.highCutFreq) << std::endl
    << std::left << std::setw(w) << "Low-cut slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.lowCutSlope) << std::endl
    << std::left << std::setw(w) << "High-cut slope (dB/octave):" << std::fixed << SwapEnd(tmpTH.highCutSlope) << std::endl
    << std::left << std::setw(w) << "Year data recorded:" << std::fixed << SwapEnd(tmpTH.year) << std::endl
    << std::left << std::setw(w) << "Day of year (Julian day for GMT and UTC time basis):" << std::fixed << SwapEnd(tmpTH.dayOfYear) << std::endl
    << std::left << std::setw(w) << "Hour of day (24 hour clock):" << std::fixed << SwapEnd(tmpTH.hour) << std::endl
    << std::left << std::setw(w) << "Minute of hour:" << std::fixed << SwapEnd(tmpTH.minute) << std::endl
    << std::left << std::setw(w) << "Second of minute:" << std::fixed << SwapEnd(tmpTH.second) << std::endl
    << std::left << std::setw(w) << "Time basis code:" << std::fixed << SwapEnd(tmpTH.timeBasisCode) << std::endl
    << std::left << std::setw(w) << "Trace weighting factor:" << std::fixed << SwapEnd(tmpTH.traceWFactor) << std::endl
    << std::left << std::setw(w) << "Geophone group number of roll switch position one:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNum) << std::endl
    << std::left << std::setw(w) << "Geophone group number of trace number:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNumOF) << std::endl
    << std::left << std::setw(w) << "Geophone group number of last trace:" << std::fixed << SwapEnd(tmpTH.geophoneGroupNumLT) << std::endl
    << std::left << std::setw(w) << "Gap size (total number of groups dropped):" << std::fixed << SwapEnd(tmpTH.gapSize) <<  std::endl
    << std::left << std::setw(w) << "Over travel associated with taper:" << std::fixed << SwapEnd(tmpTH.overTravel) << std::endl
    << std::left << std::setw(w) << "X coordinate of ensemble (CDP) position of this trace:" << std::fixed << SwapEnd(tmpTH.ensembleCoordX) << std::endl
    << std::left << std::setw(w) << "Y coordinate of ensemble (CDP) position of this trace:" << std::fixed << SwapEnd(tmpTH.ensembleCoordY) << std::endl
    << std::left << std::setw(w) << "For 3-D poststack data used for the in-line number:" << std::fixed << SwapEnd(tmpTH.inlineNumber) << std::endl
    << std::left << std::setw(w) << "For 3-D poststack data used for the cross-line number:" << std::fixed << SwapEnd(tmpTH.crosslineNumber) << std::endl
    << std::left << std::setw(w) << "Shotpoint number:" << std::fixed << SwapEnd(tmpTH.shotpointNumber) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to the shotpoint number:" << std::fixed << SwapEnd(tmpTH.shotpointNumberScalar) << std::endl
    << std::left << std::setw(w) << "Trace value measurement unit:" << std::fixed << SwapEnd(tmpTH.traceValueMeasurementUnit) << std::endl
    << std::left << std::setw(w) << "Transduction Constant:" << std::fixed << SwapEnd(tmpTH.transductionConstant) << std::endl
    << std::left << std::setw(w) << "Transduction Unit:" << std::fixed << SwapEnd(tmpTH.transductionUnit) << std::endl
    << std::left << std::setw(w) << "Device/Trace Identifier:" << std::fixed << SwapEnd(tmpTH.traceIdentifier) << std::endl
    << std::left << std::setw(w) << "Scalar to be applied to times specified:" << std::fixed << SwapEnd(tmpTH.timeScalar) << std::endl
    << std::left << std::setw(w) << "Source Type/Orientation:" << std::fixed << SwapEnd(tmpTH.sourceTypeOrientation) << std::endl
    << std::left << std::setw(w) << "Source Measurement Unit:" << std::fixed << SwapEnd(tmpTH.sourceMeasurementUnit) << std::endl
    << std::endl;
}