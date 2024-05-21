#include "../func/func.hpp"

int main()
{
    try{
    std::ifstream file("src/files/text.txt");
    checkFile(file);
    std::string line;
    std::string text;
    while(std::getline(file,line))
    {
        toLower(line);
        text += line + " ";
    }
    
    std::vector<std::string> words = splitIntoWords(text);
    std::map<std::string, int32_t> wordCount;

    for (const std::string &word : words)
    {
        wordCount[word]++;
    }

    std::cout << "\nСписок всех слов:\n";
    for (const std::string &word : words)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::cout << "\nКоличество вхождений каждого слова:\n";
    for (const auto &pair : wordCount)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    }

    catch(std::runtime_error e)
    {
        std::cerr << e.what() << '\n';
    }
}