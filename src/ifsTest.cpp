#include <iostream>
#include <fstream>

struct segyHeader{
    int jobID; //Job identification number.
    int lineNumber;
    int reelNumber;
    short unsigned int dataTracesPerEnsemble;
    short int auxilariTracesPerEnsemble;
    short unsigned int sampleInterval; //in microsec
    short unsigned int  sampleIntervalOriginalFieldRec;
    short unsigned int samplesPerTrace;
    short unsigned int samplesPerTraceOriginalFieldRec;
    unsigned short int dataSampleFormat;
    short int ensenbleFold;
    short int traceSortingCode;
    short int verticalSumCode;
    short int sweepFreqStart;
    short int sweepFreqEnd;
    short int sweepLength; //ms
    short int sweepType;
    short int sweepTraceSweep;
    short int sweepTraceTaperLen;
    short int sweepTraceTaperLen2;
    short int taperType;
    short int correlatedDataTraces;
    short int binaryGainRec;
    short int ampRecMethod;
    short int measurementSys;
    short int impulseSigPol;
    short int signnalLag;
    char unknown [240];
    short int revisionNumber;
    short int fixedTraceFlag;
    short int extendedTextFileHeaderNum;
    char unassigned[94];
};

struct traceHeader{
    /*int traceSeqNumInLine;
    int traceSeqNumInSEGY;
    int originalFieldRecordNum;
    int traceNumOrigin;
    int sourcePointNum;
    int ensembleNum;
    int traceNumInEnsemble;*/
    char ph[240];
};

template <typename T>
T SwapEnd(T var)
{
    char* varArray = reinterpret_cast<char*>(&var);
    for(long i = 0; i < static_cast<long>(sizeof(var)/2); i++){
        std::swap(varArray[sizeof(var) - 1 - i],varArray[i]);
    }
    return var;
}

int main(int argc, char** argv){
    std::ifstream ifs;
    char bb[3200];
    char buffer[400];
    segyHeader sh;

    std::cout << "bb char size: " << sizeof(bb) << std::endl;
    std::cout << "segyH char size: " << sizeof(sh) << std::endl;



    ifs.open(argv[1], std::ifstream::in | std::ifstream::binary);

    ifs.read (bb,sizeof(bb));
    //ifs.read (buffer,sizeof(sh));

    ifs.read(reinterpret_cast<char *>(&sh), sizeof(sh));
    std::cout << sh.sampleInterval << std::endl;

    std::cout << "JobID: " << sh.jobID << "\n"
    << "Line number: " << sh.lineNumber << "\n"
    << "reel number: " << sh.reelNumber <<  "\n"
    << "auxilariTracesPerEnsemble: " <<  sh.auxilariTracesPerEnsemble << "\n"
    << "dataTracesPerEnsemble: " << SwapEnd(sh.dataTracesPerEnsemble) << "\n"
    << "sample interval: " << SwapEnd(sh.sampleInterval) << "\n"
    << "sample interval2: " <<sh.sampleIntervalOriginalFieldRec << "\n"
    << "sample per trace: " << SwapEnd(sh.samplesPerTrace) << "\n"
    << "sample per trace2: " << sh.samplesPerTraceOriginalFieldRec << "\n"
    << "data sample format: " << SwapEnd(sh.dataSampleFormat) << "\n"
    << "ensenbleFold: " << sh.ensenbleFold << "\n"
    << "trace sorting code: " << sh.traceSortingCode << "\n"
    << "vertical sum: " << sh.verticalSumCode << '\n'
    << "sweep freq: " << sh.sweepFreqStart << "\n"
    << "sweep freq2: " << sh.sweepFreqEnd << "\n"
    << "sweep len: " << sh.sweepLength << "\n"
    << "sweep type: " << sh.sweepType << "\n"
    << "sweep trace sweep: " << sh.sweepTraceSweep << "\n"
    << "sweep taper len: " << sh.sweepTraceTaperLen << "\n"
    << "sweep taper len: " << sh.sweepTraceTaperLen2 << "\n"
    << "taper type: " << sh.taperType << "\n"
    << "correlated data traces: " << sh.correlatedDataTraces << "\n"
    << "binary gain rec: " << sh.binaryGainRec << "\n"
    << "amp rec method: " << sh.ampRecMethod << "\n"
    << "measurement system: " << sh.measurementSys << "\n"
    << "impulse signal polarity: " << sh.impulseSigPol << "\n"
    << "signal lag: " << sh.signnalLag << '\n'
    <<  "unknown: " << sh.unknown << "\n"
    << "revision number: " << sh.revisionNumber << '\n'
    << "fixed trace flag: " << sh.fixedTraceFlag << "\n"
    << "extended text file header number: " << sh.extendedTextFileHeaderNum << "\n"
    << std::endl;


    ifs.close();
    return 0;
}
