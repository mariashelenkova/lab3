#include <gtest.h>
#include "translator.h"

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Ru");
    char a;
    cout << "������� T ��� ������ � �������" << endl;
    cout << "������� K ��� ������ � ����������" << endl;
    cin >> a;

    if (a == 'T') {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }


    else if (a == 'K')
    {
        PostfixCalculator calculator;
        std::string expression;

        std::cout << "������� �������������� ��������� � ��������� �����:" << endl;

        while (true)
        {
            try
            {
                std::cout << ">>> ";
                std::getline(std::cin, expression);

                if (expression == "exit")
                {
                    std::cout << "����� �� ���������." << endl;
                    break;
                }

                std::string postfix = calculator.convertToPostfix(expression);
                std::cout << "����������� �����: " << postfix << endl;

                double result = calculator.evaluatePostfix(postfix);
                std::cout << "���������: " << result << endl;
            }
            catch (const char* error)
            {
                std::cout << "������: " << error << endl;
            }
            catch (...)
            {
                std::cout << "��������� ����������� ������" << endl;
            }

            std::cout << "������� ����� ��������� ��� �������� 'exit' ��� ������ �� ���������" << endl;
        }
    }

    return 0;
}

