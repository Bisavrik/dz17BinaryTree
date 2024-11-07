#include "BinaryTree.h"

TreeNode::TreeNode(const char* word, const char* translation, int access_count)
    : access_count(access_count), left(nullptr), right(nullptr)
{
    strcpy(this->word, word);
    strcpy(this->translation, translation);
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() 
{
    clear(root);
}

void BinaryTree::clear(TreeNode* node) 
{
    if (node) 
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

TreeNode* BinaryTree::addNode(TreeNode* node, const char* word, const char* translation, int access_count) 
{
    if (!node) return new TreeNode(word, translation, access_count);
    if (strcmp(word, node->word) < 0) node->left = addNode(node->left, word, translation, access_count);
    else if (strcmp(word, node->word) > 0) node->right = addNode(node->right, word, translation, access_count);
    return node;
}

void BinaryTree::addWord(const char* word, const char* translation, int access_count)
{
    root = addNode(root, word, translation, access_count);
}

TreeNode* BinaryTree::findNode(TreeNode* node, const char* word) 
{
    if (!node || strcmp(word, node->word) == 0) return node;
    if (strcmp(word, node->word) < 0) return findNode(node->left, word);
    return findNode(node->right, word);
}

void BinaryTree::displayTranslation(const char* word)
{
    TreeNode* node = findNode(root, word);
    if (node) 
    {
        node->access_count++;
        cout << "������� ����� \"" << node->word << "\": " << node->translation << endl;
    }
    else
    {
        cout << "����� \"" << word << "\" �� ������� � �������." << endl;
    }
}

void BinaryTree::replaceTranslation(const char* word, const char* new_translation)
{
    TreeNode* node = findNode(root, word);
    if (node) 
    {
        strcpy(node->translation, new_translation);
        cout << "������� ����� \"" << word << "\" ������ �� \"" << new_translation << "\"." << endl;
    }
    else
    {
        cout << "����� \"" << word << "\" �� ������� � �������." << endl;
    }
}

TreeNode* BinaryTree::deleteNode(TreeNode* node, const char* word)
{
    if (!node) return node;
    if (strcmp(word, node->word) < 0) node->left = deleteNode(node->left, word);
    else if (strcmp(word, node->word) > 0) node->right = deleteNode(node->right, word);
    else 
    {
        if (!node->left) 
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) 
        {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* temp = node->right;
        while (temp->left) temp = temp->left;
        strcpy(node->word, temp->word);
        strcpy(node->translation, temp->translation);
        node->access_count = temp->access_count;
        node->right = deleteNode(node->right, temp->word);
    }
    return node;
}

void BinaryTree::deleteWord(const char* word)
{
    root = deleteNode(root, word);
    cout << "����� \"" << word << "\" ������� �� �������." << endl;
}

TreeNode* BinaryTree::findMostPopular(TreeNode* node, TreeNode*& most_popular) 
{
    if (!node) return most_popular;
    if (!most_popular || node->access_count > most_popular->access_count) most_popular = node;
    findMostPopular(node->left, most_popular);
    findMostPopular(node->right, most_popular);
    return most_popular;
}

void BinaryTree::displayMostPopularWord()
{
    TreeNode* most_popular = nullptr;
    most_popular = findMostPopular(root, most_popular);
    if (most_popular) 
    {
        cout << "����� ���������� �����: \"" << most_popular->word << "\" � ��������� \"" << most_popular->translation << "\" (���������: " << most_popular->access_count << ")" << endl;
    }
}

TreeNode* BinaryTree::findLeastPopular(TreeNode* node, TreeNode*& least_popular) 
{
    if (!node) return least_popular;
    if (!least_popular || node->access_count < least_popular->access_count) least_popular = node;
    findLeastPopular(node->left, least_popular);
    findLeastPopular(node->right, least_popular);
    return least_popular;
}

void BinaryTree::displayLeastPopularWord() 
{
    TreeNode* least_popular = nullptr;
    least_popular = findLeastPopular(root, least_popular);
    if (least_popular)
    {
        cout << "����� ������������ �����: \"" << least_popular->word << "\" � ��������� \"" << least_popular->translation << "\" (���������: " << least_popular->access_count << ")" << endl;
    }
}