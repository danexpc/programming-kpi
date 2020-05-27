#include <iostream>

struct AnalysisData
{
    int numbers = 0;
    int letters = 0;
    int chars = 0;
};
AnalysisData rowAnalysis(const std::string& row)
{
    AnalysisData data = AnalysisData();
    for (char c : row)
    {
        if (isalpha(c))
            data.letters += 1;
        else if (isdigit(c))
            data.numbers += 1;
        else
            data.chars += 1;
    }
    return data;
}

int main() {
    AnalysisData(*foo)(const std::string& row); 
    foo = rowAnalysis;
    auto data = foo("Hello world!");
    std::cout << data.numbers << " "
    << data.letters << " " << data.chars << std::endl;
    return 0;
}
