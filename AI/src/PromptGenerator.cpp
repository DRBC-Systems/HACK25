#include <PromptGenerator.h>

namespace AI
{

// Constructor
PromptGenerator::PromptGenerator() {}

// Private generators
std::string PromptGenerator::genEQ1() {
    int a,b;
    return " Solve this equation: ";
}

std::string PromptGenerator::genEQ2() {
    int a,b,c;

    return " Solve this equation: ";
}

std::string PromptGenerator::genSYS() {
    int x1,x2,y1,y2,z1,z2;
    return " Solve this system: ";
}

std::string PromptGenerator::genPYTH() {
    int a,b;
    return " Find the hypotenuse of this triangle: ";
}

// Public generate method
std::string PromptGenerator::generate(Prompt title) {

    switch (title)
    {
    case Prompt::EQ1:
        return genEQ1();
        break;
    
    default:
        break;
    }

    return "BAB";
}

} // namespace AI