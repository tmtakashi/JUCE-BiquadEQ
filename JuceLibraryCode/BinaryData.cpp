/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== README.md ==================
static const unsigned char temp_binary_data_0[] =
"# BiquadFilter\n"
"\n"
"A C++ implementation of [Audio EQ Cookbook](https://www.w3.org/2011/audio/audio-eq-cookbook.html).\n"
"\n"
"## Usage\n"
"\n"
"```cpp\n"
"#include \"Biquad.h\"\n"
"#include <cmath> // not required\n"
"\n"
"double fs = 44100; // sample rate\n"
"double f0 = 1000; // center (cutoff) frequency\n"
"double Q = 1 / std::sqrt(2);\n"
"// dbGain parameter is required in Peaking, LowShelf, HighShelf\n"
"double dBGain = 0.0;\n"
"\n"
"Parameters params = {FilterType::LowPass, fs, f0, Q, dBGain};\n"
"\n"
"Biquad filter;\n"
"filter.setParams(params);\n"
"\n"
"// calculate output sample in processing loop\n"
"for (int i = 0; i < numSample; i++) \n"
"    double sample = filter.process(buffer[i])\n"
"```\n";

const char* README_md = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x64791dc8:  numBytes = 621; return README_md;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "README_md"
};

const char* originalFilenames[] =
{
    "README.md"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
