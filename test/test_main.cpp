#include <gtest.h>
#include "translator.h"

int main(int argc, char **argv) {

    setlocale(LC_ALL, "Ru");
    char a;
    cout << "Введите T для работы с тестами" << endl;
    cout << "Введите K для работы с выражением" << endl;
    cin >> a;

    if (a == 'T') {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }


    else if (a == 'K')
    {
        PostfixCalculator calculator;
        std::string expression;

        std::cout << "Введите арифметическое выражение в инфиксной форме:" << endl;

        while (true)
        {
            try
            {
                std::cout << ">>> ";
                std::getline(std::cin, expression);

                if (expression == "exit")
                {
                    std::cout << "Выход из программы." << endl;
                    break;
                }

                std::string postfix = calculator.convertToPostfix(expression);
                std::cout << "Постфиксная форма: " << postfix << endl;

                double result = calculator.evaluatePostfix(postfix);
                std::cout << "Результат: " << result << endl;
            }
            catch (const char* error)
            {
                std::cout << "Ошибка: " << error << endl;
            }
            catch (...)
            {
                std::cout << "Произошла неизвестная ошибка" << endl;
            }

            std::cout << "Введите новое выражение или напишите 'exit' для выходы из программы" << endl;
        }
    }

    return 0;
}

