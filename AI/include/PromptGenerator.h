#include <string>

#ifndef PROMPT_H
#define PROMPT_H

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

    /**
     * @brief Creates a first order equation e.g. aX + b = c.
     * 
     * @return std::string
     */
    std::string genEQ1();
    /**
     * @brief Creates a second order equation e.g. aX^2 + bX + c = 0.
     * 
     * @return std::string
     */
    std::string genEQ2();
    /**
     * @brief Creates a system of 2X2 equations.
     * 
     * @return std::string
     */
    std::string genSYS();
    /**
     * @brief Creates a pythagorean triangle e.g. A, B, C, right angle: A.
     * 
     * @return std::string
     */
    std::string genPYTH();
public:
    PromptGenerator();    
    std::string generate(Prompt);

};
}
#endif