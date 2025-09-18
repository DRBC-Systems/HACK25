#include <string>
struct IntSol {
    int sol1;
    int sol2=NULL;// If needed
};
namespace AI
{
class PromptGenerator{
public:
    enum class Prompt {EQ1, EQ2, SYS, PYTH};
private:
    Prompt problemType;

    std::string genEQ1();
    IntSol solEQ1();

    std::string genEQ2();
    IntSol solEQ2();

    std::string genSYS();
    IntSol solSYS();

    std::string genPYTH();
    IntSol solPYTH();
public:
    PromptGenerator(Prompt);
    IntSol sol(Prompt);
    std::string generate();

};
}