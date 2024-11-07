#include "BinaryTree.h"

int main() 
{
    setlocale(LC_ALL, "Russian");

    BinaryTree dictionary;

    dictionary.addWord("hello", "������", 5);
    dictionary.addWord("world", "���", 3);
    dictionary.addWord("apple", "������", 1);
    dictionary.addWord("banana", "�����", 2);

    dictionary.displayTranslation("hello");
    dictionary.replaceTranslation("world", "�����");
    dictionary.deleteWord("banana");

    dictionary.displayMostPopularWord();
    dictionary.displayLeastPopularWord();

    return 0;
}