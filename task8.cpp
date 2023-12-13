#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// ��������� ��� �������� ������ � ��������
struct Student {
    std::string fullName;
    int birthYear;
    std::string region;
    std::string phoneNumber;
};

// ��������� ��� ���� ��������� ������
struct TreeNode {
    Student data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Student& student) : data(student), left(nullptr), right(nullptr) {}
};

// ������� ��� ������� ���� � �������� ������ ������
TreeNode* insertIntoBST(TreeNode* root, const Student& student)
{
    if (!root)
    {
        return new TreeNode(student);
    }

    if (student.fullName < root->data.fullName)
    {
        root->left = insertIntoBST(root->left, student);
    }
    else
    {
        root->right = insertIntoBST(root->right, student);
    }

    return root;
}

// ������� ��� ���������� ����������������� ��������� ������
TreeNode* buildBalancedBST(const std::vector<Student>& students, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(students[mid]);

    root->left = buildBalancedBST(students, start, mid - 1);
    root->right = buildBalancedBST(students, mid + 1, end);

    return root;
}

// ������� ��� ������ ��������� ������
void printBST(TreeNode* root)
{
    if (root)
    {
        printBST(root->left);
        std::cout << root->data.fullName << " ";
        printBST(root->right);
    }
}

int main()
{
    // �������� ������� �������� ������� (�����)
    std::map<std::string, std::vector<Student>> groups;

    // ���������� ������ �� �����
    std::ifstream inputFile("students.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open the file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Student student;
        iss >> student.fullName >> student.birthYear >> student.region >> student.phoneNumber;

        // ��������� ����� ������ �� ��� (������ ������)
        std::string group = student.fullName.substr(0, 3);
        groups[group].push_back(student);
    }

    inputFile.close();

    // ���������� ��������� ������ ������ � ����������������� ��������� ������ �� ����� "�������"
    for (const auto& group : groups)
    {
        std::cout << "Group: " << group.first << "\n";

        // �������� ������ ������
        TreeNode* bstRoot = nullptr;
        for (const auto& student : group.second)
        {
            bstRoot = insertIntoBST(bstRoot, student);
        }
        std::cout << "BST: ";
        printBST(bstRoot);
        std::cout << "\n";

        // ���������������� �������� ������
        TreeNode* balancedBSTRoot = buildBalancedBST(group.second, 0, group.second.size() - 1);
        std::cout << "Balanced BST: ";
        printBST(balancedBSTRoot);
        std::cout << "\n\n";
    }

    return 0;
}
