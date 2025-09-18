#include <string>

namespace AI
{
class PromptGenerator{
public:
    enum class Prompt {EQ1, EQ2, SYS, PYTH};
private:
    Prompt problemType;

    std::string genEQ1();
    std::string genEQ2();
    std::string genSYS();
    std::string genPYTH();
public:
    PromptGenerator(Prompt);

    std::string generate();

};
}