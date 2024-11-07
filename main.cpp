#include "BinaryTree.h"

int main() 
{
    setlocale(LC_ALL, "Russian");

    BinaryTree dictionary;

    dictionary.addWord("hello", "привет", 5);
    dictionary.addWord("world", "мир", 3);
    dictionary.addWord("apple", "€блоко", 1);
    dictionary.addWord("banana", "банан", 2);

    dictionary.displayTranslation("hello");
    dictionary.replaceTranslation("world", "земл€");
    dictionary.deleteWord("banana");

    dictionary.displayMostPopularWord();
    dictionary.displayLeastPopularWord();

    return 0;
}