#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // �������� å �˻� �޼���
    void searchByTitle(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "�˻� ���: " << book.title << " by " << book.author << endl;
                found = true;
                break; // ������ �����ϹǷ� ã���� ���� ����
            }
        }
        if (!found) {
            cout << "���� \"" << title << "\"�� �ش��ϴ� å�� ã�� �� �����ϴ�." << endl;
        }
    }

    // �۰��� å �˻� �޼���
    void searchByAuthor(const string& author) const {
        bool found = false;
        cout << "�۰� \"" << author << "\"�� å ���:" << endl;
        for (const auto& book : books) {
            if (book.author == author) {
                cout << "- " << book.title << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "�۰� \"" << author << "\"�� å�� ã�� �� �����ϴ�." << endl;
        }
    }
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�" << endl; // å �˻� ��� �߰�
        cout << "4. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: å �˻�
            // �˻� ����� �����ϰ� �ش� ������� �˻��� �����մϴ�.
            cout << "\nå �˻� ��� ����:" << endl;
            cout << "1. �������� �˻�" << endl;
            cout << "2. �۰��� �˻�" << endl;
            cout << "����: ";

            int searchChoice;
            cin >> searchChoice;

            if (searchChoice == 1) {
                // �������� �˻�
                string searchTitle;
                cout << "�˻��� å ����: ";
                cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                getline(cin, searchTitle);
                manager.searchByTitle(searchTitle);
            }
            else if (searchChoice == 2) {
                // �۰��� �˻�
                string searchAuthor;
                cout << "�˻��� �۰���: ";
                cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                getline(cin, searchAuthor);
                manager.searchByAuthor(searchAuthor);
            }
            else {
                // �߸��� �Է� ó��
                cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
            }
        }
        else if (choice == 4) {
            // 4�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
