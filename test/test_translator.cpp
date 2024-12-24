#include "translator.h"
#include <gtest.h>

TEST(PostfixCalculator, convertToPostfixHandlesDigits) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.convertToPostfix("4567"), "4567 ");
}

TEST(PostfixCalculator, convertToPostfixHandlesOperators_sum) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.convertToPostfix("1+2"), "1 2 + ");
}

TEST(PostfixCalculator, convertToPostfixHandlesOperators_mul) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.convertToPostfix("3.9*4"), "3.9 4 * ");
}

TEST(PostfixCalculator, convertToPostfixHandlesParentheses) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.convertToPostfix("((2+3)*4)"), "2 3 + 4 * ");
}

TEST(PostfixCalculator, convertToPostfixThrowsOnInvalidCharacter_one) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.convertToPostfix("1+2*#"), const char*);
}

TEST(PostfixCalculator, convertToPostfixThrowsOnInvalidCharacter_two) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.convertToPostfix("3 4 &"), const char*);
}

TEST(PostfixCalculator, convertToPostfixThrowsOnMismatchedParentheses) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.convertToPostfix("(1+2"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixHandlesSimpleExpression) {
    PostfixCalculator calc;

    EXPECT_DOUBLE_EQ(calc.evaluatePostfix("5 1 2 + 4 * + 3 -"), 14);
}

TEST(PostfixCalculator, evaluatePostfixHandlesDivisionByZero) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("5 0 /"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixThrowsOnInvalidExpression) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("3 4 + +"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixThrowsOnDivisionByZero) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("5 / 0"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixThrowsOnEmptyInput) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix(""), const char*);
}

TEST(PostfixCalculator, evaluatePostfixThrowsOnInvalidCharactersInExpression) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("5 * (2 + &"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixHandlesMismatchedParentheses) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("((1 + 2) * (3 + 4))"), const char*);
}

TEST(PostfixCalculator, evaluatePostfixThrowsOnInvalidPostfixExpression) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.evaluatePostfix("2 3 + *"), const char*);
}

TEST(PostfixCalculator, performOperationThrowsOnInvalidOperation_one) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.performOperation(3, 4, '^'), const char*);
}

TEST(PostfixCalculator, performOperationThrowsOnInvalidOperation) {
    PostfixCalculator calc;

    EXPECT_THROW(calc.performOperation(5, 0, '/'), const char*);
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_sum) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isOperator('+'));
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_minus) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isOperator('-'));
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_mul) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isOperator('*'));
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_div) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isOperator('/'));
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_interest) {
    PostfixCalculator calc;

    EXPECT_FALSE(calc.isOperator('%'));
}

TEST(PostfixCalculator, isOperatorHandlesVariousOperators_lattice) {
    PostfixCalculator calc;

    EXPECT_FALSE(calc.isOperator('#'));
}

TEST(PostfixCalculator, isDigitHandlesVariousDigits_zero) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isDigit('0'));
}
TEST(PostfixCalculator, isDigitHandlesVariousDigits_nine) {
    PostfixCalculator calc;

    EXPECT_TRUE(calc.isDigit('9'));
}

TEST(PostfixCalculator, isDigitHandlesVariousDigits_a) {
    PostfixCalculator calc;

    EXPECT_FALSE(calc.isDigit('a'));
}

TEST(PostfixCalculator, isDigitHandlesVariousDigits_sobaka) {
    PostfixCalculator calc;

    EXPECT_FALSE(calc.isDigit('@'));
}

TEST(PostfixCalculator, getPrecedenceHandlesDifferentOperators_sum) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.getPrecedence('+'), 1);
}

TEST(PostfixCalculator, getPrecedenceHandlesDifferentOperators_minus) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.getPrecedence('-'), 1);
}

TEST(PostfixCalculator, getPrecedenceHandlesDifferentOperators_mul) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.getPrecedence('*'), 2);
}

TEST(PostfixCalculator, getPrecedenceHandlesDifferentOperators_div) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.getPrecedence('/'), 2);
}

TEST(PostfixCalculator, getPrecedenceHandlesDifferentOperators_deg) {
    PostfixCalculator calc;

    EXPECT_EQ(calc.getPrecedence('^'), 0);
}
