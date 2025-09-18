#include <string>

namespace AI
{
class PromptGenerator{
public:
    enum class Prompt {EQ1, EQ2, SYS, PYTH};
private:
    Prompt problemType;

    std::string genEQ1();
    int solEQ1();

    std::string genEQ2();
    int solEQ2();

    std::string genSYS();
    int solSYS();
    
    std::string genPYTH();
    int solPYTH();
public:
    PromptGenerator(Prompt);
    int sol(Prompt);
    std::string generate();

};
}